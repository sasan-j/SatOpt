#! /usr/bin/python

chCount = 23

algos = {'nsga2': 0, 'spea2': 1, 'ibea': 2, 'moga': 3}

for algo in algos.keys():
	argFile = open("args_"+str(chCount)+algo, "w")
	for i in range(0,30):
		line = " "+str(chCount)+" "+str(algos[algo])+" 0 15 "+str(i)
		argFile.write(line + "\n");
		line = " "+str(chCount)+" "+str(algos[algo])+" 15 30 "+str(i)
		argFile.write(line + "\n");
	argFile.close()
