#include <iostream>
#include <sqlite3.h>
#include <string>
  
using namespace std;
  
static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
  
    printf("\n");
    return 0;
}
  
int main(int argc, char** argv)
{
    sqlite3* DB;
    char* messaggeError;
    int exit = sqlite3_open("contact.db", &DB);
    string query = "SELECT * FROM contact;";
  
    cout << "STATE OF TABLE BEFORE INSERT" << endl;
  
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
  
    string sql(
    "INSERT INTO contact VALUES(1, 'Steve Gates', 'Street, 30 - Palo Alto', 'stevegates@gmail.com', '+31254233-7557');"
    "INSERT INTO contact VALUES(2, 'Anna Dowe', 'Street, 45 - Palo Alto', 'annadowe@gmail.com', '+3325422-7777');"
    "INSERT INTO contact VALUES(3, 'Hellen Gates', 'Street, 10 - Palo Alto', 'helleng@gmail.com', '+33254233-5555');"
    "INSERT INTO contact VALUES(4, 'Mariane Miles', 'Street, WQ30 - New York', 'marianem@gmail.com', '+43555422-7557');"
    "INSERT INTO contact VALUES(5, 'Gabrielle Ann', 'Street, CDW30 - City', 'grabrielle@gmail.com', '+35446985-7557');");
  
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << messaggeError << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;
  
    cout << "STATE OF TABLE AFTER INSERT" << endl;
  
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
  
    sql = "DELETE FROM contact WHERE ID = 2;";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Record deleted Successfully!" << std::endl;
  
    cout << "STATE OF TABLE AFTER DELETE OF ELEMENT" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
  
    sqlite3_close(DB);
    return (0);
}
