export GFAna_WD=`pwd`
export GFAna_LIB_PATH=$GFAna_WD/lib/
mkdir -p $GFAna_LIB_PATH
mkdir -p $GFAna_WD/tar

export GFAnaV="v1"
mkdir -p $GFAna_WD/data/$GFAnaV
export DATA_DIR=$GFAna_WD/data/$GFAnaV

export GFAnaGridOutDir="/pnfs/dune/scratch/users/$USER/GF_out"
mkdir -p $GFAnaGridOutDir

#### USER INFO ####
export GFAnaLogEmail='sungbino@fnal.gov'
export GFAnaLogWeb=''
export GFAnaLogWebDir=''

if [[ $HOSTNAME == *"dunegpvm"*"fnal.gov" ]]; then

  echo "@@@@ Working on dunegpvm"
  export GFAnaRunlogDir="/dune/app/users/$USER/Grid/GFAnaRunlog/"
  export GFAnaOutputDir="/dune/app/users/$USER/Grid/GFAnaOutput/"

  # For Alma9 GPVM nodes
  source /cvmfs/fermilab.opensciencegrid.org/packages/common/setup-env.sh
  source /cvmfs/larsoft.opensciencegrid.org/spack-packages/setup-env.sh
  spack load root@6.28.12
  spack load gcc@12.2.0
  export ROOT_INCLUDE_PATH=/cvmfs/larsoft.opensciencegrid.org/spack-packages/opt/spack/linux-almalinux9-x86_64_v2/gcc-12.2.0/root-6.28.12-sfwfmqorvxttrxgfrfhoq5kplou2pddd/include/:/exp/dune/app/users/sungbino/ProtoDUNE/GFTreeAnalyzer/build/Linux/include/:$ROOT_INCLUDE_PATH
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$GFAna_LIB_PATH:/cvmfs/larsoft.opensciencegrid.org/spack-packages/opt/spack/linux-almalinux9-x86_64_v2/gcc-12.2.0/root-6.28.12-sfwfmqorvxttrxgfrfhoq5kplou2pddd/lib/
fi

alias pdout="cd $GFAnaOutputDir/$GFAnaV/"

export MYBIN=$GFAna_WD/bin/
export PYTHONDIR=$GFAna_WD/python/
export PATH=${MYBIN}:${PYTHONDIR}:${PATH}

source $GFAna_WD/bin/BashColorSets.sh

## submodules ##
#source bin/CheckSubmodules.sh

## Todo list ##
python python/PrintToDoLists.py
source $GFAna_WD/tmp/ToDoLists.sh
rm $GFAna_WD/tmp/ToDoLists.sh

## Log Dir ##
echo "* Your Log Directory Usage"
#du -sh $GFAnaRunlogDir
echo "-----------------------------------------------------------------"
CurrentGitBranch=`git branch | grep \* | cut -d ' ' -f2`
printf "> Current GFAnaAnalyzer branch : "${BRed}$CurrentGitBranch${Color_Off}"\n"
