/*** 
 * File:   Contact.cpp
 * Author: batista
 * 
 * Created on 12 de agosto de 2022, 14:50
 **/
#include "Contact.h"

//
Contact *head;
Contact *last;
int size;
//
//string filename = "contact.txt";
ifstream ifs;

Contact::Contact() {

}

Contact::Contact(const Contact& orig) {
}

Contact::~Contact() {
}

/***
 * Read File database in format txt.
 */
void Contact::readFile() {
    //Open file name
    string line;

    string filename = "contact.txt";

    ifs.open(filename);

    // Check if the file has been opened successfully.
    if (ifs.is_open()) {
        //
        cout << "File Read Sucessfully!..." << endl;
        //
        while (getline(ifs, line)) {
            //
            setContactFromFLine(line);
            //
            cout << "[ Finishing Line to Get New One..." << endl;
        }
        //
        //  addBegin(name, phone, address, email);
    }
}

/**
 *  printing all of information for a contact
 */
void Contact::getContact() {
    cout << "\n"
            << "Name: " << name << "\n"
            << "Phone: " << phone << "\n"
            << "E-mail: " << email << "\n"
            << "Address: " << address << endl;
}

/**
 * add contact to end of contactslist
 * equals to push_back in vector
 * 
 * @param string name [name of contact]
 * @param string phone [phone of contact]
 * @param string address [address of contact]
 * @param string email [email of contact]
 */
void Contact::addEnd(string name, string phone, string address, string email) {

    Contact* new_contact = new Contact(name, phone, address, email);

    if (last == NULL) {
        head = new_contact;
        last = new_contact;
    } else {
        last->next = new_contact;
        last = new_contact;
    }

    size++;
}

/**
 * add contact to begining of contactslist
 * equals to push_front in vector
 * 
 * @param string name [name of contact]
 * @param string phone [phone of contact]
 * @param string address [address of contact]
 * @param string email [email of contact]
 */
void Contact::addBegin(string name, string phone, string address, string email) {
    //Set data to estacia from new_contact 
    Contact* new_contact = new Contact(name, phone, address, email);

    ShowMessage("Inside addBegin()...!!!", 1, 2);

    if (last == NULL || head == NULL) {
        head = new_contact;
        last = new_contact;
    } else {
        new_contact->next = head;
        head = new_contact;
    }
    //
    size++;
}

/**
 * Searching list by name or family name or both
 * you can type name of contact , famillyname of contact or both 
 * with one space seprated in serachQuery parameter
 * 
 * @param string serachQuery [string for searching list]
 * @return contact*   [returing founded contact]
 */
Contact* Contact::find(string searchQuery) {

    Contact* n = NULL;

    for (n = head; n != NULL; n = n->next)

        if (n->getName() == searchQuery ||
                n->getName().substr(0, searchQuery.length()) == searchQuery) {

            return n;
        }

    return n;
}

/***
 * getContactFilled to save on MariaDB contact Table
 */
Contact* Contact::getContactFilled() {
    string name, address, email, phone;

    //
    cout << "----------------------------------------------------" << endl;
    cout << "|   Please enter with data in the fields...        |" << endl;
    cout << "----------------------------------------------------" << endl;

    cin.ignore();
    cout << "Name: ";
    getline(cin, name, '\n');

    //cin.ignore();
    cout << "Address: ";
    getline(cin, address, '\n');

    //cin.ignore();
    cout << "E-mail: ";
    getline(cin, email, '\n');

    //cin.ignore();
    cout << "Phone: ";
    getline(cin, phone, '\n');
    //       
    Contact* contact = new Contact(name, phone, address, email);

    return contact;
}

/***
 * printing founded contact in list
 * you can type name of contact, with one space seprated 
 * in serachQuery parameter.
 * @param string serachQuery [string for searching list]
 * @return contact*   [returing founded contact]
 **/
Contact* Contact::findContact(string searchQuery) {
    //
    Contact* f = find(searchQuery);
    //
    if (f == NULL) {
        ShowMessage("Contact Not Found...!!", 5, 6);
    } else {
        ShowMessage("Contact found Sucessfully..!!", 5, 6);
        f->getContact();
        cout << "----------------------------------------------------------" << endl;
    }
    //
    return f;
}

/***
 * Deleting contact in list you can type name of contact, 
 * with one space seprated in serachQuery parameter.
 * @param string serachQuery [string for searching list]
 **/
void Contact::deleteContactToLinkdList(string searchQuery) {

    if (head->getName() == searchQuery || head->getName() == searchQuery) {
        //
        Contact* temp = head->next;
        delete head;
        head = temp;
        size--;
        return;
    }

    Contact* temp = head;

    if (temp->next == NULL) {
        ShowMessage("I Can not find...!!", 5, 6);
        return;
    }

    while (temp->next->getName() != searchQuery &&
            head->getName() != searchQuery &&
            temp != NULL) {
        temp = temp->next;

        if (temp->next == NULL) {
            ShowMessage("I Can not find...!!", 5, 6);
            return;
        };
    }

    if (temp != NULL) {
        Contact* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        if (last->getName() == searchQuery || last->getName() == searchQuery) {
            last = temp;
        }
        size--;
    }
}

/****
 * inserting new contact to the list after specific contact 
 * 
 * @param contact* n_contact [founded contact by find method of this class]
 * @param string name [name of contact]
 * @param string phone [phone of contact]
 * @param string address [address of contact]
 * @param string email [email of contact]
 */
void Contact::insertAfter(Contact* n_contact, string name, string phone, string address, string email) {

    if (n_contact == NULL) {
        ShowMessage("I Can not find...!!", 5, 6);
        return;
    }
    //
    Contact* new_contact = new Contact(name, phone, address, email);
    new_contact->next = n_contact->next;
    n_contact->next = new_contact;

    if (n_contact == last) last = n_contact;

    size++;
}

/**
 *
 * searching specific contact in the list based on searchQuery parameter and add new contact before founded case
 * 
 * @param string sreachQuery [string for searching in the list]
 * @param string name [name of contact]
 * @param string phone [phone of contact]
 * @param string address [address of contact]
 * @param string email [email of contact]
 */
void Contact::insertBefore(string searchQuery, string name, string phone, string address, string email) {

    if (head == NULL) {
        ShowMessage("Nothing...!!", 5, 6);
        return;
    };

    if (head->getName() == searchQuery ||
            head->getName() == searchQuery) {
        addBegin(name, phone, address, email);
        return;
    }

    Contact* temp = head;

    while (temp->next->getName() != searchQuery &&
            head->getName() != searchQuery && temp != NULL) {
        temp = temp->next;

        if (temp->next == NULL) {
            ShowMessage("I Can not find...!!", 5, 6);
            return;
        };
    }

    if (temp != NULL) {
        Contact* new_contact = new Contact(name, phone, address, email);
        new_contact->next = temp->next;
        temp->next = new_contact;
        size++;
    }
}

/**
 * printing all of contacts in the list
 */
void Contact::showContactsToLinkdList() {
    system("clear");

    cout << "\n\n" << "----------------------------------------------------------" << endl;

    if (last == NULL || head == NULL) {
        ShowMessage("We found nothing in the list...!!", 5, 6);
        return;
    }

    int c = 1;
    for (Contact* n = head; n != NULL; n = n->next) {
        cout << c << ") ";
        c++;
        n->getContact();
        cout << "----------------------------------------------------------" << endl;
    }

}

/**
 * printing all of contacts in the list
 */
bool Contact::saveContactsToLinkdList() {
    string str_list;
    system("clear");
    cout << "\n\n" << "----------------------------------------------------------" << endl;

    if (last == NULL || head == NULL) {
        ShowMessage("We found nothing in the list to Save...!!", 5, 6);
        return false;
    }

    ofstream outfile("contact.txt");

    int c = 1;
    for (Contact* n = head; n != NULL; n = n->next) {
        cout << c << ") ";
        c++;
        str_list = "&" + n->name + ";" + n->address + ";" + n->email + ";" + n->phone + ";#\n";
        outfile << str_list;
        cout << "----------------------------------------------------------" << endl;
    }
    return true;
}

/***
 * Method to Create contact Table in MariaDB. 
 */
bool Contact::createContactToMariaDB() {
    string strQuery = "CREATE DATABASE IF NOT EXISTS `ContactDB`; DROP TABLE IF EXISTS `ContactDB`.`contact`; ";
    strQuery += "CREATE TABLE `ContactDB`.`contact` (`id` INTEGER NOT NULL AUTO_INCREMENT, "
            "`name` VARCHAR(200) DEFAULT NULL , `address` VARCHAR(200) DEFAULT NULL , "
            "`email` VARCHAR(200) DEFAULT NULL , `phone` VARCHAR(200) DEFAULT NULL , PRIMARY KEY (`id`));";
    //
    try {
        //
        MaDBContact* madb = new MaDBContact();
        //
        madb->setUsername("system");
        madb->setPassword("sys2133");
        madb->setDb("mysql");

        ShowMessage("Inside Contact::createContactToMariaDB()!!", 7, 6);
        // Instantiate Driver
        sql::Driver* driver = sql::mariadb::get_driver_instance();

        cout << "DB: " << madb->getDb() << " User: " << madb->getUsername() << " Password: " << madb->getPassword();

        // Configure Connection
        sql::SQLString url("jdbc:mariadb://localhost:3306/" + madb->getDb());
        //        //
        sql::Properties properties({
            {"user", madb->getUsername()},
            {"password", madb->getPassword()}
        });

        // Establish Connection
        std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
        //
        if (!conn) {
            ShowMessage("Error Connecting to MariaDB!!!", 5, 6);
            return false;
            // exit(EXIT_FAILURE);
        }
        // Create a new PreparedStatement
        std::unique_ptr<sql::PreparedStatement> stmnt(conn->prepareStatement(strQuery));
        //
        if (!stmnt) {
            ShowMessage("Error Connecting to MariaDB!!!", 5, 6);
            return false;
            // exit(EXIT_FAILURE);
        }

        // Execute query
        stmnt->executeQuery();
    } catch (sql::SQLException& e) {
        std::cerr << "Error Creating new Contact: " << e.what() << std::endl;
    }
    //    
    return true;
}

/***
 * Method to Save LinkdList Contact to MariaDB Table.
 */
bool Contact::saveContactsToMariaDB() {
    //
    MaDBContact* madb = new MaDBContact();

    Contact* contact = new Contact;
    string str_list;
    //
    madb->setUsername("system");
    madb->setPassword("sys2133");
    madb->setDb("ContactDB");

    try {
        ShowMessage("Inside Contact::saveContactsToMariaDB()!!", 7, 6);
        // Instantiate Driver
        sql::Driver* driver = sql::mariadb::get_driver_instance();

        cout << "DB: " << madb->getDb() << " User: " << madb->getUsername() << " Password: " << madb->getPassword();

        // Configure Connection
        sql::SQLString url("jdbc:mariadb://localhost:3306/" + madb->getDb());
        //        //
        sql::Properties properties({
            {"user", madb->getUsername()},
            {"password", madb->getPassword()}
        });

        // Establish Connection
        std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
        //
        if (!conn) {
            ShowMessage("Error Connecting to MariaDB!!!", 5, 6);
            return false;
            // exit(EXIT_FAILURE);
        }
        //
        if (last == NULL || head == NULL) {
            ShowMessage("We found nothing in the list to Save...!!", 5, 6);
            return false;
        }
        //        //
        for (Contact* n = head; n != NULL; n = n->next) {
            //
            contact->name = n->name;
            contact->address = n->address;
            contact->email = n->email;
            contact->phone = n->phone;
            //
            str_list = "&" + n->name + ";" + n->address + ";" + n->email + ";" + n->phone + ";#\n";
            cout << str_list << endl;

            madb->addContact(conn, contact);
            //
            cout << "----------------------------------------------------------" << endl;
        }
        //
        conn->close();
    } catch (sql::SQLException& e) {
        std::cerr << "Error Connecting to MariaDB Platform: " << e.what() << std::endl;
        // Exit (Failed)
        return false;
    }

    return true;
}

/***
 * Method to Show All Contact Saved on MariaDB Table.
 */
bool Contact::showContactsToMariaDB() {
    //
    MaDBContact* madb = new MaDBContact();

    //
    madb->setUsername("system");
    madb->setPassword("sys2133");
    madb->setDb("ContactDB");

    try {
        ShowMessage("Inside Contact::showContactsToMariaDB()!!", 7, 6);
        // Instantiate Driver
        sql::Driver* driver = sql::mariadb::get_driver_instance();

        cout << "DB: " << madb->getDb() << " User: " << madb->getUsername() << " Password: " << madb->getPassword();

        // Configure Connection
        sql::SQLString url("jdbc:mariadb://localhost:3306/" + madb->getDb());
        //        //
        sql::Properties properties({
            {"user", madb->getUsername()},
            {"password", madb->getPassword()}
        });

        // Establish Connection
        std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
        //
        if (!conn) {
            ShowMessage("Error Connecting to MariaDB!!!", 5, 6);
            return false;
            // exit(EXIT_FAILURE);
        }

        // Create a new Statement
        std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
        // Execute query
        //
        if (!stmnt) {
            ShowMessage("Error Connecting to MariaDB!!!", 5, 6);
            return false;
            // exit(EXIT_FAILURE);
        }

        // Execute query
        sql::ResultSet *rs = stmnt->executeQuery("SELECT * FROM contact");
        // Loop through and print results
        while (rs->next()) {
            cout << "|-----------------------------------------|" << endl;
            cout << " Id......: [ " << rs->getInt(1) << " ]" << endl;
            cout << " Name....: " << rs->getString(2) << endl;
            cout << " Address.: " << rs->getString(3) << endl;
            cout << " E-mail..: " << rs->getString(4) << endl;
            cout << " Telephone:" << rs->getString(5) << endl;
            cout << "|_________________________________________|" << endl;
        }
    } catch (sql::SQLException& e) {
        std::cerr << "Error selecting tasks: " << e.what() << std::endl;
    }
    return true;
}

/***
 * Method to Remove All Contact to MariaDB Table.
 */
bool Contact::delAllContactsToMariaDB() {
    //
    if (createContactToMariaDB())
        ShowMessage("Database and Table created Sucessfully!!", 7, 6);

    return true;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        cout << azColName[i] << argv[i] << endl;
    }
    cout << endl;
    return 0;
}

bool Contact::testIfContactExist() {
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("Sqlite/database.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return false;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    //
    sqlite3_close(db);
    return true;
}

/***
 * Creating Contact to SqLite3
 */
bool Contact::createContactsToSqLite3() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    /* Open database */
    rc = sqlite3_open("Sqlite/database.db", &db);
    //
    if (rc) {
        cout << stderr << "Can't open database:" << sqlite3_errmsg(db) << endl;
        return (0);
    } else {
        cout << stdout << "Opened database successfully" << endl;
    }

    /* Create SQL statement */
    sql = "CREATE TABLE contact(id PRIMARY KEY NOT NULL, name TEXT NOT NULL, address CHAR(50) NOT NULL, email CHAR(50),phone CHAR(30));";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        cout << stderr << "SQL error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    } else {
        cout << stdout << "Table created successfully" << endl;
    }
    //
    sqlite3_close(db);

    return true;
}

/***
 * Save Contact to SqLite3
 */
bool Contact::saveContactsToSqLite3() {
    //

    if (createContactsToSqLite3())
        ShowMessage("Contact to Sqlite3, Created Sucessfully!!!", 5, 6);

    //
    return true;
}

bool Contact::showContactsToSqLite3() {


    return true;
}

/***
 * Remove All Contacts to SqLite3
 */
bool Contact::delAllContactsToSqLite3() {

    return true;
}

/***
 * Set Contact from file line.
 */
void Contact::setContactFromFLine(string fileline) {
    Contact ct;
    string str_name, str_address, str_phone, str_email;
    bool InToFillName = true;
    bool InToFillAddress = false;
    bool InToFillPhone = false;
    bool InToFillEmail = false;

    //
    for (auto str : fileline) {

        if (str != '&' && InToFillName == true) {//if enter, start to get name
            if (str == ';') {
                ct.name = str_name;
                cout << "\n" << "My Name: " << ct.name << endl;
                //
                InToFillName = false; //Set to false to say that is okay
                InToFillAddress = true; //Set to True to start fill in the next if
                str = '?'; //did this for facility, to get data on next field 
            } else {
                str_name += str;
            }
        }//End the Name

        if (InToFillAddress == true) {//if enter, start to get address
            //
            if (str == ';') {
                ct.address = str_address;
                cout << "Address: " << ct.address << endl;
                InToFillAddress = false; //Set to false to say that is okay
                InToFillEmail = true; //Set to True to start fill in the next if    
                str = '?';
            } else {
                if (str != '?') str_address += str;
            }
        }//End the Address      
        //
        if (InToFillEmail == true) {//if enter, start to get email
            if (str == ';') {
                ct.setEmail(str_email);
                cout << "Email: " << ct.getEmail() << endl;
                ;
                InToFillEmail = false; //Set to false to say that is okay
                InToFillPhone = true; //Set to True to start fill in the next if    
                str = '?';
            } else {
                if (str != '?') str_email += str;
            }
        }//End the Email
        //
        if (InToFillPhone == true) {//if enter, start to get phone
            //
            if (str == ';') {
                ct.setPhone(str_phone);
                cout << "Phone: " << ct.getPhone() << endl;
                InToFillPhone = false; //Set to false to say that is okay 
            } else {
                if (str != '?') str_phone += str;
            }
        }//End the Phone          

        if (str == 0x26) InToFillName = true;
    }

    addBegin(ct.name, ct.phone, ct.address, ct.email);
    cout << " End Read line" << endl;
}

/***
 * Menu of options to Manager showMainMenu(). 
 */
void Contact::showMainMenu() {
    int op;
    bool RunWhile = true;
    while (RunWhile) {
        //
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "| " << "     [           Main Menu                 ]                       |" << endl;
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "| " << "( 1 )[ Manager Linked List to Contact      ]                  |" << endl;
        cout << "| " << "( 2 )[ Manager Contact to Sqlite3 Database ]                  |" << endl;
        cout << "| " << "( 3 )[ Manager Contact to MariaDB Database ]                  |" << endl;
        cout << "| " << "( 4 )[              Exit                   ]                  |" << endl;
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "   select : ";
        //
        cin >> op;
        //
        switch (op) {
            case 1:
                ShowMessage("Manager Linked List to Contact..!!", 7, 6);
                printDashboard();
                break;
            case 2:
                ShowMessage("Manager Contact to SQlite3..!!", 7, 6);
                showMenuSqLite3();
                //
                break;
            case 3:
                ShowMessage("Manager Contact to MariaDB..!!", 7, 6);
                showMenuMariaDB();
                //do something
                break;
            case 4:
                ShowMessage("Exit From Main Menu..!!", 7, 6);
                RunWhile = false;
                system("clear");
                //do something
                break;
            default:
                break;
        }
    }
}

/***
 * Menu of options to Manager Linked List(). 
 */
void Contact::printDashboard() {
    int j, op;
    string name, phone, address, email, searching;
    Contact* f;
    Contact* a;
    Contact* ct;
    ShowMsg* msg;

    bool RunWhile = true;
    //Read data from file
    a->readFile();

    while (RunWhile) {
        //
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "| " << "[               Main Menu                   ]            |" << endl;
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "| " << "( 1 ) [ Add Contact to Begining of List     ]                  |" << endl;
        cout << "| " << "( 2 ) [ Add Contact to End of List          ]                  |" << endl;
        cout << "| " << "( 3 ) [ Add Contact After Specific Contact  ]                  |" << endl;
        cout << "| " << "( 4 ) [ Add Contact Before Specific Contact ]                  |" << endl;
        cout << "| " << "( 5 ) [ Find Contact in List by Name        ]                  |" << endl;
        cout << "| " << "( 6 ) [ Delete Specific Contact             ]                  |" << endl;
        cout << "| " << "( 7 ) [        Show All Contacts            ]                  |" << endl;
        cout << "| " << "( 8 ) [       Save Contact to File          ]                  |" << endl;
        cout << "| " << "( 9 ) [              Exit                   ]                  |" << endl;
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "   select : ";
        //
        cin >> op;
        //
        switch (op) {
            case 1:
                cout << "Inside addBegin..." << endl;
                ct = ct->getContactFilled(); //Fill data to fields
                a->addBegin(ct->getName(), ct->getPhone(), ct->getAddress(), ct->getEmail());
                cout << "done :D" << endl;
                break;
            case 2:
                ct = ct->getContactFilled(); //Fill data to fields
                //
                a->addEnd(name, phone, address, email);
                cout << "done :D" << endl;
                break;
            case 3:
                cout << "----------------------------------------------------" << endl;
                cout << "|                   Search by Name                 |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "Enter Serach Query :==> ";
                cin.ignore();
                getline(cin, searching, '\n');
                //
                f = a->find(searching);
                //
                if (f == NULL) {
                    msg->ShowMessage("Contact Not Found...!!", 5, 6);
                } else {
                    ct = ct->getContactFilled(); //Fill data to fields
                    a->insertAfter(f, ct->getName(), ct->getPhone(), ct->getAddress(), ct->getEmail());
                }
                break;
            case 4:
                cout << "----------------------------------------------------" << endl;
                cout << "|                   Search by Name                 |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "Enter Search Query :==> ";
                cin.ignore();
                getline(cin, searching, '\n');
                //
                f = a->find(searching);
                //
                if (f == NULL) {
                    msg->ShowMessage("Contact Not Found...!!", 5, 6);
                } else {
                    ct = ct->getContactFilled(); //Fill data to fields
                    a->insertBefore(searching, ct->getName(), ct->getPhone(), ct->getAddress(), ct->getEmail());
                }
                break;
            case 5:
                cout << "----------------------------------------------------" << endl;
                cout << "|                   Search by Name                 |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "Enter Search Query :==> ";
                cin.ignore();
                getline(cin, searching, '\n');
                f = a->findContact(searching);
                break;
            case 6:
                cout << "----------------------------------------------------" << endl;
                cout << "|                   Search by Name                 |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "Enter Search Query :==> ";
                cin.ignore();
                getline(cin, searching, '\n');
                a->deleteContactToLinkdList(searching);
                break;
            case 7:
                a->showContactsToLinkdList();
                break;
            case 8:
                if (a->saveContactsToLinkdList()) {
                    msg->ShowMessage("Contact Saved Sucessfully...!!", 7, 6);
                } else {
                    msg->ShowMessage("Error to Save Contact to file...!!", 4, 2);
                }
                break;
            case 9:
                RunWhile = false;
                system("clear");
                break;
            default:
                break;
        }
    }
}

/***
 * Menu of options from MariaDB(). 
 */
void Contact::showMenuMariaDB() {
    int op;
    bool RunWhile = true;

    while (RunWhile) {
        //
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "| " << "                   Menu MariaDB                          |" << endl;
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "| " << "( 1 ) [ Save All Contacts from List to Database ]        |" << endl;
        cout << "| " << "( 2 ) [ Load All Contacts to List from Database ]        |" << endl;
        cout << "| " << "( 3 ) [ Delete All Contacts from Database       ]        |" << endl;
        cout << "| " << "( 4 ) [               Exit                      ]        |" << endl;
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "   select : ";
        //
        cin >> op;
        //
        switch (op) {
            case 1:
                ShowMessage("Inside Saved Contact to MariaDB..!!", 7, 6);
                if (saveContactsToMariaDB())
                    ShowMessage("Contact Saved Sucessfully...!!", 7, 6);
                //Add data to MariaDB contact
                break;
            case 2:
                ShowMessage("Inside Load Contact to MariaDB..!!", 7, 6);
                if (showContactsToMariaDB())
                    ShowMessage("Contact Load Sucessfully...!!", 7, 6);
                //
                break;
            case 3:
                ShowMessage("Delete Contact to MariaDB..!!", 7, 6);
                if (delAllContactsToMariaDB())
                    ShowMessage("All Contacts Removed Sucessfully...!!", 7, 6);
                //do something
                break;
            case 4:
                RunWhile = false;
                system("clear");
                break;
            default:
                break;
        }
    }
}

/***
 * Menu of options from SqLite3(). 
 */
void Contact::showMenuSqLite3() {
    int op;
    bool RunWhile = true;

    while (RunWhile) {
        //
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "| " << "                   Menu SqLite3                          |" << endl;
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "| " << "( 1 ) [ Save All Contacts from List to Database ]        |" << endl;
        cout << "| " << "( 2 ) [ Load All Contacts to List from Database ]        |" << endl;
        cout << "| " << "( 3 ) [   Delete All Contacts from Database     ]        |" << endl;
        cout << "| " << "( 4 ) [                Exit                     ]        |" << endl;
        cout << "|----------------------------------------------------------------|" << "\n";
        cout << "   select : ";
        cin >> op;
        //
        switch (op) {
            case 1:
                ShowMessage("Inside Saved Contact to SqLite3..!!", 7, 6);
                if (saveContactsToSqLite3())
                    ShowMessage("Contact Saved Sucessfully...!!", 7, 6);
                //Add data to MariaDB contact
                break;
            case 2:
                ShowMessage("Inside Load Contact to SqLite3..!!", 7, 6);
                //
                break;
            case 3:
                ShowMessage("Delete Contact to SqLite3..!!", 7, 6);
                //do something
                break;
            case 4:
                //do something
                RunWhile = false;
                system("clear");
                break;
            default:
                break;
        }
    }
}