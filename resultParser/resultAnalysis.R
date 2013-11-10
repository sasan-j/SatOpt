setwd("/home/sasan/dev/SatOpt/resultParser/mergedCSV/")

files <- list.files(path = ".", pattern = NULL, all.files = FALSE,
           full.names = FALSE, recursive = FALSE,
           ignore.case = FALSE, include.dirs = FALSE)

channels  <-c("8","13","18","23","25","30","35")
algos  <-c("NSGA2","SPEA2","IBEA","MOGA")
tableHeader = c("channels","algo","avgGenCount","noSolAvg","noSolStd","unaryHVAvg","unaryHVStd","hitRate")
csvData = {}
csvFileName="data4CommonTable.csv"
files = {}
for(channel in channels){
  #print(channel)
  for(algo in algos){
    fileName <- paste("ch",channel,"_",algo,"_processed.csv", sep="")
    print(fileName)
    #files=c(files,fileName)
    data = read.csv(fileName)  # read csv file
    genCountAvg <- mean(data[,"genCount"])
    noSol <- data[,"noSolutions"]
    noSolAvg <- mean(noSol)
    noSolStd <- sd(noSol)
    
    normalizerFunc <- function(x){
      if(!(min(x)==max(x))){
        return((x-min(x))/(max(x)-min(x)))
      }
      return(x)}
    unaryHV <- normalizerFunc(data[,"unaryHyperVol"])
    #if(algo=="NSGA2" & channel=="8")
    #  print(unaryHV)
    unaryHVAvg <- mean(unaryHV)
    unaryHVStd <- sd(unaryHV)

    hitRate=length(unaryHV[unaryHV>0])/length(unaryHV)
    currentRow=c(channel,algo,genCountAvg,noSolAvg,noSolStd,unaryHVAvg,unaryHVStd,hitRate)
    csvData=c(csvData,currentRow)
  }
}

csvTable <- matrix(csvData,ncol=8,byrow=TRUE)
colnames(csvTable) <- tableHeader
csvTable <- as.table(csvTable)
write.csv(csvTable, file = csvFileName,row.names=FALSE)


for(file in files){
  print(file)
  data = read.csv(file)  # read csv file
  x <- data[,"noSolutions"]
  mean <- mean(x)
  print(mean)
  #sd <- sd(x)
  #print(sd)
  #wilcox <- wilcox.test(x)
  #print(wilcox)
}


perChannelAnalyze <- function(files){
  statements
  return(object)
}