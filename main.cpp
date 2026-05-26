#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Contact{
public:
    string firstName;
    string lastName;
    string phoneNum;

    Contact(string first, string last, string phone):
        firstName(first), lastName(last), phoneNum(phone) {}
    

    void display() const {
        cout << firstName << " " << lastName << " - " << phoneNum << endl;  
    }

    bool matches(const string& nameSearch) const {
        string q = nameSearch , full = firstName + " " + lastName;
        transform(q.begin(), q.end(), q.begin(), ::tolower);
        transform(full.begin(), full.end(), full.begin(), ::tolower);
        return full.find(q) != string::npos;
    }


};

string getLine(const string& prompt) {
    string val;
    cout << prompt;  // flush leftover newline from cin >>
    getline(std::cin, val);
    return val;
}

void displayPhonebook(const vector<Contact>& phonebook) {
    if (phonebook.empty()) {
        cout << "Phonebook is empty." << endl;
        return;
    }
    for (int i = 0; i < phonebook.size(); i++) {
        cout << i + 1 << ". ";
        phonebook[i].display();
    }
}
void addContact(vector<Contact>& phonebook) {
    string first = getLine("Enter First Name: ");
    string last = getLine("Enter Last Name: ");
    string phone = getLine("Enter Phone Number: ");
    phonebook.push_back(Contact(first, last, phone));
    cout << "Contact added! \n" << endl;
}
void removeContact(vector<Contact>& phonebook) {
    if (phonebook.empty()) {
        cout << "Phonebook is empty." << endl;
        return;
    }
    displayPhonebook(phonebook);
    int ndx;

    cout << "Select a contact to remove: ";
    cin >> ndx;

    if (ndx >= 1  && ndx <= phonebook.size()) {
        phonebook.erase(phonebook.begin() + ndx - 1);
        cout << "Contact removed. \n" << endl;
    } else {
        cout << "Invalid contact number.\n" << endl;
    }
}
void searchContact(const vector<Contact>& phonebook){
    if (phonebook.empty()) {
        cout << "Phonebook is empty." << endl;
        return;
    }
    string searchName = getLine("Enter name to search: ");
    bool found = false;
    for (const auto& contact : phonebook) {
        if (contact.matches(searchName)) {
            contact.display();
            found = true;
        }
    }
    if (!found) {
        cout << "Contact not found." << endl;
    }
}

void editContact(vector<Contact>& phonebook){
    if(phonebook.empty()) {
        cout << "Phonebook is empty." << endl;
        return;
    }
    displayPhonebook(phonebook);
    int ndx;
    cout << "Select a contact to edit: ";
    cin >> ndx;
    Contact& c = phonebook[ndx - 1];
    if (ndx < 1 || ndx > phonebook.size()) {

        cout << "Invalid contact number." << endl;
        return;
    }

    cout << "Editing contact: " << c.firstName << " " << c.lastName << endl;
    cout << "Enter new first name: ";
    cin.ignore();
    getline(cin, c.firstName);
    cout << "Enter new last name: ";
    getline(cin, c.lastName);
    cout << "Enter new phone number: ";
    getline(cin, c.phoneNum);
    cout << "Contact updated!!" << endl;
}

int main(){

    vector<Contact> PhoneBook;
    int choice; 


    while (true) {
        cout << "Welcome to the Phonebook!" << endl;
        cout << "Select an option:" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display Phonebook" << endl;
        cout << "3. Remove Contact" << endl;
        cout << "4. Edit Contact" << endl;
        cout << "5. Search Contact" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // flush leftover newline from cin >>

        switch(choice) {
            case 1:
                addContact(PhoneBook);
                break;
            case 2:
                displayPhonebook(PhoneBook);
                break;
            case 3:
                removeContact(PhoneBook);
                break;
            case 4:
                editContact(PhoneBook);
                break;
            case 5:
                searchContact(PhoneBook);
                break;
            case 0:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    }

}




  