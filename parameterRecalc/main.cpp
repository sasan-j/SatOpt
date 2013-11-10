#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream> //this is where istringstream is defined
#include <fstream>
#include <unordered_map>
#include <assert.h>
/////////////////
#include <moeo>
#include <es/eoRealInitBounded.h>
#include <es/eoRealOp.h>
#include <eo>
#include <ga.h>
#include "src/RunResult.h"


#include "satOpt.h"


using namespace std;




std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);



class ParameterReCalc
{
public:
    char chCounts[7] [3]= {"8","13","18","23","25","30","35"};
    char algoStrs[7] [6]= {"NSGA2","SPEA2","IBEA","MOGA"};
    string currentFile;
    string currentDir;
    char buff[100];
    double maxLPL;
    double minLPL;
    double maxSwChanges;
    double minSwChanges;
    std::vector < eoRealInterval > instBounds;
    SatOptObjectiveVector refPoint;
    string resultDir="";



    std::unordered_map<std::string,unsigned int> algos;


    /** Default constructor */
    ParameterReCalc()
    {
        //string filesMainDir= "finals";
        for(int i = 0; i<7; i++)
        {
            algos[algoStrs[i]]=i;
        }

    }

    void restultPrinter(RunResult result){
        cout << "elapsed time: " << result.elapsedTime << endl;
    }

    vector<RunResult>  resultProcessFile(string filePath,string algoName,int swInst,int chInst)
    {
        vector<RunResult> results;

        vector<vector<SatOptObjectiveVector>> resultsVector;
        std::ifstream infile(filePath.c_str());
        std::string line;
        std::vector<std::string> splittedLine;
        std::vector<std::string> lines;
        int startingLine=2;
        int trueFrontLength;

        //finalResFile.open(resultDir+fResultFileName, ios::app);
        if (infile.is_open())
        {

            while(!infile.eof())
            {
                std::getline(infile, line);
                lines.push_back(line);
                //cout << line << endl;
            }
            //fetched all the file contents
            line=lines[2];
            splittedLine=split(line,' ',splittedLine);
            //cout << splittedLine[0] << endl;
            if(splittedLine.size()>2)
            {
                startingLine=4;
                line=lines[4];
                splittedLine=split(line,' ',splittedLine);
            }

            trueFrontLength=atoi(splittedLine[0].c_str());


            //cout << trueFrontLength << endl;
            vector<SatOptObjectiveVector> tempObjVectVector;
            for(int i=1; i<=trueFrontLength; i++)
            {
                SatOptObjectiveVector objVect;
                splittedLine=split(lines[startingLine+i],' ',splittedLine);
                objVect[0]=atoi(splittedLine[0].c_str());
                objVect[1]=atoi(splittedLine[1].c_str());
                tempObjVectVector.push_back(objVect);
                //cout << objVect[0] << " " << objVect[1] << endl;
            }
            resultsVector.push_back(tempObjVectVector);


            int archiveSize;

            for(std::size_t i=startingLine+trueFrontLength; i<lines.size(); i++)
            {
                RunResult tempRun;
                line=lines[i];
                splittedLine=split(line,' ',splittedLine);
                if(splittedLine[0]=="genCount"){
                    tempRun.genCount = atoi(splittedLine[1].c_str());
                    line=lines[++i];
                    splittedLine=split(line,' ',splittedLine);
                    tempRun.elapsedTime= atof(splittedLine[1].c_str());
                    line=lines[++i];
                    splittedLine=split(line,' ',splittedLine);
                    tempRun.setUnaryHyperVol(atof(splittedLine[1].c_str()));
                    line=lines[++i];
                    splittedLine=split(line,' ',splittedLine);
                    tempRun.setBinaryHyperVol(atof(splittedLine[1].c_str()));
                    line=lines[++i];
                    splittedLine=split(line,' ',splittedLine);
                    tempRun.setAdditiveEps(atof(splittedLine[1].c_str()));
                    line=lines[++i];
                    splittedLine=split(line,' ',splittedLine);
                    tempRun.setEntropy(atof(splittedLine[1].c_str()));
                    line=lines[++i];
                    splittedLine=split(line,' ',splittedLine);
                }
                if(splittedLine[0]=="archive")
                {
                    vector<SatOptObjectiveVector> tempObjVectVector2;
                    line=lines[++i];
                    splittedLine=split(line,' ',splittedLine);
                    archiveSize=atoi(splittedLine[0].c_str());
                    //cout << archiveSize << endl;
                    for(int j=0; j<archiveSize; j++)
                    {
                        i++;
                        SatOptObjectiveVector objVect;
                        splittedLine=split(lines[i],' ',splittedLine);
                        objVect[0]=atoi(splittedLine[0].c_str());
                        objVect[1]=atoi(splittedLine[1].c_str());
                        tempObjVectVector2.push_back(objVect);
                        //cout << objVect[0] << " " << objVect[1] << endl;
                    }
                    resultsVector.push_back(tempObjVectVector2);
                    tempRun.finalArchiveVector = tempObjVectVector2;
                    results.push_back(tempRun);
                    restultPrinter(tempRun);

                }

            }
            return results;

        }
        else cout << "file couldn't be opened" << endl;
    }

    void calculateBounds(vector< vector< vector<SatOptObjectiveVector> > > resultsObjVectorsVect)
    {

        ////////////////////////////////////////////
        ////////////////////////////////////////////
        //calculate objective extremes
        double maxLPL=0;
        double minLPL=100;
        double maxSwChanges=0;
        double minSwChanges=100;

        for(int i=0; i<4; i++)
        {
            //cout << i << endl;

            vector< vector<SatOptObjectiveVector> >resultsObjVectors;
            resultsObjVectors = resultsObjVectorsVect[i];
            for(unsigned int j=0; j<resultsObjVectors.size(); j++)
            {
                vector<SatOptObjectiveVector> resultObjVector=resultsObjVectors[j];

                for(unsigned int k=0; k<resultObjVector.size(); k++)
                {
                    //SatOptObjectiveVector resultObjVector=resultsObjVectors[j];
                    //cout << resultObjVector[k][0] << " " << resultObjVector[k][1] << endl;
                    //Maximums

                    if(resultObjVector[k][0]>=maxLPL)
                        maxLPL=resultObjVector[k][0];
                    if(resultObjVector[k][1]>=maxSwChanges)
                        maxSwChanges=resultObjVector[k][1];

                    //Minimums
                    if(resultObjVector[k][0]<=minLPL)
                        minLPL=resultObjVector[k][0];
                    if(resultObjVector[k][1]<=minSwChanges)
                        minSwChanges=resultObjVector[k][1];
                }
            }
        }


        if(maxLPL==minLPL)
        {
            minLPL=0;
            //maxLPL=1;
        }
        if(maxSwChanges==minSwChanges)
        {
            minSwChanges=0;
            //maxSwChanges=1;
        }

        cout << "maxLPL " << maxLPL << " maxSW " << maxSwChanges << endl;
        cout << "minLPL " << minLPL << " minSW " << minSwChanges << endl;

        std::vector < eoRealInterval > bounds;
        eoRealInterval bound= eoRealInterval(minLPL,maxLPL);
        eoRealInterval bound1=eoRealInterval(minSwChanges,maxSwChanges);
        bounds.push_back(bound);
        bounds.push_back(bound1);
        instBounds=bounds;

        vector<SatOptObjectiveVector> setupObjVector;
        SatOptObjectiveVector objVect;
        objVect[0]=minLPL;
        objVect[1]=minSwChanges;
        setupObjVector.push_back(objVect);

        SatOptObjectiveVector objVect1;
        objVect1[0]=maxLPL;
        objVect1[1]=maxSwChanges;
        setupObjVector.push_back(objVect1);


        refPoint[0]=0;//maxLPL;
        refPoint[1]=0;//maxSwChanges;
    }

    std::vector < std::vector<double> > frontNormalizer(const std::vector < SatOptObjectiveVector > & _set, std::vector < eoRealInterval > _bounds ,SatOptObjectiveVector ref_point)
    {
        std::vector < std::vector<double> > front;
        front.resize(_set.size());
        for(unsigned int i=0; i < _set.size(); i++)
        {
            front[i].resize(SatOptObjectiveVector::Traits::nObjectives());
            for (unsigned int j=0; j<SatOptObjectiveVector::Traits::nObjectives(); j++)
            {
                if (SatOptObjectiveVector::Traits::minimizing(j))
                {
                    front[i][j]=1.0f - abs((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range());
                    //cout << " orig: " << _set[i][j] << "  ";
                    //cout << front[i][j] << " "; //<< "
                    //boundRange " << _bounds[j].range();

                }
                else
                {
                    front[i][j]=((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range()) - ref_point[j];
                }
            }
            //cout << endl;
        }
        return front;
    }

    void calculateAll()
    {
        //cout << ""
        for(int i = 0; i<7; i++)
        {
            int chNumberIndex=i;
            for(int k =0; k<30; k++) //sw instance
            for(int l =0; l<30; l++)  //ch instance
            {

                int swInst=k;
                int chInst=l;
                vector< vector< vector<SatOptObjectiveVector> > > resultsObjVectorsVect;
                vector< vector<RunResult> > fullResults;
                vector<SatOptObjectiveVector> trueFrontObjVect;
                for(int j =0; j<4; j++)//Algorithms
                {
                    vector<RunResult> results;
                    vector< vector<SatOptObjectiveVector> >resultsObjVectors;
                    sprintf(buff, "final_res_%s_%d_%d_%d.txt",chCounts[i],algos[algoStrs[j]],k,l);
                    currentFile=buff;
                    sprintf(buff,"finals/ch%s/%s/txt/",chCounts[i],algoStrs[j]);
                    currentDir=buff;
                    //cout << currentDir << currentFile << endl;
                    //resultsObjVectors=resultProcessFile(currentDir+currentFile,algoStrs[j],k,l);
                    results=resultProcessFile(currentDir+currentFile,algoStrs[j],k,l);

                    //assigns first element to trueFront
                    trueFrontObjVect=resultsObjVectors[0];
                    resultsObjVectors.erase(resultsObjVectors.begin());
                    resultsObjVectorsVect.push_back(resultsObjVectors);
                    fullResults.push_back(results);
                }
                //now we have all the results

                /*
                cout << "This is true front" << endl;
                for(std::vector<SatOptObjectiveVector>::size_type i=0; i<trueFrontObjVect.size(); i++)
                {
                for(int j=0; j<2; j++)
                cout << trueFrontObjVect[i][j] << " ";
                cout << endl;
                }
                */

                //sometimes we do not have ANY result from any of algorithms (no solution so far)
                if(trueFrontObjVect.size()<1)
                {
                    //cout << "there is no solution for this instances" << endl;
                    continue;
                }

                //now we should calculate bounds
                calculateBounds(resultsObjVectorsVect);

                moeoHyperVolumeMetric < SatOptObjectiveVector > hyperVolumeMetricUnary(false,refPoint);


                moeoVecVsVecAdditiveEpsilonBinaryMetric < SatOptObjectiveVector > additiveEpsilon(true);
                char temp[100];
                for(int i=0; i<4; i++)
                {
                    //cout << i << endl;
                    vector< vector<SatOptObjectiveVector> >resultsObjVectors;
                    resultsObjVectors = resultsObjVectorsVect[i];

                    //this loop builds RunResult vector and fills it
                    for(unsigned int i=0; i<resultsObjVectors.size(); i++)
                    {
                        std::vector < std::vector<double> > currentFrontNorm=frontNormalizer(resultsObjVectors[i],instBounds,refPoint);
                        //std::vector < SatOptObjectiveVector > currentFrontSat=frontNormalizerSat(resultsObjVectors[i],bounds,refPoint);
                        //std::vector < SatOptObjectiveVector > trueFrontNorm=frontNormalizerSat(trueFrontObjVect,bounds,refPoint);

                        cout << "unary HV: " << hyperVolumeMetricUnary.calc_hypervolume(currentFrontNorm,currentFrontNorm.size(),2) << endl;
                    }


                    //build file name to be saved
                    sprintf(temp,"final_res_%s_%d_%d_%d.csv",chCounts[chNumberIndex],i,swInst,chInst);//i stands for algo
                    //convert char to string
                    string fResultCSVFileName=temp;
                    //deletes existing file
                    remove((fResultCSVFileName).c_str());
                }



            }
        }
    }

    void writeToFile(string fResultCSVFileName, vector<RunResult> results, double trueFrontUnaryHV){
        ofstream  finalResCSVFile(resultDir+fResultCSVFileName, ios::app);
        if (finalResCSVFile.is_open())
        {
            finalResCSVFile << "runNumber," << "genCount," << "elapsedTime," << "noSolutions,"
                            << "unaryHyperVol," << "binaryHyperVol," << "additiveEps," << "entropy\r\n";

            for(unsigned int i=0; i<results.size(); i++)
            {
                finalResCSVFile << i << ","
                                << results[i].genCount << ","
                                << results[i].elapsedTime << ","
                                << results[i].finalArchive.size() << ","
                                << results[i].getUnaryHyperVol() << ","
                                << results[i].getBinaryHyperVol() << ","
                                << results[i].getAdditiveEps() << ","
                                << results[i].getEntropy() << "\r\n";
            }
            finalResCSVFile << ",,," << trueFrontUnaryHV << ",,,";
            finalResCSVFile.close();
        }
    }
    /** Default destructor */
    ~ParameterReCalc();
protected:
private:
    //std::string fileName;
    //double switchLoss;
    //std::unordered_map<std::string,unsigned int> channels;
    //std::vector < std::vector <std::string> > values;
    //std::unordered_map<std::string,unsigned int> links;
};




std::vector < std::vector<double> > frontNormalizerRef(const std::vector < SatOptObjectiveVector > & _set, std::vector < eoRealInterval > _bounds,SatOptObjectiveVector ref_point)
{
    std::vector < std::vector<double> > front;
    front.resize(_set.size());
    for(unsigned int i=0; i < _set.size(); i++)
    {
        front[i].resize(SatOptObjectiveVector::Traits::nObjectives());
        for (unsigned int j=0; j<SatOptObjectiveVector::Traits::nObjectives(); j++)
        {
            if (SatOptObjectiveVector::Traits::minimizing(j))
            {
                front[i][j]=ref_point[j] - abs((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range());
                //cout << "orig: " << _set[i][j] << "  ";
                //cout << front[i][j] << "   ";
            }
            else
            {
                front[i][j]=((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range()) - ref_point[j];
            }
        }
        //cout << endl;
    }
    return front;
}

int main()
{
    ParameterReCalc *pc= new ParameterReCalc();
    pc->calculateAll();

    return 0;
}





std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    elems.clear();
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}


std::vector < SatOptObjectiveVector> frontNormalizerSat(const std::vector < SatOptObjectiveVector > & _set, std::vector < eoRealInterval > _bounds /*vectors contains bounds for normalization*/
        ,SatOptObjectiveVector ref_point)
{
    //cout << "Sat norm\n";
    std::vector < SatOptObjectiveVector > front;
    front.resize(_set.size());
    for(unsigned int i=0; i < _set.size(); i++)
    {
        front[i].resize(SatOptObjectiveVector::Traits::nObjectives());
        for (unsigned int j=0; j<SatOptObjectiveVector::Traits::nObjectives(); j++)
        {
            if (SatOptObjectiveVector::Traits::minimizing(j))
            {
                front[i][j]=abs((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range());
                //cout << front[i][j] << " ";

            }
            else
            {
                front[i][j]=((_set[i][j] - _bounds[j].minimum()) /_bounds[j].range()) - ref_point[j];
            }
        }
        //cout << endl;
    }
    //cout << "Sat norm end\n";

    return front;
}
