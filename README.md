# GenieFlatAna

## Setup
This code assumes that you are using dunegpvms.
```
$ source setup.sh
```

## Compile

```
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build . -- install
```

## Run

You may need to setup proxy first
Then,

```
root -l -b -q run_GenieHadAna.C
```
## Then

You can make your own analyzing classes and corresponding running scripts.
For analyzing classes, please refer to classes in Analyzers directory.
For running script, please refer to files with "run_*.C"

## Status

```
typedef enum EGHepStatus {
   kIStUndefined                  = -1,
   kIStInitialState               =  0,   /* generator-level initial state */
   kIStStableFinalState           =  1,   /* generator-level final state: particles to be tracked by detector-level MC */
   kIStIntermediateState          =  2,
   kIStDecayedState               =  3,
   kIStCorrelatedNucleon          = 10,
   kIStNucleonTarget              = 11,
   kIStDISPreFragmHadronicState   = 12,
   kIStPreDecayResonantState      = 13,
   kIStHadronInTheNucleus         = 14,   /* hadrons inside the nucleus: marked for hadron transport modules to act on */
   kIStFinalStateNuclearRemnant   = 15,   /* low energy nuclear fragments entering the record collectively as a 'hadronic blob' pseudo-particle */
   kIStNucleonClusterTarget       = 16    // for composite nucleons before phase space decay
}
GHepStatus_t;
```