loadCsvFile <- function(fileName)
{
	csv_file<-read.csv(fileName)
	return (as.matrix(csv_file))
}

makeRow <- function(rowElements)
{
	rowString = ""
	
	for (i in 1:length(rowElements))
	{
		element = removeChars(rowElements[i])
		
		if(i == length(rowElements))
		{
			rowString = paste(rowString, element )
		}
		else
		{
			rowString = paste(rowString, element, cellSeparator )
		}
	}
	
	rowString = paste(rowString, rowSeparator )
	
	return (rowString)
}

makeTableHeader <- function(variableCols)
{
	headerString = "\\begin{table}\n"
	headerString = paste(headerString, "\\centering")
	headerString = paste(headerString, "\\begin{tabular}{l")
	
	for(i in 1:variableCols)
	{
		headerString = paste(headerString, "c")
	}
	
	headerString = paste(headerString,"}\n")
	return (headerString)
}

makeDocHeader <- function()
{
	headerString = "\\documentclass{article}\n"
	headerString = paste(headerString, "\\title{Wilcox}\n")
	headerString = paste(headerString, "\\usepackage{amssymb}\n")
	headerString = paste(headerString, "\\author{Sasan Jafarnejad}\n")
	headerString = paste(headerString, "\\begin{document}\n")
	headerString = paste(headerString, "\\maketitle\n")
	headerString = paste(headerString, "\\section{Tables}\n")

	return (headerString)
}

makeTableTail <- function()
{
	tailString = "\\hline\n"
	tailString = paste(tailString, "\\end{tabular}\n")
	tailString = paste(tailString, "\\end{table}\n")
	
	return (tailString)
}

makeDocTail <- function()
{ 
	tailString = "\\end{document}\n"
	return (tailString)
}

removeChars <-function(element)
{
	result = gsub("_100_", "", element)
	result = gsub("noncoev", "", result)
	result = gsub("_async_seq", "", result)

	return (result)
}


cellSeparator = "&"
rowSeparator = "\\\\\n"

outFile = "./ch35_wilcoson_unaryHyperVol.tex"

csvData = loadCsvFile("./ch35_wilcoson_unaryHyperVol.csv")

dataSets =  csvData[,1]

minCol = 99999

##writeLines(makeTableHeader(), outFile, append=TRUE)


tableString = makeDocHeader()
tableString = paste(tableString, makeTableHeader(length(dataSets)))



for(dataSet in dataSets)
{
	##csvData[which(csvData == "cGA_100_coev_async_seq"),]
	
	colCount = 0
	for(cell in csvData[which(csvData == dataSet),2:dim(csvData)[2]])
	{
		if (!is.na(cell))
		{
			colCount = colCount + 1
			##print(cell)
		}
	}

	if (colCount < minCol)
	{
		minCol = colCount
	}
	print(paste("> ", dataSet, " has ", colCount, " cols"))	
}

print(paste("> Analysing first", minCol, " cols"))	


## the header row
tableString = paste(tableString, makeRow(c("\\hline",dataSets)))
tableString = paste(tableString, "\\hline")

print(tableString)

#for(dataSet1 in dataSets)
for (i in 1:length(dataSets))
{
	dataSet1 = dataSets[i]
	values1 = as.numeric(csvData[which(csvData == dataSet1),2:(minCol+1)])
	average1 = mean(values1)
	
	rowElements = dataSet1
	
	#for(dataSet2 in dataSets)
	for (j in 1:length(dataSets))
	{
		dataSet2 = dataSets[j]
		values2 = as.numeric(csvData[which(csvData == dataSet2),2:(minCol+1)])	
		average2 = mean(values2)
		
		test = wilcox.test(values1, values2)$p.value
		print(test)
		
		if(i <= j)
		{
			if ((test > 0.05) || test == "NaN")
			{
				symbol = " -- "
			}
			else 
			{
				if (average1 < average2)
				{
					symbol = "$\\blacktriangle$"
				}
				else
				{
					symbol = "$\\triangledown$"
				}
			}
		}
		else
		{
			symbol = " "
		}
		
		rowElements = c(rowElements, symbol)
		
		#print(paste("> ", dataSet1, " has average ", average1))
	}
	
	tableString = paste(tableString, makeRow(rowElements))
}

tableString = paste(tableString, makeTableTail())
tableString = paste(tableString, makeDocTail())

writeLines(tableString)

writeLines(tableString, outFile)

