#include "GenieHadAna.h"

void GenieHadAna::initializeAnalyzer(){

  cout << "[[GenieHadAna::initializeAnalyzer]]" << endl;
  debug_mode = true;
  debug_mode = false;

}

void GenieHadAna::executeEvent(){

  vector<Particle> Particle_all = GetAllParticles();
  cout << "Particle_all.size() : " << Particle_all.size() << endl;
}

GenieHadAna::GenieHadAna(){

}

GenieHadAna::~GenieHadAna(){

}
