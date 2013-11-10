# -*- coding: utf-8 -*-
"""
Created on Fri Sep  6 12:19:38 2013

CSV merger

@author: sasan
"""

###########################################################
####### MAIN SECTION ######################################
###########################################################
import sys
import os
import csv

chCounts = ["8","13","18","23","25","30","35"]

#algos = {'nsga2': 0, 'spea2': 1, 'ibea': 2, 'moga': 3}

algos = ["NSGA2","SPEA2","IBEA","MOGA"]


def main():
    mergedCSVDir = "mergedCSV"
    print('Start processing')
    full_path = "/home/sasan/dev/SatOpt/resultParser/finals/" #results folder
    #This file directory only   
    for chCount in chCounts:
        #channel dir
        chDir = "ch"+chCount
        for algo in algos:
            #print dirname
            if not os.path.exists(mergedCSVDir):
                os.makedirs(mergedCSVDir)

            finalDir = os.path.join(full_path,chDir,algo)
            if(os.path.exists(finalDir)):
                csvFile = csv.writer(open(os.path.join(mergedCSVDir,chDir+"_"+algo+"_processed.csv"), "wb"))
                csvFile.writerow(["runNumber","genCount","elapsedTime","noSolutions","unaryHyperVol","binaryHyperVol","additiveEps","entropy","swInst","chInst"])
                algoResultProcess(finalDir,csvFile)
            else:
                continue


    
    
def algoResultProcess(dir,csvFile):
    print "processing this directory: "+dir
    dir = os.path.join(dir,"csv")
    files = os.listdir(dir)
    #print files
    files.sort()
    for file in files:
        #print file
        splittedFileName = os.path.splitext(file)[0].split('_')
        swInst = splittedFileName[4]
        chInst = splittedFileName[5]
        processFile(os.path.join(dir,file),csvFile,swInst,chInst)
        #csvFile.writerow(row)

def processFile(dir,csvFile,swInst,chInst):
    #print dir
    rows = []
    appends = [swInst,chInst]
    with open(dir, 'rb') as f:
        reader = csv.reader(f, delimiter=',', quoting=csv.QUOTE_NONE)
        for row in reader:
            [row.append(x) for x in appends] 
            rows.append(row)
            
            
    csvFile.writerows(rows[1:-1])

    

main()












#main("root","1234" , "satOptResults",fileName)