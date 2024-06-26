#include "AnalyzerCore.h"
#include "GenieFlatTree.h"

AnalyzerCore::AnalyzerCore(){
  MaxEvent = -1;
  NSkipEvent = 0;
  LogEvery = 1000;
  MCSample = "";
  outfile = NULL;
}

AnalyzerCore::~AnalyzerCore(){

  //=== hist maps
  for(std::map< TString, TH1D* >::iterator mapit = maphist_TH1D.begin(); mapit!=maphist_TH1D.end(); mapit++){
    delete mapit->second;
  }
  maphist_TH1D.clear();

  for(std::map< TString, TH2D* >::iterator mapit = maphist_TH2D.begin(); mapit!=maphist_TH2D.end(); mapit++){
    delete mapit->second;
  }
  maphist_TH2D.clear();

  for(std::map< TString, TH3D* >::iterator mapit = maphist_TH3D.begin(); mapit!=maphist_TH3D.end(); mapit++){
    delete mapit->second;
  }
  maphist_TH3D.clear();

  //==== output rootfile
  if(outfile) outfile->Close();
  delete outfile;

  if (!fChain) return;
  delete fChain->GetCurrentFile();
  cout << "[AnalyzerCore::~AnalyzerCore] JOB FINISHED " << printcurrunttime() << endl;
}

//==================
//==== Read Trees
//==================
Int_t AnalyzerCore::GetEntry(Long64_t entry)
{
  // Read contents of entry
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}

void AnalyzerCore::Loop(){

  Long64_t nentries = fChain->GetEntries();
  if(MaxEvent>0){
    nentries = std::min(nentries,MaxEvent);
  }

  cout << "[AnalyzerCore::Loop] MaxEvent = " << MaxEvent << endl;
  cout << "[AnalyzerCore::Loop] NSkipEvent = " << NSkipEvent << endl;
  cout << "[AnalyzerCore::Loop] LogEvery = " << LogEvery << endl;
  cout << "[AnalyzerCore::Loop] MCSample = " << MCSample << endl;
  cout << "[AnalyzerCore::Loop] Userflags = {" << endl;
  for(unsigned int i=0; i<Userflags.size(); i++){
    cout << "[AnalyzerCore::Loop]   \"" << Userflags.at(i) << "\"," << endl;
  }
  cout << "[AnalyzerCore::Loop] }" << endl;

  cout << "[AnalyzerCore::Loop] Event Loop Started " << printcurrunttime() << endl;

  for(Long64_t jentry=0; jentry<nentries;jentry++){

    if(jentry<NSkipEvent){
      continue;
    }

    if(jentry%LogEvery==0){
      cout << "[AnalyzerCore::Loop RUNNING] " << jentry << "/" << nentries << " ("<<100.*jentry/nentries<<" %) @ " << printcurrunttime() << endl;
    }

    fChain->GetEntry(jentry);
    Init_evt();
    executeEvent();
  }

  cout << "[AnalyzerCore::Loop] LOOP END " << printcurrunttime() << endl;
}

//==== Attach the historams to ai different direcotry, not outfile
//==== We will write these histograms in WriteHist() to outfile
void AnalyzerCore::SwitchToTempDir(){

  gROOT->cd();
  TDirectory *tempDir = NULL;
  int counter = 0;
  while (!tempDir) {
    //==== First, let's find a directory name that doesn't exist yet
    std::stringstream dirname;
    dirname << "AnalyzerCore" << counter;
    if (gROOT->GetDirectory((dirname.str()).c_str())) {
      ++counter;
      continue;
    }
    //==== Let's try to make this directory
    tempDir = gROOT->mkdir((dirname.str()).c_str());
  }
  tempDir->cd();

}

void AnalyzerCore::SetOutfilePath(TString outname){
  outfile = new TFile(outname,"RECREATE");
};

Event AnalyzerCore::GetEvent(){

  Event ev;
  return ev;
}

//==================
// Get Particles
//==================
std::vector<Particle> AnalyzerCore::GetAllParticles(){
  vector<Particle> out;

  for (size_t i = 0; i < evt.par_pdg->size(); i++){
    //if((*evt.par_pdg)[i].empty()) continue;

    Particle this_Particle;
    this_Particle.SetIsEmpty(false);
    this_Particle.Set_par_pdg((*evt.par_pdg).at(i));
    this_Particle.Set_par_status((*evt.par_status).at(i));
    this_Particle.Set_par_1st_mother((*evt.par_1st_mother).at(i));
    this_Particle.Set_par_last_mother((*evt.par_last_mother).at(i));
    this_Particle.Set_par_1st_daughter((*evt.par_1st_daughter).at(i));
    this_Particle.Set_par_last_daughter((*evt.par_last_daughter).at(i));
    this_Particle.Set_par_px((*evt.par_px).at(i));
    this_Particle.Set_par_py((*evt.par_py).at(i));
    this_Particle.Set_par_pz((*evt.par_pz).at(i));
    this_Particle.Set_par_E((*evt.par_E).at(i));
    this_Particle.Set_par_M((*evt.par_M).at(i));
    this_Particle.Set_par_Vx((*evt.par_Vx).at(i));
    this_Particle.Set_par_Vy((*evt.par_Vy).at(i));
    this_Particle.Set_par_Vz((*evt.par_Vz).at(i));
    this_Particle.Set_par_Vt((*evt.par_Vt).at(i));

    out.push_back(this_Particle);
  }

  return out;
}

std::vector<Particle> AnalyzerCore::GetAllOutProtons(const vector<Particle>& in){

  vector<Particle> out;
  if(in.size() < 3) return out;
  
  for(unsigned int i = 2; i < in.size(); i++){
    Particle this_in = in.at(i);
    if(this_in.pdg() == 2212){
      out.push_back(this_in);
    }
  }

  return out;
}

std::vector<Particle> AnalyzerCore::GetAllOutNeutrons(const vector<Particle>& in){

  vector<Particle> out;
  if(in.size() < 3) return out;
 
  for(unsigned int i = 2; i < in.size(); i++){
    Particle this_in = in.at(i);
    if(this_in.pdg() == 2112){
      out.push_back(this_in);
    }
  }

  return out;
}

std::vector<Particle> AnalyzerCore::GetOutProtons(const vector<Particle>& in, double ke_threshold){

  vector<Particle> out;
  if(in.size() < 3) return out;

  for(unsigned int i = 2; i < in.size(); i++){
    Particle this_in = in.at(i);
    double this_ke = this_in.E() - this_in.M();
    if(this_in.pdg() == 2212 && this_ke > ke_threshold){
      out.push_back(this_in);
    }
  }

  return out;
}

std::vector<Particle> AnalyzerCore::GetOutNeutrons(const vector<Particle>& in, double ke_threshold){

  vector<Particle> out;
  if(in.size() < 3) return out;

  for(unsigned int i = 2; i < in.size(); i++){
    Particle this_in = in.at(i);
    double this_ke = this_in.E() - this_in.M();
    if(this_in.pdg() == 2112 && this_ke > ke_threshold){
      out.push_back(this_in);
    }
  }

  return out;
}

//==================
// Initialize
//==================
void AnalyzerCore::initializeAnalyzerTools(){

}

void AnalyzerCore::Init(){
  cout << "Let's initiallize!" << endl;
  evt.Init_GenieFlatTree(fChain);
}

void AnalyzerCore::Init_evt(){
}

//==================
//==== Plotting
//==================
TH1D* AnalyzerCore::GetHist1D(TString histname){

  TH1D *h = NULL;
  std::map<TString, TH1D*>::iterator mapit = maphist_TH1D.find(histname);
  if(mapit != maphist_TH1D.end()) return mapit->second;

  return h;

}

TH2D* AnalyzerCore::GetHist2D(TString histname){

  TH2D *h = NULL;
  std::map<TString, TH2D*>::iterator mapit = maphist_TH2D.find(histname);
  if(mapit != maphist_TH2D.end()) return mapit->second;

  return h;

}

TH3D* AnalyzerCore::GetHist3D(TString histname){

  TH3D *h = NULL;
  std::map<TString, TH3D*>::iterator mapit = maphist_TH3D.find(histname);
  if(mapit != maphist_TH3D.end()) return mapit->second;

  return h;

}

void AnalyzerCore::FillHist(TString histname, double value, double weight, int n_bin, double x_min, double x_max){

  TH1D *this_hist = GetHist1D(histname);
  if( !this_hist ){
    this_hist = new TH1D(histname, "", n_bin, x_min, x_max);
    this_hist->SetDirectory(NULL);
    maphist_TH1D[histname] = this_hist;
  }

  this_hist->Fill(value, weight);

}

void AnalyzerCore::FillHist(TString histname, double value, double weight, int n_bin, double *xbins){

  TH1D *this_hist = GetHist1D(histname);
  if( !this_hist ){
    this_hist = new TH1D(histname, "", n_bin, xbins);
    this_hist->SetDirectory(NULL);
    maphist_TH1D[histname] = this_hist;
  }

  this_hist->Fill(value, weight);

}

void AnalyzerCore::FillHist(TString histname,
                            double value_x, double value_y,
                            double weight,
                            int n_binx, double x_min, double x_max,
                            int n_biny, double y_min, double y_max){

  TH2D *this_hist = GetHist2D(histname);
  if( !this_hist ){
    this_hist = new TH2D(histname, "", n_binx, x_min, x_max, n_biny, y_min, y_max);
    this_hist->SetDirectory(NULL);
    maphist_TH2D[histname] = this_hist;
  }

  this_hist->Fill(value_x, value_y, weight);

}

void AnalyzerCore::FillHist(TString histname,
                            double value_x, double value_y,
                            double weight,
                            int n_binx, double *xbins,
                            int n_biny, double *ybins){

  TH2D *this_hist = GetHist2D(histname);
  if( !this_hist ){
    this_hist = new TH2D(histname, "", n_binx, xbins, n_biny, ybins);
    this_hist->SetDirectory(NULL);
    maphist_TH2D[histname] = this_hist;
  }

  this_hist->Fill(value_x, value_y, weight);

}

void AnalyzerCore::FillHist(TString histname,
                            double value_x, double value_y, double value_z,
                            double weight,
                            int n_binx, double x_min, double x_max,
                            int n_biny, double y_min, double y_max,
                            int n_binz, double z_min, double z_max){

  TH3D *this_hist = GetHist3D(histname);
  if( !this_hist ){
    this_hist = new TH3D(histname, "", n_binx, x_min, x_max, n_biny, y_min, y_max, n_binz, z_min, z_max);
    this_hist->SetDirectory(NULL);
    maphist_TH3D[histname] = this_hist;
  }

  this_hist->Fill(value_x, value_y, value_z, weight);

}

void AnalyzerCore::FillHist(TString histname,
                            double value_x, double value_y, double value_z,
                            double weight,
                            int n_binx, double *xbins,
                            int n_biny, double *ybins,
                            int n_binz, double *zbins){

  TH3D *this_hist = GetHist3D(histname);
  if( !this_hist ){
    this_hist = new TH3D(histname, "", n_binx, xbins, n_biny, ybins, n_binz, zbins);
    this_hist->SetDirectory(NULL);
    maphist_TH3D[histname] = this_hist;
  }

  this_hist->Fill(value_x, value_y, value_z, weight);

}

TH1D* AnalyzerCore::JSGetHist1D(TString suffix, TString histname){

  TH1D *h = NULL;

  std::map< TString, std::map<TString, TH1D*> >::iterator mapit = JSmaphist_TH1D.find(suffix);
  if(mapit==JSmaphist_TH1D.end()){
    return h;
  }
  else{

    std::map<TString, TH1D*> this_maphist = mapit->second;
    std::map<TString, TH1D*>::iterator mapitit = this_maphist.find(histname);
    if(mapitit != this_maphist.end()) return mapitit->second;

  }

  return h;

}

void AnalyzerCore::JSFillHist(TString suffix, TString histname, double value, double weight, int n_bin, double x_min, double x_max){

  TH1D *this_hist = JSGetHist1D(suffix, histname);
  if( !this_hist ){

    this_hist = new TH1D(histname, "", n_bin, x_min, x_max);
    (JSmaphist_TH1D[suffix])[histname] = this_hist;

  }

  this_hist->Fill(value, weight);

}

TH2D* AnalyzerCore::JSGetHist2D(TString suffix, TString histname){

  TH2D *h = NULL;

  std::map< TString, std::map<TString, TH2D*> >::iterator mapit = JSmaphist_TH2D.find(suffix);
  if(mapit==JSmaphist_TH2D.end()){
    return h;
  }
  else{

    std::map<TString, TH2D*> this_maphist = mapit->second;
    std::map<TString, TH2D*>::iterator mapitit = this_maphist.find(histname);
    if(mapitit != this_maphist.end()) return mapitit->second;

  }

  return h;

}

void AnalyzerCore::JSFillHist(TString suffix, TString histname,
                              double value_x, double value_y,
                              double weight,
                              int n_binx, double x_min, double x_max,
                              int n_biny, double y_min, double y_max){

  TH2D *this_hist = JSGetHist2D(suffix, histname);
  if( !this_hist ){

    this_hist = new TH2D(histname, "", n_binx, x_min, x_max, n_biny, y_min, y_max);
    (JSmaphist_TH2D[suffix])[histname] = this_hist;

  }

  this_hist->Fill(value_x, value_y, weight);

}

void AnalyzerCore::JSFillHist(TString suffix, TString histname,
                              double value_x, double value_y,
                              double weight,
                              int n_binx, double *xbins,
                              int n_biny, double *ybins){

  TH2D *this_hist = JSGetHist2D(suffix, histname);
  if( !this_hist ){

    this_hist = new TH2D(histname, "", n_binx, xbins, n_biny, ybins);
    (JSmaphist_TH2D[suffix])[histname] = this_hist;

  }

  this_hist->Fill(value_x, value_y, weight);

}


void AnalyzerCore::WriteHist(){

  outfile->cd();
  for(std::map< TString, TH1D* >::iterator mapit = maphist_TH1D.begin(); mapit!=maphist_TH1D.end(); mapit++){
    TString this_fullname=mapit->second->GetName();
    TString this_name=this_fullname(this_fullname.Last('/')+1,this_fullname.Length());
    TString this_suffix=this_fullname(0,this_fullname.Last('/'));
    TDirectory *dir = outfile->GetDirectory(this_suffix);
    if(!dir){
      outfile->mkdir(this_suffix);
    }
    outfile->cd(this_suffix);
    mapit->second->Write(this_name);
    outfile->cd();
  }
  for(std::map< TString, TH2D* >::iterator mapit = maphist_TH2D.begin(); mapit!=maphist_TH2D.end(); mapit++){
    TString this_fullname=mapit->second->GetName();
    TString this_name=this_fullname(this_fullname.Last('/')+1,this_fullname.Length());
    TString this_suffix=this_fullname(0,this_fullname.Last('/'));
    TDirectory *dir = outfile->GetDirectory(this_suffix);
    if(!dir){
      outfile->mkdir(this_suffix);
    }
    outfile->cd(this_suffix);
    mapit->second->Write(this_name);
    outfile->cd();
  }
  for(std::map< TString, TH3D* >::iterator mapit = maphist_TH3D.begin(); mapit!=maphist_TH3D.end(); mapit++){
    TString this_fullname=mapit->second->GetName();
    TString this_name=this_fullname(this_fullname.Last('/')+1,this_fullname.Length());
    TString this_suffix=this_fullname(0,this_fullname.Last('/'));
    TDirectory *dir = outfile->GetDirectory(this_suffix);
    if(!dir){
      outfile->mkdir(this_suffix);
    }
    outfile->cd(this_suffix);
    mapit->second->Write(this_name);
    outfile->cd();
  }

  outfile->cd();
  for(std::map< TString, std::map<TString, TH1D*> >::iterator mapit=JSmaphist_TH1D.begin(); mapit!=JSmaphist_TH1D.end(); mapit++){

    TString this_suffix = mapit->first;
    std::map< TString, TH1D* > this_maphist = mapit->second;


    TDirectory *dir = outfile->GetDirectory(this_suffix);
    if(!dir){
      outfile->mkdir(this_suffix);
    }
    outfile->cd(this_suffix);

    for(std::map< TString, TH1D* >::iterator mapit = this_maphist.begin(); mapit!=this_maphist.end(); mapit++){
      mapit->second->Write();
    }

    outfile->cd();

  }

  for(std::map< TString, std::map<TString, TH2D*> >::iterator mapit=JSmaphist_TH2D.begin(); mapit!=JSmaphist_TH2D.end(); mapit++){

    TString this_suffix = mapit->first;
    std::map< TString, TH2D* > this_maphist = mapit->second;

    TDirectory *dir = outfile->GetDirectory(this_suffix);
    if(!dir){
      outfile->mkdir(this_suffix);
    }
    outfile->cd(this_suffix);

    for(std::map< TString, TH2D* >::iterator mapit = this_maphist.begin(); mapit!=this_maphist.end(); mapit++){
      mapit->second->Write();
    }

    outfile->cd();

  }

  outfile->cd();
}
