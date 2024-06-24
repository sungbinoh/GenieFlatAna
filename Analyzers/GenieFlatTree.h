#ifndef GenieFlatTree_h
#define GenieFlatTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TString.h>

// Header file for the classes stored in the TTree if any.
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
class GenieFlatTree {
public :

  GenieFlatTree();
  virtual ~GenieFlatTree();

  virtual void Init_GenieFlatTree(TChain *ch);

  // Declaration of leaf types
  Int_t           Mode;
  Float_t         Emiss;
  Float_t         Emiss_preFSI;
  Double_t        Emiss_GENIE;
  Float_t         pmiss;
  Float_t         pmiss_preFSI;
  Float_t         q0;
  Float_t         Q2;
  Float_t         q3;
  Float_t         Enu_true;
  Float_t         plep;
  Int_t           nucleon_pdg;
  Int_t           target_pdg;
  Int_t           nu_pdg;
  Double_t        e_nu_GeV;
  Int_t           tgt_A;
  Int_t           tgt_Z;
  Bool_t          is_cc;
  Bool_t          is_qe;
  Bool_t          is_mec;
  Int_t           mec_topology;
  Bool_t          is_res;
  Int_t           res_channel;
  Bool_t          is_dis;
  Double_t        W_GeV;
  Double_t        Q2_GeV2;
  Double_t        q0_GeV;
  Double_t        q3_GeV;
  Double_t        EAvail_GeV;
  vector<int>     *fsi_pdgs;
  vector<int>     *fsi_codes;
  vector<int>     *par_pdg;
  vector<int>     *par_status;
  vector<int>     *par_1st_mother;
  vector<int>     *par_last_mother;
  vector<int>     *par_1st_daughter;
  vector<int>     *par_last_daughter;
  vector<double>  *par_px;
  vector<double>  *par_py;
  vector<double>  *par_pz;
  vector<double>  *par_E;
  vector<double>  *par_M;
  vector<double>  *par_Vx;
  vector<double>  *par_Vy;
  vector<double>  *par_Vz;
  vector<double>  *par_Vt;
  Int_t           ntweaks_Emiss_CorrTail_Ar_p;
  Double_t        tweak_responses_Emiss_CorrTail_Ar_p[5];   //[ntweaks_Emiss_CorrTail_Ar_p]
  Double_t        paramCVWeight_Emiss_CorrTail_Ar_p;
  Int_t           ntweaks_Emiss_CorrTail_Ar_n;
  Double_t        tweak_responses_Emiss_CorrTail_Ar_n[5];   //[ntweaks_Emiss_CorrTail_Ar_n]
  Double_t        paramCVWeight_Emiss_CorrTail_Ar_n;
  Int_t           ntweaks_Emiss_Linear_Ar_p;
  Double_t        tweak_responses_Emiss_Linear_Ar_p[5];   //[ntweaks_Emiss_Linear_Ar_p]
  Double_t        paramCVWeight_Emiss_Linear_Ar_p;
  Int_t           ntweaks_Emiss_Linear_Ar_n;
  Double_t        tweak_responses_Emiss_Linear_Ar_n[5];   //[ntweaks_Emiss_Linear_Ar_n]
  Double_t        paramCVWeight_Emiss_Linear_Ar_n;
  Int_t           ntweaks_Emiss_ShiftPeak_Ar_p;
  Double_t        tweak_responses_Emiss_ShiftPeak_Ar_p[5];   //[ntweaks_Emiss_ShiftPeak_Ar_p]
  Double_t        paramCVWeight_Emiss_ShiftPeak_Ar_p;
  Int_t           ntweaks_Emiss_ShiftPeak_Ar_n;
  Double_t        tweak_responses_Emiss_ShiftPeak_Ar_n[5];   //[ntweaks_Emiss_ShiftPeak_Ar_n]
  Double_t        paramCVWeight_Emiss_ShiftPeak_Ar_n;
  Int_t           ntweaks_Emiss_CorrTail_C_p;
  Double_t        tweak_responses_Emiss_CorrTail_C_p[5];   //[ntweaks_Emiss_CorrTail_C_p]
  Double_t        paramCVWeight_Emiss_CorrTail_C_p;
  Int_t           ntweaks_Emiss_CorrTail_C_n;
  Double_t        tweak_responses_Emiss_CorrTail_C_n[5];   //[ntweaks_Emiss_CorrTail_C_n]
  Double_t        paramCVWeight_Emiss_CorrTail_C_n;
  Int_t           ntweaks_Emiss_Linear_C_p;
  Double_t        tweak_responses_Emiss_Linear_C_p[5];   //[ntweaks_Emiss_Linear_C_p]
  Double_t        paramCVWeight_Emiss_Linear_C_p;
  Int_t           ntweaks_Emiss_Linear_C_n;
  Double_t        tweak_responses_Emiss_Linear_C_n[5];   //[ntweaks_Emiss_Linear_C_n]
  Double_t        paramCVWeight_Emiss_Linear_C_n;
  Int_t           ntweaks_Emiss_ShiftPeak_C_p;
  Double_t        tweak_responses_Emiss_ShiftPeak_C_p[5];   //[ntweaks_Emiss_ShiftPeak_C_p]
  Double_t        paramCVWeight_Emiss_ShiftPeak_C_p;
  Int_t           ntweaks_Emiss_ShiftPeak_C_n;
  Double_t        tweak_responses_Emiss_ShiftPeak_C_n[5];   //[ntweaks_Emiss_ShiftPeak_C_n]
  Double_t        paramCVWeight_Emiss_ShiftPeak_C_n;

  // List of branches
  TBranch        *b_Mode;   //!
  TBranch        *b_Emiss;   //!
  TBranch        *b_Emiss_preFSI;   //!
  TBranch        *b_Emiss_GENIE;   //!
  TBranch        *b_pmiss;   //!
  TBranch        *b_pmiss_preFSI;   //!
  TBranch        *b_q0;   //!
  TBranch        *b_Q2;   //!
  TBranch        *b_q3;   //!
  TBranch        *b_Enu_true;   //!
  TBranch        *b_plep;   //!
  TBranch        *b_nucleon_pdg;   //!
  TBranch        *b_target_pdg;   //!
  TBranch        *b_nu_pdg;   //!
  TBranch        *b_e_nu_GeV;   //!
  TBranch        *b_tgt_A;   //!
  TBranch        *b_tgt_Z;   //!
  TBranch        *b_is_cc;   //!
  TBranch        *b_is_qe;   //!
  TBranch        *b_is_mec;   //!
  TBranch        *b_mec_topology;   //!
  TBranch        *b_is_res;   //!
  TBranch        *b_res_channel;   //!
  TBranch        *b_is_dis;   //!
  TBranch        *b_W_GeV;   //!
  TBranch        *b_Q2_GeV2;   //!
  TBranch        *b_q0_GeV;   //!
  TBranch        *b_q3_GeV;   //!
  TBranch        *b_EAvail_GeV;   //!
  TBranch        *b_fsi_pdgs;   //!
  TBranch        *b_fsi_codes;   //!
  TBranch        *b_par_pdg;   //!
  TBranch        *b_par_status;   //!
  TBranch        *b_par_1st_mother;   //!
  TBranch        *b_par_last_mother;   //!
  TBranch        *b_par_1st_daughter;   //!
  TBranch        *b_par_last_daughter;   //!
  TBranch        *b_par_px;   //!
  TBranch        *b_par_py;   //!
  TBranch        *b_par_pz;   //!
  TBranch        *b_par_E;   //!
  TBranch        *b_par_M;   //!
  TBranch        *b_par_Vx;   //!
  TBranch        *b_par_Vy;   //!
  TBranch        *b_par_Vz;   //!
  TBranch        *b_par_Vt;   //!
  TBranch        *b_ntweaks_Emiss_CorrTail_Ar_p;   //!
  TBranch        *b_tweak_responses_Emiss_CorrTail_Ar_p;   //!
  TBranch        *b_paramCVWeight_Emiss_CorrTail_Ar_p;   //!
  TBranch        *b_ntweaks_Emiss_CorrTail_Ar_n;   //!
  TBranch        *b_tweak_responses_Emiss_CorrTail_Ar_n;   //!
  TBranch        *b_paramCVWeight_Emiss_CorrTail_Ar_n;   //!
  TBranch        *b_ntweaks_Emiss_Linear_Ar_p;   //!
  TBranch        *b_tweak_responses_Emiss_Linear_Ar_p;   //!
  TBranch        *b_paramCVWeight_Emiss_Linear_Ar_p;   //!
  TBranch        *b_ntweaks_Emiss_Linear_Ar_n;   //!
  TBranch        *b_tweak_responses_Emiss_Linear_Ar_n;   //!
  TBranch        *b_paramCVWeight_Emiss_Linear_Ar_n;   //!
  TBranch        *b_ntweaks_Emiss_ShiftPeak_Ar_p;   //!
  TBranch        *b_tweak_responses_Emiss_ShiftPeak_Ar_p;   //!
  TBranch        *b_paramCVWeight_Emiss_ShiftPeak_Ar_p;   //!
  TBranch        *b_ntweaks_Emiss_ShiftPeak_Ar_n;   //!
  TBranch        *b_tweak_responses_Emiss_ShiftPeak_Ar_n;   //!
  TBranch        *b_paramCVWeight_Emiss_ShiftPeak_Ar_n;   //!
  TBranch        *b_ntweaks_Emiss_CorrTail_C_p;   //!
  TBranch        *b_tweak_responses_Emiss_CorrTail_C_p;   //!
  TBranch        *b_paramCVWeight_Emiss_CorrTail_C_p;   //!
  TBranch        *b_ntweaks_Emiss_CorrTail_C_n;   //!
  TBranch        *b_tweak_responses_Emiss_CorrTail_C_n;   //!
  TBranch        *b_paramCVWeight_Emiss_CorrTail_C_n;   //!
  TBranch        *b_ntweaks_Emiss_Linear_C_p;   //!
  TBranch        *b_tweak_responses_Emiss_Linear_C_p;   //!
  TBranch        *b_paramCVWeight_Emiss_Linear_C_p;   //!
  TBranch        *b_ntweaks_Emiss_Linear_C_n;   //!
  TBranch        *b_tweak_responses_Emiss_Linear_C_n;   //!
  TBranch        *b_paramCVWeight_Emiss_Linear_C_n;   //!
  TBranch        *b_ntweaks_Emiss_ShiftPeak_C_p;   //!
  TBranch        *b_tweak_responses_Emiss_ShiftPeak_C_p;   //!
  TBranch        *b_paramCVWeight_Emiss_ShiftPeak_C_p;   //!
  TBranch        *b_ntweaks_Emiss_ShiftPeak_C_n;   //!
  TBranch        *b_tweak_responses_Emiss_ShiftPeak_C_n;   //!
  TBranch        *b_paramCVWeight_Emiss_ShiftPeak_C_n;   //!

};

#endif
