/*** 
 * File:   MaDBContact.cpp
 * Author: batista
 * 
 * Created on 19 de agosto de 2022, 12:36
 ***/

#include "MaDBContact.h"

MaDBContact::MaDBContact() {

}

bool MaDBContact::testConnection(){
    //
    try {
        // Instantiate Driver
        sql::Driver* driver = sql::mariadb::get_driver_instance();
        
        // Configure Connection
        sql::SQLString url("jdbc:mariadb://localhost:3306/ContactDB");
        //
        sql::Properties properties({
            {"user", "system"},
            {"password", "sys2133"}
        });

        // Establish Connection
        unique_ptr<sql::Connection> conn(driver->connect(url, properties));                     
        // Close Connection
        
        conn->close();
    } catch (sql::SQLException& e) {
        std::cerr << "Error Connecting to MariaDB Platform: " << e.what() << std::endl;
        // Exit (Failed)
       return false;
    }    
    
    return true;
}

/***
 * Add Contact to Contact Table in MariaDB.
 */
void MaDBContact::addContact(std::unique_ptr<sql::Connection>& conn, Contact* contact){
    try {
        // Create a new PreparedStatement
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement("INSERT into contact (name, address, email, phone) values (?,?,?,?)"));
        // Bind values to SQL statement
        stmnt->setString(1, contact->getName());
        stmnt->setString(2, contact->getAddress());
        stmnt->setString(3, contact->getEmail());
        stmnt->setString(4, contact->getPhone());
        // Execute query
        stmnt->executeQuery();
    }
    catch(sql::SQLException& e){
      std::cerr << "Error inserting new contact: " << e.what() << std::endl;
   }    
}