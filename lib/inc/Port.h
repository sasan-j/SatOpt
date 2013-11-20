/* 
 * File:   Port.h
 * Author: sasan
 *
 * Created on March 28, 2013, 6:17 PM
 */

#ifndef PORT_H
#define	PORT_H


#include <iostream>



class Port {
	std::string name;
	Port* connector;
	Port* sw_pos_connector;
	std::string str_connector;
public:
        Port(std::string name);
        /*Port(const Port& orig);*/
        virtual ~Port();
    	std::string getName();
	void addConnection(Port* p);
	void addConnection(std::string p);
	void removePortConnection(Port *p_to_remove);
	void removeStingConnection();
	void addSwitchPositionConnection(Port* p);
	std::string getStringConnection();
	Port* getPortConnection();
	Port* getSwitchPositionConnection();
};

#endif	/* PORT_H */

