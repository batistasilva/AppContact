#include <cstdlib>
#include "Contact.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int n;
    string name, phone, address, email, searching;
    Contact* f;
    Contact* a;
    Contact* c;
    ShowMsg* msg;
    
    //Read data from file
    a->readFile();

    while (c->printDashboard()) {

        cin >> n;

        switch (n) {
            case 1:
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

                a->addBegin(name, phone, address, email);
                cout << "done :D" << endl;
                break;

            case 2:
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
                if (f == NULL) {
                    msg->ShowMessage("Contact Nor Found...!!", 5, 6);
                } else {
                    cin.ignore();
                    //
                    cout << "----------------------------------------------------" << endl;
                    cout << "|   Please enter with data in the fields...        |" << endl;
                    cout << "----------------------------------------------------" << endl;

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

                    a->insertAfter(f, name, phone, address, email);
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
                if (f == NULL) {
                    msg->ShowMessage("Contact Not Found...!!", 5, 6);
                } else {
                    cin.ignore();
                    //
                    cout << "----------------------------------------------------" << endl;
                    cout << "|   Please enter with data in the fields...        |" << endl;
                    cout << "----------------------------------------------------" << endl;

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

                    a->insertBefore(searching, name, phone, address, email);
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
                return 0;
                break;
            default:
                break;
        }
    }

    return 0;
}

