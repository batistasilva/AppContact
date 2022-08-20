/* 
 * File:   createDB.cpp
 * Author: batista
 *
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
