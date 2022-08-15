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

Contact::Contact() {

}

Contact::Contact(const Contact& orig) {
}

Contact::~Contact() {
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
    Contact* new_contact = new Contact(name, phone, address, email);

    ShowMessage("Inside addBegin...!!!", 1, 2);
    

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
 *	searching list by name or family name or both
 * 	you can type name of contact , famillyname of contact or both 
 *  with one space seprated in serachQuery parameter
 * 
 * @param string serachQuery [string for searching list]
 * @return contact*   [returing founded contact]
 */
Contact* Contact::find(string serachQuery) {

    Contact* n = NULL;

    for (n = head; n != NULL; n = n->next)

        if (n->getName() == serachQuery ||
                n->getName().substr(0, serachQuery.length()) == serachQuery) {

            return n;
        }

    return n;
}

/**
 *
 *	printing founded contact in list
 *
 * 	you can type name of contact, with one space seprated in serachQuery parameter
 * 
 * @param string serachQuery [string for searching list]
 * @return contact*   [returing founded contact]
 */
Contact* Contact::findContact(string serachQuery) {
    Contact* f = find(serachQuery);

    if (f == NULL){
        ShowMessage("Contact Nor Found...!!", 5, 6);
//        cout << "|--------------------------------------------------|" << endl;
//        cout << "|          Contact Not found...!!!                 |" << endl;
//        cout << "|--------------------------------------------------|" << endl;
    } else {
        ShowMessage("Contact found Sucessfully..!!", 5, 6);
//        cout << "|--------------------------------------------------|" << endl;
//        cout << "|          Contact found Sucessfully...!!!         |" << endl;
//        cout << "|--------------------------------------------------|" << endl;
        f->getContact();
        cout << "----------------------------------------------------------" << endl;
    }
    //
    return f;
}

/**
 *
 *	deleting contact in list
 *
 * 	you can type name of contact, with one space seprated in serachQuery parameter
 * 
 * @param string serachQuery [string for searching list]
 * 
 */
void Contact::deleteContact(string serachQuery) {

    if (
            head->getName() == serachQuery ||
            head->getName() == serachQuery) {

        Contact* temp = head->next;
        delete head;
        head = temp;

        size--;
        return;
    }

    Contact* temp = head;

    if (temp->next == NULL) {
        cout << "\n ================ \n i can't find :|" << endl;
        return;
    }

    while (temp->next->getName() != serachQuery &&
            head->getName() != serachQuery &&
            temp != NULL) {

        temp = temp->next;

        if (temp->next == NULL) {
            cout << "\n ================ \n i can't find :|" << endl;
            return;
        };
    }

    if (temp != NULL) {

        Contact* temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;

        if (
                last->getName() == serachQuery ||
                last->getName() == serachQuery) {
            last = temp;
        }

        size--;
    }
}

/**
 *
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
        cout << "\n ================ \n i can't find :|" << endl;
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
void Contact::insertBefore(string serachQuery, string name, string phone, string address, string email) {

    if (head == NULL) {
        cout << "nothing" << endl;
        return;
    };

    if (head->getName() == serachQuery ||
            head->getName() == serachQuery) {
        addBegin(name, phone, address, email);
        return;
    }

    Contact* temp = head;

    while (temp->next->getName() != serachQuery &&
            head->getName() != serachQuery && temp != NULL) {
        temp = temp->next;

        if (temp->next == NULL) {
            cout << "\n ================ \n i can't find :|" << endl;
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
void Contact::showContacts() {
    system("clear");

    cout << "\n\n" << "----------------------------------------------------------" << endl;

    if (last == NULL || head == NULL) {
        cout << "|--------------------------------------------------|" << endl;
        cout << "|          We found nothing in the list...!!!      |" << endl;
        cout << "|--------------------------------------------------|" << endl;
        return;

    }

    int c = 1;
    for (Contact* n = head; n != NULL; n = n->next) {
        cout << c << ") ";
        c++;
        n->getContact();
        cout << "----------------------------------------------------------" << endl;
    }

};

/**
 * printing all of contacts in the list
 */
bool Contact::saveContacts() {
    Contact* cf;
    string str_list;
    system("clear");

    cout << "\n\n" << "----------------------------------------------------------" << endl;

    if (last == NULL || head == NULL) {
        cout << "|--------------------------------------------------|" << endl;
        cout << "|   We found nothing in the list to Save...!!!     |" << endl;
        cout << "|--------------------------------------------------|" << endl;
        return false;
    }


    ofstream outfile("contact.txt");
    
    int c = 1;
    for (Contact* n = head; n != NULL; n = n->next) {
        cout << c << ") ";
        c++;
        str_list = n->name +";"+n->address+";"+n->email+";"+n->phone+"\n";
        outfile << str_list;
        
        cout << "----------------------------------------------------------" << endl;
    }

    return true;
};



bool Contact::printDashboard() {

    cout << "|----------------------------------------------------------------|" << "\n";
    cout << "| " << "               Select an option by number :                    |" << endl;
    cout << "|----------------------------------------------------------------|" << "\n";
    cout << "| " << "( 1 ) add Contact to begining of list                          |" << endl;
    cout << "| " << "( 2 ) add Contact to end of list                               |" << endl;
    cout << "| " << "( 3 ) add Contact after specific contact by searching          |" << endl;
    cout << "| " << "( 4 ) add Contact before specific contact by searching         |" << endl;
    cout << "| " << "( 5 ) find specific contact in list by searching based on name |" << endl;
    cout << "| " << "( 6 ) delete specific contact by searching                     |" << endl;
    cout << "| " << "( 7 ) show all of contacts                                     |" << endl;
    cout << "| " << "( 8 ) Save Contact to File                                     |" << endl;
    cout << "| " << "( 9 ) exit                                                     |" << endl;    
    cout << "|----------------------------------------------------------------|" << "\n";
    cout << "   select : ";
    return true;
}


