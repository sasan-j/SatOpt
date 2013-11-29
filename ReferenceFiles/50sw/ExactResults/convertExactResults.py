import re
 #  Pareto front found for 7_6 in time: 47.57   
# (z = 6, changes = 3)
# (z = 4, changes = 4)
# (z = 1, changes = 5) 

def data_parser(line):
  splittedLine=line.split()
  print splittedLine
  if(splittedLine[0]=="Pareto"):
    tmp=splittedLine[4].split("_")
    return "Pareto "+tmp[0]+" "+tmp[1]
  else:
    tmp=re.findall("(\d)+",line)
    return tmp[0]+" "+tmp[1]
 
 
    

inputfile = open('p8.txt')
outputfile = open('p8_snj.txt', 'w')

# sample text string, just for demonstration to let you know how the data looks like
# my_text = '"2012-06-23 03:09:13.23",4323584,-1.911224,-0.4657288,-0.1166382,-0.24823,0.256485,"NAN",-0.3489428,-0.130449,-0.2440527,-0.2942413,0.04944348,0.4337797,-1.105218,-1.201882,-0.5962594,-0.586636'

# dictionary definition 0-, 1- etc. are there to parse the date block delimited with dashes, and make sure the negative numbers are not effected
#reps = {'"NAN"':'NAN', '"':'', '0-':'0,','1-':'1,','2-':'2,','3-':'3,','4-':'4,','5-':'5,','6-':'6,','7-':'7,','8-':'8,','9-':'9,', ' ':',', ':':',' }

#for i in range(4): inputfile.next() # skip first four lines
for line in inputfile:
    if(len(line.split())<1):
      continue
    outputfile.writelines(data_parser(line)+"\n")

inputfile.close()
outputfile.close()




inputfile = open('p13.txt')
outputfile = open('p13_snj.txt', 'w')

# sample text string, just for demonstration to let you know how the data looks like
# my_text = '"2012-06-23 03:09:13.23",4323584,-1.911224,-0.4657288,-0.1166382,-0.24823,0.256485,"NAN",-0.3489428,-0.130449,-0.2440527,-0.2942413,0.04944348,0.4337797,-1.105218,-1.201882,-0.5962594,-0.586636'

# dictionary definition 0-, 1- etc. are there to parse the date block delimited with dashes, and make sure the negative numbers are not effected
#reps = {'"NAN"':'NAN', '"':'', '0-':'0,','1-':'1,','2-':'2,','3-':'3,','4-':'4,','5-':'5,','6-':'6,','7-':'7,','8-':'8,','9-':'9,', ' ':',', ':':',' }

#for i in range(4): inputfile.next() # skip first four lines
for line in inputfile:
    if(len(line.split())<1):
      continue
    outputfile.writelines(data_parser(line)+"\n")

inputfile.close()
outputfile.close() 

inputfile = open('p18.txt')
outputfile = open('p18_snj.txt', 'w')

# sample text string, just for demonstration to let you know how the data looks like
# my_text = '"2012-06-23 03:09:13.23",4323584,-1.911224,-0.4657288,-0.1166382,-0.24823,0.256485,"NAN",-0.3489428,-0.130449,-0.2440527,-0.2942413,0.04944348,0.4337797,-1.105218,-1.201882,-0.5962594,-0.586636'

# dictionary definition 0-, 1- etc. are there to parse the date block delimited with dashes, and make sure the negative numbers are not effected
#reps = {'"NAN"':'NAN', '"':'', '0-':'0,','1-':'1,','2-':'2,','3-':'3,','4-':'4,','5-':'5,','6-':'6,','7-':'7,','8-':'8,','9-':'9,', ' ':',', ':':',' }

#for i in range(4): inputfile.next() # skip first four lines
for line in inputfile:
    if(len(line.split())<1):
      continue
    outputfile.writelines(data_parser(line)+"\n")

inputfile.close()
outputfile.close() 