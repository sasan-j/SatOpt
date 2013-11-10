setwd("/home/sasan/dev/SatOpt/resultParser/graphRefs/")
data = read.csv("payload50.csv")  # read csv file 
attach(data)
plot(x, y, pch=19, cex = 1, col=nodeType+2)
text(x+0.15, y+0.05, nodeName)
