#include "./Analyzers/GenieHadAna.h"

void run_GenieHadAna(){
  gSystem->Load("./lib/libDataFormats.so");
  gSystem->Load("./lib/libAnalyzers.so");

  GenieHadAna m;
  m.MaxEvent = -1;
  m.LogEvery = 10000;
  m.MCSample = "Data";
  m.SetTreeName();
  m.AddFile("/pnfs/dune/persistent/users/sungbino/Genie/proton_Ar/ke_300MeV/gntp.inuke.0.ghep_flat.root");
  m.SetOutfilePath("test.root");
  m.Init();
  m.initializeAnalyzer();
  m.initializeAnalyzerTools();
  m.SwitchToTempDir();
  m.Loop();
  m.WriteHist();
}
