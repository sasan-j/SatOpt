#! /usr/bin/python

chCounts = ["8","13","18","23","25","30","35"]

algos = {'nsga2': 0, 'spea2': 1, 'ibea': 2, 'moga': 3}
for chCount in chCounts:
	if(int(chCount)>23):
		chCountParam = "100"
	else:
		chCountParam = "50"
	argFile = open("args_"+chCount, "w")
	for i in range(0,30):
		for j in range(0,30):
			line = " "+chCount+" "+str(i)+" "+str(j)+" "+chCountParam
			argFile.write(line + "\n");
	argFile.close()
