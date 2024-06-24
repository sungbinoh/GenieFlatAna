#include "GenieHadAna.h"

void GenieHadAna::initializeAnalyzer(){

  cout << "[[GenieHadAna::initializeAnalyzer]]" << endl;
  debug_mode = true;
  debug_mode = false;

}

void GenieHadAna::executeEvent(){

  vector<Particle> Particle_all = GetAllParticles();
  //cout << "Particle_all.size() : " << Particle_all.size() << endl;

  if(Particle_all.size() == 2) return;
  vector<Particle> out_protons = GetAllOutProtons(Particle_all);
  vector<Particle> out_protons_10MeV = GetOutProtons(out_protons, 0.01);
  vector<Particle> out_protons_70MeV = GetOutProtons(out_protons, 0.07);
  vector<Particle> out_protons_100MeV = GetOutProtons(out_protons, 0.1);

  FillHist("N_out_proton_ke_10MeV", out_protons_10MeV.size(), 1., 30., -0.5, 29.5);
  FillHist("N_out_proton_ke_70MeV", out_protons_70MeV.size(), 1., 30., -0.5, 29.5);
  FillHist("N_out_proton_ke_100MeV", out_protons_100MeV.size(), 1., 30., -0.5, 29.5);

}

GenieHadAna::GenieHadAna(){

}

GenieHadAna::~GenieHadAna(){

}
