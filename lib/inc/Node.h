/* 
 * File:   Node.h
 * Author: sasan
 *
 * Created on March 28, 2013, 6:07 PM
 */

#ifndef NODE_H
#define	NODE_H

#include <vector>
#include "Port.h"
#include "PrIns.h"

//#define DEBUG_ALL

using namespace std;

class Node {
    std::string name;
    std::string type;
    int x;
    int y;
    int pos;
    bool isUsed;
    Node* left;
    Node* up;
    Node* right;
    Node* down;
    Node* backup_left;
    Node* backup_up;
    Node* backup_right;
    Node* backup_down;
    vector<Node*> connections;
    Port* port_l;
    Port* port_r;
    Port* port_u;
    Port* port_d;
public:
    Node(string name, string type, int x, int y);
    /*Node(const Node& orig);*/
    ~Node();
       /* */
        
        
    bool isNone();
    bool isAmplifier();
    bool isChannel();
    bool isAvailable();
    Node& operator=(const Node& other);
    string getName();
    int getX();
    int getY();

    int getPos();
    int setPos(int p);

    unsigned short getNumberofNeighbors();
    Node* getLeftNeighbor();
    void setLeftNeighbor(Node* l);
    Node* getUpNeighbor();
    void setUpNeighbor(Node* u);
    Node* getRightNeighbor();
    void setRightNeighbor(Node* r);
    Node* getDownNeighbor();
    void setDownNeighbor(Node* d);

    //BACK UP NEIGHBORS

    Node* getBackupLeftNeighbor();
    void setBackupLeftNeighbor(Node* l);
    Node* getBackupUpNeighbor();
    void setBackupUpNeighbor(Node* u);
    Node* getBackupRightNeighbor();
    void setBackupRightNeighbor(Node* r);
    Node* getBackupDownNeighbor();
    void setBackupDownNeighbor(Node* d);

    void setIfIsUsed(bool u);

    vector<Node*> getConnections();
    void addConnection(Node* c);

    void setPorts(Port* l, Port* u, Port* r, Port* d);

	Port* getLeftPort();
	Port* getDownPort();
	Port* getUpPort();
	Port* getRightPort();
    Node* getChannelNeighbor(Node* c);
    void createGraph(vector<Node*> switches);

    Port* getChannelsNeighborPort(Node* s);

    vector<int> existsPathInGraph(Node* chan);

    void setNeighbors(Node* l, Node* u, Node* r, Node* d);

    vector<int> run(vector<int> solution, vector<int> position_vector, int xxx,
            vector<string> chan_instance);

};
#endif	/* NODE_H */