/*
 * File:   Payload.h
 * Author: snjix
 *
 * Created on June 15, 2013, 5:05 PM
 */

#ifndef PAYLOAD_100_H
#define	PAYLOAD_100_H

#include <vector>
#include "Port.h"
#include "PrIns.h"
#include "Node.h"
#include "LossCalculator.h"

class Payload_100
{


    Node *f1;
    Node *f3;
    Node *f5;
    Node *f7;
    Node *f9;
    Node *f11;

    Node *g1;
    Node *g3;
    Node *g5;
    Node *g7;
    Node *g9;
    Node *g11;
    Node *g13;
    Node *g15;

    Node *e1;
    Node *e3;
    Node *e5;
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


//subgroup1
    Node *c1;
    Node *c3;
    Node *c5;
    Node *c7;
    Node *c9;
    Node *c11;
    Node *c13;
    Node *c15;
    Node *ta5;
    Node *ta7;
    Node *f13;
    Node *f15;
    Node *f17;
    Node *f19;
    Node *b1;
    Node *b3;
    Node *b5;
    Node *b7;
    Node *b9;
    Node *b11;
    Node *b13;
    Node *b15;



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

    //subgroup1
    Node *t37;//("T37", "amplifier", 1, 27);
    Node *t38;//("T38", "amplifier", 5, 38);
    Node *t39;//("T39", "amplifier", 1, 36);
    Node *t40;//("T40", "amplifier", 5, 33);
    Node *t41;//("T41", "amplifier", 1, 35);
    Node *t43;//("T43", "amplifier", 1, 30);
    Node *t44;//("T44", "amplifier", 5, 30);
    Node *t47;//("T47", "amplifier", 5, 26);
    Node *t48;//("T48", "amplifier", 5, 27);
    Node *t50;//("T50", "amplifier", 1, 24);
    Node *t52;//("T52", "amplifier", 1, 23);
    Node *t53;//("T53", "amplifier", 5, 23);




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


    //subgroup1

    Node *s51;//("s51", "switch", 1, 22);
    Node *s52;//("s52", "switch", 2, 22);
    Node *s53;//("s53", "switch", 3, 22);
    Node *s54;//("s54", "switch", 4, 22);
    Node *s55;//("s55", "switch", 5, 22);
    Node *s56;//("s56", "switch", 6, 22);
    Node *s57;//("s57", "switch", 0, 25);
    Node *s58;//("s58", "switch", 1, 25);
    Node *s59;//("s59", "switch", 2, 25);
    Node *s60;//("s60", "switch", 3, 25);
    Node *s61;//("s61", "switch", 4, 25);
    Node *s62;//("s62", "switch", 5, 25);
    Node *s63;//("s63", "switch", 6, 25);
    Node *s64;//("s64", "switch", 7, 25);
    Node *s65;//("s65", "switch", 0, 28);
    Node *s66;//("s66", "switch", 1, 28);
    Node *s67;//("s67", "switch", 2, 28);
    Node *s68;//("s68", "switch", 3, 28);
    Node *s69;//("s69", "switch", 4, 28);
    Node *s70;//("s70", "switch", 5, 28);
    Node *s71;//("s71", "switch", 6, 28);
    Node *s72;//("s72", "switch", 7, 28);
    Node *s73;//("s73", "switch", 0, 31);
    Node *s74;//("s74", "switch", 1, 31);
    Node *s75;//("s75", "switch", 2, 31);
    Node *s76;//("s76", "switch", 3, 31);
    Node *s77;//("s77", "switch", 4, 31);
    Node *s78;//("s78", "switch", 5, 31);
    Node *s79;//("s79", "switch", 6, 31);
    Node *s80;//("s80", "switch", 7, 31);
    Node *s81;//("s81", "switch", 0, 34);
    Node *s82;//("s82", "switch", 1, 34);
    Node *s83;//("s83", "switch", 2, 34);
    Node *s84;//("s84", "switch", 3, 34);
    Node *s85;//("s85", "switch", 4, 34);
    Node *s86;//("s86", "switch", 5, 34);
    Node *s87;//("s87", "switch", 6, 34);
    Node *s88;//("s88", "switch", 7, 34);
    Node *s89;//("s89", "switch", 1, 37);
    Node *s90;//("s90", "switch", 2, 37);
    Node *s91;//("s91", "switch", 5, 37);
    Node *s92;//("s92", "switch", 6, 37);


    Node *s93;//("s93", "switch", 6, 38); // no care for coordinates for the moment
    Node *s94;//("s94", "switch", 5, 38);   // no care for coordinates for the moment
    Node *s95;//("s95", "switch", 6, 39);  // no care for coordinates for the moment
    Node *s96;//("s96", "switch", 7, 38);  // no care for coordinates for the moment
    Node *s97;//("s97", "switch", 7, 36);  // no care for coordinates for the moment
    Node *s98;//("s98", "switch", 8, 37);  // no care for coordinates for the moment
    Node *s99;//("s99", "switch", 8, 36);  // no care for coordinates for the moment
    Node *s100;//("s100", "switch", 7, 37);  // no care for coordinates for the moment





    vector<Node*> amplifiers;
    vector<Node*> channels;
    vector<Node*> switches;
    vector<Node*> testex;


public:
    double penaltyCoeff;
    double penaltyLPLCoeff;

    Payload_100();
    Payload_100(const Payload_100& orig);
    Port* getChannelsNeighborPort(Node* s);
    Node* getChannelNeighbor(Node* c);
    void createGraph(vector<Node*> switches);
    vector<int> existsPathInGraph(Node* chan);
    vector<double> run(vector<int> position_vector, vector<string> chan_instance);
    double calcPathLoss(vector<std::string> pathStrVec);
    void clearSettings();
    ~Payload_100();
private:
};

#endif	/* PAYLOAD_100_H */

