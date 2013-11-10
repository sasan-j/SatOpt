#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Hello world!" << endl;

    vector<int> tmpVector;
    vector<int> switchPos;

    string input=argv[1];


    for (unsigned i = 0; i < input.size(); i++)
    {
        //char *a = input[i];
        tmpVector.push_back(input[i]-48); //load individual into tmpVector
    }

    //converting int vector of the individual (tmpVector) into
    //another vector representing switch state
    //each two bit -> one switch state
    int result;
    for (unsigned int g = 0; g <= tmpVector.size() - 2; g = g + 2)
    {
        int x = tmpVector[g];
        int y = tmpVector[g + 1];
        if (x == 0 && y == 0)
        {
            result = 1;
        }
        else if (x == 1 && y == 0)
        {
            result = 2;
        }
        else if (x == 0 && y == 1)
        {
            result = 3;
        }
        else
        {
            result = 4;
        }
        switchPos.push_back(result);
    }

    for(unsigned int i=0; i< switchPos.size();i++)
        cout << switchPos[i];




    return 0;
}
