/*
 * File:   Payload.cpp
 * Author: snjix
 *
 * Created on June 15, 2013, 5:05 PM
 */

#include "../inc/Payload.h"

Payload::Payload(bool _isPathLoss) {

    penaltyCoeff = 15.01f;
    penaltyLPLCoeff = 1.0f;
    isPathLoss = _isPathLoss;

    this->f1= new Node("F1", "channel", 1, 0);
    this->f3= new Node("F3", "channel", 2, 0);
    this->f5= new Node("F5", "channel", 6, 2);
    this->f7= new Node("F7", "channel", 5, 3);
    this->f9= new Node("F9", "channel", 1, 5);
    this->f11= new Node("F11", "channel", 1, 6);

    this->g1= new Node("G1", "channel", 5, 6);
    this->g3= new Node("G3", "channel", 6, 6);
    this->g5= new Node("G5", "channel", 2, 9);
    this->g7= new Node("G7", "channel", 5, 9);
    this->g9= new Node("G9", "channel", 1, 12);
    this->g11= new Node("G11", "channel", 5, 12);
    this->g13= new Node("G13", "channel", 6, 12);
    this->g15= new Node("G15", "channel", 1, 15);

    this->e1= new Node("E1", "channel", 5, 17);
    this->e3= new Node("E3", "channel", 4, 17);
    this->e5= new Node("E5", "channel", 6, 20);
    this->e7= new Node("E7", "channel", 1, 20);

    this->tb7= new Node("TB7", "channel", 2, 20);
    this->tb9= new Node("TB9", "channel", 5, 20);
    this->tb11= new Node("TB11", "channel", 2, 17);

    this->tg1= new Node("TG1", "channel", 2, 12);
    this->tg3= new Node("TG3", "channel", 1, 9);
    this->tg5= new Node("TG5", "channel", 2, 6);
    this->tg7= new Node("TG7", "channel", 6, 3);
    this->tg9= new Node("TG9", "channel", 2, 3);
    this->tg11= new Node("TG11", "channel", 5, 2);


    channels.push_back(f1);
    channels.push_back(f3);
    channels.push_back(f5);
    channels.push_back(f7);
    channels.push_back(f9);
    channels.push_back(f11);
    channels.push_back(g1);
    channels.push_back(g3);
    channels.push_back(g5);
    channels.push_back(g7);
    channels.push_back(g9);
    channels.push_back(g11);
    channels.push_back(g13);
    channels.push_back(g15);
    channels.push_back(e1);
    channels.push_back(e3);
    channels.push_back(e5);
    channels.push_back(e7);
    channels.push_back(tb7);
    channels.push_back(tb9);
    channels.push_back(tb11);
    channels.push_back(tg1);
    channels.push_back(tg3);
    channels.push_back(tg5);
    channels.push_back(tg7);
    channels.push_back(tg9);
    channels.push_back(tg11);


    this->t42= new Node("t42", "amplifier", 2, 14);
    this->t45= new Node("t45", "amplifier", 2, 11);
    this->t46= new Node("t46", "amplifier", 6, 14);
    this->t49= new Node("t49", "amplifier", 6, 8);
    this->t51= new Node("t51", "amplifier", 2, 8);
    this->t55= new Node("t55", "amplifier", 6, 18);
    this->t56= new Node("t56", "amplifier", 5, 18);
    this->t57= new Node("t57", "amplifier", 1, 18);
    this->t58= new Node("t58", "amplifier", 2, 18);
    this->t59= new Node("t59", "amplifier", 1, 17);
    this->t60= new Node("t60", "amplifier", 5, 15);
    this->t61= new Node("t61", "amplifier", 5, 14);
    this->t62= new Node("t62", "amplifier", 1, 14);
    this->t63= new Node("t63", "amplifier", 5, 11);
    this->t64= new Node("t64", "amplifier", 1, 11);
    this->t65= new Node("t65", "amplifier", 5, 8);
    this->t66= new Node("t66", "amplifier", 1, 8);
    this->t67= new Node("t67", "amplifier", 5, 5);
    this->t68= new Node("t68", "amplifier", 1, 3);
    this->t69= new Node("t69", "amplifier", 2, 2);
    this->t70= new Node("t70", "amplifier", 1, 2);
    this->t71= new Node("t71", "amplifier", 5, 0);
    this->t72= new Node("t72", "amplifier", 6, 0);


    amplifiers.push_back(t42);
    amplifiers.push_back(t45);
    amplifiers.push_back(t46);
    amplifiers.push_back(t49);
    amplifiers.push_back(t51);
    amplifiers.push_back(t55);
    amplifiers.push_back(t56);
    amplifiers.push_back(t57);
    amplifiers.push_back(t58);
    amplifiers.push_back(t59);
    amplifiers.push_back(t60);
    amplifiers.push_back(t61);
    amplifiers.push_back(t62);
    amplifiers.push_back(t63);
    amplifiers.push_back(t64);
    amplifiers.push_back(t65);
    amplifiers.push_back(t66);
    amplifiers.push_back(t67);
    amplifiers.push_back(t68);
    amplifiers.push_back(t69);
    amplifiers.push_back(t70);
    amplifiers.push_back(t71);
    amplifiers.push_back(t72);


    this->s1= new Node("s1", "switch", 1, 1);
    this->s2= new Node("s2", "switch", 2, 1);
    this->s3= new Node("s3", "switch", 5, 1);
    this->s4= new Node("s4", "switch", 6, 1);
    this->s5= new Node("s5", "switch", 0, 4);
    this->s6= new Node("s6", "switch", 1, 4);
    this->s7= new Node("s7", "switch", 2, 4);
    this->s8= new Node("s8", "switch", 3, 4);
    this->s9= new Node("s9", "switch", 4, 4);
    this->s10= new Node("s10", "switch", 5, 4);
    this->s11= new Node("s11", "switch", 6, 4);
    this->s12= new Node("s12", "switch", 7, 4);
    this->s13= new Node("s13", "switch", 0, 7);
    this->s14= new Node("s14", "switch", 1, 7);
    this->s15= new Node("s15", "switch", 2, 7);
    this->s16= new Node("s16", "switch", 3, 7);
    this->s17= new Node("s17", "switch", 4, 7);
    this->s18= new Node("s18", "switch", 5, 7);
    this->s19= new Node("s19", "switch", 6, 7);
    this->s20= new Node("s20", "switch", 7, 7);
    this->s21= new Node("s21", "switch", 0, 10);
    this->s22= new Node("s22", "switch", 1, 10);
    this->s23= new Node("s23", "switch", 2, 10);
    this->s24= new Node("s24", "switch", 3, 10);
    this->s25= new Node("s25", "switch", 4, 10);
    this->s26= new Node("s26", "switch", 5, 10);
    this->s27= new Node("s27", "switch", 6, 10);
    this->s28= new Node("s28", "switch", 7, 10);
    this->s29= new Node("s29", "switch", 0, 13);
    this->s30= new Node("s30", "switch", 1, 13);
    this->s31= new Node("s31", "switch", 2, 13);
    this->s32= new Node("s32", "switch", 3, 13);
    this->s33= new Node("s33", "switch", 4, 13);
    this->s34= new Node("s34", "switch", 5, 13);
    this->s35= new Node("s35", "switch", 6, 13);
    this->s36= new Node("s36", "switch", 7, 13);
    this->s37= new Node("s37", "switch", 0, 16);
    this->s38= new Node("s38", "switch", 1, 16);
    this->s39= new Node("s39", "switch", 2, 16);
    this->s40= new Node("s40", "switch", 3, 16);
    this->s41= new Node("s41", "switch", 4, 16);
    this->s42= new Node("s42", "switch", 5, 16);
    this->s43= new Node("s43", "switch", 6, 16);
    this->s44= new Node("s44", "switch", 7, 16);
    this->s45= new Node("s45", "switch", 1, 19);
    this->s46= new Node("s46", "switch", 2, 19);
    this->s47= new Node("s47", "switch", 3, 19);
    this->s48= new Node("s48", "switch", 4, 19);
    this->s49= new Node("s49", "switch", 5, 19);
    this->s50= new Node("s50", "switch", 6, 19);



    switches.push_back(s1);
    switches.push_back(s2);
    switches.push_back(s3);
    switches.push_back(s4);
    switches.push_back(s5);
    switches.push_back(s6);
    switches.push_back(s7);
    switches.push_back(s8);
    switches.push_back(s9);
    switches.push_back(s10);
    switches.push_back(s11);
    switches.push_back(s12);
    switches.push_back(s13);
    switches.push_back(s14);
    switches.push_back(s15);
    switches.push_back(s16);
    switches.push_back(s17);
    switches.push_back(s18);
    switches.push_back(s19);
    switches.push_back(s20);
    switches.push_back(s21);
    switches.push_back(s22);
    switches.push_back(s23);
    switches.push_back(s24);
    switches.push_back(s25);
    switches.push_back(s26);
    switches.push_back(s27);
    switches.push_back(s28);
    switches.push_back(s29);
    switches.push_back(s30);
    switches.push_back(s31);
    switches.push_back(s32);
    switches.push_back(s33);
    switches.push_back(s34);
    switches.push_back(s35);
    switches.push_back(s36);
    switches.push_back(s37);
    switches.push_back(s38);
    switches.push_back(s39);
    switches.push_back(s40);
    switches.push_back(s41);
    switches.push_back(s42);
    switches.push_back(s43);
    switches.push_back(s44);
    switches.push_back(s45);
    switches.push_back(s46);
    switches.push_back(s47);
    switches.push_back(s48);
    switches.push_back(s49);
    switches.push_back(s50);




    f1->setNeighbors(0, s1, 0, 0); // channel neighbors
    f3->setNeighbors(0, s2, 0, 0);
    f5->setNeighbors(0, 0, 0, s4);
    f7->setNeighbors(0, s10, 0, 0);
    f9->setNeighbors(0, 0, 0, s6);
    f11->setNeighbors(0, s14, 0, 0);

    tg11->setNeighbors(0, 0, 0, s3);
    tg9->setNeighbors(0, s7, 0, 0);
    tg7->setNeighbors(0, s11, 0, 0);
    tg5->setNeighbors(0, s15, 0, 0);
    tg3->setNeighbors(0, s22, 0, 0);
    tg1->setNeighbors(0, s31, 0, 0);

    g1->setNeighbors(0, s18, 0, 0);
    g3->setNeighbors(0, s19, 0, 0);
    g5->setNeighbors(0, s23, 0, 0);
    g7->setNeighbors(0, s26, 0, 0);
    g9->setNeighbors(0, s30, 0, 0);
    g11->setNeighbors(0, s34, 0, 0);
    g13->setNeighbors(0, s35, 0, 0);
    g15->setNeighbors(0, s38, 0, 0);

    e1->setNeighbors(0, 0, 0, s43);
    e3->setNeighbors(0, 0, 0, s42);
    e5->setNeighbors(0, 0, 0, s50);
    e7->setNeighbors(0, 0, 0, s45);

    tb7->setNeighbors(0, 0, 0, s46);
    tb9->setNeighbors(0, 0, 0, s49);
    tb11->setNeighbors(0, 0, 0, s39);


    t42->setNeighbors(0, 0, 0, s31); // amplifier neighbors
    t45->setNeighbors(0, 0, 0, s23);
    t46->setNeighbors(0, 0, 0, s35);
    t49->setNeighbors(0, 0, 0, s19);
    t51->setNeighbors(0, 0, 0, s15);
    t55->setNeighbors(0, s50, 0, 0);
    t56->setNeighbors(0, s49, 0, 0);
    t57->setNeighbors(0, s45, 0, 0);
    t58->setNeighbors(0, s46, 0, 0);
    t59->setNeighbors(0, 0, 0, s38);
    t60->setNeighbors(0, s42, 0, 0);
    t61->setNeighbors(0, 0, 0, s34);
    t62->setNeighbors(0, 0, 0, s30);
    t63->setNeighbors(0, 0, 0, s26);
    t64->setNeighbors(0, 0, 0, s22);
    t65->setNeighbors(0, 0, 0, s18);
    t66->setNeighbors(0, 0, 0, s14);
    t67->setNeighbors(0, 0, 0, s10);
    t68->setNeighbors(0, s6, 0, 0);
    t69->setNeighbors(0, 0, 0, s2);
    t70->setNeighbors(0, 0, 0, s1);
    t71->setNeighbors(0, s3, 0, 0);
    t72->setNeighbors(0, s4, 0, 0);


    s1->setNeighbors(s5, t70, s2, f1); //switch neighbors
    s2->setNeighbors(s1, t69, s8, f3);
    s3->setNeighbors(s9, tg11, s4, t71);
    s4->setNeighbors(s3, f5, s12, t72);
    s5->setNeighbors(s12, s13, s6, s1);
    s6->setNeighbors(s5, f9, s7, t68);
    s7->setNeighbors(s6, s39, s8, tg9);
    s8->setNeighbors(s7, s16, s9, s2);
    s9->setNeighbors(s8, s17, s10, s3);
    s10->setNeighbors(s9, t67, s11, f7);
    s11->setNeighbors(s10, s43, s12, tg7);
    s12->setNeighbors(s11, s20, s5, s4);

    s13->setNeighbors(s20, s21, s14, s5);
    s14->setNeighbors(s13, t66, s15, f11);
    s15->setNeighbors(s14, t51, s16, tg5);
    s16->setNeighbors(s15, s24, s17, s8);
    s17->setNeighbors(s16, s25, s18, s9);
    s18->setNeighbors(s17, t65, s19, g1);
    s19->setNeighbors(s18, t49, s20, g3);
    s20->setNeighbors(s19, s28, s13, s12);

    s21->setNeighbors(s28, s29, s22, s13);
    s22->setNeighbors(s21, t64, s23, tg3);
    s23->setNeighbors(s22, t45, s24, g5);
    s24->setNeighbors(s23, s32, s25, s16);
    s25->setNeighbors(s24, s33, s26, s17);
    s26->setNeighbors(s25, t63, s27, g7);
    //s27->setNeighbors(s26, s71, s28, s79);
    s27->setNeighbors(s26, 0, s28, 0);
    s28->setNeighbors(s27, s36, s21, s20);

    s29->setNeighbors(s36, s37, s30, s21);
    s30->setNeighbors(s29, t62, s31, g9);
    s31->setNeighbors(s30, t42, s32, tg1);
    s32->setNeighbors(s31, s40, s33, s24);
    s33->setNeighbors(s32, s41, s34, s25);
    s34->setNeighbors(s33, t61, s35, g11);
    s35->setNeighbors(s34, t46, s36, g13);
    s36->setNeighbors(s35, s44, s29, s28);

    s37->setNeighbors(s44, s45, s38, s29);
    s38->setNeighbors(s37, t59, s39, g15);
    s39->setNeighbors(s38, tb11, s40, s7);
    s40->setNeighbors(s39, s47, s41, s32);
    s41->setNeighbors(s40, s48, s42, s33);
    s42->setNeighbors(s41, e3, s43, t60);
    s43->setNeighbors(s42, e1, s44, s11);
    s44->setNeighbors(s43, s50, s37, s36);

    s45->setNeighbors(s37, e7, s46, t57);
    s46->setNeighbors(s45, tb7, s47, t58);
    //s47->setNeighbors(s46, s53, s48, s40);
    //s48->setNeighbors(s47, s54, s49, s41);
    s47->setNeighbors(s46, 0, s48, s40);
    s48->setNeighbors(s47, 0, s49, s41);
    s49->setNeighbors(s48, tb9, s50, t56);
    s50->setNeighbors(s49, e5, s44, t55);


/*
    cout << "No of Amplifiers :" << this->amplifiers.size() << endl;
    for(int i=0;i<this->amplifiers.size();i++){
        cout << this->amplifiers[i].getName() << endl;
    }
    cout << "No of channels :" << this->channels.size() << endl;

    for(int i=0;i<this->channels.size();i++){
        cout << this->channels[i].getName() << endl;
    }
    cout << "No of switches :" << this->switches.size() << endl;
    for(int i=0;i<this->switches.size();i++){
        cout << this->switches[i].getName() << endl;
    }

  */
}

Payload::Payload(const Payload& orig) {
}

void Payload::clearSettings(){
    //this->amplifiers;
    //this->channels;
    //this->switches;
}


void Payload::createGraph(vector<Node*> switches) { // This function creates the graph given a set of switch objects..
    //At the first step creates the links between the neighbor switches.
    //At the second step creates the links between the ports of the same switch, based on its position.

    //cout << "inside create graph" << endl;
    while (!switches.empty()) {
        Node* current;
        //Node* temp;
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



Port* Payload::getChannelsNeighborPort(Node* s) {
    Node* t;
    t = s->getChannelNeighbor(s);
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


vector<int> Payload::existsPathInGraph(Node* chan) { // check for a given channel object if a path to an amplifier exists.
    vector<Port*> path;
    vector<int> pathsLength;
    int result;
    Node* current;
    Port *p1;
    Port *p2;
    Port *p3;
    current = chan;
    p1 = getChannelsNeighborPort(current);
    path.push_back(p1);
    currentPathStrVect.clear();

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

      	//next 10 lines are dedicated to calculatePathLoss functionality
        std::string pre="";
        std::string delimiter = "_";

        currentPathStrVect.push_back(chan->getName());

        for (unsigned int t = 0; t < path.size(); t++) {
            std::string currentItem = path[t]->getName();
            currentItem = currentItem.substr(0, currentItem.find(delimiter));
            if(currentItem.compare(pre)!=0){
                currentPathStrVect.push_back(currentItem);
            }
            pre=currentItem;
        }
        currentPathStrVect.push_back(p2->getStringConnection());


        //for (unsigned int t = 0; t < pathStringVec.size(); t++) {
        //    cout << pathStringVec[t] << "-";
        //}
        //cout << endl;
	

	
#ifdef DEBUG_PAYLOAD

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
#ifdef DEBUG_PAYLOAD
        cout << " No path for " << chan->getName() << endl;
#endif
        result = 0;
        pathsLength.push_back(0);
        pathsLength.push_back(0);
    }
    return pathsLength;
}

vector<double> Payload::run(vector<int> position_vector,
        vector<string> chan_instance) { // here i define all the objects that exist in my network (switches, ports, channels etc..)

    vector<Node*> testex;


    Port *s1_port_l = new Port("s1_port_l");
    Port *s1_port_u = new Port("s1_port_u");
    Port *s1_port_r = new Port("s1_port_r");
    Port *s1_port_d = new Port("s1_port_d");
    s1->setPorts(s1_port_l, s1_port_u, s1_port_r, s1_port_d);
    Port *s2_port_l = new Port("s2_port_l");
    Port *s2_port_u = new Port("s2_port_u");
    Port *s2_port_r = new Port("s2_port_r");
    Port *s2_port_d = new Port("s2_port_d");
    s2->setPorts(s2_port_l, s2_port_u, s2_port_r, s2_port_d);
    Port *s3_port_l = new Port("s3_port_l");
    Port *s3_port_u = new Port("s3_port_u");
    Port *s3_port_r = new Port("s3_port_r");
    Port *s3_port_d = new Port("s3_port_d");
    s3->setPorts(s3_port_l, s3_port_u, s3_port_r, s3_port_d);
    Port *s4_port_l = new Port("s4_port_l");
    Port *s4_port_u = new Port("s4_port_u");
    Port *s4_port_r = new Port("s4_port_r");
    Port *s4_port_d = new Port("s4_port_d");
    s4->setPorts(s4_port_l, s4_port_u, s4_port_r, s4_port_d);
    Port *s5_port_l = new Port("s5_port_l");
    Port *s5_port_u = new Port("s5_port_u");
    Port *s5_port_r = new Port("s5_port_r");
    Port *s5_port_d = new Port("s5_port_d");
    s5->setPorts(s5_port_l, s5_port_u, s5_port_r, s5_port_d);
    Port *s6_port_l = new Port("s6_port_l");
    Port *s6_port_u = new Port("s6_port_u");
    Port *s6_port_r = new Port("s6_port_r");
    Port *s6_port_d = new Port("s6_port_d");
    s6->setPorts(s6_port_l, s6_port_u, s6_port_r, s6_port_d);
    Port *s7_port_l = new Port("s7_port_l");
    Port *s7_port_u = new Port("s7_port_u");
    Port *s7_port_r = new Port("s7_port_r");
    Port *s7_port_d = new Port("s7_port_d");
    s7->setPorts(s7_port_l, s7_port_u, s7_port_r, s7_port_d);
    Port *s8_port_l = new Port("s8_port_l");
    Port *s8_port_u = new Port("s8_port_u");
    Port *s8_port_r = new Port("s8_port_r");
    Port *s8_port_d = new Port("s8_port_d");
    s8->setPorts(s8_port_l, s8_port_u, s8_port_r, s8_port_d);
    Port *s9_port_l = new Port("s9_port_l");
    Port *s9_port_u = new Port("s9_port_u");
    Port *s9_port_r = new Port("s9_port_r");
    Port *s9_port_d = new Port("s9_port_d");
    s9->setPorts(s9_port_l, s9_port_u, s9_port_r, s9_port_d);
    Port *s10_port_l = new Port("s10_port_l");
    Port *s10_port_u = new Port("s10_port_u");
    Port *s10_port_r = new Port("s10_port_r");
    Port *s10_port_d = new Port("s10_port_d");
    s10->setPorts(s10_port_l, s10_port_u, s10_port_r, s10_port_d);
    Port *s11_port_l = new Port("s11_port_l");
    Port *s11_port_u = new Port("s11_port_u");
    Port *s11_port_r = new Port("s11_port_r");
    Port *s11_port_d = new Port("s11_port_d");
    s11->setPorts(s11_port_l, s11_port_u, s11_port_r, s11_port_d);
    Port *s12_port_l = new Port("s12_port_l");
    Port *s12_port_u = new Port("s12_port_u");
    Port *s12_port_r = new Port("s12_port_r");
    Port *s12_port_d = new Port("s12_port_d");
    s12->setPorts(s12_port_l, s12_port_u, s12_port_r, s12_port_d);
    Port *s13_port_l = new Port("s13_port_l");
    Port *s13_port_u = new Port("s13_port_u");
    Port *s13_port_r = new Port("s13_port_r");
    Port *s13_port_d = new Port("s13_port_d");
    s13->setPorts(s13_port_l, s13_port_u, s13_port_r, s13_port_d);
    Port *s14_port_l = new Port("s14_port_l");
    Port *s14_port_u = new Port("s14_port_u");
    Port *s14_port_r = new Port("s14_port_r");
    Port *s14_port_d = new Port("s14_port_d");
    s14->setPorts(s14_port_l, s14_port_u, s14_port_r, s14_port_d);
    Port *s15_port_l = new Port("s15_port_l");
    Port *s15_port_u = new Port("s15_port_u");
    Port *s15_port_r = new Port("s15_port_r");
    Port *s15_port_d = new Port("s15_port_d");
    s15->setPorts(s15_port_l, s15_port_u, s15_port_r, s15_port_d);
    Port *s16_port_l = new Port("s16_port_l");
    Port *s16_port_u = new Port("s16_port_u");
    Port *s16_port_r = new Port("s16_port_r");
    Port *s16_port_d = new Port("s16_port_d");
    s16->setPorts(s16_port_l, s16_port_u, s16_port_r, s16_port_d);
    Port *s17_port_l = new Port("s17_port_l");
    Port *s17_port_u = new Port("s17_port_u");
    Port *s17_port_r = new Port("s17_port_r");
    Port *s17_port_d = new Port("s17_port_d");
    s17->setPorts(s17_port_l, s17_port_u, s17_port_r, s17_port_d);
    Port *s18_port_l = new Port("s18_port_l");
    Port *s18_port_u = new Port("s18_port_u");
    Port *s18_port_r = new Port("s18_port_r");
    Port *s18_port_d = new Port("s18_port_d");
    s18->setPorts(s18_port_l, s18_port_u, s18_port_r, s18_port_d);
    Port *s19_port_l = new Port("s19_port_l");
    Port *s19_port_u = new Port("s19_port_u");
    Port *s19_port_r = new Port("s19_port_r");
    Port *s19_port_d = new Port("s19_port_d");
    s19->setPorts(s19_port_l, s19_port_u, s19_port_r, s19_port_d);
    Port *s20_port_l = new Port("s20_port_l");
    Port *s20_port_u = new Port("s20_port_u");
    Port *s20_port_r = new Port("s20_port_r");
    Port *s20_port_d = new Port("s20_port_d");
    s20->setPorts(s20_port_l, s20_port_u, s20_port_r, s20_port_d);
    Port *s21_port_l = new Port("s21_port_l");
    Port *s21_port_u = new Port("s21_port_u");
    Port *s21_port_r = new Port("s21_port_r");
    Port *s21_port_d = new Port("s21_port_d");
    s21->setPorts(s21_port_l, s21_port_u, s21_port_r, s21_port_d);
    Port *s22_port_l = new Port("s22_port_l");
    Port *s22_port_u = new Port("s22_port_u");
    Port *s22_port_r = new Port("s22_port_r");
    Port *s22_port_d = new Port("s22_port_d");
    s22->setPorts(s22_port_l, s22_port_u, s22_port_r, s22_port_d);
    Port *s23_port_l = new Port("s23_port_l");
    Port *s23_port_u = new Port("s23_port_u");
    Port *s23_port_r = new Port("s23_port_r");
    Port *s23_port_d = new Port("s23_port_d");
    s23->setPorts(s23_port_l, s23_port_u, s23_port_r, s23_port_d);
    Port *s24_port_l = new Port("s24_port_l");
    Port *s24_port_u = new Port("s24_port_u");
    Port *s24_port_r = new Port("s24_port_r");
    Port *s24_port_d = new Port("s24_port_d");
    s24->setPorts(s24_port_l, s24_port_u, s24_port_r, s24_port_d);
    Port *s25_port_l = new Port("s25_port_l");
    Port *s25_port_u = new Port("s25_port_u");
    Port *s25_port_r = new Port("s25_port_r");
    Port *s25_port_d = new Port("s25_port_d");
    s25->setPorts(s25_port_l, s25_port_u, s25_port_r, s25_port_d);
    Port *s26_port_l = new Port("s26_port_l");
    Port *s26_port_u = new Port("s26_port_u");
    Port *s26_port_r = new Port("s26_port_r");
    Port *s26_port_d = new Port("s26_port_d");
    s26->setPorts(s26_port_l, s26_port_u, s26_port_r, s26_port_d);
    Port *s27_port_l = new Port("s27_port_l");
    Port *s27_port_u = new Port("s27_port_u");
    Port *s27_port_r = new Port("s27_port_r");
    Port *s27_port_d = new Port("s27_port_d");
    s27->setPorts(s27_port_l, s27_port_u, s27_port_r, s27_port_d);
    Port *s28_port_l = new Port("s28_port_l");
    Port *s28_port_u = new Port("s28_port_u");
    Port *s28_port_r = new Port("s28_port_r");
    Port *s28_port_d = new Port("s28_port_d");
    s28->setPorts(s28_port_l, s28_port_u, s28_port_r, s28_port_d);
    Port *s29_port_l = new Port("s29_port_l");
    Port *s29_port_u = new Port("s29_port_u");
    Port *s29_port_r = new Port("s29_port_r");
    Port *s29_port_d = new Port("s29_port_d");
    s29->setPorts(s29_port_l, s29_port_u, s29_port_r, s29_port_d);
    Port *s30_port_l = new Port("s30_port_l");
    Port *s30_port_u = new Port("s30_port_u");
    Port *s30_port_r = new Port("s30_port_r");
    Port *s30_port_d = new Port("s30_port_d");
    s30->setPorts(s30_port_l, s30_port_u, s30_port_r, s30_port_d);
    Port *s31_port_l = new Port("s31_port_l");
    Port *s31_port_u = new Port("s31_port_u");
    Port *s31_port_r = new Port("s31_port_r");
    Port *s31_port_d = new Port("s31_port_d");
    s31->setPorts(s31_port_l, s31_port_u, s31_port_r, s31_port_d);
    Port *s32_port_l = new Port("s32_port_l");
    Port *s32_port_u = new Port("s32_port_u");
    Port *s32_port_r = new Port("s32_port_r");
    Port *s32_port_d = new Port("s32_port_d");
    s32->setPorts(s32_port_l, s32_port_u, s32_port_r, s32_port_d);
    Port *s33_port_l = new Port("s33_port_l");
    Port *s33_port_u = new Port("s33_port_u");
    Port *s33_port_r = new Port("s33_port_r");
    Port *s33_port_d = new Port("s33_port_d");
    s33->setPorts(s33_port_l, s33_port_u, s33_port_r, s33_port_d);
    Port *s34_port_l = new Port("s34_port_l");
    Port *s34_port_u = new Port("s34_port_u");
    Port *s34_port_r = new Port("s34_port_r");
    Port *s34_port_d = new Port("s34_port_d");
    s34->setPorts(s34_port_l, s34_port_u, s34_port_r, s34_port_d);
    Port *s35_port_l = new Port("s35_port_l");
    Port *s35_port_u = new Port("s35_port_u");
    Port *s35_port_r = new Port("s35_port_r");
    Port *s35_port_d = new Port("s35_port_d");
    s35->setPorts(s35_port_l, s35_port_u, s35_port_r, s35_port_d);
    Port *s36_port_l = new Port("s36_port_l");
    Port *s36_port_u = new Port("s36_port_u");
    Port *s36_port_r = new Port("s36_port_r");
    Port *s36_port_d = new Port("s36_port_d");
    s36->setPorts(s36_port_l, s36_port_u, s36_port_r, s36_port_d);
    Port *s37_port_l = new Port("s37_port_l");
    Port *s37_port_u = new Port("s37_port_u");
    Port *s37_port_r = new Port("s37_port_r");
    Port *s37_port_d = new Port("s37_port_d");
    s37->setPorts(s37_port_l, s37_port_u, s37_port_r, s37_port_d);
    Port *s38_port_l = new Port("s38_port_l");
    Port *s38_port_u = new Port("s38_port_u");
    Port *s38_port_r = new Port("s38_port_r");
    Port *s38_port_d = new Port("s38_port_d");
    s38->setPorts(s38_port_l, s38_port_u, s38_port_r, s38_port_d);
    Port *s39_port_l = new Port("s39_port_l");
    Port *s39_port_u = new Port("s39_port_u");
    Port *s39_port_r = new Port("s39_port_r");
    Port *s39_port_d = new Port("s39_port_d");
    s39->setPorts(s39_port_l, s39_port_u, s39_port_r, s39_port_d);
    Port *s40_port_l = new Port("s40_port_l");
    Port *s40_port_u = new Port("s40_port_u");
    Port *s40_port_r = new Port("s40_port_r");
    Port *s40_port_d = new Port("s40_port_d");
    s40->setPorts(s40_port_l, s40_port_u, s40_port_r, s40_port_d);
    Port *s41_port_l = new Port("s41_port_l");
    Port *s41_port_u = new Port("s41_port_u");
    Port *s41_port_r = new Port("s41_port_r");
    Port *s41_port_d = new Port("s41_port_d");
    s41->setPorts(s41_port_l, s41_port_u, s41_port_r, s41_port_d);
    Port *s42_port_l = new Port("s42_port_l");
    Port *s42_port_u = new Port("s42_port_u");
    Port *s42_port_r = new Port("s42_port_r");
    Port *s42_port_d = new Port("s42_port_d");
    s42->setPorts(s42_port_l, s42_port_u, s42_port_r, s42_port_d);
    Port *s43_port_l = new Port("s43_port_l");
    Port *s43_port_u = new Port("s43_port_u");
    Port *s43_port_r = new Port("s43_port_r");
    Port *s43_port_d = new Port("s43_port_d");
    s43->setPorts(s43_port_l, s43_port_u, s43_port_r, s43_port_d);
    Port *s44_port_l = new Port("s44_port_l");
    Port *s44_port_u = new Port("s44_port_u");
    Port *s44_port_r = new Port("s44_port_r");
    Port *s44_port_d = new Port("s44_port_d");
    s44->setPorts(s44_port_l, s44_port_u, s44_port_r, s44_port_d);
    Port *s45_port_l = new Port("s45_port_l");
    Port *s45_port_u = new Port("s45_port_u");
    Port *s45_port_r = new Port("s45_port_r");
    Port *s45_port_d = new Port("s45_port_d");
    s45->setPorts(s45_port_l, s45_port_u, s45_port_r, s45_port_d);
    Port *s46_port_l = new Port("s46_port_l");
    Port *s46_port_u = new Port("s46_port_u");
    Port *s46_port_r = new Port("s46_port_r");
    Port *s46_port_d = new Port("s46_port_d");
    s46->setPorts(s46_port_l, s46_port_u, s46_port_r, s46_port_d);
    Port *s47_port_l = new Port("s47_port_l");
    Port *s47_port_u = new Port("s47_port_u");
    Port *s47_port_r = new Port("s47_port_r");
    Port *s47_port_d = new Port("s47_port_d");
    s47->setPorts(s47_port_l, s47_port_u, s47_port_r, s47_port_d);
    Port *s48_port_l = new Port("s48_port_l");
    Port *s48_port_u = new Port("s48_port_u");
    Port *s48_port_r = new Port("s48_port_r");
    Port *s48_port_d = new Port("s48_port_d");
    s48->setPorts(s48_port_l, s48_port_u, s48_port_r, s48_port_d);
    Port *s49_port_l = new Port("s49_port_l");
    Port *s49_port_u = new Port("s49_port_u");
    Port *s49_port_r = new Port("s49_port_r");
    Port *s49_port_d = new Port("s49_port_d");
    s49->setPorts(s49_port_l, s49_port_u, s49_port_r, s49_port_d);
    Port *s50_port_l = new Port("s50_port_l");
    Port *s50_port_u = new Port("s50_port_u");
    Port *s50_port_r = new Port("s50_port_r");
    Port *s50_port_d = new Port("s50_port_d");
    s50->setPorts(s50_port_l, s50_port_u, s50_port_r, s50_port_d);

    testex.push_back(s1);
    testex.push_back(s2);
    testex.push_back(s3);
    testex.push_back(s4);
    testex.push_back(s5);
    testex.push_back(s6);
    testex.push_back(s7);
    testex.push_back(s8);
    testex.push_back(s9);
    testex.push_back(s10);
    testex.push_back(s11);
    testex.push_back(s12);

    testex.push_back(s13);
    testex.push_back(s14);
    testex.push_back(s15);
    testex.push_back(s16);
    testex.push_back(s17);
    testex.push_back(s18);
    testex.push_back(s19);
    testex.push_back(s20);
    testex.push_back(s21);
    testex.push_back(s22);
    testex.push_back(s23);
    testex.push_back(s24);

    testex.push_back(s25);
    testex.push_back(s26);
    testex.push_back(s27);
    testex.push_back(s28);
    testex.push_back(s29);
    testex.push_back(s30);
    testex.push_back(s31);
    testex.push_back(s32);
    testex.push_back(s33);
    testex.push_back(s34);
    testex.push_back(s35);
    testex.push_back(s36);

    testex.push_back(s37);
    testex.push_back(s38);
    testex.push_back(s39);
    testex.push_back(s40);
    testex.push_back(s41);
    testex.push_back(s42);
    testex.push_back(s43);
    testex.push_back(s44);
    testex.push_back(s45);
    testex.push_back(s46);
    testex.push_back(s47);
    testex.push_back(s48);
    testex.push_back(s49);
    testex.push_back(s50);

    testex.push_back(f1);
    testex.push_back(f3);
    testex.push_back(f5);
    testex.push_back(f7);
    testex.push_back(f9);
    testex.push_back(f11);
    testex.push_back(g1);
    testex.push_back(g3);
    testex.push_back(g5);
    testex.push_back(g7);
    testex.push_back(g9);
    testex.push_back(g11);
    testex.push_back(g13);
    testex.push_back(g15);
    testex.push_back(e1);
    testex.push_back(e3);
    testex.push_back(e5);
    testex.push_back(e7);
    testex.push_back(tb7);
    testex.push_back(tb9);
    testex.push_back(tb11);
    testex.push_back(tg1);
    testex.push_back(tg3);
    testex.push_back(tg5);
    testex.push_back(tg7);
    testex.push_back(tg9);
    testex.push_back(tg11);

    for (unsigned int r = 0; r < position_vector.size(); r++) {
        this->switches[r]->setPos(position_vector[r]);
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


    createGraph(testex);
    //cout << "after createGraph function call" << endl;
    //cout << "channel instance vect size " << chan_instance.size() << endl;
    for (unsigned int r = 0; r < chan_instance.size(); r++) {
        //cout << chan_instance[r] << endl;
        for (unsigned int j = 0; j < this->channels.size(); j++) {
            if (chan_instance[r] == this->channels[j]->getName()) {
                channels_to_test_path.push_back(this->channels[j]);
                break;
            }
        }
    }

    //cout << "after filling channels to test path" << endl;
    vector<int> vv;
    unsigned int ConstructedPaths=0;//No of paths that has been created
    int LongestPathLenght=0;
    double LargestPathLoss=0.0f;
    //cout << "before checking path existance for " << channels_to_test_path.size() << " channels" << endl;
    for (unsigned int y = 0; y < channels_to_test_path.size(); y++) {
        vv = existsPathInGraph(channels_to_test_path[y]);
        //cout << "after checking path existance for " << y << " one" << endl;
        int path = vv[0];
        int length = vv[1];
        ConstructedPaths = ConstructedPaths + path;

        if (length > LongestPathLenght) {
            LongestPathLenght = length;
        }
        
        if(isPathLoss)
	  if(currentPathStrVect.size()>2){
	    double tempPathLoss;
	    tempPathLoss=calcPathLoss(&currentPathStrVect);
	    if(tempPathLoss>LargestPathLoss)
	      LargestPathLoss=tempPathLoss;
	  }
	
    }
    //cout << "after checking path existance" << endl;
    if(ConstructedPaths==0)
        LongestPathLenght=10;//was1000

#ifdef DEBUG_ALL

    cout << "Constructed paths: " << ConstructedPaths
            //<< ". Total number of used switches: " << fitness2
            << ". Longest Path length: " << LongestPathLenght << endl;

#endif
    double qualityMetric=1.0f;//I think its better to call this value as quality metric
    vector<double> result;

    if (ConstructedPaths < channels_to_test_path.size()) {
        qualityMetric=((channels_to_test_path.size() - ConstructedPaths) * penaltyCoeff)+LongestPathLenght*penaltyLPLCoeff;
        //qualityMetric = ((channels_to_test_path.size() - ConstructedPaths) * 50)+LongestPathLenght;
        //qualityMetric=penaltyCoeff+LongestPathLenght;
    }
    else {
        qualityMetric=LongestPathLenght;
    }
    result.push_back(qualityMetric);
    result.push_back(ConstructedPaths);
    result.push_back(LongestPathLenght);


   delete s1_port_l;
   delete s1_port_u;// new Port("s1_port_u");
   delete s1_port_r;// new Port("s1_port_r");
   delete s1_port_d;// new Port("s1_port_d");
   delete s2_port_l;// new Port("s2_port_l");
   delete s2_port_u;// new Port("s2_port_u");
   delete s2_port_r;// new Port("s2_port_r");
   delete s2_port_d;// new Port("s2_port_d");
   delete s3_port_l;// new Port("s3_port_l");
   delete s3_port_u;// new Port("s3_port_u");
   delete s3_port_r;// new Port("s3_port_r");
   delete s3_port_d;// new Port("s3_port_d");
   delete s4_port_l;// new Port("s4_port_l");
   delete s4_port_u;// new Port("s4_port_u");
   delete s4_port_r;// new Port("s4_port_r");
   delete s4_port_d;// new Port("s4_port_d");
   delete s5_port_l;// new Port("s5_port_l");
   delete s5_port_u;// new Port("s5_port_u");
   delete s5_port_r;// new Port("s5_port_r");
   delete s5_port_d;// new Port("s5_port_d");
   delete s6_port_l;// new Port("s6_port_l");
   delete s6_port_u;// new Port("s6_port_u");
   delete s6_port_r;// new Port("s6_port_r");
   delete s6_port_d;// new Port("s6_port_d");
   delete s7_port_l;// new Port("s7_port_l");
   delete s7_port_u;// new Port("s7_port_u");
   delete s7_port_r;// new Port("s7_port_r");
   delete s7_port_d;// new Port("s7_port_d");
   delete s8_port_l;// new Port("s8_port_l");
   delete s8_port_u;// new Port("s8_port_u");
   delete s8_port_r;// new Port("s8_port_r");
   delete s8_port_d;// new Port("s8_port_d");
   delete s9_port_l;// new Port("s9_port_l");
   delete s9_port_u;// new Port("s9_port_u");
   delete s9_port_r;// new Port("s9_port_r");
   delete s9_port_d;// new Port("s9_port_d");
   delete s10_port_l;// new Port("s10_port_l");
   delete s10_port_u;// new Port("s10_port_u");
   delete s10_port_r;// new Port("s10_port_r");
   delete s10_port_d;// new Port("s10_port_d");
   delete s11_port_l;// new Port("s11_port_l");
   delete s11_port_u;// new Port("s11_port_u");
   delete s11_port_r;// new Port("s11_port_r");
   delete s11_port_d;// new Port("s11_port_d");
   delete s12_port_l;// new Port("s12_port_l");
   delete s12_port_u;// new Port("s12_port_u");
   delete s12_port_r;// new Port("s12_port_r");
   delete s12_port_d;// new Port("s12_port_d");
   delete s13_port_l;// new Port("s13_port_l");
   delete s13_port_u;// new Port("s13_port_u");
   delete s13_port_r;// new Port("s13_port_r");
   delete s13_port_d;// new Port("s13_port_d");
   delete s14_port_l;// new Port("s14_port_l");
   delete s14_port_u;// new Port("s14_port_u");
   delete s14_port_r;// new Port("s14_port_r");
   delete s14_port_d;// new Port("s14_port_d");
   delete s15_port_l;// new Port("s15_port_l");
   delete s15_port_u;// new Port("s15_port_u");
   delete s15_port_r;// new Port("s15_port_r");
   delete s15_port_d;// new Port("s15_port_d");
   delete s16_port_l;// new Port("s16_port_l");
   delete s16_port_u;// new Port("s16_port_u");
   delete s16_port_r;// new Port("s16_port_r");
   delete s16_port_d;// new Port("s16_port_d");
   delete s17_port_l;// new Port("s17_port_l");
   delete s17_port_u;// new Port("s17_port_u");
   delete s17_port_r;// new Port("s17_port_r");
   delete s17_port_d;// new Port("s17_port_d");
   delete s18_port_l;// new Port("s18_port_l");
   delete s18_port_u;// new Port("s18_port_u");
   delete s18_port_r;// new Port("s18_port_r");
   delete s18_port_d;// new Port("s18_port_d");
   delete s19_port_l;// new Port("s19_port_l");
   delete s19_port_u;// new Port("s19_port_u");
   delete s19_port_r;// new Port("s19_port_r");
   delete s19_port_d;// new Port("s19_port_d");
   delete s20_port_l;// new Port("s20_port_l");
   delete s20_port_u;// new Port("s20_port_u");
   delete s20_port_r;// new Port("s20_port_r");
   delete s20_port_d;// new Port("s20_port_d");
   delete s21_port_l;// new Port("s21_port_l");
   delete s21_port_u;// new Port("s21_port_u");
   delete s21_port_r;// new Port("s21_port_r");
   delete s21_port_d;// new Port("s21_port_d");
   delete s22_port_l;// new Port("s22_port_l");
   delete s22_port_u;// new Port("s22_port_u");
   delete s22_port_r;// new Port("s22_port_r");
   delete s22_port_d;// new Port("s22_port_d");
   delete s23_port_l;// new Port("s23_port_l");
   delete s23_port_u;// new Port("s23_port_u");
   delete s23_port_r;// new Port("s23_port_r");
   delete s23_port_d;// new Port("s23_port_d");
   delete s24_port_l;// new Port("s24_port_l");
   delete s24_port_u;// new Port("s24_port_u");
   delete s24_port_r;// new Port("s24_port_r");
   delete s24_port_d;// new Port("s24_port_d");
   delete s25_port_l;// new Port("s25_port_l");
   delete s25_port_u;// new Port("s25_port_u");
   delete s25_port_r;// new Port("s25_port_r");
   delete s25_port_d;// new Port("s25_port_d");
   delete s26_port_l;// new Port("s26_port_l");
   delete s26_port_u;// new Port("s26_port_u");
   delete s26_port_r;// new Port("s26_port_r");
   delete s26_port_d;// new Port("s26_port_d");
   delete s27_port_l;// new Port("s27_port_l");
   delete s27_port_u;// new Port("s27_port_u");
   delete s27_port_r;// new Port("s27_port_r");
   delete s27_port_d;// new Port("s27_port_d");
   delete s28_port_l;// new Port("s28_port_l");
   delete s28_port_u;// new Port("s28_port_u");
   delete s28_port_r;// new Port("s28_port_r");
   delete s28_port_d;// new Port("s28_port_d");
   delete s29_port_l;// new Port("s29_port_l");
   delete s29_port_u;// new Port("s29_port_u");
   delete s29_port_r;// new Port("s29_port_r");
   delete s29_port_d;// new Port("s29_port_d");
   delete s30_port_l;// new Port("s30_port_l");
   delete s30_port_u;// new Port("s30_port_u");
   delete s30_port_r;// new Port("s30_port_r");
   delete s30_port_d;// new Port("s30_port_d");
   delete s31_port_l;// new Port("s31_port_l");
   delete s31_port_u;// new Port("s31_port_u");
   delete s31_port_r;// new Port("s31_port_r");
   delete s31_port_d;// new Port("s31_port_d");
   delete s32_port_l;// new Port("s32_port_l");
   delete s32_port_u;// new Port("s32_port_u");
   delete s32_port_r;// new Port("s32_port_r");
   delete s32_port_d;// new Port("s32_port_d");
   delete s33_port_l;// new Port("s33_port_l");
   delete s33_port_u;// new Port("s33_port_u");
   delete s33_port_r;// new Port("s33_port_r");
   delete s33_port_d;// new Port("s33_port_d");
   delete s34_port_l;// new Port("s34_port_l");
   delete s34_port_u;// new Port("s34_port_u");
   delete s34_port_r;// new Port("s34_port_r");
   delete s34_port_d;// new Port("s34_port_d");
   delete s35_port_l;// new Port("s35_port_l");
   delete s35_port_u;// new Port("s35_port_u");
   delete s35_port_r;// new Port("s35_port_r");
   delete s35_port_d;// new Port("s35_port_d");
   delete s36_port_l;// new Port("s36_port_l");
   delete s36_port_u;// new Port("s36_port_u");
   delete s36_port_r;// new Port("s36_port_r");
   delete s36_port_d;// new Port("s36_port_d");
   delete s37_port_l;// new Port("s37_port_l");
   delete s37_port_u;// new Port("s37_port_u");
   delete s37_port_r;// new Port("s37_port_r");
   delete s37_port_d;// new Port("s37_port_d");
   delete s38_port_l;// new Port("s38_port_l");
   delete s38_port_u;// new Port("s38_port_u");
   delete s38_port_r;// new Port("s38_port_r");
   delete s38_port_d;// new Port("s38_port_d");
   delete s39_port_l;// new Port("s29_port_l");
   delete s39_port_u;// new Port("s29_port_u");
   delete s39_port_r;// new Port("s29_port_r");
   delete s39_port_d;// new Port("s29_port_d");
   delete s40_port_l;// new Port("s40_port_l");
   delete s40_port_u;// new Port("s40_port_u");
   delete s40_port_r;// new Port("s40_port_r");
   delete s40_port_d;// new Port("s40_port_d");
   delete s41_port_l;// new Port("s41_port_l");
   delete s41_port_u;// new Port("s41_port_u");
   delete s41_port_r;// new Port("s41_port_r");
   delete s41_port_d;// new Port("s41_port_d");
   delete s42_port_l;// new Port("s42_port_l");
   delete s42_port_u;// new Port("s42_port_u");
   delete s42_port_r;// new Port("s42_port_r");
   delete s42_port_d;// new Port("s42_port_d");
   delete s43_port_l;// new Port("s43_port_l");
   delete s43_port_u;// new Port("s43_port_u");
   delete s43_port_r;// new Port("s43_port_r");
   delete s43_port_d;// new Port("s43_port_d");
   delete s44_port_l;// new Port("s44_port_l");
   delete s44_port_u;// new Port("s44_port_u");
   delete s44_port_r;// new Port("s44_port_r");
   delete s44_port_d;// new Port("s44_port_d");
   delete s45_port_l;// new Port("s45_port_l");
   delete s45_port_u;// new Port("s45_port_u");
   delete s45_port_r;// new Port("s45_port_r");
   delete s45_port_d;// new Port("s45_port_d");
   delete s46_port_l;// new Port("s46_port_l");
   delete s46_port_u;// new Port("s46_port_u");
   delete s46_port_r;// new Port("s46_port_r");
   delete s46_port_d;// new Port("s46_port_d");
   delete s47_port_l;// new Port("s47_port_l");
   delete s47_port_u;// new Port("s47_port_u");
   delete s47_port_r;// new Port("s47_port_r");
   delete s47_port_d;// new Port("s47_port_d");
   delete s48_port_l;// new Port("s48_port_l");
   delete s48_port_u;// new Port("s48_port_u");
   delete s48_port_r;// new Port("s48_port_r");
   delete s48_port_d;// new Port("s48_port_d");
   delete s49_port_l;// new Port("s49_port_l");
   delete s49_port_u;// new Port("s49_port_u");
   delete s49_port_r;// new Port("s49_port_r");
   delete s49_port_d;// new Port("s49_port_d");
   delete s50_port_l;// new Port("s50_port_l");
   delete s50_port_u;// new Port("s50_port_u");
   delete s50_port_r;// new Port("s50_port_r");
   delete s50_port_d;// new Port("s50_port_d");


    testex.clear();

    return result;
}


double Payload::calcPathLoss(vector<std::string> *pathStrVec){
    double pathLoss;
    LossCalculator lc= LossCalculator();
    std::cout << "pathloss: "<< pathLoss << std::endl;
    pathLoss=lc.calculatePathLoss(pathStrVec);
    std::cout << "pathloss: "<< pathLoss << std::endl;
return pathLoss;
}



Payload::~Payload() {


}

