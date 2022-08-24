#include <cstdlib>
#include "Contact.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n, j, o;
    string name, phone, address, email, searching;
    Contact* f;
    Contact* a;
    Contact* ct;
    ShowMsg* msg;
    
    //Read data from file
    a->readFile();
    while (ct->printDashboard()) {
        cin >> n;
        switch (n) {
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
                a->deleteContact(searching);
                break;
            case 7:
                a->showContacts();
                break;
            case 8:
                if (a->saveContacts()) {
                    msg->ShowMessage("Contact Saved Sucessfully...!!", 7, 6);
                } else {
                    msg->ShowMessage("Error to Save Contact to file...!!", 4, 2);
                }
                break;
            case 9:
                while (ct->showMenuSqLite3()) {
                    cin.ignore();
                    cin >> j;
                    switch (j) {
                        case 1:
                            //Add data to SQLite3 contact
                            break;
                        case 2:
                            //
                            break;
                        case 3:
                            //do something
                            break;
                        case 4:
                            //do something
                            break;
                        case 5:
                            //do something
                            return false;
                            break;
                        default:
                            break;
                    }
                }
                //safeContactToSQLite3()
                return 0;
                break;
            case 10:

                //madb->getConnection();
                break;
            case 11:
                return 0;
                break;
            default:
                break;
        }
    }
    return 0;
}

