/*
 * File:   Payload_100.cpp
 * Author: snjix
 *
 * Created on June 15, 2013, 5:05 PM
 */

#include "Payload_100.h"

Payload_100::Payload_100()
{

    penaltyCoeff = 15.01f;
    penaltyLPLCoeff = 1.0f;


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

    //subgroup1

    this->c1= new Node("C1", "channel", 1, 38);
    this->c3= new Node("C3", "channel", 2, 38);
    this->c5= new Node("C5", "channel", 5, 36);
    this->c7= new Node("C7", "channel", 2, 35);
    this->c9= new Node("C9", "channel", 5, 35);
    this->c11= new Node("C11", "channel", 6, 35);
    this->c13= new Node("C13", "channel", 2, 33);
    this->c15= new Node("C15", "channel", 2, 32);

    this->ta5= new Node("TA5", "channel", 2, 32);
    this->ta7= new Node("TA7", "channel", 1, 29);

    this->f13= new Node("F13", "channel", 5, 27);
    this->f15= new Node("F15", "channel", 5, 29);
    this->f17= new Node("F17", "channel", 6, 32);
    this->f19= new Node("F19", "channel", 5, 32);

    this->b1= new Node("B1", "channel", 1, 21);
    this->b3= new Node("B3", "channel", 2, 21);
    this->b5= new Node("B5", "channel", 5, 21);
    this->b7= new Node("B7", "channel", 2, 24);
    this->b9= new Node("B9", "channel", 5, 24);
    this->b11= new Node("B11", "channel", 6, 24);
    this->b13= new Node("B13", "channel", 1, 26);
    this->b15= new Node("B15", "channel", 2, 29);
////////////////////////////




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


    //subgroup1
    channels.push_back(c1);
    channels.push_back(c3);
    channels.push_back(c5);
    channels.push_back(c7);
    channels.push_back(c9);
    channels.push_back(c11);
    channels.push_back(c13);
    channels.push_back(c15);
    channels.push_back(ta5);
    channels.push_back(ta7);
    channels.push_back(f13);
    channels.push_back(f15);
    channels.push_back(f17);
    channels.push_back(f19);
    channels.push_back(b1);
    channels.push_back(b3);
    channels.push_back(b5);
    channels.push_back(b7);
    channels.push_back(b9);
    channels.push_back(b11);
    channels.push_back(b13);
    channels.push_back(b15);
/////////////////////////////





    this->t42= new Node("T42", "amplifier", 2, 14);
    this->t45= new Node("T45", "amplifier", 2, 11);
    this->t46= new Node("T46", "amplifier", 6, 14);
    this->t49= new Node("T49", "amplifier", 6, 8);
    this->t51= new Node("T51", "amplifier", 2, 8);
    this->t55= new Node("T55", "amplifier", 6, 18);
    this->t56= new Node("T56", "amplifier", 5, 18);
    this->t57= new Node("T57", "amplifier", 1, 18);
    this->t58= new Node("T58", "amplifier", 2, 18);
    this->t59= new Node("T59", "amplifier", 1, 17);
    this->t60= new Node("T60", "amplifier", 5, 15);
    this->t61= new Node("T61", "amplifier", 5, 14);
    this->t62= new Node("T62", "amplifier", 1, 14);
    this->t63= new Node("T63", "amplifier", 5, 11);
    this->t64= new Node("T64", "amplifier", 1, 11);
    this->t65= new Node("T65", "amplifier", 5, 8);
    this->t66= new Node("T66", "amplifier", 1, 8);
    this->t67= new Node("T67", "amplifier", 5, 5);
    this->t68= new Node("T68", "amplifier", 1, 3);
    this->t69= new Node("T69", "amplifier", 2, 2);
    this->t70= new Node("T70", "amplifier", 1, 2);
    this->t71= new Node("T71", "amplifier", 5, 0);
    this->t72= new Node("T72", "amplifier", 6, 0);

    //subgroup1
    this->t37= new Node("T37", "amplifier", 1, 27);
    this->t38= new Node("T38", "amplifier", 5, 38);
    this->t39= new Node("T39", "amplifier", 1, 36);
    this->t40= new Node("T40", "amplifier", 5, 33);
    this->t41= new Node("T41", "amplifier", 1, 35);
    this->t43= new Node("T43", "amplifier", 1, 30);
    this->t44= new Node("T44", "amplifier", 5, 30);
    this->t47= new Node("T47", "amplifier", 5, 26);
    this->t48= new Node("T48", "amplifier", 5, 27);
    this->t50= new Node("T50", "amplifier", 1, 24);
    this->t52= new Node("T52", "amplifier", 1, 23);
    this->t53= new Node("T53", "amplifier", 5, 23);
////////////////////////////////////


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

    //subgroup1
    amplifiers.push_back(t37);
    amplifiers.push_back(t38);
    amplifiers.push_back(t39);
    amplifiers.push_back(t40);
    amplifiers.push_back(t41);
    amplifiers.push_back(t43);
    amplifiers.push_back(t44);
    amplifiers.push_back(t47);
    amplifiers.push_back(t48);
    amplifiers.push_back(t50);
    amplifiers.push_back(t52);
    amplifiers.push_back(t53);
//////////////////////////////////////////////


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

//subgroup1

    this->s51= new Node("s51", "switch", 1, 22);
    this->s52= new Node("s52", "switch", 2, 22);
    this->s53= new Node("s53", "switch", 3, 22);
    this->s54= new Node("s54", "switch", 4, 22);
    this->s55= new Node("s55", "switch", 5, 22);
    this->s56= new Node("s56", "switch", 6, 22);
    this->s57= new Node("s57", "switch", 0, 25);
    this->s58= new Node("s58", "switch", 1, 25);
    this->s59= new Node("s59", "switch", 2, 25);
    this->s60= new Node("s60", "switch", 3, 25);
    this->s61= new Node("s61", "switch", 4, 25);
    this->s62= new Node("s62", "switch", 5, 25);
    this->s63= new Node("s63", "switch", 6, 25);
    this->s64= new Node("s64", "switch", 7, 25);
    this->s65= new Node("s65", "switch", 0, 28);
    this->s66= new Node("s66", "switch", 1, 28);
    this->s67= new Node("s67", "switch", 2, 28);
    this->s68= new Node("s68", "switch", 3, 28);
    this->s69= new Node("s69", "switch", 4, 28);
    this->s70= new Node("s70", "switch", 5, 28);
    this->s71= new Node("s71", "switch", 6, 28);
    this->s72= new Node("s72", "switch", 7, 28);
    this->s73= new Node("s73", "switch", 0, 31);
    this->s74= new Node("s74", "switch", 1, 31);
    this->s75= new Node("s75", "switch", 2, 31);
    this->s76= new Node("s76", "switch", 3, 31);
    this->s77= new Node("s77", "switch", 4, 31);
    this->s78= new Node("s78", "switch", 5, 31);
    this->s79= new Node("s79", "switch", 6, 31);
    this->s80= new Node("s80", "switch", 7, 31);
    this->s81= new Node("s81", "switch", 0, 34);
    this->s82= new Node("s82", "switch", 1, 34);
    this->s83= new Node("s83", "switch", 2, 34);
    this->s84= new Node("s84", "switch", 3, 34);
    this->s85= new Node("s85", "switch", 4, 34);
    this->s86= new Node("s86", "switch", 5, 34);
    this->s87= new Node("s87", "switch", 6, 34);
    this->s88= new Node("s88", "switch", 7, 34);
    this->s89= new Node("s89", "switch", 1, 37);
    this->s90= new Node("s90", "switch", 2, 37);
    this->s91= new Node("s91", "switch", 5, 37);
    this->s92= new Node("s92", "switch", 6, 37);

    this->s93= new Node("s93", "switch", 6, 38); // no care for coordinates for the moment
    this->s94= new Node("s94", "switch", 5, 38);   // no care for coordinates for the moment
    this->s95= new Node("s95", "switch", 6, 39);  // no care for coordinates for the moment
    this->s96= new Node("s96", "switch", 7, 38);  // no care for coordinates for the moment
    this->s97= new Node("s97", "switch", 7, 36);  // no care for coordinates for the moment
    this->s98= new Node("s98", "switch", 8, 37);  // no care for coordinates for the moment
    this->s99= new Node("s99", "switch", 8, 36);  // no care for coordinates for the moment
    this->s100= new Node("s100", "switch", 7, 37);  // no care for coordinates for the moment



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

    //subgroup1
    switches.push_back(s51);
    switches.push_back(s52);
    switches.push_back(s53);
    switches.push_back(s54);
    switches.push_back(s55);
    switches.push_back(s56);
    switches.push_back(s57);
    switches.push_back(s58);
    switches.push_back(s59);
    switches.push_back(s60);
    switches.push_back(s61);
    switches.push_back(s62);
    switches.push_back(s63);
    switches.push_back(s64);
    switches.push_back(s65);
    switches.push_back(s66);
    switches.push_back(s67);
    switches.push_back(s68);
    switches.push_back(s69);
    switches.push_back(s70);
    switches.push_back(s71);
    switches.push_back(s72);
    switches.push_back(s73);
    switches.push_back(s74);
    switches.push_back(s75);
    switches.push_back(s76);
    switches.push_back(s77);
    switches.push_back(s78);
    switches.push_back(s79);
    switches.push_back(s80);
    switches.push_back(s81);
    switches.push_back(s82);
    switches.push_back(s83);
    switches.push_back(s84);
    switches.push_back(s85);
    switches.push_back(s86);
    switches.push_back(s87);
    switches.push_back(s88);
    switches.push_back(s89);
    switches.push_back(s90);
    switches.push_back(s91);
    switches.push_back(s92);
    switches.push_back(s93);
    switches.push_back(s94);
    switches.push_back(s95);
    switches.push_back(s96);
    switches.push_back(s97);
    switches.push_back(s98);
    switches.push_back(s99);
    switches.push_back(s100);
////////////////////////////////



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

    // subgroup1 l, u, r, d
    c1->setNeighbors(0, 0, 0, s89); // channel neighbors
    c3->setNeighbors(0, 0, 0, s90);
    c5->setNeighbors(0, s91, 0, 0);
    c7->setNeighbors(0, 0, 0, s83);
    c9->setNeighbors(0, 0, 0, s86);

    c11->setNeighbors(0, 0, 0, s87);
    c13->setNeighbors(0, s82, 0, 0);
    c15->setNeighbors(0, 0, 0, s74);

    ta5->setNeighbors(0, 0, 0, s75);
    ta7->setNeighbors(0, 0, 0, s66);

    f13->setNeighbors(0, s71, 0, 0);
    f15->setNeighbors(0, 0, 0, s70);
    f17->setNeighbors(0, 0, 0, s79);
    f19->setNeighbors(0, 0, 0, s78);

    b1->setNeighbors(0, s51, 0, 0); // channel neighbors
    b3->setNeighbors(0, s52, 0, 0);
    b5->setNeighbors(0, s55, 0, 0);
    b7->setNeighbors(0, s59, 0, 0);
    b9->setNeighbors(0, s62, 0, 0);
    b11->setNeighbors(0, s63, 0, 0);
    b13->setNeighbors(0, 0, 0, s58);
    b15->setNeighbors(0, 0, 0, s67);
/////////////////////////////////////


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

    // subgroup1  TO CHECK AGAIN
    t37->setNeighbors(0, s66, 0, 0); // amp neighb sbg1
    t38->setNeighbors(0, 0, 0, s91);
    t39->setNeighbors(0, s89, 0, 0);
    t40->setNeighbors(0, s86, 0, 0);
    t41->setNeighbors(0, 0, 0, s82);
    t43->setNeighbors(0, s74, 0, 0);
    t44->setNeighbors(0, s78, 0, 0);
    t47->setNeighbors(0, 0, 0, s62);
    t48->setNeighbors(0, s70, 0, 0);
    t50->setNeighbors(0, s58, 0, 0);
    t52->setNeighbors(0, 0, 0, s51);
    t53->setNeighbors(0, 0, 0, s55);
    ////////////////////


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
    s27->setNeighbors(s26, s71, s28, s79);
    //s27->setNeighbors(s26, 0, s28, 0);
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
    s47->setNeighbors(s46, s53, s48, s40);
    s48->setNeighbors(s47, s54, s49, s41);
    //s47->setNeighbors(s46, 0, s48, s40);
    //s48->setNeighbors(s47, 0, s49, s41);
    s49->setNeighbors(s48, tb9, s50, t56);
    s50->setNeighbors(s49, e5, s44, t55);

    // SUBGROUP 1
    s51->setNeighbors(s57, t52, s52, b1);   // SBG1 switch neighbors
    s52->setNeighbors(s51, 0, s53, b3);
    s53->setNeighbors(s52, s60, s54, s47);
    s54->setNeighbors(s53, s61, s55, s48);
    s55->setNeighbors(s54, t53, s56, b5);
    s56->setNeighbors(s55, 0, s64, 0);

    s57->setNeighbors(s64, s65, s66, s51);
    s58->setNeighbors(s57, b13, s59, t50);
    s59->setNeighbors(s58, s83, s60, b7);
    s60->setNeighbors(s59, s68, s61, s53);
    s61->setNeighbors(s60, s69, s62, s54);
    s62->setNeighbors(s61, t47, s63, b9);
    s63->setNeighbors(s62, s87, s64, b11);
    s64->setNeighbors(s63, s72, s57, s56);

    s65->setNeighbors(s72, s73, s66, s57);
    s66->setNeighbors(s65, ta7, s67, t37);
    s67->setNeighbors(s66, b15, s68, 0);
    s68->setNeighbors(s67, s76, s69, s60);
    s69->setNeighbors(s68, s77, s70, s61);
    s70->setNeighbors(s69, f15, s71, t48);
    s71->setNeighbors(s70, s27, s72, f13);
    s72->setNeighbors(s71, s80, s65, s64);

    s73->setNeighbors(s80, s81, s74, s65);
    s74->setNeighbors(s73, c15, s75, t43);
    s75->setNeighbors(s74, ta5, s76, 0);
    s76->setNeighbors(s75, s84, s77, s68);
    s77->setNeighbors(s76, s85, s78, s69);
    s78->setNeighbors(s77, f19, s79, t44);
    s79->setNeighbors(s78, f17, s80, s27);
    s80->setNeighbors(s79, s88, s73, s72);

    s81->setNeighbors(s88, s89, s82, s73);
    s82->setNeighbors(s81, t41, s83, c13);
    s83->setNeighbors(s82, c7, s84, s59);
    s84->setNeighbors(s83, s90, s85, s76);
    s85->setNeighbors(s84, s91, s86, s77);
    s86->setNeighbors(s85, c9, s87, t40);
    s87->setNeighbors(s86, c11, s88, s63);
    s88->setNeighbors(s87, s92, s81, s80);

    s89->setNeighbors(s81, c1, s90, t39);
    s90->setNeighbors(s89, c3, s84, 0);
    s91->setNeighbors(s85, t38, s92, c5);
    //s92->setNeighbors(s91, 0, s88, 0);

    s92->setNeighbors(s91, s93, s88, s97);

    s93->setNeighbors(s94, s95, s96, s92);
    s94->setNeighbors(0, 0, s93, 0);
    s95->setNeighbors(0, 0, 0, s93);
    s96->setNeighbors(s93, 0, 0, 0);
    s97->setNeighbors(s98, s92, s99, s100);
    s98->setNeighbors(0, 0, s97, 0);
    s99->setNeighbors(s97, 0, 0, 0);
    s100->setNeighbors(0, s97, 0, 0);
    ///////////////////////////////

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
    testex.push_back(s51);
    testex.push_back(s52);
    testex.push_back(s53);
    testex.push_back(s54);
    testex.push_back(s55);
    testex.push_back(s56);
    testex.push_back(s57);
    testex.push_back(s58);
    testex.push_back(s59);
    testex.push_back(s60);
    testex.push_back(s61);
    testex.push_back(s62);

    testex.push_back(s63);
    testex.push_back(s64);
    testex.push_back(s65);
    testex.push_back(s66);
    testex.push_back(s67);
    testex.push_back(s68);
    testex.push_back(s69);
    testex.push_back(s70);
    testex.push_back(s71);
    testex.push_back(s72);
    testex.push_back(s73);
    testex.push_back(s74);

    testex.push_back(s75);
    testex.push_back(s76);
    testex.push_back(s77);
    testex.push_back(s78);
    testex.push_back(s79);
    testex.push_back(s80);
    testex.push_back(s81);
    testex.push_back(s82);
    testex.push_back(s83);
    testex.push_back(s84);
    testex.push_back(s85);
    testex.push_back(s86);

    testex.push_back(s87);
    testex.push_back(s88);
    testex.push_back(s89);
    testex.push_back(s90);
    testex.push_back(s91);
    testex.push_back(s92);


    testex.push_back(s93);
    testex.push_back(s94);
    testex.push_back(s95);
    testex.push_back(s96);
    testex.push_back(s97);
    testex.push_back(s98);
    testex.push_back(s99);
    testex.push_back(s100);

    ///////////////////////////


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

Payload_100::Payload_100(const Payload_100& orig)
{
}

void Payload_100::clearSettings()
{
    //this->amplifiers;
    //this->channels;
    //this->switches;
}


void Payload_100::createGraph(vector<Node*> switches)   // This function creates the graph given a set of switch objects..
{
    //At the first step creates the links between the neighbor switches.
    //At the second step creates the links between the ports of the same switch, based on its position.

    //cout << "inside create graph" << endl;
    while (!switches.empty())
    {
        Node* current;
        //Node* temp;
        current = switches[0];
        string name = current->getName();

        if (current->isChannel())
        {
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
        else   // if it is a switch
        {
            int current_pos = current->getPos();
            if (current->getLeftNeighbor()
                    && !current->getLeftNeighbor()->isAmplifier()
                    && !current->getLeftNeighbor()->isChannel())
            {
                if (current->getLeftNeighbor()->getRightNeighbor()
                        && (current->getLeftNeighbor()->getRightNeighbor()->getName()).compare(
                            current->getName()) == 0)
                {
                    current->getLeftPort()->addConnection(
                        current->getLeftNeighbor()->getRightPort());

                }
                else if (current->getLeftNeighbor()->getUpNeighbor()
                         && (current->getLeftNeighbor()->getUpNeighbor()->getName()).compare(
                             current->getName()) == 0)
                {
                    current->getLeftPort()->addConnection(
                        current->getLeftNeighbor()->getUpPort());

                }
                else if (current->getLeftNeighbor()->getDownNeighbor()
                         && (current->getLeftNeighbor()->getDownNeighbor()->getName()).compare(
                             current->getName()) == 0)
                {
                    current->getLeftPort()->addConnection(
                        current->getLeftNeighbor()->getDownPort());

                }
                else if (current->getLeftNeighbor()->getLeftNeighbor()
                         && (current->getLeftNeighbor()->getLeftNeighbor()->getName()).compare(
                             current->getName()) == 0)
                {
                    current->getLeftPort()->addConnection(
                        current->getLeftNeighbor()->getLeftPort());

                }
            }                //	 else if(current->getLeftNeighbor() && current->getLeftNeighbor()->isAmplifier() || current->getLeftNeighbor()->isChannel()){
            // 	 		current->getLeftPort()->addConnection(current->getLeftNeighbor()->getName());
            // 	 } else {

            // 	 }
            else if (current->getLeftNeighbor()
                     && current->getLeftNeighbor()->isAmplifier())
            {
                current->getLeftPort()->addConnection(
                    current->getLeftNeighbor()->getName());
            }
            else
            {

            }

            if (current->getRightNeighbor()
                    && !current->getRightNeighbor()->isAmplifier()
                    && !current->getRightNeighbor()->isChannel())
            {

                if (current->getRightNeighbor()->getLeftNeighbor()
                        && (current->getRightNeighbor()->getLeftNeighbor()->getName()).compare(
                            current->getName()) == 0)
                {
                    current->getRightPort()->addConnection(
                        current->getRightNeighbor()->getLeftPort());

                }
                else if (current->getRightNeighbor()->getUpNeighbor()
                         && (current->getRightNeighbor()->getUpNeighbor()->getName()).compare(
                             current->getName()) == 0)
                {
                    current->getRightPort()->addConnection(
                        current->getRightNeighbor()->getUpPort());

                }
                else if (current->getRightNeighbor()->getDownNeighbor()
                         && (current->getRightNeighbor()->getDownNeighbor()->getName()).compare(
                             current->getName()) == 0)
                {
                    current->getRightPort()->addConnection(
                        current->getRightNeighbor()->getDownPort());

                }
                else if (current->getRightNeighbor()->getRightNeighbor()
                         && (current->getRightNeighbor()->getRightNeighbor()->getName()).compare(
                             current->getName()) == 0)
                {
                    current->getRightPort()->addConnection(
                        current->getRightNeighbor()->getRightPort());

                }
            }                //else if(current->getRightNeighbor() && current->getRightNeighbor()->isAmplifier() || current->getRightNeighbor()->isChannel()){
            //		current->getRightPort()->addConnection(current->getRightNeighbor()->getName());
            //} else {

            // }
            else if (current->getRightNeighbor()
                     && current->getRightNeighbor()->isAmplifier())
            {
                current->getRightPort()->addConnection(
                    current->getRightNeighbor()->getName());
            }
            else
            {

            }

            if (current->getUpNeighbor())
            {
                if (!current->getUpNeighbor()->isAmplifier()
                        && !current->getUpNeighbor()->isChannel())
                {

                    if (current->getUpNeighbor()->getLeftNeighbor()
                            && (current->getUpNeighbor()->getLeftNeighbor()->getName()).compare(
                                current->getName()) == 0)
                    {
                        current->getUpPort()->addConnection(
                            current->getUpNeighbor()->getLeftPort());

                    }
                    else if (current->getUpNeighbor()->getUpNeighbor()
                             && (current->getUpNeighbor()->getUpNeighbor()->getName()).compare(
                                 current->getName()) == 0)
                    {
                        current->getUpPort()->addConnection(
                            current->getUpNeighbor()->getUpPort());

                    }
                    else if (current->getUpNeighbor()->getDownNeighbor()
                             && (current->getUpNeighbor()->getDownNeighbor()->getName()).compare(
                                 current->getName()) == 0)
                    {
                        current->getUpPort()->addConnection(
                            current->getUpNeighbor()->getDownPort());

                    }
                    else if (current->getUpNeighbor()->getRightNeighbor()
                             && (current->getUpNeighbor()->getRightNeighbor()->getName()).compare(
                                 current->getName()) == 0)
                    {
                        current->getUpPort()->addConnection(
                            current->getUpNeighbor()->getRightPort());

                    }
                    else
                    {

                    }

                    // 	 } else if(current->getUpNeighbor()->isAmplifier() || current->getUpNeighbor()->isChannel()){
                    // 	 		current->getUpPort()->addConnection(current->getUpNeighbor()->getName());

                    // 	 } else {

                    //	 }

                }
                else if (current->getUpNeighbor()
                         && current->getUpNeighbor()->isAmplifier())
                {
                    current->getUpPort()->addConnection(
                        current->getUpNeighbor()->getName());

                }
                else
                {

                }

            }

            if (current->getDownNeighbor())
            {
                if (!current->getDownNeighbor()->isAmplifier()
                        && !current->getDownNeighbor()->isChannel())
                {

                    if (current->getDownNeighbor()->getLeftNeighbor()
                            && (current->getDownNeighbor()->getLeftNeighbor()->getName()).compare(
                                current->getName()) == 0)
                    {
                        current->getDownPort()->addConnection(
                            current->getDownNeighbor()->getLeftPort());

                    }
                    else if (current->getDownNeighbor()->getUpNeighbor()
                             && (current->getDownNeighbor()->getUpNeighbor()->getName()).compare(
                                 current->getName()) == 0)
                    {
                        current->getDownPort()->addConnection(
                            current->getDownNeighbor()->getUpPort());

                    }
                    else if (current->getDownNeighbor()->getDownNeighbor()
                             && (current->getDownNeighbor()->getDownNeighbor()->getName()).compare(
                                 current->getName()) == 0)
                    {
                        current->getDownPort()->addConnection(
                            current->getDownNeighbor()->getDownPort());

                    }
                    else if (current->getDownNeighbor()->getRightNeighbor()
                             && (current->getDownNeighbor()->getRightNeighbor()->getName()).compare(
                                 current->getName()) == 0)
                    {
                        current->getDownPort()->addConnection(
                            current->getDownNeighbor()->getRightPort());

                    }
                }                    //	 else if(current->getDownNeighbor()->isAmplifier() || current->getDownNeighbor()->isChannel()){
                //	 		current->getDownPort()->addConnection(current->getDownNeighbor()->getName());
                //	 } else{

                //	}
                else if (current->getDownNeighbor()
                         && current->getDownNeighbor()->isAmplifier())
                {
                    current->getDownPort()->addConnection(
                        current->getDownNeighbor()->getName());
                }
                else
                {

                }

            }

            // Fix network based on positions
            if (current_pos == 1)
            {
                current->getLeftPort()->addSwitchPositionConnection(
                    current->getDownPort());
                current->getDownPort()->addSwitchPositionConnection(
                    current->getLeftPort());
                current->getUpPort()->addSwitchPositionConnection(
                    current->getRightPort());
                current->getRightPort()->addSwitchPositionConnection(
                    current->getUpPort());
            }
            else if (current_pos == 4)
            {
                current->getLeftPort()->addSwitchPositionConnection(
                    current->getRightPort());
                current->getRightPort()->addSwitchPositionConnection(
                    current->getLeftPort());
            }
            else if (current_pos == 3)
            {
                current->getLeftPort()->addSwitchPositionConnection(
                    current->getUpPort());
                current->getUpPort()->addSwitchPositionConnection(
                    current->getLeftPort());
                current->getDownPort()->addSwitchPositionConnection(
                    current->getRightPort());
                current->getRightPort()->addSwitchPositionConnection(
                    current->getDownPort());
            }
            else
            {
                current->getDownPort()->addSwitchPositionConnection(
                    current->getUpPort());
                current->getUpPort()->addSwitchPositionConnection(
                    current->getDownPort());
            }

        }

        switches.erase(switches.begin());
    }
}



Port* Payload_100::getChannelsNeighborPort(Node* s)
{
    Node* t;
    t = s->getChannelNeighbor(s);
    if (t->getLeftNeighbor()
            && t->getLeftNeighbor()->getName().compare(s->getName()) == 0)
    {
        return t->getLeftPort();
    }
    else if (t->getRightNeighbor()
             && t->getRightNeighbor()->getName().compare(s->getName())
             == 0)
    {
        return t->getRightPort();
    }
    else if (t->getUpNeighbor()
             && t->getUpNeighbor()->getName().compare(s->getName()) == 0)
    {
        return t->getUpPort();
    }
    else
    {
        return t->getDownPort();
    }
}


vector<int> Payload_100::existsPathInGraph(Node* chan)   // check for a given channel object if a path to an amplifier exists.
{
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

    if (p1->getSwitchPositionConnection())
    {
        p2 = p1->getSwitchPositionConnection();
        path.push_back(p2);
    }
    else
    {
        result = 0;
        pathsLength.push_back(0);
        pathsLength.push_back(0);
        return pathsLength;
    }

    while (p2->getStringConnection().empty())
    {
        if (p2->getPortConnection())
        {
            p3 = p2->getPortConnection();
            path.push_back(p3);
        }
        else
        {
            break;
        }

        p1 = p3;
        if (p1->getSwitchPositionConnection())
        {
            p2 = p1->getSwitchPositionConnection();
            path.push_back(p2);
        }
        else
        {
            break;
        }
    }
    if (!p2->getStringConnection().empty())
    {

        std::vector<std::string> pathStringVec;// this will hold whole path string names
        std::string pre="";
        std::string delimiter = "_";

        pathStringVec.push_back(chan->getName());

        for (unsigned int t = 0; t < path.size(); t++)
        {
            std::string currentItem = path[t]->getName();
            currentItem = currentItem.substr(0, currentItem.find(delimiter));
            if(currentItem.compare(pre)!=0)
            {
                pathStringVec.push_back(currentItem);
            }
            pre=currentItem;
        }
        pathStringVec.push_back(p2->getStringConnection());


        //for (unsigned int t = 0; t < pathStringVec.size(); t++) {
        //    cout << pathStringVec[t] << "-";
        //}
        //cout << endl;

#ifdef DEBUG_ALL

        cout << "Path found for " << chan->getName() << " !!!" << endl;
        for (int t = 0; t < path.size(); t++)
        {
            cout << path[t]->getName() << endl;
        }
        cout << p2->getStringConnection() << endl;
#endif
        result = 1;
        pathsLength.push_back(1);
        pathsLength.push_back(path.size() / 2);
    }
    else
    {
#ifdef DEBUG_ALL
        cout << " No path for " << chan->getName() << endl;
#endif
        result = 0;
        pathsLength.push_back(0);
        pathsLength.push_back(0);
    }
    return pathsLength;
}

vector<double> Payload_100::run(vector<int> position_vector,
                                vector<string> chan_instance)   // here i define all the objects that exist in my network (switches, ports, channels etc..)
{

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
    Port *s39_port_l = new Port("s29_port_l");
    Port *s39_port_u = new Port("s29_port_u");
    Port *s39_port_r = new Port("s29_port_r");
    Port *s39_port_d = new Port("s29_port_d");
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


    // SUBGROUP 1
    Port *s51_port_l = new Port("s51_port_l");
    Port *s51_port_u = new Port("s51_port_u");
    Port *s51_port_r = new Port("s51_port_r");
    Port *s51_port_d = new Port("s51_port_d");
    s51->setPorts(s51_port_l, s51_port_u, s51_port_r, s51_port_d);
    Port *s52_port_l = new Port("s52_port_l");
    Port *s52_port_u = new Port("s52_port_u");
    Port *s52_port_r = new Port("s52_port_r");
    Port *s52_port_d = new Port("s52_port_d");
    s52->setPorts(s52_port_l, s52_port_u, s52_port_r, s52_port_d);
    Port *s53_port_l = new Port("s53_port_l");
    Port *s53_port_u = new Port("s53_port_u");
    Port *s53_port_r = new Port("s53_port_r");
    Port *s53_port_d = new Port("s53_port_d");
    s53->setPorts(s53_port_l, s53_port_u, s53_port_r, s53_port_d);
    Port *s54_port_l = new Port("s54_port_l");
    Port *s54_port_u = new Port("s54_port_u");
    Port *s54_port_r = new Port("s54_port_r");
    Port *s54_port_d = new Port("s54_port_d");
    s54->setPorts(s54_port_l, s54_port_u, s54_port_r, s54_port_d);
    Port *s55_port_l = new Port("s55_port_l");
    Port *s55_port_u = new Port("s55_port_u");
    Port *s55_port_r = new Port("s55_port_r");
    Port *s55_port_d = new Port("s55_port_d");
    s55->setPorts(s55_port_l, s55_port_u, s55_port_r, s55_port_d);
    Port *s56_port_l = new Port("s56_port_l");
    Port *s56_port_u = new Port("s56_port_u");
    Port *s56_port_r = new Port("s56_port_r");
    Port *s56_port_d = new Port("s56_port_d");
    s56->setPorts(s56_port_l, s56_port_u, s56_port_r, s56_port_d);
    Port *s57_port_l = new Port("s57_port_l");
    Port *s57_port_u = new Port("s57_port_u");
    Port *s57_port_r = new Port("s57_port_r");
    Port *s57_port_d = new Port("s57_port_d");
    s57->setPorts(s57_port_l, s57_port_u, s57_port_r, s57_port_d);
    Port *s58_port_l = new Port("s58_port_l");
    Port *s58_port_u = new Port("s58_port_u");
    Port *s58_port_r = new Port("s58_port_r");
    Port *s58_port_d = new Port("s58_port_d");
    s58->setPorts(s58_port_l, s58_port_u, s58_port_r, s58_port_d);
    Port *s59_port_l = new Port("s59_port_l");
    Port *s59_port_u = new Port("s59_port_u");
    Port *s59_port_r = new Port("s59_port_r");
    Port *s59_port_d = new Port("s59_port_d");
    s59->setPorts(s59_port_l, s59_port_u, s59_port_r, s59_port_d);
    Port *s60_port_l = new Port("s60_port_l");
    Port *s60_port_u = new Port("s60_port_u");
    Port *s60_port_r = new Port("s60_port_r");
    Port *s60_port_d = new Port("s60_port_d");
    s60->setPorts(s60_port_l, s60_port_u, s60_port_r, s60_port_d);

    Port *s61_port_l = new Port("s61_port_l");
    Port *s61_port_u = new Port("s61_port_u");
    Port *s61_port_r = new Port("s61_port_r");
    Port *s61_port_d = new Port("s61_port_d");
    s61->setPorts(s61_port_l, s61_port_u, s61_port_r, s61_port_d);
    Port *s62_port_l = new Port("s62_port_l");
    Port *s62_port_u = new Port("s62_port_u");
    Port *s62_port_r = new Port("s62_port_r");
    Port *s62_port_d = new Port("s62_port_d");
    s62->setPorts(s62_port_l, s62_port_u, s62_port_r, s62_port_d);
    Port *s63_port_l = new Port("s63_port_l");
    Port *s63_port_u = new Port("s63_port_u");
    Port *s63_port_r = new Port("s63_port_r");
    Port *s63_port_d = new Port("s63_port_d");
    s63->setPorts(s63_port_l, s63_port_u, s63_port_r, s63_port_d);
    Port *s64_port_l = new Port("s64_port_l");
    Port *s64_port_u = new Port("s64_port_u");
    Port *s64_port_r = new Port("s64_port_r");
    Port *s64_port_d = new Port("s64_port_d");
    s64->setPorts(s64_port_l, s64_port_u, s64_port_r, s64_port_d);
    Port *s65_port_l = new Port("s65_port_l");
    Port *s65_port_u = new Port("s65_port_u");
    Port *s65_port_r = new Port("s65_port_r");
    Port *s65_port_d = new Port("s65_port_d");
    s65->setPorts(s65_port_l, s65_port_u, s65_port_r, s65_port_d);
    Port *s66_port_l = new Port("s66_port_l");
    Port *s66_port_u = new Port("s66_port_u");
    Port *s66_port_r = new Port("s66_port_r");
    Port *s66_port_d = new Port("s66_port_d");
    s66->setPorts(s66_port_l, s66_port_u, s66_port_r, s66_port_d);
    Port *s67_port_l = new Port("s67_port_l");
    Port *s67_port_u = new Port("s67_port_u");
    Port *s67_port_r = new Port("s67_port_r");
    Port *s67_port_d = new Port("s67_port_d");
    s67->setPorts(s67_port_l, s67_port_u, s67_port_r, s67_port_d);
    Port *s68_port_l = new Port("s68_port_l");
    Port *s68_port_u = new Port("s68_port_u");
    Port *s68_port_r = new Port("s68_port_r");
    Port *s68_port_d = new Port("s68_port_d");
    s68->setPorts(s68_port_l, s68_port_u, s68_port_r, s68_port_d);
    Port *s69_port_l = new Port("s69_port_l");
    Port *s69_port_u = new Port("s69_port_u");
    Port *s69_port_r = new Port("s69_port_r");
    Port *s69_port_d = new Port("s69_port_d");
    s69->setPorts(s69_port_l, s69_port_u, s69_port_r, s69_port_d);
    Port *s70_port_l = new Port("s70_port_l");
    Port *s70_port_u = new Port("s70_port_u");
    Port *s70_port_r = new Port("s70_port_r");
    Port *s70_port_d = new Port("s70_port_d");
    s70->setPorts(s70_port_l, s70_port_u, s70_port_r, s70_port_d);
    Port *s71_port_l = new Port("s71_port_l");
    Port *s71_port_u = new Port("s71_port_u");
    Port *s71_port_r = new Port("s71_port_r");
    Port *s71_port_d = new Port("s71_port_d");
    s71->setPorts(s71_port_l, s71_port_u, s71_port_r, s71_port_d);
    Port *s72_port_l = new Port("s72_port_l");
    Port *s72_port_u = new Port("s72_port_u");
    Port *s72_port_r = new Port("s72_port_r");
    Port *s72_port_d = new Port("s72_port_d");
    s72->setPorts(s72_port_l, s72_port_u, s72_port_r, s72_port_d);
    Port *s73_port_l = new Port("s73_port_l");
    Port *s73_port_u = new Port("s73_port_u");
    Port *s73_port_r = new Port("s73_port_r");
    Port *s73_port_d = new Port("s73_port_d");
    s73->setPorts(s73_port_l, s73_port_u, s73_port_r, s73_port_d);
    Port *s74_port_l = new Port("s74_port_l");
    Port *s74_port_u = new Port("s74_port_u");
    Port *s74_port_r = new Port("s74_port_r");
    Port *s74_port_d = new Port("s74_port_d");
    s74->setPorts(s74_port_l, s74_port_u, s74_port_r, s74_port_d);
    Port *s75_port_l = new Port("s75_port_l");
    Port *s75_port_u = new Port("s75_port_u");
    Port *s75_port_r = new Port("s75_port_r");
    Port *s75_port_d = new Port("s75_port_d");
    s75->setPorts(s75_port_l, s75_port_u, s75_port_r, s75_port_d);
    Port *s76_port_l = new Port("s76_port_l");
    Port *s76_port_u = new Port("s76_port_u");
    Port *s76_port_r = new Port("s76_port_r");
    Port *s76_port_d = new Port("s76_port_d");
    s76->setPorts(s76_port_l, s76_port_u, s76_port_r, s76_port_d);
    Port *s77_port_l = new Port("s77_port_l");
    Port *s77_port_u = new Port("s77_port_u");
    Port *s77_port_r = new Port("s77_port_r");
    Port *s77_port_d = new Port("s77_port_d");
    s77->setPorts(s77_port_l, s77_port_u, s77_port_r, s77_port_d);
    Port *s78_port_l = new Port("s78_port_l");
    Port *s78_port_u = new Port("s78_port_u");
    Port *s78_port_r = new Port("s78_port_r");
    Port *s78_port_d = new Port("s78_port_d");
    s78->setPorts(s78_port_l, s78_port_u, s78_port_r, s78_port_d);
    Port *s79_port_l = new Port("s79_port_l");
    Port *s79_port_u = new Port("s79_port_u");
    Port *s79_port_r = new Port("s79_port_r");
    Port *s79_port_d = new Port("s79_port_d");
    s79->setPorts(s79_port_l, s79_port_u, s79_port_r, s79_port_d);
    Port *s80_port_l = new Port("s80_port_l");
    Port *s80_port_u = new Port("s80_port_u");
    Port *s80_port_r = new Port("s80_port_r");
    Port *s80_port_d = new Port("s80_port_d");
    s80->setPorts(s80_port_l, s80_port_u, s80_port_r, s80_port_d);
    Port *s81_port_l = new Port("s81_port_l");
    Port *s81_port_u = new Port("s81_port_u");
    Port *s81_port_r = new Port("s81_port_r");
    Port *s81_port_d = new Port("s81_port_d");
    s81->setPorts(s81_port_l, s81_port_u, s81_port_r, s81_port_d);
    Port *s82_port_l = new Port("s82_port_l");
    Port *s82_port_u = new Port("s82_port_u");
    Port *s82_port_r = new Port("s82_port_r");
    Port *s82_port_d = new Port("s82_port_d");
    s82->setPorts(s82_port_l, s82_port_u, s82_port_r, s82_port_d);
    Port *s83_port_l = new Port("s83_port_l");
    Port *s83_port_u = new Port("s83_port_u");
    Port *s83_port_r = new Port("s83_port_r");
    Port *s83_port_d = new Port("s83_port_d");
    s83->setPorts(s83_port_l, s83_port_u, s83_port_r, s83_port_d);
    Port *s84_port_l = new Port("s84_port_l");
    Port *s84_port_u = new Port("s84_port_u");
    Port *s84_port_r = new Port("s84_port_r");
    Port *s84_port_d = new Port("s84_port_d");
    s84->setPorts(s84_port_l, s84_port_u, s84_port_r, s84_port_d);
    Port *s85_port_l = new Port("s85_port_l");
    Port *s85_port_u = new Port("s85_port_u");
    Port *s85_port_r = new Port("s85_port_r");
    Port *s85_port_d = new Port("s85_port_d");
    s85->setPorts(s85_port_l, s85_port_u, s85_port_r, s85_port_d);
    Port *s86_port_l = new Port("s86_port_l");
    Port *s86_port_u = new Port("s86_port_u");
    Port *s86_port_r = new Port("s86_port_r");
    Port *s86_port_d = new Port("s86_port_d");
    s86->setPorts(s86_port_l, s86_port_u, s86_port_r, s86_port_d);
    Port *s87_port_l = new Port("s87_port_l");
    Port *s87_port_u = new Port("s87_port_u");
    Port *s87_port_r = new Port("s87_port_r");
    Port *s87_port_d = new Port("s87_port_d");
    s87->setPorts(s87_port_l, s87_port_u, s87_port_r, s87_port_d);
    Port *s88_port_l = new Port("s88_port_l");
    Port *s88_port_u = new Port("s88_port_u");
    Port *s88_port_r = new Port("s88_port_r");
    Port *s88_port_d = new Port("s88_port_d");
    s88->setPorts(s88_port_l, s88_port_u, s88_port_r, s88_port_d);
    Port *s89_port_l = new Port("s89_port_l");
    Port *s89_port_u = new Port("s89_port_u");
    Port *s89_port_r = new Port("s89_port_r");
    Port *s89_port_d = new Port("s89_port_d");
    s89->setPorts(s89_port_l, s89_port_u, s89_port_r, s89_port_d);
    Port *s90_port_l = new Port("s90_port_l");
    Port *s90_port_u = new Port("s90_port_u");
    Port *s90_port_r = new Port("s90_port_r");
    Port *s90_port_d = new Port("s90_port_d");
    s90->setPorts(s90_port_l, s90_port_u, s90_port_r, s90_port_d);


    Port *s91_port_l = new Port("s91_port_l");
    Port *s91_port_u = new Port("s91_port_u");
    Port *s91_port_r = new Port("s91_port_r");
    Port *s91_port_d = new Port("s91_port_d");
    s91->setPorts(s91_port_l, s91_port_u, s91_port_r, s91_port_d);
    Port *s92_port_l = new Port("s92_port_l");
    Port *s92_port_u = new Port("s92_port_u");
    Port *s92_port_r = new Port("s92_port_r");
    Port *s92_port_d = new Port("s92_port_d");
    s92->setPorts(s92_port_l, s92_port_u, s92_port_r, s92_port_d);



    Port *s93_port_l = new Port("s93_port_l");
    Port *s93_port_u = new Port("s93_port_u");
    Port *s93_port_r = new Port("s93_port_r");
    Port *s93_port_d = new Port("s93_port_d");
    s93->setPorts(s93_port_l, s93_port_u, s93_port_r, s93_port_d);


    Port *s94_port_l = new Port("s94_port_l");
    Port *s94_port_u = new Port("s94_port_u");
    Port *s94_port_r = new Port("s94_port_r");
    Port *s94_port_d = new Port("s94_port_d");
    s94->setPorts(s94_port_l, s94_port_u, s94_port_r, s94_port_d);
    Port *s95_port_l = new Port("s95_port_l");
    Port *s95_port_u = new Port("s95_port_u");
    Port *s95_port_r = new Port("s95_port_r");
    Port *s95_port_d = new Port("s95_port_d");
    s95->setPorts(s95_port_l, s95_port_u, s95_port_r, s95_port_d);
    Port *s96_port_l = new Port("s96_port_l");
    Port *s96_port_u = new Port("s96_port_u");
    Port *s96_port_r = new Port("s96_port_r");
    Port *s96_port_d = new Port("s96_port_d");
    s96->setPorts(s96_port_l, s96_port_u, s96_port_r, s96_port_d);
    Port *s97_port_l = new Port("s97_port_l");
    Port *s97_port_u = new Port("s97_port_u");
    Port *s97_port_r = new Port("s97_port_r");
    Port *s97_port_d = new Port("s97_port_d");
    s97->setPorts(s97_port_l, s97_port_u, s97_port_r, s97_port_d);
    Port *s98_port_l = new Port("s98_port_l");
    Port *s98_port_u = new Port("s98_port_u");
    Port *s98_port_r = new Port("s98_port_r");
    Port *s98_port_d = new Port("s98_port_d");
    s98->setPorts(s98_port_l, s98_port_u, s98_port_r, s98_port_d);
    Port *s99_port_l = new Port("s99_port_l");
    Port *s99_port_u = new Port("s99_port_u");
    Port *s99_port_r = new Port("s99_port_r");
    Port *s99_port_d = new Port("s99_port_d");
    s99->setPorts(s99_port_l, s99_port_u, s99_port_r, s99_port_d);
    Port *s100_port_l = new Port("s100_port_l");
    Port *s100_port_u = new Port("s100_port_u");
    Port *s100_port_r = new Port("s100_port_r");
    Port *s100_port_d = new Port("s100_port_d");
    s100->setPorts(s100_port_l, s100_port_u, s100_port_r, s100_port_d);


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
    testex.push_back(s51);
    testex.push_back(s52);
    testex.push_back(s53);
    testex.push_back(s54);
    testex.push_back(s55);
    testex.push_back(s56);
    testex.push_back(s57);
    testex.push_back(s58);
    testex.push_back(s59);
    testex.push_back(s60);
    testex.push_back(s61);
    testex.push_back(s62);
    testex.push_back(s63);
    testex.push_back(s64);
    testex.push_back(s65);
    testex.push_back(s66);
    testex.push_back(s67);
    testex.push_back(s68);
    testex.push_back(s69);
    testex.push_back(s70);
    testex.push_back(s71);
    testex.push_back(s72);
    testex.push_back(s73);
    testex.push_back(s74);
    testex.push_back(s75);
    testex.push_back(s76);
    testex.push_back(s77);
    testex.push_back(s78);
    testex.push_back(s79);
    testex.push_back(s80);
    testex.push_back(s81);
    testex.push_back(s82);
    testex.push_back(s83);
    testex.push_back(s84);
    testex.push_back(s85);
    testex.push_back(s86);
    testex.push_back(s87);
    testex.push_back(s88);
    testex.push_back(s89);
    testex.push_back(s90);
    testex.push_back(s91);
    testex.push_back(s92);

    testex.push_back(s93);
    testex.push_back(s94);
    testex.push_back(s95);
    testex.push_back(s96);
    testex.push_back(s97);
    testex.push_back(s98);
    testex.push_back(s99);
    testex.push_back(s100);


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


    testex.push_back(c1);
    testex.push_back(c3);
    testex.push_back(c5);
    testex.push_back(c7);
    testex.push_back(c9);
    testex.push_back(c11);
    testex.push_back(c13);
    testex.push_back(c15);
    testex.push_back(tg5);
    testex.push_back(tg7);
    testex.push_back(f13);
    testex.push_back(f15);
    testex.push_back(f17);
    testex.push_back(f19);
    testex.push_back(b1);
    testex.push_back(b3);
    testex.push_back(b5);
    testex.push_back(b7);
    testex.push_back(b9);
    testex.push_back(b11);
    testex.push_back(b13);
    testex.push_back(b15);

    for (unsigned int r = 0; r < position_vector.size(); r++)
    {
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
    for (unsigned int r = 0; r < chan_instance.size(); r++)
    {
        for (unsigned int j = 0; j < this->channels.size(); j++)
        {
            if (chan_instance[r] == this->channels[j]->getName())
            {
                channels_to_test_path.push_back(this->channels[j]);
                break;
            }
        }
    }

    //cout << "after filling channels to test path" << endl;
    vector<int> vv;
    unsigned int ConstructedPaths=0;//No of paths that has been created
    int LongestPathLenght=0;
    //cout << "before checking path existance for " << channels_to_test_path.size() << " channels" << endl;
    for (unsigned int y = 0; y < channels_to_test_path.size(); y++)
    {
        vv = existsPathInGraph(channels_to_test_path[y]);
        //cout << "after checking path existance for " << y << " one" << endl;
        int path = vv[0];
        int length = vv[1];
        ConstructedPaths = ConstructedPaths + path;

        if (length > LongestPathLenght)
        {
            LongestPathLenght = length;
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

    if (ConstructedPaths < channels_to_test_path.size())
    {
        qualityMetric=((channels_to_test_path.size() - ConstructedPaths) * penaltyCoeff)+LongestPathLenght*penaltyLPLCoeff;
        //qualityMetric=penaltyCoeff+LongestPathLenght;
    }
    else
    {
        qualityMetric=LongestPathLenght;
    }
    result.push_back(qualityMetric);
    result.push_back(ConstructedPaths);
    result.push_back(LongestPathLenght);
    /*
        /////////////////////////
        cout << "\nNo of switches :" << this->switches.size() << endl;
        for(int i=0;i<this->switches.size();i++){
            //cout << i << "= " << this->switches[i]->getName() << endl;
            //switches[i]->~Node();
        }
        cout << "\nNo of Amplifiers :" << this->amplifiers.size() << endl;
        for(int i=0;i<this->amplifiers.size();i++){
            //cout << i << "= " << this->amplifiers[i]->getName() << endl;
            //amplifiers[i]->~Node();
        }
        cout << "\nNo of channels :" << this->channels.size() << endl;
        for(int i=0;i<this->channels.size();i++){
            //cout << i << "= " << this->channels[i]->getName() << endl;
            //channels[i]->~Node();
        }
     */
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


    // SUBGROUP 1
    delete s51_port_l;//new Port("s51_port_l");
    delete s51_port_u;//new Port("s51_port_u");
    delete s51_port_r;//new Port("s51_port_r");
    delete s51_port_d;//new Port("s51_port_d");
    delete s52_port_l;//new Port("s52_port_l");
    delete s52_port_u;//new Port("s52_port_u");
    delete s52_port_r;//new Port("s52_port_r");
    delete s52_port_d;//new Port("s52_port_d");
    delete s53_port_l;//new Port("s53_port_l");
    delete s53_port_u;//new Port("s53_port_u");
    delete s53_port_r;//new Port("s53_port_r");
    delete s53_port_d;//new Port("s53_port_d");
    delete s54_port_l;//new Port("s54_port_l");
    delete s54_port_u;//new Port("s54_port_u");
    delete s54_port_r;//new Port("s54_port_r");
    delete s54_port_d;//new Port("s54_port_d");
    delete s55_port_l;//new Port("s55_port_l");
    delete s55_port_u;//new Port("s55_port_u");
    delete s55_port_r;//new Port("s55_port_r");
    delete s55_port_d;//new Port("s55_port_d");
    delete s56_port_l;//new Port("s56_port_l");
    delete s56_port_u;//new Port("s56_port_u");
    delete s56_port_r;//new Port("s56_port_r");
    delete s56_port_d;//new Port("s56_port_d");
    delete s57_port_l;//new Port("s57_port_l");
    delete s57_port_u;//new Port("s57_port_u");
    delete s57_port_r;//new Port("s57_port_r");
    delete s57_port_d;//new Port("s57_port_d");
    delete s58_port_l;//new Port("s58_port_l");
    delete s58_port_u;//new Port("s58_port_u");
    delete s58_port_r;//new Port("s58_port_r");
    delete s58_port_d;//new Port("s58_port_d");
    delete s59_port_l;//new Port("s59_port_l");
    delete s59_port_u;//new Port("s59_port_u");
    delete s59_port_r;//new Port("s59_port_r");
    delete s59_port_d;//new Port("s59_port_d");
    delete s60_port_l;//new Port("s60_port_l");
    delete s60_port_u;//new Port("s60_port_u");
    delete s60_port_r;//new Port("s60_port_r");
    delete s60_port_d;//new Port("s60_port_d");

    delete s61_port_l;//new Port("s61_port_l");
    delete s61_port_u;//new Port("s61_port_u");
    delete s61_port_r;//new Port("s61_port_r");
    delete s61_port_d;//new Port("s61_port_d");
    delete s62_port_l;//new Port("s62_port_l");
    delete s62_port_u;//new Port("s62_port_u");
    delete s62_port_r;//new Port("s62_port_r");
    delete s62_port_d;//new Port("s62_port_d");
    delete s63_port_l;//new Port("s63_port_l");
    delete s63_port_u;//new Port("s63_port_u");
    delete s63_port_r;//new Port("s63_port_r");
    delete s63_port_d;//new Port("s63_port_d");
    delete s64_port_l;//new Port("s64_port_l");
    delete s64_port_u;//new Port("s64_port_u");
    delete s64_port_r;//new Port("s64_port_r");
    delete s64_port_d;//new Port("s64_port_d");
    delete s65_port_l;//new Port("s65_port_l");
    delete s65_port_u;//new Port("s65_port_u");
    delete s65_port_r;//new Port("s65_port_r");
    delete s65_port_d;//new Port("s65_port_d");
    delete s66_port_l;//new Port("s66_port_l");
    delete s66_port_u;//new Port("s66_port_u");
    delete s66_port_r;//new Port("s66_port_r");
    delete s66_port_d;//new Port("s66_port_d");
    delete s67_port_l;//new Port("s67_port_l");
    delete s67_port_u;//new Port("s67_port_u");
    delete s67_port_r;//new Port("s67_port_r");
    delete s67_port_d;//new Port("s67_port_d");
    delete s68_port_l;//new Port("s68_port_l");
    delete s68_port_u;//new Port("s68_port_u");
    delete s68_port_r;//new Port("s68_port_r");
    delete s68_port_d;//new Port("s68_port_d");
    delete s69_port_l;//new Port("s69_port_l");
    delete s69_port_u;//new Port("s69_port_u");
    delete s69_port_r;//new Port("s69_port_r");
    delete s69_port_d;//new Port("s69_port_d");
    delete s70_port_l;//new Port("s70_port_l");
    delete s70_port_u;//new Port("s70_port_u");
    delete s70_port_r;//new Port("s70_port_r");
    delete s70_port_d;//new Port("s70_port_d");
    delete s71_port_l;//new Port("s71_port_l");
    delete s71_port_u;//new Port("s71_port_u");
    delete s71_port_r;//new Port("s71_port_r");
    delete s71_port_d;//new Port("s71_port_d");
    delete s72_port_l;//new Port("s72_port_l");
    delete s72_port_u;//new Port("s72_port_u");
    delete s72_port_r;//new Port("s72_port_r");
    delete s72_port_d;//new Port("s72_port_d");
    delete s73_port_l;//new Port("s73_port_l");
    delete s73_port_u;//new Port("s73_port_u");
    delete s73_port_r;//new Port("s73_port_r");
    delete s73_port_d;//new Port("s73_port_d");
    delete s74_port_l;//new Port("s74_port_l");
    delete s74_port_u;//new Port("s74_port_u");
    delete s74_port_r;//new Port("s74_port_r");
    delete s74_port_d;//new Port("s74_port_d");
    delete s75_port_l;//new Port("s75_port_l");
    delete s75_port_u;//new Port("s75_port_u");
    delete s75_port_r;//new Port("s75_port_r");
    delete s75_port_d;//new Port("s75_port_d");
    delete s76_port_l;//new Port("s76_port_l");
    delete s76_port_u;//new Port("s76_port_u");
    delete s76_port_r;//new Port("s76_port_r");
    delete s76_port_d;//new Port("s76_port_d");
    delete s77_port_l;//new Port("s77_port_l");
    delete s77_port_u;//new Port("s77_port_u");
    delete s77_port_r;//new Port("s77_port_r");
    delete s77_port_d;//new Port("s77_port_d");
    delete s78_port_l;//new Port("s78_port_l");
    delete s78_port_u;//new Port("s78_port_u");
    delete s78_port_r;//new Port("s78_port_r");
    delete s78_port_d;//new Port("s78_port_d");
    delete s79_port_l;//new Port("s79_port_l");
    delete s79_port_u;//new Port("s79_port_u");
    delete s79_port_r;//new Port("s79_port_r");
    delete s79_port_d;//new Port("s79_port_d");
    delete s80_port_l;//new Port("s80_port_l");
    delete s80_port_u;//new Port("s80_port_u");
    delete s80_port_r;//new Port("s80_port_r");
    delete s80_port_d;//new Port("s80_port_d");
    delete s81_port_l;//new Port("s81_port_l");
    delete s81_port_u;//new Port("s81_port_u");
    delete s81_port_r;//new Port("s81_port_r");
    delete s81_port_d;//new Port("s81_port_d");
    delete s82_port_l;//new Port("s82_port_l");
    delete s82_port_u;//new Port("s82_port_u");
    delete s82_port_r;//new Port("s82_port_r");
    delete s82_port_d;//new Port("s82_port_d");
    delete s83_port_l;//new Port("s83_port_l");
    delete s83_port_u;//new Port("s83_port_u");
    delete s83_port_r;//new Port("s83_port_r");
    delete s83_port_d;//new Port("s83_port_d");
    delete s84_port_l;//new Port("s84_port_l");
    delete s84_port_u;//new Port("s84_port_u");
    delete s84_port_r;//new Port("s84_port_r");
    delete s84_port_d;//new Port("s84_port_d");
    delete s85_port_l;//new Port("s85_port_l");
    delete s85_port_u;//new Port("s85_port_u");
    delete s85_port_r;//new Port("s85_port_r");
    delete s85_port_d;//new Port("s85_port_d");
    delete s86_port_l;//new Port("s86_port_l");
    delete s86_port_u;//new Port("s86_port_u");
    delete s86_port_r;//new Port("s86_port_r");
    delete s86_port_d;//new Port("s86_port_d");
    delete s87_port_l;//new Port("s87_port_l");
    delete s87_port_u;//new Port("s87_port_u");
    delete s87_port_r;//new Port("s87_port_r");
    delete s87_port_d;//new Port("s87_port_d");
    delete s88_port_l;//new Port("s88_port_l");
    delete s88_port_u;//new Port("s88_port_u");
    delete s88_port_r;//new Port("s88_port_r");
    delete s88_port_d;//new Port("s88_port_d");
    delete s89_port_l;//new Port("s89_port_l");
    delete s89_port_u;//new Port("s89_port_u");
    delete s89_port_r;//new Port("s89_port_r");
    delete s89_port_d;//new Port("s89_port_d");
    delete s90_port_l;//new Port("s90_port_l");
    delete s90_port_u;//new Port("s90_port_u");
    delete s90_port_r;//new Port("s90_port_r");
    delete s90_port_d;//new Port("s90_port_d");


    delete s91_port_l;//new Port("s91_port_l");
    delete s91_port_u;//new Port("s91_port_u");
    delete s91_port_r;//new Port("s91_port_r");
    delete s91_port_d;//new Port("s91_port_d");
    delete s92_port_l;//new Port("s92_port_l");
    delete s92_port_u;//new Port("s92_port_u");
    delete s92_port_r;//new Port("s92_port_r");
    delete s92_port_d;//new Port("s92_port_d");



    delete s93_port_l;//new Port("s93_port_l");
    delete s93_port_u;//new Port("s93_port_u");
    delete s93_port_r;//new Port("s93_port_r");
    delete s93_port_d;//new Port("s93_port_d");


    delete s94_port_l;//new Port("s94_port_l");
    delete s94_port_u;//new Port("s94_port_u");
    delete s94_port_r;//new Port("s94_port_r");
    delete s94_port_d;//new Port("s94_port_d");
    delete s95_port_l;//new Port("s95_port_l");
    delete s95_port_u;//new Port("s95_port_u");
    delete s95_port_r;//new Port("s95_port_r");
    delete s95_port_d;//new Port("s95_port_d");
    delete s96_port_l;//new Port("s96_port_l");
    delete s96_port_u;//new Port("s96_port_u");
    delete s96_port_r;//new Port("s96_port_r");
    delete s96_port_d;//new Port("s96_port_d");
    delete s97_port_l;//new Port("s97_port_l");
    delete s97_port_u;//new Port("s97_port_u");
    delete s97_port_r;//new Port("s97_port_r");
    delete s97_port_d;//new Port("s97_port_d");
    delete s98_port_l;//new Port("s98_port_l");
    delete s98_port_u;//new Port("s98_port_u");
    delete s98_port_r;//new Port("s98_port_r");
    delete s98_port_d;//new Port("s98_port_d");
    delete s99_port_l;//new Port("s99_port_l");
    delete s99_port_u;//new Port("s99_port_u");
    delete s99_port_r;//new Port("s99_port_r");
    delete s99_port_d;//new Port("s99_port_d");
    delete s100_port_l;//new Port("s100_port_l");
    delete s100_port_u;//new Port("s100_port_u");
    delete s100_port_r;//new Port("s100_port_r");
    delete s100_port_d;//new Port("s100_port_d");



    testex.clear();
    //testex.~vector();

    return result;
}


double Payload_100::calcPathLoss(vector<std::string> pathStrVec)
{
    double pathLoss;

    return pathLoss;
}



Payload_100::~Payload_100()
{

    /*
    cout << "\nNo of Amplifiers :" << this->amplifiers.size() << endl;
    for(int i=0;i<this->amplifiers.size();i++){
        cout << i << "= " << this->amplifiers[i].getName() << endl;
        //this->amplifiers[i].~Node();
    }
    cout << "\nNo of channels :" << this->channels.size() << endl;
    for(int i=0;i<this->channels.size();i++){
        cout << i << "= " << this->channels[i].getName() << endl;
        //this->channels[i].~Node();
    }

    cout << "\nNo of switches :" << this->switches.size() << endl;
    for(int i=0;i<this->switches.size();i++){
        cout << i << "= " << this->switches[i].getName() << endl;
        //this->switches[i].~Node();
    }
    */
}

