#! /bin/bash
. /etc/profile
module load GCC/4.7.3
#gcc --version
#;./satOptMOEO -W='+chCount+' -A='+algo+' -U='+str(i)+' -V='+chInst+' -T=2'
cd $HOME/myCodes/SatOpt/parallel/
./satOptMOEO_LPL -W=$1 -U=$2 -V=$3 -S=$4 -T=600 -R=30
