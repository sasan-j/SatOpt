/* 
 * File:   Port.cpp
 * Author: sasan
 * 
 * Created on March 28, 2013, 6:17 PM
 */

#include "../inc/Port.h"

/*
Port::Port(const Port& orig) {
}
*/

Port::~Port() {
}

Port::Port(std::string name) {
    this->name = name;
    this->connector = 0;
    this->sw_pos_connector = 0;

}

std::string Port::getName() {
    return this->name;
}

void Port::addConnection(Port* p) {
    this->connector = p;
}

void Port::addConnection(std::string p) {
    this->str_connector = p;
}

void Port::removePortConnection(Port *p_to_remove) {
    this->connector = 0;
}

void Port::removeStingConnection() {
    this->str_connector = "";
}

void Port::addSwitchPositionConnection(Port* p) {
    this->sw_pos_connector = p;
}

std::string Port::getStringConnection() {
    return this->str_connector;
}

Port* Port::getPortConnection() {
    return this->connector;
}

Port* Port::getSwitchPositionConnection() {
    return this->sw_pos_connector;
}


