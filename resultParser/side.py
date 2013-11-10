###########################################################
####### MAIN SECTION ######################################
###########################################################
import sys
import os
import csv
import subprocess
import sqlite3




def main(user, passwd, db, txtfile):
    extension='.txt'
    executionTime='600'
    
    print('Start processing')
    full_path = os.path.realpath(__file__)
    #This file directory only
    directory=os.path.dirname(full_path)
    c = csv.writer(open("MYFILE.csv", "wb"))
    
    
    for dirname, dirnames, filenames in os.walk('exact'):
        # print path to all filenames.
        for filename in filenames:
            print os.path.join(dirname, filename)
            f = open(os.path.join(dirname, filename))
            splittedName=filename.replace(".","_").split("_")
            swichPos=splittedName[4]
            chanIns=splittedName[5]
            lines = f.readlines()
            #print lines
            f.close()
            front=[]
            for line in lines:
                #print line
                line=line[:-1].split(",")
                line = map(int, line)
                front.append(line)
                #print line
            #print lines
            #front = [int(i) for i in front]
            #front = map(int, front)
            print front
            referencePoint = [20,20]
            hyperVolume = HyperVolume(referencePoint)
            #front = [[1, 0], [0, 1, 0]]
            result = hyperVolume.compute(front)
            print result
            c.writerow([swichPos,chanIns,result])
    
    
        # Advanced usage:
        # editing the 'dirnames' list will stop os.walk() from recursing into there.
        if '.git' in dirnames:
            # don't go into any .git directories.
            dirnames.remove('.git')



    f = open(directory+"/"+txtfile)
    lines = f.readlines()
    f.close()


    finalArchive=getFinalArchive(lines)
    finalPop=getFinalPop(lines)
    #print finalPop
    #initialSwPos=lines[2]
    #print initialSwPos

    instanceParams=[]
    count=0
    for line in lines:
	    #print line
        if line.find("Instance")!= -1:
            channelInstane=lines[count].split()[2]
            print "The channel instance is: '"+channelInstane+"'"
            break
        count=count+1  


    lines=lines[count+1::]

    count=0
    for line in lines:

        if line.find("Switch")!= -1:
            initialSwPos=lines[count+1][:-1]
            print "The switch instance is: '"+initialSwPos+"'"
            break
        count=count+1

    lines=lines[count::]

    count=0
    for line in lines:
        if line.find("Initial Population")!= -1:
            break
        count=count+1

    popCount=lines[count+1][:-1]
    print "PopCount is :"+popCount

    lines=lines[count+2::]

    #print lines[:10]


    initialPop=[]


    for line in lines[:int(popCount)]:
        splitedLine=line.split()
        initialPop.append([splitedLine[0],splitedLine[1],splitedLine[3]])

    #print initialPop[-2:]

    lines=lines[int(popCount):]

    bestIndiTillGen=[]
    #print lines[:10]
    preGenCount=-1
    count=0
    for i in range(len(lines)):
        splitedLine=lines[i].split()
        #print len(splitedLine)
        if len(splitedLine)>0:
            if splitedLine[0]>preGenCount:
                bestIndiTillGen.append([splitedLine[0],splitedLine[1],splitedLine[2],splitedLine[4]])
        else:
            #print "reached to the end with finishing"
            killed=False
            break
        #count=count+1

    #print count
    #print lines[count:count+10]
    #print bestIndiTillGen[0:-10]

    print "Is this job killed? "+str(killed)
















#main("root","1234" , "satOptResults",fileName)