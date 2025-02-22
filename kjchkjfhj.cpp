#include <iostream>
#include <string>

using namespace std;

struct Booking {
    string name;
    string phone;
    double balance;
};

const int MAX_BOOKINGS = 10;  // Max booking limit
Booking bookings[MAX_BOOKINGS];  
int bookingCount = 0;  // Number of bookings

int main() {
    string languages[] = {"English", "Russian"};
    string languageInput;
    string specificcommand;

    cout << "Choose the language (English/Russian): ";
    cin >> languageInput;
    cin.ignore();  // Fixes `getline` issue after `cin`

    if (languageInput == "English") {
        cout << "\nAvailable commands:\n";
        cout << "- Book a queue at the center\n";
        cout << "- Contact operator\n";
        cout << "- Services\n";
        cout << "- Check document readiness at the center\n";
        cout << "- Install center's app\n";
        cout << "- Check for administrative fines\n";
        cout << "- Nearest Center\n";
        cout << "- About the bot\n";
        cout << "- Settings\n";

        while (true) {
            cout << "\nEnter a command(enter Exit to exit): ";
            getline(cin, specificcommand);

            if (specificcommand == "Book a queue at the center") {
                if (bookingCount < MAX_BOOKINGS) {  
                    cout << "Enter your name: ";
                    getline(cin, bookings[bookingCount].name);
                    cout << "Enter your phone number: ";
                    getline(cin, bookings[bookingCount].phone);

                    cout << " Booking confirmed for " << bookings[bookingCount].name << "!\n";
                    bookingCount++;
                } else {
                    cout << " Booking list is full!\n";
                }
            } 
            if (specificcommand == "Contact operator") {
                string name, phone;
                cout << "Enter your name: ";
                getline(cin, name);
            
                cout << "Enter your phone number: ";
                getline(cin, phone);
            
                if (name.empty() || phone.empty()) {
                    cout << "⚠ Error: Name and phone cannot be empty!\n";
                } else {
                    // Simulate queue number (random for now)
                    int queueNumber = rand() % 5 + 1;  // Generates a random number between 1 and 5
                    
                    cout << " Request received, " << name << "!\n";
                    cout << " An operator will contact you in 15-30 min.\n";
                    cout << " You are #" << queueNumber << " in the queue.\n";
                }
            }
            if (specificcommand == "Services") {
                cout << "\n Available Bank Services:\n";
                cout << "- Check account balance\n";
                cout << "- Apply for a loan\n";
                cout << "- Exit services\n";

                while (true) {
                    cout << "\nEnter a service: ";
                    getline(cin, specificcommand);

                    if (specificcommand == "Check account balance") {
                        if (bookingCount > 0) {
                            string name;
                            cout << "Enter your name: ";
                            getline(cin, name);

                            bool found = false;
                            for (int i = 0; i < bookingCount; i++) {
                                if (bookings[i].name == name) {
                                    cout << " Your balance is: $" << bookings[i].balance << "\n";
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) {
                                cout << "No account found under this name.\n";
                            }
                        } else {
                            cout << " No users registered yet.\n";
                        }
                    } 
                    else if (specificcommand == "Apply for a loan") {
                        string name;
                        double loanAmount;
                        cout << "Enter your name: ";
                        getline(cin, name);

                        bool found = false;
                        for (int i = 0; i < bookingCount; i++) {
                            if (bookings[i].name == name) {
                                cout << " Enter loan amount: $";
                                cin >> loanAmount;
                                cin.ignore();

                                bookings[i].balance += loanAmount;
                                cout << " Loan approved! Your new balance is $" << bookings[i].balance << "\n";
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            cout << " No account found under this name.\n";
                        }
                    } 
                    else if (specificcommand == "Exit services") {
                        break;
                    } 
                    else {
                        cout << "⚠ Unknown service request.\n";
                    }
                }
            }

            else if (specificcommand == "Exit") {
                cout << " Exiting chatbot...\n";
                break;
            } 
            else {
                cout << " Unknown command. Try again.\n";
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


