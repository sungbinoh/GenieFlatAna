#include "Particle.h"

Particle::Particle(){

  j_IsEmpty = true;
  j_par_pdg = -9999;
  j_par_1st_mother = -1;
  j_par_last_mother = -1;
  j_par_1st_daughter = -1;
  j_par_last_daughter = -1;
  j_par_px = -9999.;
  j_par_py = -9999.;
  j_par_pz = -9999.;
  j_par_E = -9999.;
  j_par_M = -9999.;
  j_par_Vx = -9999.;
  j_par_Vy = -9999.;
  j_par_Vz = -9999.;
  j_par_Vt = -9999.;
}

Particle::~Particle(){}

void Particle::SetIsEmpty(bool i_IsEmpty){ j_IsEmpty = i_IsEmpty; }
void Particle::Set_par_pdg(int i_par_pdg){ j_par_pdg = i_par_pdg; }
void Particle::Set_par_1st_mother(int i_par_1st_mother){ j_par_1st_mother = i_par_1st_mother; }
void Particle::Set_par_last_mother(int i_par_last_mother){ j_par_last_mother = i_par_last_mother; }
void Particle::Set_par_1st_daughter(int i_par_1st_daughter){ j_par_1st_daughter = i_par_1st_daughter; }
void Particle::Set_par_last_daughter(int i_par_last_daughter){ j_par_last_daughter = i_par_last_daughter; }
void Particle::Set_par_px(double i_par_px){ j_par_px = i_par_px; }
void Particle::Set_par_py(double i_par_py){ j_par_py = i_par_py; }
void Particle::Set_par_pz(double i_par_pz){ j_par_pz = i_par_pz; }
void Particle::Set_par_E(double i_par_E){ j_par_E = i_par_E; }
void Particle::Set_par_M(double i_par_M){ j_par_M = i_par_M; }
void Particle::Set_par_Vx(double i_par_Vx){ j_par_Vx = i_par_Vx; }
void Particle::Set_par_Vy(double i_par_Vy){ j_par_Vy = i_par_Vy; }
void Particle::Set_par_Vz(double i_par_Vz){ j_par_Vz = i_par_Vz; }
void Particle::Set_par_Vt(double i_par_Vt){ j_par_Vt = i_par_Vt; }
