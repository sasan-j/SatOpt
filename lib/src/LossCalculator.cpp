#include "../inc/LossCalculator.h"

LossCalculator::LossCalculator()
{
    //ctor
    switchLoss = -0.04f;
    fileName="../ref/Losses_50sw_snj.txt";
    //std::cout << "file name is "<< fileName << std::endl;
    //vector<std::string> channels;

    std::ifstream infile(fileName.c_str());
    std::string line;

    std::vector<std::string> lines;

    while(!infile.eof())
    {
        std::getline(infile, line);
        lines.push_back(line);
    }
    unsigned int noLinks = lines.size() - 2;


    std::string delimiter = ",";

    line = lines[1];
    //cout << line << endl;


    std::string currentItem;
    std::string::size_type pos;
    //to leave out Link
    pos=line.find(delimiter);
    line = line.substr(pos+1,std::string::npos);

    int i=0;
    while(1)
    {

        pos=line.find(delimiter);
        currentItem = line.substr(0, pos);
        line = line.substr(pos+1,std::string::npos);
        if(pos==std::string::npos){
            currentItem = currentItem.substr(0,currentItem.length());
            channels[currentItem]=i++;
            //std::cout << currentItem << std::endl;
            break;
        }
        channels[currentItem]=i++;
        //std::cout << currentItem << std::endl;
    }
    //std::cout << channels.size() << std::endl;



    i=1;
    for(std::vector<std::string>::iterator it = lines.begin()+2; it != lines.end(); it++)
    {
        std::vector<std::string> row;
        std::string currentItem;
        std::string::size_type pos;
        std::string line = *it;
        pos=line.find(delimiter);
        //if(pos==std::string::npos)
        //    break;
        currentItem = line.substr(0, pos);
        line = line.substr(pos+1,std::string::npos);
        //std::cout << "line:" << line << std::endl;
        links[currentItem]=i++;

        //std::cout << "current Link: " << currentItem << "\t" << links[currentItem] << std::endl;
        for(std::vector<std::string>::size_type j=0;j<channels.size();j++)
        {
            pos=line.find(delimiter);
            currentItem = line.substr(0, pos);
            //std::cout << "line:" << line << std::endl;
            //std::cout << "current value: " << currentItem << std::endl;
            if(pos==std::string::npos){
                //currentItem = currentItem.substr(0,currentItem.length()-2);
                row.push_back(currentItem);
                //std::cout << currentItem << std::endl;
                break;
            }
            line = line.substr(pos+1,std::string::npos);
            row.push_back(currentItem);


        }
        //std::cout << " QQQQQQQQQQQ\n";
        values.push_back(row);
    }
    
    /*
    std::cout << values[links["s45->t57"]][channels["F3"]] << std::endl;
    assert(values[links["s45->t57"]][channels["F3"]].compare("-0.1458")==0);
    std::cout << values[links["s45->t57"]][channels["F3"]] << std::endl;
    assert(values[links["s46->t58"]][channels["F3"]].compare("-0.1515")==0);
    std::cout << values[links["s46->t58"]][channels["F3"]] << std::endl;
    assert(values[links["s34->t61"]][channels["F11"]].compare("-0.1820")==0);
    std::cout << values[links["s34->t61"]][channels["F11"]] << std::endl;
    assert(values[links["s35->t46"]][channels["TG1"]].compare("-0.2417")==0);
    std::cout << values[links["s35->t46"]][channels["TG1"]] << std::endl;
    assert(values[links["s50->t55"]][channels["G1"]].compare("-0.1111")==0);
    std::cout << values[links["s50->t55"]][channels["G1"]] << std::endl;
    assert(values[links["s49->t56"]][channels["G15"]].compare("-0.1056")==0);
    std::cout << values[links["s49->t56"]][channels["G15"]] << std::endl;
    
    std::cout << "channel TM2 id: " << channels["TM2"] << std::endl; 
    std::cout << "channel TM1 id: " << channels["TM1"] << std::endl; 
    std::cout << "channel F3 id: " << channels["F3"] << std::endl; 

    std::cout << values[links["s46->t58"]][channels["TM2"]] << std::endl;
    std::cout << values[links["s45->t57"]][channels["TM2"]] << std::endl;

    assert(values[links["s46->t58"]][channels["TM2"]].compare("-0.1515")==0);
    std::cout << values[links["s46->t58"]][channels["TM2"]] << std::endl;
    
    assert(values[links["s45->t57"]][channels["TM2"]].compare("-0.1458")==0);
    std::cout << values[links["s45->t57"]][channels["TM2"]] << std::endl;
    std::cout << "tests finished and object created" << std::endl;
    */
}

double LossCalculator::calculatePathLoss(std::string line){
    double pathLoss= 0.0f;
    double tmp;
    std::string currentItem;
    std::string prevItem;
    std::string channel;
    std::string link;
    std::string delimiter=",";
    std::string::size_type pos;
    //to leave out Link
    pos=line.find(delimiter);
    prevItem = line.substr(0,pos);
    line = line.substr(pos+1,std::string::npos);
    channel = prevItem;
    //pos=line.find(delimiter);
    //currentItem = line.substr(0,pos);
    //line = line.substr(pos+1,std::string::npos);
    int i=0;
    while(1)
    {
        pos=line.find(delimiter);
        currentItem = line.substr(0, pos);
        line = line.substr(pos+1,std::string::npos);
        if(pos==std::string::npos){
            currentItem = currentItem.substr(0,currentItem.length());
            link = prevItem + "->" + currentItem;
            std::cout << link << std::endl;
            tmp=atof(values[links[link]][channels[channel]].c_str());
            std::cout << tmp << std::endl;
            pathLoss+=tmp;
            break;
        }
        //channels[currentItem]=i++;
        //cout << currentItem << endl;
        link = prevItem + "->" + currentItem;
        //std::cout << link << std::endl;
        tmp=atof(values[links[link]][channels[channel]].c_str());
        //std::cout << tmp << std::endl;
        pathLoss+=tmp;
        pathLoss+=switchLoss;
        prevItem = currentItem;
    }
    return pathLoss;
}

double LossCalculator::calculatePathLoss(std::vector<std::string> *pathStrVec){
    double pathLoss= 0.0f;
    double tmp;
    int linkID;
    std::string currentItem;
    std::string prevItem;
    std::string link;
    std::string channel;
    
    std::vector<std::string>::iterator it=pathStrVec->begin();
    prevItem=(*it);
    channel = prevItem;
    
    //this for calculates link losses
    for(it=pathStrVec->begin()+1;it!=pathStrVec->end();it++){
      currentItem=(*it);
      link = prevItem + "->" + currentItem;
      linkID=links[link];
      if(linkID==0){
	link = currentItem + "->" + prevItem;
	linkID=links[link];
	if(linkID==0)
	  std::cout << "ERROR" << std::endl;
      }
      tmp=atof(values[linkID-1][channels[channel]].c_str());
      std::cout << "link: " << link << " loss: " << tmp << std::endl;
      pathLoss+=tmp;
      prevItem = currentItem;
    }
    //added loss of the middle switches
    pathLoss+=(switchLoss*(pathStrVec->size()-1));
    
    return pathLoss;
}


LossCalculator::~LossCalculator()
{
    //dtor
}
