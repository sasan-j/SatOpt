#!/usr/bin/python
__author__ = 'sjafarnejad'
import sys
import os
import subprocess


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
chCount = int(sys.argv[1])
#Algo
algo = int(sys.argv[2])
#starting switch instance
swInst = int(sys.argv[3])
#end switch instance
swInstLast = int(sys.argv[4])
#channel Instance
chInst = int(sys.argv[5])

for i in range(swInst,swInstLast):	
	subprocess.call(['../satOptMOEOS_cb/satOptMOEO -W='+chCount+' -A='+algo+' -U='+i+' -V='+chInst],shell=True)
	print i











