/*** 
 * File:   MaDBContact.h
 * Author: batista
 * Created on 19 de agosto de 2022, 12:36
 ***/
//g++ -o mysqlconnect $(mysql_config --cflags) mysqlconnect.cpp $(mysql_config --libs)
//g++ -o example tasks.cpp  -I/usr/local/include/mariadb/conncpp/  -L/usr/local/lib/mariadb/ -lmariadbcpp 

/***
 * Doing that:
   LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/mariadb/
   export LD_LIBRARY_PATH
 * You'll can do that:
 * g++ -o testSelect testSelect.cpp    -L/usr/local/lib/mariadb/ -lmariadbcpp
 */

#ifndef MADBCONTACT_H
#define MADBCONTACT_H

#include <string>
#include <iostream>
#include <cstring>
#include <mariadb/conncpp.hpp>
#include "../ShowMsg.h"
#include "../Contact.h"

using namespace std;

class Contact;
class MaDBContact{
public:
    MaDBContact();
    //

    MaDBContact(string db, string username, string password){
       this->db = db;
       this->username = username;
       this->password = password;
    }

    //
    void deleteContact(std::unique_ptr<sql::Connection> &conn, Contact * ct);
    void updateContact(std::unique_ptr<sql::Connection> &conn, Contact* contact);
    void addContact(std::unique_ptr<sql::Connection> &conn, Contact* contact);
    void showAllContact(std::unique_ptr<sql::Connection> &conn);
    bool testConnection();
    
    string getDb() const {
        return db;
    }

    void setDb(string db) {
        this->db = db;
    } 
    
    string getPassword() const {
        return password;
    }

    void setPassword(string password) {
        this->password = password;
    }

    string getUrl() const {
        return url;
    }

    void setUrl(string url) {
        this->url = url;
    }

    string getUsername() const {
        return username;
    }

    void setUsername(string username) {
        this->username = username;
    }
  
    
private:
    string db;
    string username;
    string password;
    string url;
};

#endif /* MADBCONTACT_H */

