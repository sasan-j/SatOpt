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
    extension='.txt'
    executionTime='600'
    mergedCSVDir = "mergedCSV"
    wilcoxonDir = "wilcoxonCSV"
    print('Start processing')
    full_path = "/home/sasan/dev/SatOpt/resultParser/mergedCSV/" #results folder
    #This file directory only  
                #print dirname
    fullWilcoxonDir = os.path.join(full_path,wilcoxonDir)
    if not os.path.exists(fullWilcoxonDir):
        os.makedirs(fullWilcoxonDir)
    for chCount in chCounts:
        #channel dir
        chName = "ch"+chCount
        if(os.path.exists(fullWilcoxonDir)):
            csvFile = csv.writer(open(os.path.join(fullWilcoxonDir,chName+"_wilcoson_unaryHyperVol.csv"), "wb"))
            firstRow =  ["algo"]
            [firstRow.append("n"+str(i)) for i in range(0,27001)]
            csvFile.writerow(firstRow)
        for algo in algos:
            csvFileName=chName+"_"+algo+"_processed.csv"
            csvFile.writerow(processFile(os.path.join(full_path,csvFileName),algo))


def processFile(csvFilePath,algo):
    #print dir
    #rows = []
    #appends = [swInst,chInst]
    values = [algo]
    with open(csvFilePath, 'rb') as f:
        reader = csv.reader(f, delimiter=',', quoting=csv.QUOTE_NONE)
        for row in reader:
            #[row.append(x) for x in appends] 
            #rows.append(row)
            if(row[4]!="unaryHyperVol"):
                values.append(row[4])
            
            
    #csvFile.writerows(rows[1:-1])
    return values
    
    


main()