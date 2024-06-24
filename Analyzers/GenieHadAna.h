#ifndef GenieHadAna_h
#define GenieHadAna_h

#include "AnalyzerCore.h"

class GenieHadAna : public AnalyzerCore {

 public:

  void initializeAnalyzer();
  void executeEvent();

  GenieHadAna();
  ~GenieHadAna();

};

#endif
