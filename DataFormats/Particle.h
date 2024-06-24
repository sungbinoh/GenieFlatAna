#ifndef Particle_h
#define Particle_h

#include <string>
#include <vector>

using namespace std;

class Particle{
public:

  Particle();
  virtual ~Particle();

  void SetIsEmpty(bool i_IsEmpty);
  inline bool IsEmpty() const { return j_IsEmpty; }

  // == Variables
  void Set_par_pdg(int i_par_pdg);
  void Set_par_1st_mother(int i_par_1st_mother);
  void Set_par_last_mother(int i_par_last_mother);
  void Set_par_1st_daughter(int i_par_1st_daughter);
  void Set_par_last_daughter(int i_par_last_daughter);
  void Set_par_px(double i_par_px);
  void Set_par_py(double i_par_py);
  void Set_par_pz(double i_par_pz);
  void Set_par_E(double i_par_E);
  void Set_par_M(double i_par_M);
  void Set_par_Vx(double i_par_Vx);
  void Set_par_Vy(double i_par_Vy);
  void Set_par_Vz(double i_par_Vz);
  void Set_par_Vt(double i_par_Vt);

  inline int pdg() const { return j_par_pdg};
  inline int first_mother() const { return j_par_1st_mother};
  inline int last_mother() const { return j_par_last_mother};
  inline int first_daughter() const { return j_par_1st_daughter};
  inline int last_daughter() const { return j_par_last_daughter};
  inline double px() const { return j_par_px};
  inline double	py() const { return j_par_py};
  inline double	pz() const { return j_par_pz};
  inline double	E() const { return j_par_E};
  inline double	M() const { return j_par_M};
  inline double	Vx() const { return j_par_Vx};
  inline double Vy() const { return j_par_Vy};
  inline double Vz() const { return j_par_Vz};
  inline double Vt() const { return j_par_Vt};

private:
  bool j_IsEmpty;

  int j_par_pdg;
  int j_par_1st_mother;
  int j_par_last_mother;
  int j_par_1st_daughter;
  int j_par_last_daughter;
  double j_par_px;
  double j_par_py;
  double j_par_pz;
  double j_par_E;
  double j_par_M;
  double j_par_Vx;
  double j_par_Vy;
  double j_par_Vz;
  double j_par_Vt;
};

#endif
