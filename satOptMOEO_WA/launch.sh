#!/bin/bash --login
. /etc/profile
module load GCC/4.7.3
#gcc --version
#;./satOptMOEO -W='+chCount+' -A='+algo+' -U='+str(i)+' -V='+chInst+' -T=2'
./satOptMOEO -W=$1 -A=$2 -U=$3 -V=$4 -T=$5
