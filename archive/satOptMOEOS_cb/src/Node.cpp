/*
 * File:   Node.cpp
 * Author: sasan
 *
 * Created on March 28, 2013, 6:07 PM
 */

#include "Node.h"

using namespace std;


Node::Node(string name, string type, int x, int y) {
    this->name = name;
    this->type = type;
    this->x = x;
    this->y = y;
    this->left = 0;
    this->up = 0;
    this->right = 0;
    this->down = 0;

    this->backup_left = 0; // keep back-up neighbors
    this->backup_up = 0;
    this->backup_right = 0;
    this->backup_down = 0;
    this->isUsed = false;

    this->port_l = 0;
    this->port_u = 0;
    this->port_r = 0;
    this->port_d = 0;
}

/*
Node::Node(const Node& orig) {
}*/

Node::~Node() {
  //  cout << "node is decunstructing...\n";
}

bool Node::isNone() {
    return (this->name == "none");
}

bool Node::isAmplifier() {

    if (this->type == "amplifier") {
        return true;
    } else {
        return false;
    }
}

bool Node::isChannel() {
    if (this->type == "channel") {
        return true;
    } else {
        return false;
    }
}

bool Node::isAvailable() {
    if (this->type == "amplifier") {
        if (this->isUsed == false) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

Node& Node::operator=(const Node& other) {
    if (this != &other) {
        this->name = other.name;
        this->type = other.type;
        this->x = other.x;
        this->y = other.y;
        this->left = other.left;
        this->up = other.up;
        this->right = other.right;
        this->down = other.down;
    }
    return *this;
}

string Node::getName() {

    return name;

}

int Node::getX() {

    return x;

}

int Node::getY() {

    return y;

}

int Node::getPos() {
    return this->pos;
}

int Node::setPos(int p) {
    this->pos = p;
}

unsigned short Node::getNumberofNeighbors() {
    unsigned short num = 0;
    if (this->left && !this->left->isNone()) {
        num++;
    }
    if (this->up && !this->up->isNone()) {
        num++;
    }
    if (this->right && !this->right->isNone()) {
        num++;
    }
    if (this->down && !this->down->isNone()) {
        num++;
    }
    return num;
}

Node* Node::getLeftNeighbor() {
    return this->left;
}

void Node::setLeftNeighbor(Node* l) {
    this->left = l;
}

Node* Node::getUpNeighbor() {
    return this->up;
}

void Node::setUpNeighbor(Node* u) {
    this->up = u;
}

Node* Node::getRightNeighbor() {
    return this->right;
}

void Node::setRightNeighbor(Node* r) {
    this->right = r;
}

Node* Node::getDownNeighbor() {
    return this->down;
}

void Node::setDownNeighbor(Node* d) {
    this->down = d;
}

//BACK UP NEIGHBORS

Node* Node::getBackupLeftNeighbor() {
    return this->backup_left;
}

void Node::setBackupLeftNeighbor(Node* l) {
    this->backup_left = l;
}

Node* Node::getBackupUpNeighbor() {
    return this->backup_up;
}

void Node::setBackupUpNeighbor(Node* u) {
    this->backup_up = u;
}

Node* Node::getBackupRightNeighbor() {
    return this->backup_right;
}

void Node::setBackupRightNeighbor(Node* r) {
    this->backup_right = r;
}

Node* Node::getBackupDownNeighbor() {
    return this->backup_down;
}

void Node::setBackupDownNeighbor(Node* d) {
    this->backup_down = d;
}

void Node::setIfIsUsed(bool u) {
    this->isUsed = u;
}

vector<Node*> Node::getConnections() {
    return this->connections;
}

void Node::addConnection(Node* c) {
    this->connections.push_back(c);
}

void Node::setPorts(Port* l, Port* u, Port* r, Port* d) {

    this->port_l = l;
    this->port_u = u;
    this->port_r = r;
    this->port_d = d;

}

Port*  Node::getLeftPort() {
    return this->port_l;
}

Port*  Node::getDownPort() {
    return this->port_d;
}

Port*  Node::getUpPort() {
    return this->port_u;
}

Port*  Node::getRightPort() {
    return this->port_r;
}

Node* Node::getChannelNeighbor(Node* c) {
    if (c->getUpNeighbor()) {
        return c->getUpNeighbor();
        cout << "8b" << endl;

    } else if (c->getDownNeighbor()) {
        return c->getDownNeighbor();
        cout << "8c" << endl;

    } else if (c->getLeftNeighbor()) {
        return c->getLeftNeighbor();
        cout << "8d" << endl;

    } else {
        return getRightNeighbor();
        cout << "8e" << endl;

    }
}

void Node::createGraph(vector<Node*> switches) { // This function creates the graph given a set of switch objects..
    //At the first step creates the links between the neighbor switches.
    //At the second step creates the links between the ports of the same switch, based on its position.

    while (!switches.empty()) {
        Node* current;
        Node* temp;
        current = switches[0];
        string name = current->getName();

        if (current->isChannel()) {
            /*	 temp = current->getChannelNeighbor(current);
             if(temp->getRightNeighbor() && (temp->getRightNeighbor()->getName()).compare(name)==0){
             temp->getRightPort()->addConnection(current->getName());
             }else if(temp->getLeftNeighbor() && (temp->getLeftNeighbor()->getName()).compare(name)==0){
             temp->getLeftPort()->addConnection(current->getName());
             }else if(temp->getDownNeighbor() && (temp->getDownNeighbor()->getName()).compare(name)==0){
             temp->getDownPort()->addConnection(current->getName());
             }else {
             temp->getUpPort()->addConnection(current->getName());
             }
             */
        }
        else { // if it is a switch
            int current_pos = current->getPos();
            if (current->getLeftNeighbor()
                    && !current->getLeftNeighbor()->isAmplifier()
                    && !current->getLeftNeighbor()->isChannel()) {
                if (current->getLeftNeighbor()->getRightNeighbor()
                        && (current->getLeftNeighbor()->getRightNeighbor()->getName()).compare(
                        current->getName()) == 0) {
                    current->getLeftPort()->addConnection(
                            current->getLeftNeighbor()->getRightPort());

                } else if (current->getLeftNeighbor()->getUpNeighbor()
                        && (current->getLeftNeighbor()->getUpNeighbor()->getName()).compare(
                        current->getName()) == 0) {
                    current->getLeftPort()->addConnection(
                            current->getLeftNeighbor()->getUpPort());

                } else if (current->getLeftNeighbor()->getDownNeighbor()
                        && (current->getLeftNeighbor()->getDownNeighbor()->getName()).compare(
                        current->getName()) == 0) {
                    current->getLeftPort()->addConnection(
                            current->getLeftNeighbor()->getDownPort());

                } else if (current->getLeftNeighbor()->getLeftNeighbor()
                        && (current->getLeftNeighbor()->getLeftNeighbor()->getName()).compare(
                        current->getName()) == 0) {
                    current->getLeftPort()->addConnection(
                            current->getLeftNeighbor()->getLeftPort());

                }
            }                //	 else if(current->getLeftNeighbor() && current->getLeftNeighbor()->isAmplifier() || current->getLeftNeighbor()->isChannel()){
                // 	 		current->getLeftPort()->addConnection(current->getLeftNeighbor()->getName());
                // 	 } else {

                // 	 }
            else if (current->getLeftNeighbor()
                    && current->getLeftNeighbor()->isAmplifier()) {
                current->getLeftPort()->addConnection(
                        current->getLeftNeighbor()->getName());
            } else {

            }

            if (current->getRightNeighbor()
                    && !current->getRightNeighbor()->isAmplifier()
                    && !current->getRightNeighbor()->isChannel()) {

                if (current->getRightNeighbor()->getLeftNeighbor()
                        && (current->getRightNeighbor()->getLeftNeighbor()->getName()).compare(
                        current->getName()) == 0) {
                    current->getRightPort()->addConnection(
                            current->getRightNeighbor()->getLeftPort());

                } else if (current->getRightNeighbor()->getUpNeighbor()
                        && (current->getRightNeighbor()->getUpNeighbor()->getName()).compare(
                        current->getName()) == 0) {
                    current->getRightPort()->addConnection(
                            current->getRightNeighbor()->getUpPort());

                } else if (current->getRightNeighbor()->getDownNeighbor()
                        && (current->getRightNeighbor()->getDownNeighbor()->getName()).compare(
                        current->getName()) == 0) {
                    current->getRightPort()->addConnection(
                            current->getRightNeighbor()->getDownPort());

                } else if (current->getRightNeighbor()->getRightNeighbor()
                        && (current->getRightNeighbor()->getRightNeighbor()->getName()).compare(
                        current->getName()) == 0) {
                    current->getRightPort()->addConnection(
                            current->getRightNeighbor()->getRightPort());

                }
            }                //else if(current->getRightNeighbor() && current->getRightNeighbor()->isAmplifier() || current->getRightNeighbor()->isChannel()){
                //		current->getRightPort()->addConnection(current->getRightNeighbor()->getName());
                //} else {

                // }
            else if (current->getRightNeighbor()
                    && current->getRightNeighbor()->isAmplifier()) {
                current->getRightPort()->addConnection(
                        current->getRightNeighbor()->getName());
            } else {

            }

            if (current->getUpNeighbor()) {
                if (!current->getUpNeighbor()->isAmplifier()
                        && !current->getUpNeighbor()->isChannel()) {

                    if (current->getUpNeighbor()->getLeftNeighbor()
                            && (current->getUpNeighbor()->getLeftNeighbor()->getName()).compare(
                            current->getName()) == 0) {
                        current->getUpPort()->addConnection(
                                current->getUpNeighbor()->getLeftPort());

                    } else if (current->getUpNeighbor()->getUpNeighbor()
                            && (current->getUpNeighbor()->getUpNeighbor()->getName()).compare(
                            current->getName()) == 0) {
                        current->getUpPort()->addConnection(
                                current->getUpNeighbor()->getUpPort());

                    } else if (current->getUpNeighbor()->getDownNeighbor()
                            && (current->getUpNeighbor()->getDownNeighbor()->getName()).compare(
                            current->getName()) == 0) {
                        current->getUpPort()->addConnection(
                                current->getUpNeighbor()->getDownPort());

                    } else if (current->getUpNeighbor()->getRightNeighbor()
                            && (current->getUpNeighbor()->getRightNeighbor()->getName()).compare(
                            current->getName()) == 0) {
                        current->getUpPort()->addConnection(
                                current->getUpNeighbor()->getRightPort());

                    } else {

                    }

                    // 	 } else if(current->getUpNeighbor()->isAmplifier() || current->getUpNeighbor()->isChannel()){
                    // 	 		current->getUpPort()->addConnection(current->getUpNeighbor()->getName());

                    // 	 } else {

                    //	 }

                } else if (current->getUpNeighbor()
                        && current->getUpNeighbor()->isAmplifier()) {
                    current->getUpPort()->addConnection(
                            current->getUpNeighbor()->getName());

                } else {

                }

            }

            if (current->getDownNeighbor()) {
                if (!current->getDownNeighbor()->isAmplifier()
                        && !current->getDownNeighbor()->isChannel()) {

                    if (current->getDownNeighbor()->getLeftNeighbor()
                            && (current->getDownNeighbor()->getLeftNeighbor()->getName()).compare(
                            current->getName()) == 0) {
                        current->getDownPort()->addConnection(
                                current->getDownNeighbor()->getLeftPort());

                    } else if (current->getDownNeighbor()->getUpNeighbor()
                            && (current->getDownNeighbor()->getUpNeighbor()->getName()).compare(
                            current->getName()) == 0) {
                        current->getDownPort()->addConnection(
                                current->getDownNeighbor()->getUpPort());

                    } else if (current->getDownNeighbor()->getDownNeighbor()
                            && (current->getDownNeighbor()->getDownNeighbor()->getName()).compare(
                            current->getName()) == 0) {
                        current->getDownPort()->addConnection(
                                current->getDownNeighbor()->getDownPort());

                    } else if (current->getDownNeighbor()->getRightNeighbor()
                            && (current->getDownNeighbor()->getRightNeighbor()->getName()).compare(
                            current->getName()) == 0) {
                        current->getDownPort()->addConnection(
                                current->getDownNeighbor()->getRightPort());

                    }
                }                    //	 else if(current->getDownNeighbor()->isAmplifier() || current->getDownNeighbor()->isChannel()){
                    //	 		current->getDownPort()->addConnection(current->getDownNeighbor()->getName());
                    //	 } else{

                    //	}
                else if (current->getDownNeighbor()
                        && current->getDownNeighbor()->isAmplifier()) {
                    current->getDownPort()->addConnection(
                            current->getDownNeighbor()->getName());
                } else {

                }

            }

            // Fix network based on positions
            if (current_pos == 1) {
                current->getLeftPort()->addSwitchPositionConnection(
                        current->getDownPort());
                current->getDownPort()->addSwitchPositionConnection(
                        current->getLeftPort());
                current->getUpPort()->addSwitchPositionConnection(
                        current->getRightPort());
                current->getRightPort()->addSwitchPositionConnection(
                        current->getUpPort());
            } else if (current_pos == 4) {
                current->getLeftPort()->addSwitchPositionConnection(
                        current->getRightPort());
                current->getRightPort()->addSwitchPositionConnection(
                        current->getLeftPort());
            } else if (current_pos == 3) {
                current->getLeftPort()->addSwitchPositionConnection(
                        current->getUpPort());
                current->getUpPort()->addSwitchPositionConnection(
                        current->getLeftPort());
                current->getDownPort()->addSwitchPositionConnection(
                        current->getRightPort());
                current->getRightPort()->addSwitchPositionConnection(
                        current->getDownPort());
            } else {
                current->getDownPort()->addSwitchPositionConnection(
                        current->getUpPort());
                current->getUpPort()->addSwitchPositionConnection(
                        current->getDownPort());
            }

        }

        switches.erase(switches.begin());
    }
}

Port* Node::getChannelsNeighborPort(Node* s) {
    Node* t;
    t = getChannelNeighbor(s);
    if (t->getLeftNeighbor()
            && t->getLeftNeighbor()->getName().compare(s->getName()) == 0) {
        return t->getLeftPort();
    } else if (t->getRightNeighbor()
            && t->getRightNeighbor()->getName().compare(s->getName())
            == 0) {
        return t->getRightPort();
    } else if (t->getUpNeighbor()
            && t->getUpNeighbor()->getName().compare(s->getName()) == 0) {
        return t->getUpPort();
    } else {
        return t->getDownPort();
    }
}

vector<int> Node::existsPathInGraph(Node* chan) { // check for a given channel object if a path to an amplifier exists.
    vector<Port*> path;
    vector<int> pathsLength;
    int result;
    Node* current;
    Port * p1;
    Port *p2;
    Port *p3;
    current = chan;
    p1 = getChannelsNeighborPort(current);
    path.push_back(p1);
    if (p1->getSwitchPositionConnection()) {
        p2 = p1->getSwitchPositionConnection();
        path.push_back(p2);
    } else {
        result = 0;
        pathsLength.push_back(0);
        pathsLength.push_back(0);
        return pathsLength;
    }

    while (p2->getStringConnection().empty()) {
        if (p2->getPortConnection()) {
            p3 = p2->getPortConnection();
            path.push_back(p3);
        } else {
            break;
        }

        p1 = p3;
        if (p1->getSwitchPositionConnection()) {
            p2 = p1->getSwitchPositionConnection();
            path.push_back(p2);
        } else {
            break;
        }
    }
    if (!p2->getStringConnection().empty()) {
#ifdef DEBUG_ALL

        cout << "Path found for " << chan->getName() << " !!!" << endl;
        for (int t = 0; t < path.size(); t++) {
            cout << path[t]->getName() << endl;
        }
        cout << p2->getStringConnection() << endl;
#endif
        result = 1;
        pathsLength.push_back(1);
        pathsLength.push_back(path.size() / 2);
    } else {
#ifdef DEBUG_ALL
        cout << " No path for " << chan->getName() << endl;
#endif
        result = 0;
        pathsLength.push_back(0);
        pathsLength.push_back(0);
    }
    return pathsLength;
}

void Node::setNeighbors(Node* l, Node* u, Node* r, Node* d) {

    this->left = l;
    this->up = u;
    this->right = r;
    this->down = d;

    this->backup_left = l; // set also the backup neighbors
    this->backup_up = u;
    this->backup_right = r;
    this->backup_down = d;
}

vector<int> Node::run(vector<int> solution, vector<int> position_vector, int xxx,
        vector<string> chan_instance) { // here i define all the objects that exist in my network (switches, ports, channels etc..)

    vector<Node*> path;


    vector<Node*> switches; //list of all switches
    vector<Node*> amplifiers; //list of all amps
    vector<Node*> channels; //list of all channels

    vector<Node*> testex;



    //int fitness = 0; // maximum path length

    //int fitness2 = 0; // total number of switches used

    //int fitn = 0; // fitness number of paths

    //int flag = 0;



    Node f1("F1", "channel", 1, 0);
    Node f3("F3", "channel", 2, 0);
    Node f5("F5", "channel", 6, 2);
    Node f7("F7", "channel", 5, 3);
    Node f9("F9", "channel", 1, 5);
    Node f11("F11", "channel", 1, 6);

    Node g1("G1", "channel", 5, 6);
    Node g3("G3", "channel", 6, 6);
    Node g5("G5", "channel", 2, 9);
    Node g7("G7", "channel", 5, 9);
    Node g9("G9", "channel", 1, 12);
    Node g11("G11", "channel", 5, 12);
    Node g13("G13", "channel", 6, 12);
    Node g15("G15", "channel", 1, 15);

    Node e1("E1", "channel", 5, 17);
    Node e3("E3", "channel", 4, 17);
    Node e5("E5", "channel", 6, 20);
    Node e7("E7", "channel", 1, 20);

    Node tb7("TB7", "channel", 2, 20);
    Node tb9("TB9", "channel", 5, 20);
    Node tb11("TB11", "channel", 2, 17);

    Node tg1("TG1", "channel", 2, 12);
    Node tg3("TG3", "channel", 1, 9);
    Node tg5("TG5", "channel", 2, 6);
    Node tg7("TG7", "channel", 6, 3);
    Node tg9("TG9", "channel", 2, 3);
    Node tg11("TG11", "channel", 5, 2);

    //subgroup1
  /*
    Node c1("C1", "channel", 1, 38);
    Node c3("C3", "channel", 2, 38);
    Node c5("C5", "channel", 5, 36);
    Node c7("C7", "channel", 2, 35);
    Node c9("C9", "channel", 5, 35);
    Node c11("C11", "channel", 6, 35);
    Node c13("C13", "channel", 2, 33);
    Node c15("C15", "channel", 2, 32);

    Node ta5("TA5", "channel", 2, 32);
    Node ta7("TA7", "channel", 1, 29);

    Node f13("F13", "channel", 5, 27);
    Node f15("F15", "channel", 5, 29);
    Node f17("F17", "channel", 6, 32);
    Node f19("F19", "channel", 5, 32);

    Node b1("B1", "channel", 1, 21);
    Node b3("B3", "channel", 2, 21);
    Node b5("B5", "channel", 5, 21);
    Node b7("B7", "channel", 2, 24);
    Node b9("B9", "channel", 5, 24);
    Node b11("B11", "channel", 6, 24);
    Node b13("B13", "channel", 1, 26);
    Node b15("B15", "channel", 2, 29);
*/
    channels.push_back(&f1);
    channels.push_back(&f3);
    channels.push_back(&f5);
    channels.push_back(&f7);
    channels.push_back(&f9);
    channels.push_back(&f11);
    channels.push_back(&g1);
    channels.push_back(&g3);
    channels.push_back(&g5);
    channels.push_back(&g7);
    channels.push_back(&g9);
    channels.push_back(&g11);
    channels.push_back(&g13);
    channels.push_back(&g15);
    channels.push_back(&e1);
    channels.push_back(&e3);
    channels.push_back(&e5);
    channels.push_back(&e7);
    channels.push_back(&tb7);
    channels.push_back(&tb9);
    channels.push_back(&tb11);
    channels.push_back(&tg1);
    channels.push_back(&tg3);
    channels.push_back(&tg5);
    channels.push_back(&tg7);
    channels.push_back(&tg9);
    channels.push_back(&tg11);

    //subgroup1
/*
    channels.push_back(&c1);
    channels.push_back(&c3);
    channels.push_back(&c5);
    channels.push_back(&c7);
    channels.push_back(&c9);
    channels.push_back(&c11);
    channels.push_back(&c13);
    channels.push_back(&c15);
    channels.push_back(&ta5);
    channels.push_back(&ta7);
    channels.push_back(&f13);
    channels.push_back(&f15);
    channels.push_back(&f17);
    channels.push_back(&f19);
    channels.push_back(&b1);
    channels.push_back(&b3);
    channels.push_back(&b5);
    channels.push_back(&b7);
    channels.push_back(&b9);
    channels.push_back(&b11);
    channels.push_back(&b13);
    channels.push_back(&b15);
*/
    Node t42("T42", "amplifier", 2, 14);
    Node t45("T45", "amplifier", 2, 11);
    Node t46("T46", "amplifier", 6, 14);
    Node t49("T49", "amplifier", 6, 8);
    Node t51("T51", "amplifier", 2, 8);
    Node t55("T55", "amplifier", 6, 18);
    Node t56("T56", "amplifier", 5, 18);
    Node t57("T57", "amplifier", 1, 18);
    Node t58("T58", "amplifier", 2, 18);
    Node t59("T59", "amplifier", 1, 17);
    Node t60("T60", "amplifier", 5, 15);
    Node t61("T61", "amplifier", 5, 14);
    Node t62("T62", "amplifier", 1, 14);
    Node t63("T63", "amplifier", 5, 11);
    Node t64("T64", "amplifier", 1, 11);
    Node t65("T65", "amplifier", 5, 8);
    Node t66("T66", "amplifier", 1, 8);
    Node t67("T67", "amplifier", 5, 5);
    Node t68("T68", "amplifier", 1, 3);
    Node t69("T69", "amplifier", 2, 2);
    Node t70("T70", "amplifier", 1, 2);
    Node t71("T71", "amplifier", 5, 0);
    Node t72("T72", "amplifier", 6, 0);

    //subgroup1
/*
    Node t37("T37", "amplifier", 1, 27);
    Node t38("T38", "amplifier", 5, 38);
    Node t39("T39", "amplifier", 1, 36);
    Node t40("T40", "amplifier", 5, 33);
    Node t41("T41", "amplifier", 1, 35);
    Node t43("T43", "amplifier", 1, 30);
    Node t44("T44", "amplifier", 5, 30);
    Node t47("T47", "amplifier", 5, 26);
    Node t48("T48", "amplifier", 5, 27);
    Node t50("T50", "amplifier", 1, 24);
    Node t52("T52", "amplifier", 1, 23);
    Node t53("T53", "amplifier", 5, 23);
*/
    amplifiers.push_back(&t42);
    amplifiers.push_back(&t45);
    amplifiers.push_back(&t46);
    amplifiers.push_back(&t49);
    amplifiers.push_back(&t51);
    amplifiers.push_back(&t55);
    amplifiers.push_back(&t56);
    amplifiers.push_back(&t57);
    amplifiers.push_back(&t58);
    amplifiers.push_back(&t59);
    amplifiers.push_back(&t60);
    amplifiers.push_back(&t61);
    amplifiers.push_back(&t62);
    amplifiers.push_back(&t63);
    amplifiers.push_back(&t64);
    amplifiers.push_back(&t65);
    amplifiers.push_back(&t66);
    amplifiers.push_back(&t67);
    amplifiers.push_back(&t68);
    amplifiers.push_back(&t69);
    amplifiers.push_back(&t70);
    amplifiers.push_back(&t71);
    amplifiers.push_back(&t72);

    //subgroup1
/*
    amplifiers.push_back(&t37);
    amplifiers.push_back(&t38);
    amplifiers.push_back(&t39);
    amplifiers.push_back(&t40);
    amplifiers.push_back(&t41);
    amplifiers.push_back(&t43);
    amplifiers.push_back(&t44);
    amplifiers.push_back(&t47);
    amplifiers.push_back(&t48);
    amplifiers.push_back(&t50);
    amplifiers.push_back(&t52);
    amplifiers.push_back(&t53);
*/
    Node s1("s1", "switch", 1, 1);
    Node s2("s2", "switch", 2, 1);
    Node s3("s3", "switch", 5, 1);
    Node s4("s4", "switch", 6, 1);
    Node s5("s5", "switch", 0, 4);
    Node s6("s6", "switch", 1, 4);
    Node s7("s7", "switch", 2, 4);
    Node s8("s8", "switch", 3, 4);
    Node s9("s9", "switch", 4, 4);
    Node s10("s10", "switch", 5, 4);
    Node s11("s11", "switch", 6, 4);
    Node s12("s12", "switch", 7, 4);
    Node s13("s13", "switch", 0, 7);
    Node s14("s14", "switch", 1, 7);
    Node s15("s15", "switch", 2, 7);
    Node s16("s16", "switch", 3, 7);
    Node s17("s17", "switch", 4, 7);
    Node s18("s18", "switch", 5, 7);
    Node s19("s19", "switch", 6, 7);
    Node s20("s20", "switch", 7, 7);
    Node s21("s21", "switch", 0, 10);
    Node s22("s22", "switch", 1, 10);
    Node s23("s23", "switch", 2, 10);
    Node s24("s24", "switch", 3, 10);
    Node s25("s25", "switch", 4, 10);
    Node s26("s26", "switch", 5, 10);
    Node s27("s27", "switch", 6, 10);
    Node s28("s28", "switch", 7, 10);
    Node s29("s29", "switch", 0, 13);
    Node s30("s30", "switch", 1, 13);
    Node s31("s31", "switch", 2, 13);
    Node s32("s32", "switch", 3, 13);
    Node s33("s33", "switch", 4, 13);
    Node s34("s34", "switch", 5, 13);
    Node s35("s35", "switch", 6, 13);
    Node s36("s36", "switch", 7, 13);
    Node s37("s37", "switch", 0, 16);
    Node s38("s38", "switch", 1, 16);
    Node s39("s39", "switch", 2, 16);
    Node s40("s40", "switch", 3, 16);
    Node s41("s41", "switch", 4, 16);
    Node s42("s42", "switch", 5, 16);
    Node s43("s43", "switch", 6, 16);
    Node s44("s44", "switch", 7, 16);
    Node s45("s45", "switch", 1, 19);
    Node s46("s46", "switch", 2, 19);
    Node s47("s47", "switch", 3, 19);
    Node s48("s48", "switch", 4, 19);
    Node s49("s49", "switch", 5, 19);
    Node s50("s50", "switch", 6, 19);

    //subgroup1
/*
    Node s51("s51", "switch", 1, 22);
    Node s52("s52", "switch", 2, 22);
    Node s53("s53", "switch", 3, 22);
    Node s54("s54", "switch", 4, 22);
    Node s55("s55", "switch", 5, 22);
    Node s56("s56", "switch", 6, 22);
    Node s57("s57", "switch", 0, 25);
    Node s58("s58", "switch", 1, 25);
    Node s59("s59", "switch", 2, 25);
    Node s60("s60", "switch", 3, 25);
    Node s61("s61", "switch", 4, 25);
    Node s62("s62", "switch", 5, 25);
    Node s63("s63", "switch", 6, 25);
    Node s64("s64", "switch", 7, 25);
    Node s65("s65", "switch", 0, 28);
    Node s66("s66", "switch", 1, 28);
    Node s67("s67", "switch", 2, 28);
    Node s68("s68", "switch", 3, 28);
    Node s69("s69", "switch", 4, 28);
    Node s70("s70", "switch", 5, 28);
    Node s71("s71", "switch", 6, 28);
    Node s72("s72", "switch", 7, 28);
    Node s73("s73", "switch", 0, 31);
    Node s74("s74", "switch", 1, 31);
    Node s75("s75", "switch", 2, 31);
    Node s76("s76", "switch", 3, 31);
    Node s77("s77", "switch", 4, 31);
    Node s78("s78", "switch", 5, 31);
    Node s79("s79", "switch", 6, 31);
    Node s80("s80", "switch", 7, 31);
    Node s81("s81", "switch", 0, 34);
    Node s82("s82", "switch", 1, 34);
    Node s83("s83", "switch", 2, 34);
    Node s84("s84", "switch", 3, 34);
    Node s85("s85", "switch", 4, 34);
    Node s86("s86", "switch", 5, 34);
    Node s87("s87", "switch", 6, 34);
    Node s88("s88", "switch", 7, 34);
    Node s89("s89", "switch", 1, 37);
    Node s90("s90", "switch", 2, 37);
    Node s91("s91", "switch", 5, 37);
    Node s92("s92", "switch", 6, 37);
*/

    switches.push_back(&s1);
    switches.push_back(&s2);
    switches.push_back(&s3);
    switches.push_back(&s4);
    switches.push_back(&s5);
    switches.push_back(&s6);
    switches.push_back(&s7);
    switches.push_back(&s8);
    switches.push_back(&s9);
    switches.push_back(&s10);
    switches.push_back(&s11);
    switches.push_back(&s12);
    switches.push_back(&s13);
    switches.push_back(&s14);
    switches.push_back(&s15);
    switches.push_back(&s16);
    switches.push_back(&s17);
    switches.push_back(&s18);
    switches.push_back(&s19);
    switches.push_back(&s20);
    switches.push_back(&s21);
    switches.push_back(&s22);
    switches.push_back(&s23);
    switches.push_back(&s24);
    switches.push_back(&s25);
    switches.push_back(&s26);
    switches.push_back(&s27);
    switches.push_back(&s28);
    switches.push_back(&s29);
    switches.push_back(&s30);
    switches.push_back(&s31);
    switches.push_back(&s32);
    switches.push_back(&s33);
    switches.push_back(&s34);
    switches.push_back(&s35);
    switches.push_back(&s36);
    switches.push_back(&s37);
    switches.push_back(&s38);
    switches.push_back(&s39);
    switches.push_back(&s40);
    switches.push_back(&s41);
    switches.push_back(&s42);
    switches.push_back(&s43);
    switches.push_back(&s44);
    switches.push_back(&s45);
    switches.push_back(&s46);
    switches.push_back(&s47);
    switches.push_back(&s48);
    switches.push_back(&s49);
    switches.push_back(&s50);
    /*
    switches.push_back(&s51);
    switches.push_back(&s52);
    switches.push_back(&s53);
    switches.push_back(&s54);
    switches.push_back(&s55);
    switches.push_back(&s56);
    switches.push_back(&s57);
    switches.push_back(&s58);
    switches.push_back(&s59);
    switches.push_back(&s60);
    switches.push_back(&s61);
    switches.push_back(&s62);
    switches.push_back(&s63);
    switches.push_back(&s64);
    switches.push_back(&s65);
    switches.push_back(&s66);
    switches.push_back(&s67);
    switches.push_back(&s68);
    switches.push_back(&s69);
    switches.push_back(&s70);
    switches.push_back(&s71);
    switches.push_back(&s72);
    switches.push_back(&s73);
    switches.push_back(&s74);
    switches.push_back(&s75);
    switches.push_back(&s76);
    switches.push_back(&s77);
    switches.push_back(&s78);
    switches.push_back(&s79);
    switches.push_back(&s80);
    switches.push_back(&s81);
    switches.push_back(&s82);
    switches.push_back(&s83);
    switches.push_back(&s84);
    switches.push_back(&s85);
    switches.push_back(&s86);
    switches.push_back(&s87);
    switches.push_back(&s88);
    switches.push_back(&s89);
    switches.push_back(&s90);
    switches.push_back(&s91);
    switches.push_back(&s92);
*/



    f1.setNeighbors(0, &s1, 0, 0); // channel neighbors
    f3.setNeighbors(0, &s2, 0, 0);
    f5.setNeighbors(0, 0, 0, &s4);
    f7.setNeighbors(0, &s10, 0, 0);
    f9.setNeighbors(0, 0, 0, &s6);
    f11.setNeighbors(0, &s14, 0, 0);

    tg11.setNeighbors(0, 0, 0, &s3);
    tg9.setNeighbors(0, &s7, 0, 0);
    tg7.setNeighbors(0, &s11, 0, 0);
    tg5.setNeighbors(0, &s15, 0, 0);
    tg3.setNeighbors(0, &s22, 0, 0);
    tg1.setNeighbors(0, &s31, 0, 0);

    g1.setNeighbors(0, &s18, 0, 0);
    g3.setNeighbors(0, &s19, 0, 0);
    g5.setNeighbors(0, &s23, 0, 0);
    g7.setNeighbors(0, &s26, 0, 0);
    g9.setNeighbors(0, &s30, 0, 0);
    g11.setNeighbors(0, &s34, 0, 0);
    g13.setNeighbors(0, &s35, 0, 0);
    g15.setNeighbors(0, &s38, 0, 0);

    e1.setNeighbors(0, 0, 0, &s43);
    e3.setNeighbors(0, 0, 0, &s42);
    e5.setNeighbors(0, 0, 0, &s50);
    e7.setNeighbors(0, 0, 0, &s45);

    tb7.setNeighbors(0, 0, 0, &s46);
    tb9.setNeighbors(0, 0, 0, &s49);
    tb11.setNeighbors(0, 0, 0, &s39);

    // subgroup1 l, u, r, d
  /*
    c1.setNeighbors(0, 0, 0, &s89); // channel neighbors
    c3.setNeighbors(0, 0, 0, &s90);
    c5.setNeighbors(0, &s91, 0, 0);
    c7.setNeighbors(0, 0, 0, &s83);
    c9.setNeighbors(0, 0, 0, &s86);

    c11.setNeighbors(0, 0, 0, &s87);
    c13.setNeighbors(0, &s82, 0, 0);
    c15.setNeighbors(0, 0, 0, &s74);

    ta5.setNeighbors(0, 0, 0, &s75);
    ta7.setNeighbors(0, 0, 0, &s66);

    f13.setNeighbors(0, &s71, 0, 0);
    f15.setNeighbors(0, 0, 0, &s70);
    f17.setNeighbors(0, 0, 0, &s79);
    f19.setNeighbors(0, 0, 0, &s78);

    b1.setNeighbors(0, &s51, 0, 0); // channel neighbors
    b3.setNeighbors(0, &s52, 0, 0);
    b5.setNeighbors(0, &s55, 0, 0);
    b7.setNeighbors(0, &s59, 0, 0);
    b9.setNeighbors(0, &s62, 0, 0);
    b11.setNeighbors(0, &s63, 0, 0);
    b13.setNeighbors(0, 0, 0, &s58);
    b15.setNeighbors(0, 0, 0, &s67);

  */
    t42.setNeighbors(0, 0, 0, &s31); // amplifier neighbors
    t45.setNeighbors(0, 0, 0, &s23);
    t46.setNeighbors(0, 0, 0, &s35);
    t49.setNeighbors(0, 0, 0, &s19);
    t51.setNeighbors(0, 0, 0, &s15);
    t55.setNeighbors(0, &s50, 0, 0);
    t56.setNeighbors(0, &s49, 0, 0);
    t57.setNeighbors(0, &s45, 0, 0);
    t58.setNeighbors(0, &s46, 0, 0);
    t59.setNeighbors(0, 0, 0, &s38);
    t60.setNeighbors(0, &s42, 0, 0);
    t61.setNeighbors(0, 0, 0, &s34);
    t62.setNeighbors(0, 0, 0, &s30);
    t63.setNeighbors(0, 0, 0, &s26);
    t64.setNeighbors(0, 0, 0, &s22);
    t65.setNeighbors(0, 0, 0, &s18);
    t66.setNeighbors(0, 0, 0, &s14);
    t67.setNeighbors(0, 0, 0, &s10);
    t68.setNeighbors(0, &s6, 0, 0);
    t69.setNeighbors(0, 0, 0, &s2);
    t70.setNeighbors(0, 0, 0, &s1);
    t71.setNeighbors(0, &s3, 0, 0);
    t72.setNeighbors(0, &s4, 0, 0);

    // subgroup1  TO CHECK AGAIN
  /*
    t37.setNeighbors(0, &s66, 0, 0); // amp neighb sbg1
    t38.setNeighbors(0, 0, 0, &s91);
    t39.setNeighbors(0, &s89, 0, 0);
    t40.setNeighbors(0, &s86, 0, 0);
    t41.setNeighbors(0, 0, 0, &s82);
    t43.setNeighbors(0, &s74, 0, 0);
    t44.setNeighbors(0, &s78, 0, 0);
    t47.setNeighbors(0, 0, 0, &s62);
    t48.setNeighbors(0, &s70, 0, 0);
    t50.setNeighbors(0, &s58, 0, 0);
    t52.setNeighbors(0, 0, 0, &s51);
    t53.setNeighbors(0, 0, 0, &s55);
*/
    s1.setNeighbors(&s5, &t70, &s2, &f1); //switch neighbors
    s2.setNeighbors(&s1, &t69, &s8, &f3);
    s3.setNeighbors(&s9, &tg11, &s4, &t71);
    s4.setNeighbors(&s3, &f5, &s12, &t72);
    s5.setNeighbors(&s12, &s13, &s6, &s1);
    s6.setNeighbors(&s5, &f9, &s7, &t68);
    s7.setNeighbors(&s6, &s39, &s8, &tg9);
    s8.setNeighbors(&s7, &s16, &s9, &s2);
    s9.setNeighbors(&s8, &s17, &s10, &s3);
    s10.setNeighbors(&s9, &t67, &s11, &f7);
    s11.setNeighbors(&s10, &s43, &s12, &tg7);
    s12.setNeighbors(&s11, &s20, &s5, &s4);

    s13.setNeighbors(&s20, &s21, &s14, &s5);
    s14.setNeighbors(&s13, &t66, &s15, &f11);
    s15.setNeighbors(&s14, &t51, &s16, &tg5);
    s16.setNeighbors(&s15, &s24, &s17, &s8);
    s17.setNeighbors(&s16, &s25, &s18, &s9);
    s18.setNeighbors(&s17, &t65, &s19, &g1);
    s19.setNeighbors(&s18, &t49, &s20, &g3);
    s20.setNeighbors(&s19, &s28, &s13, &s12);

    s21.setNeighbors(&s28, &s29, &s22, &s13);
    s22.setNeighbors(&s21, &t64, &s23, &tg3);
    s23.setNeighbors(&s22, &t45, &s24, &g5);
    s24.setNeighbors(&s23, &s32, &s25, &s16);
    s25.setNeighbors(&s24, &s33, &s26, &s17);
    s26.setNeighbors(&s25, &t63, &s27, &g7);
    //s27.setNeighbors(&s26, &s71, &s28, &s79);
    s27.setNeighbors(&s26, 0, &s28, 0);
    s28.setNeighbors(&s27, &s36, &s21, &s20);

    s29.setNeighbors(&s36, &s37, &s30, &s21);
    s30.setNeighbors(&s29, &t62, &s31, &g9);
    s31.setNeighbors(&s30, &t42, &s32, &tg1);
    s32.setNeighbors(&s31, &s40, &s33, &s24);
    s33.setNeighbors(&s32, &s41, &s34, &s25);
    s34.setNeighbors(&s33, &t61, &s35, &g11);
    s35.setNeighbors(&s34, &t46, &s36, &g13);
    s36.setNeighbors(&s35, &s44, &s29, &s28);

    s37.setNeighbors(&s44, &s45, &s38, &s29);
    s38.setNeighbors(&s37, &t59, &s39, &g15);
    s39.setNeighbors(&s38, &tb11, &s40, &s7);
    s40.setNeighbors(&s39, &s47, &s41, &s32);
    s41.setNeighbors(&s40, &s48, &s42, &s33);
    s42.setNeighbors(&s41, &e3, &s43, &t60);
    s43.setNeighbors(&s42, &e1, &s44, &s11);
    s44.setNeighbors(&s43, &s50, &s37, &s36);

    s45.setNeighbors(&s37, &e7, &s46, &t57);
    s46.setNeighbors(&s45, &tb7, &s47, &t58);
    //s47.setNeighbors(&s46, &s53, &s48, &s40);
    //s48.setNeighbors(&s47, &s54, &s49, &s41);
    s47.setNeighbors(&s46, 0, &s48, &s40);
    s48.setNeighbors(&s47, 0, &s49, &s41);
    s49.setNeighbors(&s48, &tb9, &s50, &t56);
    s50.setNeighbors(&s49, &e5, &s44, &t55);

    // SUBGROUP 1
/*
    s51.setNeighbors(&s57, &t52, &s52, &b1); // SBG1 switch neighbors
    s52.setNeighbors(&s51, 0, &s53, &b3);
    s53.setNeighbors(&s52, &s60, &s54, &s47);
    s54.setNeighbors(&s53, &s61, &s55, &s48);
    s55.setNeighbors(&s54, &t53, &s56, &b5);
    s56.setNeighbors(&s55, 0, &s64, 0);

    s57.setNeighbors(&s64, &s65, &s66, &s51);
    s58.setNeighbors(&s57, &b13, &s59, &t50);
    s59.setNeighbors(&s58, &s83, &s60, &b7);
    s60.setNeighbors(&s59, &s68, &s61, &s53);
    s61.setNeighbors(&s60, &s69, &s62, &s54);
    s62.setNeighbors(&s61, &t47, &s63, &b9);
    s63.setNeighbors(&s62, &s87, &s64, &b11);
    s64.setNeighbors(&s63, &s72, &s57, &s56);

    s65.setNeighbors(&s72, &s73, &s66, &s57);
    s66.setNeighbors(&s65, &ta7, &s67, &t37);
    s67.setNeighbors(&s66, &b15, &s68, 0);
    s68.setNeighbors(&s67, &s76, &s69, &s60);
    s69.setNeighbors(&s68, &s77, &s70, &s61);
    s70.setNeighbors(&s69, &f15, &s71, &t48);
    s71.setNeighbors(&s70, &s27, &s72, &f13);
    s72.setNeighbors(&s71, &s80, &s65, &s64);

    s73.setNeighbors(&s80, &s81, &s74, &s65);
    s74.setNeighbors(&s73, &c15, &s75, &t43);
    s75.setNeighbors(&s74, &ta5, &s76, 0);
    s76.setNeighbors(&s75, &s84, &s77, &s68);
    s77.setNeighbors(&s76, &s85, &s78, &s69);
    s78.setNeighbors(&s77, &f19, &s79, &t44);
    s79.setNeighbors(&s78, &f17, &s80, &s27);
    s80.setNeighbors(&s79, &s88, &s73, &s72);

    s81.setNeighbors(&s88, &s89, &s82, &s73);
    s82.setNeighbors(&s81, &t41, &s83, &c13);
    s83.setNeighbors(&s82, &c7, &s84, &s59);
    s84.setNeighbors(&s83, &s90, &s85, &s76);
    s85.setNeighbors(&s84, &s91, &s86, &s77);
    s86.setNeighbors(&s85, &c9, &s87, &t40);
    s87.setNeighbors(&s86, &c11, &s88, &s63);
    s88.setNeighbors(&s87, &s92, &s81, &s80);

    s89.setNeighbors(&s81, &c1, &s90, &t39);
    s90.setNeighbors(&s89, &c3, &s84, 0);
    s91.setNeighbors(&s85, &t38, &s92, &c5);
    s92.setNeighbors(&s91, 0, &s88, 0);
*/
    Port *s1_port_l = new Port("s1_port_l");
    Port *s1_port_u = new Port("s1_port_u");
    Port *s1_port_r = new Port("s1_port_r");
    Port *s1_port_d = new Port("s1_port_d");
    s1.setPorts(s1_port_l, s1_port_u, s1_port_r, s1_port_d);
    Port *s2_port_l = new Port("s2_port_l");
    Port *s2_port_u = new Port("s2_port_u");
    Port *s2_port_r = new Port("s2_port_r");
    Port *s2_port_d = new Port("s2_port_d");
    s2.setPorts(s2_port_l, s2_port_u, s2_port_r, s2_port_d);
    Port *s3_port_l = new Port("s3_port_l");
    Port *s3_port_u = new Port("s3_port_u");
    Port *s3_port_r = new Port("s3_port_r");
    Port *s3_port_d = new Port("s3_port_d");
    s3.setPorts(s3_port_l, s3_port_u, s3_port_r, s3_port_d);
    Port *s4_port_l = new Port("s4_port_l");
    Port *s4_port_u = new Port("s4_port_u");
    Port *s4_port_r = new Port("s4_port_r");
    Port *s4_port_d = new Port("s4_port_d");
    s4.setPorts(s4_port_l, s4_port_u, s4_port_r, s4_port_d);
    Port *s5_port_l = new Port("s5_port_l");
    Port *s5_port_u = new Port("s5_port_u");
    Port *s5_port_r = new Port("s5_port_r");
    Port *s5_port_d = new Port("s5_port_d");
    s5.setPorts(s5_port_l, s5_port_u, s5_port_r, s5_port_d);
    Port *s6_port_l = new Port("s6_port_l");
    Port *s6_port_u = new Port("s6_port_u");
    Port *s6_port_r = new Port("s6_port_r");
    Port *s6_port_d = new Port("s6_port_d");
    s6.setPorts(s6_port_l, s6_port_u, s6_port_r, s6_port_d);
    Port *s7_port_l = new Port("s7_port_l");
    Port *s7_port_u = new Port("s7_port_u");
    Port *s7_port_r = new Port("s7_port_r");
    Port *s7_port_d = new Port("s7_port_d");
    s7.setPorts(s7_port_l, s7_port_u, s7_port_r, s7_port_d);
    Port *s8_port_l = new Port("s8_port_l");
    Port *s8_port_u = new Port("s8_port_u");
    Port *s8_port_r = new Port("s8_port_r");
    Port *s8_port_d = new Port("s8_port_d");
    s8.setPorts(s8_port_l, s8_port_u, s8_port_r, s8_port_d);
    Port *s9_port_l = new Port("s9_port_l");
    Port *s9_port_u = new Port("s9_port_u");
    Port *s9_port_r = new Port("s9_port_r");
    Port *s9_port_d = new Port("s9_port_d");
    s9.setPorts(s9_port_l, s9_port_u, s9_port_r, s9_port_d);
    Port *s10_port_l = new Port("s10_port_l");
    Port *s10_port_u = new Port("s10_port_u");
    Port *s10_port_r = new Port("s10_port_r");
    Port *s10_port_d = new Port("s10_port_d");
    s10.setPorts(s10_port_l, s10_port_u, s10_port_r, s10_port_d);
    Port *s11_port_l = new Port("s11_port_l");
    Port *s11_port_u = new Port("s11_port_u");
    Port *s11_port_r = new Port("s11_port_r");
    Port *s11_port_d = new Port("s11_port_d");
    s11.setPorts(s11_port_l, s11_port_u, s11_port_r, s11_port_d);
    Port *s12_port_l = new Port("s12_port_l");
    Port *s12_port_u = new Port("s12_port_u");
    Port *s12_port_r = new Port("s12_port_r");
    Port *s12_port_d = new Port("s12_port_d");
    s12.setPorts(s12_port_l, s12_port_u, s12_port_r, s12_port_d);
    Port *s13_port_l = new Port("s13_port_l");
    Port *s13_port_u = new Port("s13_port_u");
    Port *s13_port_r = new Port("s13_port_r");
    Port *s13_port_d = new Port("s13_port_d");
    s13.setPorts(s13_port_l, s13_port_u, s13_port_r, s13_port_d);
    Port *s14_port_l = new Port("s14_port_l");
    Port *s14_port_u = new Port("s14_port_u");
    Port *s14_port_r = new Port("s14_port_r");
    Port *s14_port_d = new Port("s14_port_d");
    s14.setPorts(s14_port_l, s14_port_u, s14_port_r, s14_port_d);
    Port *s15_port_l = new Port("s15_port_l");
    Port *s15_port_u = new Port("s15_port_u");
    Port *s15_port_r = new Port("s15_port_r");
    Port *s15_port_d = new Port("s15_port_d");
    s15.setPorts(s15_port_l, s15_port_u, s15_port_r, s15_port_d);
    Port *s16_port_l = new Port("s16_port_l");
    Port *s16_port_u = new Port("s16_port_u");
    Port *s16_port_r = new Port("s16_port_r");
    Port *s16_port_d = new Port("s16_port_d");
    s16.setPorts(s16_port_l, s16_port_u, s16_port_r, s16_port_d);
    Port *s17_port_l = new Port("s17_port_l");
    Port *s17_port_u = new Port("s17_port_u");
    Port *s17_port_r = new Port("s17_port_r");
    Port *s17_port_d = new Port("s17_port_d");
    s17.setPorts(s17_port_l, s17_port_u, s17_port_r, s17_port_d);
    Port *s18_port_l = new Port("s18_port_l");
    Port *s18_port_u = new Port("s18_port_u");
    Port *s18_port_r = new Port("s18_port_r");
    Port *s18_port_d = new Port("s18_port_d");
    s18.setPorts(s18_port_l, s18_port_u, s18_port_r, s18_port_d);
    Port *s19_port_l = new Port("s19_port_l");
    Port *s19_port_u = new Port("s19_port_u");
    Port *s19_port_r = new Port("s19_port_r");
    Port *s19_port_d = new Port("s19_port_d");
    s19.setPorts(s19_port_l, s19_port_u, s19_port_r, s19_port_d);
    Port *s20_port_l = new Port("s20_port_l");
    Port *s20_port_u = new Port("s20_port_u");
    Port *s20_port_r = new Port("s20_port_r");
    Port *s20_port_d = new Port("s20_port_d");
    s20.setPorts(s20_port_l, s20_port_u, s20_port_r, s20_port_d);
    Port *s21_port_l = new Port("s21_port_l");
    Port *s21_port_u = new Port("s21_port_u");
    Port *s21_port_r = new Port("s21_port_r");
    Port *s21_port_d = new Port("s21_port_d");
    s21.setPorts(s21_port_l, s21_port_u, s21_port_r, s21_port_d);
    Port *s22_port_l = new Port("s22_port_l");
    Port *s22_port_u = new Port("s22_port_u");
    Port *s22_port_r = new Port("s22_port_r");
    Port *s22_port_d = new Port("s22_port_d");
    s22.setPorts(s22_port_l, s22_port_u, s22_port_r, s22_port_d);
    Port *s23_port_l = new Port("s23_port_l");
    Port *s23_port_u = new Port("s23_port_u");
    Port *s23_port_r = new Port("s23_port_r");
    Port *s23_port_d = new Port("s23_port_d");
    s23.setPorts(s23_port_l, s23_port_u, s23_port_r, s23_port_d);
    Port *s24_port_l = new Port("s24_port_l");
    Port *s24_port_u = new Port("s24_port_u");
    Port *s24_port_r = new Port("s24_port_r");
    Port *s24_port_d = new Port("s24_port_d");
    s24.setPorts(s24_port_l, s24_port_u, s24_port_r, s24_port_d);
    Port *s25_port_l = new Port("s25_port_l");
    Port *s25_port_u = new Port("s25_port_u");
    Port *s25_port_r = new Port("s25_port_r");
    Port *s25_port_d = new Port("s25_port_d");
    s25.setPorts(s25_port_l, s25_port_u, s25_port_r, s25_port_d);
    Port *s26_port_l = new Port("s26_port_l");
    Port *s26_port_u = new Port("s26_port_u");
    Port *s26_port_r = new Port("s26_port_r");
    Port *s26_port_d = new Port("s26_port_d");
    s26.setPorts(s26_port_l, s26_port_u, s26_port_r, s26_port_d);
    Port *s27_port_l = new Port("s27_port_l");
    Port *s27_port_u = new Port("s27_port_u");
    Port *s27_port_r = new Port("s27_port_r");
    Port *s27_port_d = new Port("s27_port_d");
    s27.setPorts(s27_port_l, s27_port_u, s27_port_r, s27_port_d);
    Port *s28_port_l = new Port("s28_port_l");
    Port *s28_port_u = new Port("s28_port_u");
    Port *s28_port_r = new Port("s28_port_r");
    Port *s28_port_d = new Port("s28_port_d");
    s28.setPorts(s28_port_l, s28_port_u, s28_port_r, s28_port_d);
    Port *s29_port_l = new Port("s29_port_l");
    Port *s29_port_u = new Port("s29_port_u");
    Port *s29_port_r = new Port("s29_port_r");
    Port *s29_port_d = new Port("s29_port_d");
    s29.setPorts(s29_port_l, s29_port_u, s29_port_r, s29_port_d);
    Port *s30_port_l = new Port("s30_port_l");
    Port *s30_port_u = new Port("s30_port_u");
    Port *s30_port_r = new Port("s30_port_r");
    Port *s30_port_d = new Port("s30_port_d");
    s30.setPorts(s30_port_l, s30_port_u, s30_port_r, s30_port_d);
    Port *s31_port_l = new Port("s31_port_l");
    Port *s31_port_u = new Port("s31_port_u");
    Port *s31_port_r = new Port("s31_port_r");
    Port *s31_port_d = new Port("s31_port_d");
    s31.setPorts(s31_port_l, s31_port_u, s31_port_r, s31_port_d);
    Port *s32_port_l = new Port("s32_port_l");
    Port *s32_port_u = new Port("s32_port_u");
    Port *s32_port_r = new Port("s32_port_r");
    Port *s32_port_d = new Port("s32_port_d");
    s32.setPorts(s32_port_l, s32_port_u, s32_port_r, s32_port_d);
    Port *s33_port_l = new Port("s33_port_l");
    Port *s33_port_u = new Port("s33_port_u");
    Port *s33_port_r = new Port("s33_port_r");
    Port *s33_port_d = new Port("s33_port_d");
    s33.setPorts(s33_port_l, s33_port_u, s33_port_r, s33_port_d);
    Port *s34_port_l = new Port("s34_port_l");
    Port *s34_port_u = new Port("s34_port_u");
    Port *s34_port_r = new Port("s34_port_r");
    Port *s34_port_d = new Port("s34_port_d");
    s34.setPorts(s34_port_l, s34_port_u, s34_port_r, s34_port_d);
    Port *s35_port_l = new Port("s35_port_l");
    Port *s35_port_u = new Port("s35_port_u");
    Port *s35_port_r = new Port("s35_port_r");
    Port *s35_port_d = new Port("s35_port_d");
    s35.setPorts(s35_port_l, s35_port_u, s35_port_r, s35_port_d);
    Port *s36_port_l = new Port("s36_port_l");
    Port *s36_port_u = new Port("s36_port_u");
    Port *s36_port_r = new Port("s36_port_r");
    Port *s36_port_d = new Port("s36_port_d");
    s36.setPorts(s36_port_l, s36_port_u, s36_port_r, s36_port_d);
    Port *s37_port_l = new Port("s37_port_l");
    Port *s37_port_u = new Port("s37_port_u");
    Port *s37_port_r = new Port("s37_port_r");
    Port *s37_port_d = new Port("s37_port_d");
    s37.setPorts(s37_port_l, s37_port_u, s37_port_r, s37_port_d);
    Port *s38_port_l = new Port("s38_port_l");
    Port *s38_port_u = new Port("s38_port_u");
    Port *s38_port_r = new Port("s38_port_r");
    Port *s38_port_d = new Port("s38_port_d");
    s38.setPorts(s38_port_l, s38_port_u, s38_port_r, s38_port_d);
    Port *s39_port_l = new Port("s29_port_l");
    Port *s39_port_u = new Port("s29_port_u");
    Port *s39_port_r = new Port("s29_port_r");
    Port *s39_port_d = new Port("s29_port_d");
    s39.setPorts(s39_port_l, s39_port_u, s39_port_r, s39_port_d);
    Port *s40_port_l = new Port("s40_port_l");
    Port *s40_port_u = new Port("s40_port_u");
    Port *s40_port_r = new Port("s40_port_r");
    Port *s40_port_d = new Port("s40_port_d");
    s40.setPorts(s40_port_l, s40_port_u, s40_port_r, s40_port_d);
    Port *s41_port_l = new Port("s41_port_l");
    Port *s41_port_u = new Port("s41_port_u");
    Port *s41_port_r = new Port("s41_port_r");
    Port *s41_port_d = new Port("s41_port_d");
    s41.setPorts(s41_port_l, s41_port_u, s41_port_r, s41_port_d);
    Port *s42_port_l = new Port("s42_port_l");
    Port *s42_port_u = new Port("s42_port_u");
    Port *s42_port_r = new Port("s42_port_r");
    Port *s42_port_d = new Port("s42_port_d");
    s42.setPorts(s42_port_l, s42_port_u, s42_port_r, s42_port_d);
    Port *s43_port_l = new Port("s43_port_l");
    Port *s43_port_u = new Port("s43_port_u");
    Port *s43_port_r = new Port("s43_port_r");
    Port *s43_port_d = new Port("s43_port_d");
    s43.setPorts(s43_port_l, s43_port_u, s43_port_r, s43_port_d);
    Port *s44_port_l = new Port("s44_port_l");
    Port *s44_port_u = new Port("s44_port_u");
    Port *s44_port_r = new Port("s44_port_r");
    Port *s44_port_d = new Port("s44_port_d");
    s44.setPorts(s44_port_l, s44_port_u, s44_port_r, s44_port_d);
    Port *s45_port_l = new Port("s45_port_l");
    Port *s45_port_u = new Port("s45_port_u");
    Port *s45_port_r = new Port("s45_port_r");
    Port *s45_port_d = new Port("s45_port_d");
    s45.setPorts(s45_port_l, s45_port_u, s45_port_r, s45_port_d);
    Port *s46_port_l = new Port("s46_port_l");
    Port *s46_port_u = new Port("s46_port_u");
    Port *s46_port_r = new Port("s46_port_r");
    Port *s46_port_d = new Port("s46_port_d");
    s46.setPorts(s46_port_l, s46_port_u, s46_port_r, s46_port_d);
    Port *s47_port_l = new Port("s47_port_l");
    Port *s47_port_u = new Port("s47_port_u");
    Port *s47_port_r = new Port("s47_port_r");
    Port *s47_port_d = new Port("s47_port_d");
    s47.setPorts(s47_port_l, s47_port_u, s47_port_r, s47_port_d);
    Port *s48_port_l = new Port("s48_port_l");
    Port *s48_port_u = new Port("s48_port_u");
    Port *s48_port_r = new Port("s48_port_r");
    Port *s48_port_d = new Port("s48_port_d");
    s48.setPorts(s48_port_l, s48_port_u, s48_port_r, s48_port_d);
    Port *s49_port_l = new Port("s49_port_l");
    Port *s49_port_u = new Port("s49_port_u");
    Port *s49_port_r = new Port("s49_port_r");
    Port *s49_port_d = new Port("s49_port_d");
    s49.setPorts(s49_port_l, s49_port_u, s49_port_r, s49_port_d);
    Port *s50_port_l = new Port("s50_port_l");
    Port *s50_port_u = new Port("s50_port_u");
    Port *s50_port_r = new Port("s50_port_r");
    Port *s50_port_d = new Port("s50_port_d");
    s50.setPorts(s50_port_l, s50_port_u, s50_port_r, s50_port_d);

     /*
    Port *s51_port_l = new Port("s51_port_l");
    Port *s51_port_u = new Port("s51_port_u");
    Port *s51_port_r = new Port("s51_port_r");
    Port *s51_port_d = new Port("s51_port_d");
    s51.setPorts(s51_port_l, s51_port_u, s51_port_r, s51_port_d);
    Port *s52_port_l = new Port("s52_port_l");
    Port *s52_port_u = new Port("s52_port_u");
    Port *s52_port_r = new Port("s52_port_r");
    Port *s52_port_d = new Port("s52_port_d");
    s52.setPorts(s52_port_l, s52_port_u, s52_port_r, s52_port_d);
    Port *s53_port_l = new Port("s53_port_l");
    Port *s53_port_u = new Port("s53_port_u");
    Port *s53_port_r = new Port("s53_port_r");
    Port *s53_port_d = new Port("s53_port_d");
    s53.setPorts(s53_port_l, s53_port_u, s53_port_r, s53_port_d);
    Port *s54_port_l = new Port("s54_port_l");
    Port *s54_port_u = new Port("s54_port_u");
    Port *s54_port_r = new Port("s54_port_r");
    Port *s54_port_d = new Port("s54_port_d");
    s54.setPorts(s54_port_l, s54_port_u, s54_port_r, s54_port_d);
    Port *s55_port_l = new Port("s55_port_l");
    Port *s55_port_u = new Port("s55_port_u");
    Port *s55_port_r = new Port("s55_port_r");
    Port *s55_port_d = new Port("s55_port_d");
    s55.setPorts(s55_port_l, s55_port_u, s55_port_r, s55_port_d);
    Port *s56_port_l = new Port("s56_port_l");
    Port *s56_port_u = new Port("s56_port_u");
    Port *s56_port_r = new Port("s56_port_r");
    Port *s56_port_d = new Port("s56_port_d");
    s56.setPorts(s56_port_l, s56_port_u, s56_port_r, s56_port_d);
    Port *s57_port_l = new Port("s57_port_l");
    Port *s57_port_u = new Port("s57_port_u");
    Port *s57_port_r = new Port("s57_port_r");
    Port *s57_port_d = new Port("s57_port_d");
    s57.setPorts(s57_port_l, s57_port_u, s57_port_r, s57_port_d);
    Port *s58_port_l = new Port("s58_port_l");
    Port *s58_port_u = new Port("s58_port_u");
    Port *s58_port_r = new Port("s58_port_r");
    Port *s58_port_d = new Port("s58_port_d");
    s58.setPorts(s58_port_l, s58_port_u, s58_port_r, s58_port_d);
    Port *s59_port_l = new Port("s29_port_l");
    Port *s59_port_u = new Port("s29_port_u");
    Port *s59_port_r = new Port("s29_port_r");
    Port *s59_port_d = new Port("s29_port_d");
    s59.setPorts(s59_port_l, s59_port_u, s59_port_r, s59_port_d);
    Port *s60_port_l = new Port("s60_port_l");
    Port *s60_port_u = new Port("s60_port_u");
    Port *s60_port_r = new Port("s60_port_r");
    Port *s60_port_d = new Port("s60_port_d");
    s60.setPorts(s60_port_l, s60_port_u, s60_port_r, s60_port_d);

    Port *s61_port_l = new Port("s61_port_l");
    Port *s61_port_u = new Port("s61_port_u");
    Port *s61_port_r = new Port("s61_port_r");
    Port *s61_port_d = new Port("s61_port_d");
    s61.setPorts(s61_port_l, s61_port_u, s61_port_r, s61_port_d);
    Port *s62_port_l = new Port("s62_port_l");
    Port *s62_port_u = new Port("s62_port_u");
    Port *s62_port_r = new Port("s62_port_r");
    Port *s62_port_d = new Port("s62_port_d");
    s62.setPorts(s62_port_l, s62_port_u, s62_port_r, s62_port_d);
    Port *s63_port_l = new Port("s63_port_l");
    Port *s63_port_u = new Port("s63_port_u");
    Port *s63_port_r = new Port("s63_port_r");
    Port *s63_port_d = new Port("s63_port_d");
    s63.setPorts(s63_port_l, s63_port_u, s63_port_r, s63_port_d);
    Port *s64_port_l = new Port("s64_port_l");
    Port *s64_port_u = new Port("s64_port_u");
    Port *s64_port_r = new Port("s64_port_r");
    Port *s64_port_d = new Port("s64_port_d");
    s64.setPorts(s64_port_l, s64_port_u, s64_port_r, s64_port_d);
    Port *s65_port_l = new Port("s65_port_l");
    Port *s65_port_u = new Port("s65_port_u");
    Port *s65_port_r = new Port("s65_port_r");
    Port *s65_port_d = new Port("s65_port_d");
    s65.setPorts(s65_port_l, s65_port_u, s65_port_r, s65_port_d);
    Port *s66_port_l = new Port("s66_port_l");
    Port *s66_port_u = new Port("s66_port_u");
    Port *s66_port_r = new Port("s66_port_r");
    Port *s66_port_d = new Port("s66_port_d");
    s66.setPorts(s66_port_l, s66_port_u, s66_port_r, s66_port_d);
    Port *s67_port_l = new Port("s67_port_l");
    Port *s67_port_u = new Port("s67_port_u");
    Port *s67_port_r = new Port("s67_port_r");
    Port *s67_port_d = new Port("s67_port_d");
    s67.setPorts(s67_port_l, s67_port_u, s67_port_r, s67_port_d);
    Port *s68_port_l = new Port("s68_port_l");
    Port *s68_port_u = new Port("s68_port_u");
    Port *s68_port_r = new Port("s68_port_r");
    Port *s68_port_d = new Port("s68_port_d");
    s68.setPorts(s68_port_l, s68_port_u, s68_port_r, s68_port_d);
    Port *s69_port_l = new Port("s29_port_l");
    Port *s69_port_u = new Port("s29_port_u");
    Port *s69_port_r = new Port("s29_port_r");
    Port *s69_port_d = new Port("s29_port_d");
    s69.setPorts(s69_port_l, s69_port_u, s69_port_r, s69_port_d);
    Port *s70_port_l = new Port("s70_port_l");
    Port *s70_port_u = new Port("s70_port_u");
    Port *s70_port_r = new Port("s70_port_r");
    Port *s70_port_d = new Port("s70_port_d");
    s70.setPorts(s70_port_l, s70_port_u, s70_port_r, s70_port_d);

    Port *s71_port_l = new Port("s71_port_l");
    Port *s71_port_u = new Port("s71_port_u");
    Port *s71_port_r = new Port("s71_port_r");
    Port *s71_port_d = new Port("s71_port_d");
    s71.setPorts(s71_port_l, s71_port_u, s71_port_r, s71_port_d);
    Port *s72_port_l = new Port("s72_port_l");
    Port *s72_port_u = new Port("s72_port_u");
    Port *s72_port_r = new Port("s72_port_r");
    Port *s72_port_d = new Port("s72_port_d");
    s72.setPorts(s72_port_l, s72_port_u, s72_port_r, s72_port_d);
    Port *s73_port_l = new Port("s73_port_l");
    Port *s73_port_u = new Port("s73_port_u");
    Port *s73_port_r = new Port("s73_port_r");
    Port *s73_port_d = new Port("s73_port_d");
    s73.setPorts(s73_port_l, s73_port_u, s73_port_r, s73_port_d);
    Port *s74_port_l = new Port("s74_port_l");
    Port *s74_port_u = new Port("s74_port_u");
    Port *s74_port_r = new Port("s74_port_r");
    Port *s74_port_d = new Port("s74_port_d");
    s74.setPorts(s74_port_l, s74_port_u, s74_port_r, s74_port_d);
    Port *s75_port_l = new Port("s75_port_l");
    Port *s75_port_u = new Port("s75_port_u");
    Port *s75_port_r = new Port("s75_port_r");
    Port *s75_port_d = new Port("s75_port_d");
    s75.setPorts(s75_port_l, s75_port_u, s75_port_r, s75_port_d);
    Port *s76_port_l = new Port("s76_port_l");
    Port *s76_port_u = new Port("s76_port_u");
    Port *s76_port_r = new Port("s76_port_r");
    Port *s76_port_d = new Port("s76_port_d");
    s76.setPorts(s76_port_l, s76_port_u, s76_port_r, s76_port_d);
    Port *s77_port_l = new Port("s77_port_l");
    Port *s77_port_u = new Port("s77_port_u");
    Port *s77_port_r = new Port("s77_port_r");
    Port *s77_port_d = new Port("s77_port_d");
    s77.setPorts(s77_port_l, s77_port_u, s77_port_r, s77_port_d);
    Port *s78_port_l = new Port("s78_port_l");
    Port *s78_port_u = new Port("s78_port_u");
    Port *s78_port_r = new Port("s78_port_r");
    Port *s78_port_d = new Port("s78_port_d");
    s78.setPorts(s78_port_l, s78_port_u, s78_port_r, s78_port_d);
    Port *s79_port_l = new Port("s29_port_l");
    Port *s79_port_u = new Port("s29_port_u");
    Port *s79_port_r = new Port("s29_port_r");
    Port *s79_port_d = new Port("s29_port_d");
    s79.setPorts(s79_port_l, s79_port_u, s79_port_r, s79_port_d);
    Port *s80_port_l = new Port("s80_port_l");
    Port *s80_port_u = new Port("s80_port_u");
    Port *s80_port_r = new Port("s80_port_r");
    Port *s80_port_d = new Port("s80_port_d");
    s80.setPorts(s80_port_l, s80_port_u, s80_port_r, s80_port_d);

    Port *s81_port_l = new Port("s81_port_l");
    Port *s81_port_u = new Port("s81_port_u");
    Port *s81_port_r = new Port("s81_port_r");
    Port *s81_port_d = new Port("s81_port_d");
    s81.setPorts(s81_port_l, s81_port_u, s81_port_r, s81_port_d);
    Port *s82_port_l = new Port("s82_port_l");
    Port *s82_port_u = new Port("s82_port_u");
    Port *s82_port_r = new Port("s82_port_r");
    Port *s82_port_d = new Port("s82_port_d");
    s82.setPorts(s82_port_l, s82_port_u, s82_port_r, s82_port_d);
    Port *s83_port_l = new Port("s83_port_l");
    Port *s83_port_u = new Port("s83_port_u");
    Port *s83_port_r = new Port("s83_port_r");
    Port *s83_port_d = new Port("s83_port_d");
    s83.setPorts(s83_port_l, s83_port_u, s83_port_r, s83_port_d);
    Port *s84_port_l = new Port("s84_port_l");
    Port *s84_port_u = new Port("s84_port_u");
    Port *s84_port_r = new Port("s84_port_r");
    Port *s84_port_d = new Port("s84_port_d");
    s84.setPorts(s84_port_l, s84_port_u, s84_port_r, s84_port_d);
    Port *s85_port_l = new Port("s85_port_l");
    Port *s85_port_u = new Port("s85_port_u");
    Port *s85_port_r = new Port("s85_port_r");
    Port *s85_port_d = new Port("s85_port_d");
    s85.setPorts(s85_port_l, s85_port_u, s85_port_r, s85_port_d);
    Port *s86_port_l = new Port("s86_port_l");
    Port *s86_port_u = new Port("s86_port_u");
    Port *s86_port_r = new Port("s86_port_r");
    Port *s86_port_d = new Port("s86_port_d");
    s86.setPorts(s86_port_l, s86_port_u, s86_port_r, s86_port_d);
    Port *s87_port_l = new Port("s87_port_l");
    Port *s87_port_u = new Port("s87_port_u");
    Port *s87_port_r = new Port("s87_port_r");
    Port *s87_port_d = new Port("s87_port_d");
    s87.setPorts(s87_port_l, s87_port_u, s87_port_r, s87_port_d);
    Port *s88_port_l = new Port("s88_port_l");
    Port *s88_port_u = new Port("s88_port_u");
    Port *s88_port_r = new Port("s88_port_r");
    Port *s88_port_d = new Port("s88_port_d");
    s88.setPorts(s88_port_l, s88_port_u, s88_port_r, s88_port_d);
    Port *s89_port_l = new Port("s29_port_l");
    Port *s89_port_u = new Port("s29_port_u");
    Port *s89_port_r = new Port("s29_port_r");
    Port *s89_port_d = new Port("s29_port_d");
    s89.setPorts(s89_port_l, s89_port_u, s89_port_r, s89_port_d);
    Port *s90_port_l = new Port("s90_port_l");
    Port *s90_port_u = new Port("s90_port_u");
    Port *s90_port_r = new Port("s90_port_r");
    Port *s90_port_d = new Port("s90_port_d");
    s90.setPorts(s90_port_l, s90_port_u, s90_port_r, s90_port_d);
    Port *s91_port_l = new Port("s91_port_l");
    Port *s91_port_u = new Port("s91_port_u");
    Port *s91_port_r = new Port("s91_port_r");
    Port *s91_port_d = new Port("s91_port_d");
    s91.setPorts(s91_port_l, s91_port_u, s91_port_r, s91_port_d);
    Port *s92_port_l = new Port("s92_port_l");
    Port *s92_port_u = new Port("s92_port_u");
    Port *s92_port_r = new Port("s92_port_r");
    Port *s92_port_d = new Port("s92_port_d");
    s92.setPorts(s92_port_l, s92_port_u, s92_port_r, s92_port_d);
*/
    testex.push_back(&s1);
    testex.push_back(&s2);
    testex.push_back(&s3);
    testex.push_back(&s4);
    testex.push_back(&s5);
    testex.push_back(&s6);
    testex.push_back(&s7);
    testex.push_back(&s8);
    testex.push_back(&s9);
    testex.push_back(&s10);
    testex.push_back(&s11);
    testex.push_back(&s12);

    testex.push_back(&s13);
    testex.push_back(&s14);
    testex.push_back(&s15);
    testex.push_back(&s16);
    testex.push_back(&s17);
    testex.push_back(&s18);
    testex.push_back(&s19);
    testex.push_back(&s20);
    testex.push_back(&s21);
    testex.push_back(&s22);
    testex.push_back(&s23);
    testex.push_back(&s24);

    testex.push_back(&s25);
    testex.push_back(&s26);
    testex.push_back(&s27);
    testex.push_back(&s28);
    testex.push_back(&s29);
    testex.push_back(&s30);
    testex.push_back(&s31);
    testex.push_back(&s32);
    testex.push_back(&s33);
    testex.push_back(&s34);
    testex.push_back(&s35);
    testex.push_back(&s36);

    testex.push_back(&s37);
    testex.push_back(&s38);
    testex.push_back(&s39);
    testex.push_back(&s40);
    testex.push_back(&s41);
    testex.push_back(&s42);
    testex.push_back(&s43);
    testex.push_back(&s44);
    testex.push_back(&s45);
    testex.push_back(&s46);
    testex.push_back(&s47);
    testex.push_back(&s48);
    testex.push_back(&s49);
    testex.push_back(&s50);
/*
    testex.push_back(&s51);
    testex.push_back(&s52);
    testex.push_back(&s53);
    testex.push_back(&s54);
    testex.push_back(&s55);
    testex.push_back(&s56);
    testex.push_back(&s57);
    testex.push_back(&s58);
    testex.push_back(&s59);
    testex.push_back(&s60);
    testex.push_back(&s61);
    testex.push_back(&s62);

    testex.push_back(&s63);
    testex.push_back(&s64);
    testex.push_back(&s65);
    testex.push_back(&s66);
    testex.push_back(&s67);
    testex.push_back(&s68);
    testex.push_back(&s69);
    testex.push_back(&s70);
    testex.push_back(&s71);
    testex.push_back(&s72);
    testex.push_back(&s73);
    testex.push_back(&s74);

    testex.push_back(&s75);
    testex.push_back(&s76);
    testex.push_back(&s77);
    testex.push_back(&s78);
    testex.push_back(&s79);
    testex.push_back(&s80);
    testex.push_back(&s81);
    testex.push_back(&s82);
    testex.push_back(&s83);
    testex.push_back(&s84);
    testex.push_back(&s85);
    testex.push_back(&s86);

    testex.push_back(&s87);
    testex.push_back(&s88);
    testex.push_back(&s89);
    testex.push_back(&s90);
    testex.push_back(&s91);
    testex.push_back(&s92);
*/
    for (std::vector<int>::size_type r = 0; r < position_vector.size(); r++) {
        testex[r]->setPos(position_vector[r]);
    }

    //int min_distance = 100;
    //int up_distance;
    //int right_distance;
    //int down_distance;
    //int x = 1;

    //Node* prec = 0;
    //Node* nextNode = 0;

    vector<Node*> source_init;
    vector<Node*> destination_init;

    vector<Node*> channels_to_test_path;

    testex.push_back(&f1);
    testex.push_back(&f3);
    testex.push_back(&f5);
    testex.push_back(&f7);
    testex.push_back(&f9);
    testex.push_back(&f11);
    testex.push_back(&g1);
    testex.push_back(&g3);
    testex.push_back(&g5);
    testex.push_back(&g7);
    testex.push_back(&g9);
    testex.push_back(&g11);
    testex.push_back(&g13);
    testex.push_back(&g15);
    testex.push_back(&e1);
    testex.push_back(&e3);
    testex.push_back(&e5);
    testex.push_back(&e7);
    testex.push_back(&tb7);
    testex.push_back(&tb9);
    testex.push_back(&tb11);
    testex.push_back(&tg1);
    testex.push_back(&tg3);
    testex.push_back(&tg5);
    testex.push_back(&tg7);
    testex.push_back(&tg9);
    testex.push_back(&tg11);

    createGraph(testex);
    for (std::vector<string>::size_type r = 0; r < chan_instance.size(); r++) {
        for (std::vector<Node*>::size_type j = 0; j < channels.size(); j++) {
            if (chan_instance[r] == channels[j]->getName()) {
                channels_to_test_path.push_back(channels[j]);
                break;
            }
        }
    }


    vector<int> vv;
    int ConstructedPaths=0;//No of paths that has been created
    int LongestPathLenght=0;
    for (std::vector<Node*>::size_type y = 0; y < channels_to_test_path.size(); y++) {
        vv = existsPathInGraph(channels_to_test_path[y]);
        int path = vv[0];
        int length = vv[1];
        ConstructedPaths = ConstructedPaths + path;

        if (length > LongestPathLenght) {
            LongestPathLenght = length;
        }
    }
    if(ConstructedPaths==0)
        LongestPathLenght=1000;

#ifdef DEBUG_ALL

    cout << "Constructed paths: " << ConstructedPaths
            << ". Total number of used switches: " << fitness2
            << ". Longest Path length: " << LongestPathLenght << endl;

#endif
    int qualityMetric=1;//I think its better to call this value as quality metric
    vector<int> result;

    if (ConstructedPaths != channels_to_test_path.size()) {
        qualityMetric=((channels_to_test_path.size() - ConstructedPaths) * 100)+LongestPathLenght;
    }
    else {
        qualityMetric=LongestPathLenght;
    }
    result.push_back(qualityMetric);
    result.push_back(ConstructedPaths);
    result.push_back(LongestPathLenght);

    /////////////////////////

    //path.;


    //switches; //list of all switches
    //amplifiers; //list of all amps
    //channels; //list of all channels
    source_init.~vector();
    destination_init.~vector();

    channels_to_test_path.~vector();
    testex.~vector();
    /////////////////////////
       for (std::vector<Node*>::size_type y = 0; y < switches.size(); y++) {
           switches[y]->~Node();
        }
        for (std::vector<Node*>::size_type y = 0; y < amplifiers.size(); y++) {
           amplifiers[y]->~Node();
        }
       for (std::vector<Node*>::size_type y = 0; y < channels.size(); y++) {
           channels[y]->~Node();
       }

    return result;
}
