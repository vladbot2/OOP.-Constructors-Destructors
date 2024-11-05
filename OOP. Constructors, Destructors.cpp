#include <iostream>
#include <string>

using namespace std;

class Contact {
private:
    string fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string additionalInfo;

public:
    Contact(const string& name, const string& home, const string& work, const string& mobile, const string& additional) {
        fullName = name;
        homePhone = home;
        workPhone = work;
        mobilePhone = mobile;
        additionalInfo = additional;
    }

    void display() const {
        cout << "Name: " << fullName << endl;
        cout << "Home Phone: " << homePhone << endl;
        cout << "Work Phone: " << workPhone << endl;
        cout << "Mobile Phone: " << mobilePhone << endl;
        cout << "Additional Info: " << additionalInfo << endl;
    }

    const string& getFullName() const {
        return fullName;
    }

    const string& getHomePhone() const {
        return homePhone;
    }
};

class PhoneBook {
private:
    Contact* contacts[100];
    int count;

public:
    PhoneBook() : count(0) {}

    void addContact(const string& name, const string& home, const string& work, const string& mobile, const string& additional) {
        if (count < 100) {
            contacts[count++] = new Contact(name, home, work, mobile, additional);
        }
        else {
            cout << "Phone book full" << endl;
        }
    }

    void deleteContact(const string& name) {
        for (int i = 0; i < count; ++i) {
            if (contacts[i]->getFullName() == name) {
                delete contacts[i];
                for (int j = i; j < count - 1; ++j) {
                    contacts[j] = contacts[j + 1];
                }
                --count;
                cout << "Contact " << name << " deleted." << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }

    void searchContact(const string& name) {
        for (int i = 0; i < count; ++i) {
            if (contacts[i]->getFullName() == name) {
                contacts[i]->display();
                return;
            }
        }
        cout << "Contact not found" << endl;
    }

    void displayAllContacts() {
        if (count == 0) {
            cout << "Phone book empty" << endl;
        }
        else {
            for (int i = 0; i < count; ++i) {
                contacts[i]->display();
                cout << "--------------------------" << endl;
            }
        }
    }

    ~PhoneBook() {
        for (int i = 0; i < count; ++i) {
            delete contacts[i];
        }
    }
};

int main() {
    PhoneBook pb;

    pb.addContact("Travis Scott", "666-999", "888-555", "111-222", " info");
    pb.addContact("Eminem", "444-333", "111-999", "000-666", "info");
    pb.addContact("Linda", "111-333", "555-999", "777-222", "info");

    pb.displayAllContacts();
    pb.searchContact("Travis Scott");

    pb.deleteContact("Eminem");

    pb.displayAllContacts();
}
