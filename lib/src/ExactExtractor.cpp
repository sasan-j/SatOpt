#include "ExactExtractor.h"



ExactExtractor::ExactExtractor(unsigned int _swInst, unsigned int _chCount ,unsigned int _chInst)
{
    swInst = _swInst+1;//because in the files swInst starts from 1 not 0
    chCount = _chCount;
    chInst = _chInst;
}

bool ExactExtractor::isAvailable()
{
    std::string fileName;
    bool found=false;
    std::ifstream infile;
    std::string line;
    std::vector<std::string> lines;
    std::string compareStr;
    int a,b;
    switch (chCount)
    {
    case 8:
        fileName="ref/ExactResults/Pareto_size8/NEW_Correct_Pareto_Points_"+std::to_string(swInst)+"_"+std::to_string(chInst)+".txt";
        //std::cout << "file name is "<< fileName << std::endl;
        infile.open(fileName.c_str());
        if (infile.is_open())
        {
            found = true;
            while ( infile.good() )
            {
                //cout << "reads the file" << endl;
                getline (infile,line);
                if(line.length() > 2)
                {
                    //cout << line << endl;
                    sscanf(line.c_str(),"%d,%d\n",&a,&b);
                    //cout << "the values read from file\n";
                    //cout << a << endl << b << endl;
                    SatOptObjectiveVector objVec;
                    objVec[0] = a; //quality metric LPL
                    objVec[1] = b;
                    optimalFront.push_back(objVec);
                }
                else
                    break;

            }
            std::cout << optimalFront.size() << std::endl;
            infile.close();
        }
        break;
    case 13:
    case 18:
        fileName="ref/ExactResults/ParetoPoints"+std::to_string(chCount)+".txt";
        std::cout << fileName << std::endl;
        //std::cout << "file name is "<< fileName << std::endl;
        infile.open(fileName.c_str());
        while ( infile.good() )
        {
            //cout << "reads the file" << endl;

            getline (infile,line);
            //cout << line << endl;
            if(line.length()>5)
                lines.push_back(line);
            //cout << lines.size() << endl;
        }
        infile.close();
        compareStr="Pareto front found for "+std::to_string(swInst)+"_"+std::to_string(chInst);
        for(std::vector<std::string>::size_type i=0; i<lines.size(); i++)
        {
            //cout << "-----------------" << endl;
            //cout << lines[i] << endl;
            //cout << compareStr << endl;
            if(lines[i].find(compareStr)!=std::string::npos)
            {
                found = true;
                i++;
                while(lines[i].find(" Pareto")== std::string::npos)
                {
                    sscanf(lines[i].c_str(),"(%d,%d)\n",&a,&b);
                    //cout << "the values read from file\n";
                    //cout << a << endl << b << endl;
                    SatOptObjectiveVector objVec;
                    objVec[0] = a; //quality metric LPL
                    objVec[1] = b;
                    optimalFront.push_back(objVec);
                    i++;
                }
                break;
            }
        }

        break;
    case 25:
    case 30:
    case 35:
        return false;
    default:
        return false;
    }
    return found;
}

std::vector<SatOptObjectiveVector> ExactExtractor::getExactFront(void)
{
    return optimalFront;
}

