#define GenieFlatTree_cxx
#include "GenieFlatTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

GenieFlatTree::GenieFlatTree(){
}

GenieFlatTree::~GenieFlatTree(){
}

void GenieFlatTree::Init_GenieFlatTree(TChain *ch)
{
  ch->SetMakeClass(0);
  // Set object pointer
  fsi_pdgs = 0;
  fsi_codes = 0;
  par_pdg = 0;
  par_1st_mother = 0;
  par_last_mother = 0;
  par_1st_daughter = 0;
  par_last_daughter = 0;
  par_px = 0;
  par_py = 0;
  par_pz = 0;
  par_E = 0;
  par_M = 0;
  par_Vx = 0;
  par_Vy = 0;
  par_Vz = 0;
  par_Vt = 0;
  // Set branch addresses and branch pointers
  ch->SetBranchAddress("Mode", &Mode, &b_Mode);
  ch->SetBranchAddress("Emiss", &Emiss, &b_Emiss);
  ch->SetBranchAddress("Emiss_preFSI", &Emiss_preFSI, &b_Emiss_preFSI);
  ch->SetBranchAddress("Emiss_GENIE", &Emiss_GENIE, &b_Emiss_GENIE);
  ch->SetBranchAddress("pmiss", &pmiss, &b_pmiss);
  ch->SetBranchAddress("pmiss_preFSI", &pmiss_preFSI, &b_pmiss_preFSI);
  ch->SetBranchAddress("q0", &q0, &b_q0);
  ch->SetBranchAddress("Q2", &Q2, &b_Q2);
  ch->SetBranchAddress("q3", &q3, &b_q3);
  ch->SetBranchAddress("Enu_true", &Enu_true, &b_Enu_true);
  ch->SetBranchAddress("plep", &plep, &b_plep);
  ch->SetBranchAddress("nucleon_pdg", &nucleon_pdg, &b_nucleon_pdg);
  ch->SetBranchAddress("target_pdg", &target_pdg, &b_target_pdg);
  ch->SetBranchAddress("nu_pdg", &nu_pdg, &b_nu_pdg);
  ch->SetBranchAddress("e_nu_GeV", &e_nu_GeV, &b_e_nu_GeV);
  ch->SetBranchAddress("tgt_A", &tgt_A, &b_tgt_A);
  ch->SetBranchAddress("tgt_Z", &tgt_Z, &b_tgt_Z);
  ch->SetBranchAddress("is_cc", &is_cc, &b_is_cc);
  ch->SetBranchAddress("is_qe", &is_qe, &b_is_qe);
  ch->SetBranchAddress("is_mec", &is_mec, &b_is_mec);
  ch->SetBranchAddress("mec_topology", &mec_topology, &b_mec_topology);
  ch->SetBranchAddress("is_res", &is_res, &b_is_res);
  ch->SetBranchAddress("res_channel", &res_channel, &b_res_channel);
  ch->SetBranchAddress("is_dis", &is_dis, &b_is_dis);
  ch->SetBranchAddress("W_GeV", &W_GeV, &b_W_GeV);
  ch->SetBranchAddress("Q2_GeV2", &Q2_GeV2, &b_Q2_GeV2);
  ch->SetBranchAddress("q0_GeV", &q0_GeV, &b_q0_GeV);
  ch->SetBranchAddress("q3_GeV", &q3_GeV, &b_q3_GeV);
  ch->SetBranchAddress("EAvail_GeV", &EAvail_GeV, &b_EAvail_GeV);
  ch->SetBranchAddress("fsi_pdgs", &fsi_pdgs, &b_fsi_pdgs);
  ch->SetBranchAddress("fsi_codes", &fsi_codes, &b_fsi_codes);
  ch->SetBranchAddress("par_pdg", &par_pdg, &b_par_pdg);
  ch->SetBranchAddress("par_1st_mother", &par_1st_mother, &b_par_1st_mother);
  ch->SetBranchAddress("par_last_mother", &par_last_mother, &b_par_last_mother);
  ch->SetBranchAddress("par_1st_daughter", &par_1st_daughter, &b_par_1st_daughter);
  ch->SetBranchAddress("par_last_daughter", &par_last_daughter, &b_par_last_daughter);
  ch->SetBranchAddress("par_px", &par_px, &b_par_px);
  ch->SetBranchAddress("par_py", &par_py, &b_par_py);
  ch->SetBranchAddress("par_pz", &par_pz, &b_par_pz);
  ch->SetBranchAddress("par_E", &par_E, &b_par_E);
  ch->SetBranchAddress("par_M", &par_M, &b_par_M);
  ch->SetBranchAddress("par_Vx", &par_Vx, &b_par_Vx);
  ch->SetBranchAddress("par_Vy", &par_Vy, &b_par_Vy);
  ch->SetBranchAddress("par_Vz", &par_Vz, &b_par_Vz);
  ch->SetBranchAddress("par_Vt", &par_Vt, &b_par_Vt);
  ch->SetBranchAddress("ntweaks_Emiss_CorrTail_Ar_p", &ntweaks_Emiss_CorrTail_Ar_p, &b_ntweaks_Emiss_CorrTail_Ar_p);
  ch->SetBranchAddress("tweak_responses_Emiss_CorrTail_Ar_p", tweak_responses_Emiss_CorrTail_Ar_p, &b_tweak_responses_Emiss_CorrTail_Ar_p);
  ch->SetBranchAddress("paramCVWeight_Emiss_CorrTail_Ar_p", &paramCVWeight_Emiss_CorrTail_Ar_p, &b_paramCVWeight_Emiss_CorrTail_Ar_p);
  ch->SetBranchAddress("ntweaks_Emiss_CorrTail_Ar_n", &ntweaks_Emiss_CorrTail_Ar_n, &b_ntweaks_Emiss_CorrTail_Ar_n);
  ch->SetBranchAddress("tweak_responses_Emiss_CorrTail_Ar_n", tweak_responses_Emiss_CorrTail_Ar_n, &b_tweak_responses_Emiss_CorrTail_Ar_n);
  ch->SetBranchAddress("paramCVWeight_Emiss_CorrTail_Ar_n", &paramCVWeight_Emiss_CorrTail_Ar_n, &b_paramCVWeight_Emiss_CorrTail_Ar_n);
  ch->SetBranchAddress("ntweaks_Emiss_Linear_Ar_p", &ntweaks_Emiss_Linear_Ar_p, &b_ntweaks_Emiss_Linear_Ar_p);
  ch->SetBranchAddress("tweak_responses_Emiss_Linear_Ar_p", tweak_responses_Emiss_Linear_Ar_p, &b_tweak_responses_Emiss_Linear_Ar_p);
  ch->SetBranchAddress("paramCVWeight_Emiss_Linear_Ar_p", &paramCVWeight_Emiss_Linear_Ar_p, &b_paramCVWeight_Emiss_Linear_Ar_p);
  ch->SetBranchAddress("ntweaks_Emiss_Linear_Ar_n", &ntweaks_Emiss_Linear_Ar_n, &b_ntweaks_Emiss_Linear_Ar_n);
  ch->SetBranchAddress("tweak_responses_Emiss_Linear_Ar_n", tweak_responses_Emiss_Linear_Ar_n, &b_tweak_responses_Emiss_Linear_Ar_n);
  ch->SetBranchAddress("paramCVWeight_Emiss_Linear_Ar_n", &paramCVWeight_Emiss_Linear_Ar_n, &b_paramCVWeight_Emiss_Linear_Ar_n);
  ch->SetBranchAddress("ntweaks_Emiss_ShiftPeak_Ar_p", &ntweaks_Emiss_ShiftPeak_Ar_p, &b_ntweaks_Emiss_ShiftPeak_Ar_p);
  ch->SetBranchAddress("tweak_responses_Emiss_ShiftPeak_Ar_p", tweak_responses_Emiss_ShiftPeak_Ar_p, &b_tweak_responses_Emiss_ShiftPeak_Ar_p);
  ch->SetBranchAddress("paramCVWeight_Emiss_ShiftPeak_Ar_p", &paramCVWeight_Emiss_ShiftPeak_Ar_p, &b_paramCVWeight_Emiss_ShiftPeak_Ar_p);
  ch->SetBranchAddress("ntweaks_Emiss_ShiftPeak_Ar_n", &ntweaks_Emiss_ShiftPeak_Ar_n, &b_ntweaks_Emiss_ShiftPeak_Ar_n);
  ch->SetBranchAddress("tweak_responses_Emiss_ShiftPeak_Ar_n", tweak_responses_Emiss_ShiftPeak_Ar_n, &b_tweak_responses_Emiss_ShiftPeak_Ar_n);
  ch->SetBranchAddress("paramCVWeight_Emiss_ShiftPeak_Ar_n", &paramCVWeight_Emiss_ShiftPeak_Ar_n, &b_paramCVWeight_Emiss_ShiftPeak_Ar_n);
  ch->SetBranchAddress("ntweaks_Emiss_CorrTail_C_p", &ntweaks_Emiss_CorrTail_C_p, &b_ntweaks_Emiss_CorrTail_C_p);
  ch->SetBranchAddress("tweak_responses_Emiss_CorrTail_C_p", tweak_responses_Emiss_CorrTail_C_p, &b_tweak_responses_Emiss_CorrTail_C_p);
  ch->SetBranchAddress("paramCVWeight_Emiss_CorrTail_C_p", &paramCVWeight_Emiss_CorrTail_C_p, &b_paramCVWeight_Emiss_CorrTail_C_p);
  ch->SetBranchAddress("ntweaks_Emiss_CorrTail_C_n", &ntweaks_Emiss_CorrTail_C_n, &b_ntweaks_Emiss_CorrTail_C_n);
  ch->SetBranchAddress("tweak_responses_Emiss_CorrTail_C_n", tweak_responses_Emiss_CorrTail_C_n, &b_tweak_responses_Emiss_CorrTail_C_n);
  ch->SetBranchAddress("paramCVWeight_Emiss_CorrTail_C_n", &paramCVWeight_Emiss_CorrTail_C_n, &b_paramCVWeight_Emiss_CorrTail_C_n);
  ch->SetBranchAddress("ntweaks_Emiss_Linear_C_p", &ntweaks_Emiss_Linear_C_p, &b_ntweaks_Emiss_Linear_C_p);
  ch->SetBranchAddress("tweak_responses_Emiss_Linear_C_p", tweak_responses_Emiss_Linear_C_p, &b_tweak_responses_Emiss_Linear_C_p);
  ch->SetBranchAddress("paramCVWeight_Emiss_Linear_C_p", &paramCVWeight_Emiss_Linear_C_p, &b_paramCVWeight_Emiss_Linear_C_p);
  ch->SetBranchAddress("ntweaks_Emiss_Linear_C_n", &ntweaks_Emiss_Linear_C_n, &b_ntweaks_Emiss_Linear_C_n);
  ch->SetBranchAddress("tweak_responses_Emiss_Linear_C_n", tweak_responses_Emiss_Linear_C_n, &b_tweak_responses_Emiss_Linear_C_n);
  ch->SetBranchAddress("paramCVWeight_Emiss_Linear_C_n", &paramCVWeight_Emiss_Linear_C_n, &b_paramCVWeight_Emiss_Linear_C_n);
  ch->SetBranchAddress("ntweaks_Emiss_ShiftPeak_C_p", &ntweaks_Emiss_ShiftPeak_C_p, &b_ntweaks_Emiss_ShiftPeak_C_p);
  ch->SetBranchAddress("tweak_responses_Emiss_ShiftPeak_C_p", tweak_responses_Emiss_ShiftPeak_C_p, &b_tweak_responses_Emiss_ShiftPeak_C_p);
  ch->SetBranchAddress("paramCVWeight_Emiss_ShiftPeak_C_p", &paramCVWeight_Emiss_ShiftPeak_C_p, &b_paramCVWeight_Emiss_ShiftPeak_C_p);
  ch->SetBranchAddress("ntweaks_Emiss_ShiftPeak_C_n", &ntweaks_Emiss_ShiftPeak_C_n, &b_ntweaks_Emiss_ShiftPeak_C_n);
  ch->SetBranchAddress("tweak_responses_Emiss_ShiftPeak_C_n", tweak_responses_Emiss_ShiftPeak_C_n, &b_tweak_responses_Emiss_ShiftPeak_C_n);
  ch->SetBranchAddress("paramCVWeight_Emiss_ShiftPeak_C_n", &paramCVWeight_Emiss_ShiftPeak_C_n, &b_paramCVWeight_Emiss_ShiftPeak_C_n);
}
