/* 
 * File:   Payload.h
 * Author: snjix
 *
 * Created on June 15, 2013, 5:05 PM
 */

#ifndef PAYLOAD_H
#define	PAYLOAD_H

#include <vector>
#include "Port.h"
#include "PrIns.h"
#include "Node.h"

class Payload {
    
    
    Node *f1;
    Node *f3;
    Node *f5;
    Node *f7;
    Node *f9;
    Node *f11;
    Node *g1;//("G1", "channel", 5, 6);
    Node *g3;//("G3", "channel", 6, 6);
    Node *g5;//("G5", "channel", 2, 9);
    Node *g7;//("G7", "channel", 5, 9);
    Node *g9;//("G9", "channel", 1, 12);
    Node *g11;//("G11", "channel", 5, 12);
    Node *g13;//("G13", "channel", 6, 12);
    Node *g15;//("G15", "channel", 1, 15);

    Node *e1;//("E1", "channel", 5, 17);
    Node *e3;//("E3", "channel", 4, 17);
    Node *e5;//("E5", "channel", 6, 20);
    Node *e7;

    Node *tb7;
    Node *tb9;
    Node *tb11;

    Node *tg1;
    Node *tg3;
    Node *tg5;
    Node *tg7;
    Node *tg9;
    Node *tg11;
    
    Node *t42;//("T42", "amplifier", 2, 14);
    Node *t45;//("T45", "amplifier", 2, 11);
    Node *t46;//("T46", "amplifier", 6, 14);
    Node *t49;//("T49", "amplifier", 6, 8);
    Node *t51;//("T51", "amplifier", 2, 8);
    Node *t55;//("T55", "amplifier", 6, 18);
    Node *t56;//("T56", "amplifier", 5, 18);
    Node *t57;//("T57", "amplifier", 1, 18);
    Node *t58;//("T58", "amplifier", 2, 18);
    Node *t59;//("T59", "amplifier", 1, 17);
    Node *t60;//("T60", "amplifier", 5, 15);
    Node *t61;//("T61", "amplifier", 5, 14);
    Node *t62;//("T62", "amplifier", 1, 14);
    Node *t63;//("T63", "amplifier", 5, 11);
    Node *t64;//("T64", "amplifier", 1, 11);
    Node *t65;//("T65", "amplifier", 5, 8);
    Node *t66;//("T66", "amplifier", 1, 8);
    Node *t67;//("T67", "amplifier", 5, 5);
    Node *t68;//("T68", "amplifier", 1, 3);
    Node *t69;//("T69", "amplifier", 2, 2);
    Node *t70;//("T70", "amplifier", 1, 2);
    Node *t71;//("T71", "amplifier", 5, 0);
    Node *t72;//("T72", "amplifier", 6, 0);

    Node *s1;//("s1", "switch", 1, 1);
    Node *s2;//("s2", "switch", 2, 1);
    Node *s3;//("s3", "switch", 5, 1);
    Node *s4;//("s4", "switch", 6, 1);
    Node *s5;//("s5", "switch", 0, 4);
    Node *s6;//("s6", "switch", 1, 4);
    Node *s7;//("s7", "switch", 2, 4);
    Node *s8;//("s8", "switch", 3, 4);
    Node *s9;//("s9", "switch", 4, 4);
    Node *s10;//("s10", "switch", 5, 4);
    Node *s11;//("s11", "switch", 6, 4);
    Node *s12;//("s12", "switch", 7, 4);
    Node *s13;//("s13", "switch", 0, 7);
    Node *s14;//("s14", "switch", 1, 7);
    Node *s15;//("s15", "switch", 2, 7);
    Node *s16;//("s16", "switch", 3, 7);
    Node *s17;//("s17", "switch", 4, 7);
    Node *s18;//("s18", "switch", 5, 7);
    Node *s19;//("s19", "switch", 6, 7);
    Node *s20;//("s20", "switch", 7, 7);
    Node *s21;//("s21", "switch", 0, 10);
    Node *s22;//("s22", "switch", 1, 10);
    Node *s23;//("s23", "switch", 2, 10);
    Node *s24;//("s24", "switch", 3, 10);
    Node *s25;//("s25", "switch", 4, 10);
    Node *s26;//("s26", "switch", 5, 10);
    Node *s27;//("s27", "switch", 6, 10);
    Node *s28;//("s28", "switch", 7, 10);
    Node *s29;//("s29", "switch", 0, 13);
    Node *s30;//("s30", "switch", 1, 13);
    Node *s31;//("s31", "switch", 2, 13);
    Node *s32;//("s32", "switch", 3, 13);
    Node *s33;//("s33", "switch", 4, 13);
    Node *s34;//("s34", "switch", 5, 13);
    Node *s35;//("s35", "switch", 6, 13);
    Node *s36;//("s36", "switch", 7, 13);
    Node *s37;//("s37", "switch", 0, 16);
    Node *s38;//("s38", "switch", 1, 16);
    Node *s39;//("s39", "switch", 2, 16);
    Node *s40;//("s40", "switch", 3, 16);
    Node *s41;//("s41", "switch", 4, 16);
    Node *s42;//("s42", "switch", 5, 16);
    Node *s43;//("s43", "switch", 6, 16);
    Node *s44;//("s44", "switch", 7, 16);
    Node *s45;//("s45", "switch", 1, 19);
    Node *s46;//("s46", "switch", 2, 19);
    Node *s47;//("s47", "switch", 3, 19);
    Node *s48;//("s48", "switch", 4, 19);
    Node *s49;//("s49", "switch", 5, 19);
    Node *s50;//("s50", "switch", 6, 19);

    
    
    vector<Node*> amplifiers;
    vector<Node*> channels;
    vector<Node*> switches;
    vector<Node*> testex;
    
   
public:
    double penaltyCoeff;
    double penaltyLPLCoeff;

    Payload();
    Payload(const Payload& orig);
    Port* getChannelsNeighborPort(Node* s);
    Node* getChannelNeighbor(Node* c);
    void createGraph(vector<Node*> switches);
    vector<int> existsPathInGraph(Node* chan);
    vector<double> run(vector<int> position_vector, vector<string> chan_instance);
    void clearSettings();
    ~Payload();
private:
};

#endif	/* PAYLOAD_H */

