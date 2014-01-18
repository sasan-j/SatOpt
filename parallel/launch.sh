#! /bin/bash
. /etc/profile
module load GCC
#gcc --version
#;./satOptMOEO -W='+chCount+' -A='+algo+' -U='+str(i)+' -V='+chInst+' -T=2'
cd $WORK/myCodes/SatOpt/parallel/
$HOME/myCodes/SatOpt/satOptMOEO_$1/satOptMOEO_$1 -W=$2 -U=$3 -V=$4 -S=$5 -T=600 -R=30
#echo "$HOME/myCodes/SatOpt/satOptMOEO_$1/satOptMOEO_$1 -W=$2 -U=$3 -V=$4 -S=$5 -T=1 -R=4"
#pwd
