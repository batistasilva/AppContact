/* 
 * File:   createDB.cpp
 * Author: batista
 *  If you're using SQLite version 3.3+ you can easily create a table with:
 *  create table if not exists TableName (col1 typ1, ..., colN typN)
 *  In the same way, you can remove a table only if it exists by using:
 *  drop table if exists TableName
 * Created on 18 de agosto de 2022, 14:37
 */

#include <cstdlib>
#include <iostream>
#include <sqlite3.h>
  
int main(int argc, char** argv)
{
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("contact.db", &DB);
  
    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;
    sqlite3_close(DB);
    return (0);
}
