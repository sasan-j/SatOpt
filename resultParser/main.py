###########################################################
####### MAIN SECTION ######################################
###########################################################
import sys
import os
import csv

chCounts = ["8"]#,"13","18","23","25","30","35"]

#algos = {'nsga2': 0, 'spea2': 1, 'ibea': 2, 'moga': 3}

algos = ["NSGA2"]#,"SPEA2","IBEA","MOGA"]


def main():
    extension='.txt'
    executionTime='600'
    
    print('Start processing')
    full_path = "/home/sasan/dev/SatOpt/resultParser/finals/" #results folder
    #This file directory only   
    for chCount in chCounts:
        #channel dir
        chDir = "ch"+chCount
        for algo in algos:
            #print dirname
            csvFile = csv.writer(open(chDir+"_"+algo+"_processed.csv", "wb"))
            finalDir = os.path.join(full_path,chDir,algo)
            if(os.path.exists(finalDir)):
                algoResultProcess(finalDir,csvFile)
            else:
                continue


    
    
def algoResultProcess(dir,csvFile):
    print "processing this directory: "+dir
    dir = os.path.join(dir,"txt")
    files = os.listdir(dir)
    #print files
    for file in files:
        processFile(os.path.join(dir,file))
        #csvFile.writerow(row)

def processFile(dir):
    #print dir
    f = open(dir)
    lines = f.readlines()
    #print lines[34]
    f.close()
    for line in lines:
        splittedLine=line.split()
        if(len(splittedLine)>0):
            if(splittedLine[0].lower() == "runNumber".lower()):
                print line
    

main()












#main("root","1234" , "satOptResults",fileName)