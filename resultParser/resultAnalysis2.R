setwd("/home/sasan/dev/SatOpt/resultParser/mergedCSV/")

files <- list.files(path = ".", pattern = NULL, all.files = FALSE,
                    full.names = FALSE, recursive = FALSE,
                    ignore.case = FALSE, include.dirs = FALSE)

channels  <-c("8","13","18","23","25","30","35")
algos  <-c("NSGA2","SPEA2","IBEA","MOGA")
tableHeader = c("channels","algo","binHVAvg","binHVStd","%total","addEpsAvg","addEpsStd","%total","entropyAvg","entropyStd","%total")
csvData = {}
csvFileName="data4ConditionalTable.csv"
files = {}
for(channel in channels){
  #print(channel)
  for(algo in algos){
    fileName <- paste("ch",channel,"_",algo,"_processed.csv", sep="")
    print(fileName)
    #files=c(files,fileName)
    data = read.csv(fileName)  # read csv file
    
    
    #prepare data culomns
    binHVU <- data[,"binaryHyperVol"]
    binHV <- binHVU[binHVU!=333]
    binHV <- binHV[binHV!='Inf']
    binHV <- binHV[binHV!='-Inf']
    binHVAvg <- mean(binHV)
    binHVStd <- sd(binHV)
    binHVpt <- (length(binHV)/length(binHVU))*100
    
    
    addEpsU <- data[,"additiveEps"]
    addEps <- addEpsU[addEpsU!=333]
    addEps <- addEps[addEps!='Inf']
    addEps <- addEps[addEps!='-Inf']
    addEpsAvg <- mean(addEps)
    addEpsStd <- sd(addEps)
    addEpspt <- (length(addEps)/length(addEpsU))*100
    
    entropyU <- data[,"entropy"]
    entropy <- entropyU[entropyU!=333]
    entropy <- entropy[entropy!='Inf']
    entropy <- entropy[entropy!='-Inf']
    entropyAvg <- mean(entropy)
    entropyStd <- sd(entropy)
    entropypt <- (length(entropy)/length(entropyU))*100   

    
    normalizerFunc <- function(x){
      if(!(min(x)==max(x))){
        return((x-min(x))/(max(x)-min(x)))
      }
      return(x)}
    unaryHV <- normalizerFunc(data[,"unaryHyperVol"])
    
   if(algo=="SPEA2" & channel=="25"){
    print(length(binHVU))
    print(length(addEps))
    print(entropy[0:200])
   }
    
    
    currentRow=c(channel,algo,binHVAvg,binHVStd,binHVpt,addEpsAvg,addEpsStd,addEpspt,entropyAvg,entropyStd,entropypt)
    csvData=c(csvData,currentRow)
  }
}

csvTable <- matrix(csvData,ncol=11,byrow=TRUE)
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