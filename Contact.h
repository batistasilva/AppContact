/* 
 * File:   Contact.h
 * Author: batista
 *
 * Created on 12 de agosto de 2022, 14:50
 */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Contact {
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

    void addBegin(string, string, string, string);
    void addEnd(string, string, string, string);
    void deleteContact(string);

    Contact* findContact(string);
    void showContacts();
    void insertAfter(Contact*, string, string, string, string);
    void insertBefore(string, string, string, string, string);
    void getContact();
    /**
     * prototype for printing dashboard
     * 
     * @return [boolean for Infinite loop]
     */
    bool printDashboard();
    
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

    Contact* getNext() const {
        return next;
    }

    void setNext(Contact* next) {
        this->next = next;
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

};


#endif /* CONTACT_H */
