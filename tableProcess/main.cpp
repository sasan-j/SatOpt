#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream> //this is where istringstream is defined
#include <fstream>
#include <unordered_map>
#include <assert.h>
#include "lossCalculator.h"


using namespace std;

int main()
{

    lossCalculator lc= lossCalculator();
    cout << lc.calculatePathLoss("F1,s1,s2,t69") << endl;
    /*
    for(int i=0; i<noLinks; i++){
        for(int j=0; j<channels.size();j++)
            cout << values[i][j] << " ";

        cout << endl;
    }
    */
    //cout << values.size() << endl;
    //cout << channels.size() << endl;
    //cout << links.size() << endl;
    //cout << channels["EMI"] << endl;
    //cout << channels["B1"] << endl;
    //cout << channels["B11"] << endl;
    //cout << channels["TM2"] << endl;
    //cout << channels["TM1"] << endl;
    //cout << links["s34->t61"] << endl;



/*
    cout << values[links["s33->s41"]][channels["F1"]] << endl;
    cout << values[links["s40->s47"]][channels["F1"]] << endl;
    cout << values[links["s44->s50"]][channels["F1"]] << endl;
    cout << values[links["s31->s42"]][channels["F1"]] << endl;
    cout << values[links["s50->s55"]][channels["F1"]];
*/


//int** ary = new int*[sizeX];
//for(int i = 0; i < sizeX; ++i)
//    ary[i] = new int[sizeY];


    /*

        for(int i=0;i<=chan_inst;i++)
        {
            //std::cout << fileName.c_str() << std::endl;
            std::getline(infile, line);
            //std::cout << line << std::endl;
            std::istringstream iss(line);
            if (!(iss >> a >> b >> c)) { break; } // error
            //std::cout << a << "  " << b << "  " << c << std::endl;
            if(i==chan_inst){
                std::vector<std::string> instance;
                instance.push_back(a);
                instance.push_back(c);
                return instance;
            }

        }*/



    return 0;
}
