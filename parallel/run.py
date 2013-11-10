#!/usr/bin/python
__author__ = 'sjafarnejad'
import sys
import os
import subprocess

print sys.argv[1]
print sys.argv[2]
print sys.argv[3]
print sys.argv[4]
print sys.argv[5]


full_path = os.path.realpath(__file__)
#print(full_path + "\n")

#print("This file directory and name")
#path, file = os.path.split(full_path)
#print(path + ' --> ' + file + "\n")
#statFile=path+'/'+file.replace('.py','.txt',1)
#print statFile
#tmpFile = open(statFile, 'w')
#tmpFile.write('')
#tmpFile.close()


#channel count 
chCount = sys.argv[1]
#Algo
algo = sys.argv[2]
#starting switch instance
swInst = int(sys.argv[3])
#end switch instance
swInstLast = int(sys.argv[4])
#channel Instance
chInst = sys.argv[5]
#print swInst
#subprocess.call(['cd ../satOptMOEOS_cb;bash launch.sh'],shell=True)
for i in range(swInst,swInstLast):	
	subprocess.call(['bash /home/clusterusers/sjafarnejad/myCodes/TaSpl/parallel/launch.sh '+chCount+' '+algo+' '+str(i)+' '+chInst+' 7'],shell=True)
	#print i
	#print "hi"











