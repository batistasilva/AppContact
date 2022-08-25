/* 
 * File:   Contact.h
 * Author: batista
 *
 * Created on 12 de agosto de 2022, 14:50
 */
//g++ -o mysqlconnect $(mysql_config --cflags) mysqlconnect.cpp $(mysql_config --libs)
//g++ -o example tasks.cpp  -I/usr/local/include/mariadb/conncpp/  -L/usr/local/lib/mariadb/ -lmariadbcpp 
/***
 * Doing that:
   LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/mariadb/
   export LD_LIBRARY_PATH
 * You'll can do that:
 * g++ -o testSelect testSelect.cpp    -L/usr/local/lib/mariadb/ -lmariadbcpp
 */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>  
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstring>
#include <mariadb/conncpp.hpp>
#include "MySql/MaDBContact.h"
#include "ShowMsg.h"

using namespace std;

class Contact: public ShowMsg {
public:
    Contact();
    Contact(const Contact& orig);
    virtual ~Contact();
    Contact *next;

    /**
     * constructor with seting information to class
     * 
     * @param string name [name of contact]
     * @param string phone [phone of contact]
     * @param string address [address of contact]
     * @param string email [email of contact]
     * 
     */
    Contact(string name, string phone, string address, string email) {
        this->name = name;
        this->phone = phone;
        this->address = address;
        this->email = email;
        next = NULL;
    }

    /**
     * seting information for a contact
     *  
     * @param string name [name of contact]
     * @param string phone [phone of contact]
     * @param string address [address of contact]
     * @param string email [email of contact]
     */
    void setContact(string name, string phone, string address, string email) {
        this->name = name;
        this->phone = phone;
        this->address = address;
        this->email = email;
    }


    Contact* find(string);

    void addBegin(string name, string phone, string address, string email);
    void addEnd(string name, string phone, string address, string email);
    void deleteContactToLinkdList(string);
    void readFile();

    Contact* findContact(string);
    Contact* getContactFilled();
    //
    void showContactsToLinkdList();
    bool saveContactsToLinkdList();
    //
    bool createContactToMariaDB();
    bool saveContactsToMariaDB();
    bool showContactsToMariaDB();
    bool delAllContactsToMariaDB();
    //
    bool saveContactsToSqLite3();
    void insertAfter(Contact*, string, string, string, string);
    void insertBefore(string, string, string, string, string);
    void getContact();
    void setContactFromFLine(string fileline);
    
    /**
     * prototype for printing dashboard
     * 
     * @return [boolean for Infinite loop]
     */
    void showMainMenu();
    void printDashboard();
    void showMenuMariaDB();   
    void showMenuSqLite3();      
    //

    string getAddress() const {
        return address;
    }

    void setAddress(string address) {
        this->address = address;
    }

    string getEmail() const {
        return email;
    }

    void setEmail(string email) {
        this->email = email;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getPhone() const {
        return phone;
    }

    void setPhone(string phone) {
        this->phone = phone;
    }

private:
    string name;
    string address;
    string phone;
    string email;
    //
};


#endif /* CONTACT_H */

