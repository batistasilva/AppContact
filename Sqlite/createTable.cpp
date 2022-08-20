/**** 
 * File:   createTable.cpp
 * Author: batista
 * Created on 18 de agosto de 2022, 14:27
 * g++ createTable.cpp -l sqlite3
 ***/

#include <cstdlib>
#include <iostream>
#include <sqlite3.h>
  
int main(int argc, char** argv)
{
    sqlite3* DB;
    std::string sql = "CREATE TABLE contact("
                      "id INT PRIMARY KEY     NOT NULL, "
                      "name           TEXT    NOT NULL, "
                      "address        TEXT    NOT NULL, "
                      "phone          TEXT    NOT NULL, "
                      "email          TEXT    NOT NULL);";
    int exit = 0;
    exit = sqlite3_open("contact.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << messaggeError << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    sqlite3_close(DB);
    return (0);
}