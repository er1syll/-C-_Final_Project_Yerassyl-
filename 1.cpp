#include <iostream>
#include <string>

using namespace std;

struct User {
    string name;
    string phone;
    double balance;
};

struct ServiceCenter {
    string name;
    string address;
};

const int MAX_USERS = 10;
const int NUM_CENTERS = 3;
User users[MAX_USERS];  
int userCount = 0;

ServiceCenter centers[NUM_CENTERS] = {
    {"Kabanbay batyr", "75"},
    {"Ken dala", "21"},
    {"Mangilik el", "845"}
};

int main() {
    string languageInput;
    string specificCommand;

    cout << "Choose the language (English/Russian): ";
    cin >> languageInput;
    cin.ignore();

    if (languageInput == "English") {
        cout << "\nAvailable commands:\n";
        cout << "- Register user\n";
        cout << "- Book a queue at the center\n";
        cout << "- Contact operator\n";
        cout << "- Services\n";
        cout << "- Location of Services\n";
        cout << "- Exit\n";

        while (true) {
            cout << "\nEnter a command: ";
            getline(cin, specificCommand);

            if (specificCommand == "Register user") {
                if (userCount < MAX_USERS) {
                    cout << "Enter your name: ";
                    getline(cin, users[userCount].name);
                    cout << "Enter your phone number: ";
                    getline(cin, users[userCount].phone);
                    users[userCount].balance = 0.0;
                    cout << "Registration successful!\n";
                    userCount++;
                } else {
                    cout << "User limit reached!\n";
                }
            } 
            else if (specificCommand == "Book a queue at the center") {
                cout << "Feature not implemented yet.\n";
            } 
            else if (specificCommand == "Contact operator") {
                string name, phone;
                cout << "Enter your name: ";
                getline(cin, name);
                cout << "Enter your phone number: ";
                getline(cin, phone);
                cout << "An operator will contact you in 15-30 min.\n";
            } 
            else if (specificCommand == "Services") {
                cout << "\nAvailable Bank Services:\n";
                cout << "- Check account balance\n";
                cout << "- Apply for a loan\n";
                cout << "- Exit services\n";

                while (true) {
                    cout << "\nEnter a service: ";
                    getline(cin, specificCommand);

                    if (specificCommand == "Check account balance") {
                        string name;
                        cout << "Enter your name: ";
                        getline(cin, name);

                        bool found = false;
                        for (int i = 0; i < userCount; i++) {
                            if (users[i].name == name) {
                                cout << "Your balance is: $" << users[i].balance << "\n";
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "No account found under this name.\n";
                        }
                    } 
                    else if (specificCommand == "Apply for a loan") {
                        string name;
                        double loanAmount;
                        cout << "Enter your name: ";
                        getline(cin, name);

                        bool found = false;
                        for (int i = 0; i < userCount; i++) {
                            if (users[i].name == name) {
                                cout << "Enter loan amount: $";
                                cin >> loanAmount;
                                cin.ignore();
                                users[i].balance += loanAmount;
                                cout << "Loan approved! Your new balance is $" << users[i].balance << "\n";
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << "No account found under this name.\n";
                        }
                    } 
                    else if (specificCommand == "Exit services") {
                        break;
                    } 
                    else {
                        cout << "Unknown service request.\n";
                    }
                }
            } 
            else if (specificCommand == "Location of Services") {
                cout << "\nAvailable service centers:\n";
                for (int i = 0; i < NUM_CENTERS; i++) {
                    cout << "- " << centers[i].name << " at " << centers[i].address << "\n";
                }
            } 
            else if (specificCommand == "Exit") {
                cout << "Exiting chatbot...\n";
                break;
            } 
            else {
                cout << "Unknown command. Try again.\n";
            }
        }
    } 
    else if (languageInput == "Russian") {
        cout << "Russian version is not implemented yet.\n";
    } 
    else {
        cout << "Invalid language choice.\n";
    }

    return 0;
}






