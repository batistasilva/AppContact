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
                    cout << "|--------------------------------------------------|" << endl;
                    cout << "|          Contact Not found...!!!                 |" << endl;
                    cout << "|--------------------------------------------------|" << endl;
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
                cout << "=== searching by name  ===== \n" << endl << "enter serachQuery :==>";
                cin >> searching;
                cout << "\n please enter name , phone , address , email by order ( seprate by one space or enter ) :" << endl << " :==>  ";
                cin >> name >> phone >> address >> email;
                a->insertBefore(searching, name, phone, address, email);
            case 5:
                cout << "----------------------------------------------------" << endl;
                cout << "|                   Search by Name                 |" << endl;
                cout << "----------------------------------------------------" << endl;
                cout << "Enter Serach Query :==> ";
                cin.ignore();
                getline(cin, searching, '\n');

                f = a->findContact(searching);
                break;
            case 6:
                cout << "=== searching by name  ===== \n" << endl << "enter serachQuery :==>";
                cin >> searching;
                a->deleteContact(searching);
            case 7:
                a->showContacts();
                break;
            case 8:
                return 0;
                break;
            default:
                break;
        }
    }

    return 0;
}

