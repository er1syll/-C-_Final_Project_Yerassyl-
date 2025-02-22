#include <iostream>
#include <string>

using namespace std;

// Structure to store user information
struct User {
    string name;   // User's name
    string phone;  // User's phone number
    double balance; // User's account balance
};

// Structure to store service center details
struct ServiceCenter {
    string name;    // Name of the service center
    string address; // Address of the service center
};

// Constants for maximum users and service centers
const int MAX_USERS = 10;
const int NUM_CENTERS = 3;

// Array to store registered users
User users[MAX_USERS] = {
    {"Yerrasyl", "123-456-7890", 100.50},
    {"Ali", "987-654-3210", 250.75},
    {"Bekarys", "555-666-7777", 75.00}
};  
int userCount = 3; // Keeps track of the number of registered users

// Array containing locations of service centers
ServiceCenter centers[NUM_CENTERS] = {
    {"Kabanbay batyr", "75"},
    {"Ken dala", "21"},
    {"Mangilik el", "845"}
};

// Function to register a new user
void registerUser() {
    if (userCount < MAX_USERS) { // Check if the user limit is reached
        cout << "Enter your name: ";
        getline(cin, users[userCount].name); // Get user's name
        cout << "Enter your phone number: ";
        getline(cin, users[userCount].phone); // Get user's phone number
        users[userCount].balance = 0.0; // Initialize balance to zero
        cout << "Registration successful!\n";
        userCount++; // Increase user count
    } else {
        cout << "User limit reached!\n"; // Display error if limit is reached
    }
}

// Function to contact an operator
void contactOperator() {
    string name, phone;
    cout << "Enter your name: ";
    getline(cin, name); // Get user's name
    cout << "Enter your phone number: ";
    getline(cin, phone); // Get user's phone number
    cout << "An operator will contact you in 15-30 min.\n"; // Response message
}

// Function to check the balance of a registered user
void checkBalance() {
    string name;
    cout << "Enter your name: ";
    getline(cin, name); // Get user's name
    
    bool found = false;
    for (int i = 0; i < userCount; i++) {
        if (users[i].name == name) { // Check if name matches a registered user
            cout << "Your balance is: $" << users[i].balance << "\n"; // Display balance
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No account found under this name.\n"; // Error if user not found
    }
}

// Function to apply for a loan
void applyForLoan() {
    string name;
    double loanAmount;
    cout << "Enter your name: ";
    getline(cin, name); // Get user's name
    
    bool found = false;
    for (int i = 0; i < userCount; i++) {
        if (users[i].name == name) { // Check if user exists
            cout << "Enter loan amount: $";
            cin >> loanAmount; // Get loan ss
            users[i].balance += loanAmount; // Add loan amount to user's balance
            cout << "Loan approved! Your new balance is $" << users[i].balance << "\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No account found under this name.\n"; // Error if user not found
    }
}

// Function to display available service centers
void showServiceCenters() {
    cout << "\nAvailable service centers:\n";
    for (int i = 0; i < NUM_CENTERS; i++) {
        cout << "- " << centers[i].name << " at " << centers[i].address << "\n"; // Print service centers
    }
}

int main() {
    string languageInput;  // Variable to store language selection
    string specificCommand; // Variable to store user command

    // Prompt the user to choose a language
    cout << "Choose the language (English/Russian): ";
    cin >> languageInput;
    cin.ignore(); // Clear input buffer to prevent issues with getline()

    if (languageInput == "English") { // Check if the chosen language is English
        cout << "\nAvailable commands:\n";
        cout << "- Register user\n";
        cout << "- Book a queue at the center\n";
        cout << "- Contact operator\n";
        cout << "- Services\n";
        cout << "- Nearest Services\n";
        cout << "- Exit\n";

        // Loop to continuously take user input for commands
        while (true) {
            cout << "\nEnter a command: ";
            getline(cin, specificCommand); // Get user command

            if (specificCommand == "Register user") {
                registerUser(); // Call function to register user
            } 
            else if (specificCommand == "Book a queue at the center") {
                cout << "Feature not implemented yet.\n"; // Placeholder for future feature
            } 
            else if (specificCommand == "Contact operator") {
                contactOperator(); // Call function to contact an operator
            } 
            else if (specificCommand == "Services") {
                cout << "\nAvailable Bank Services:\n";
                cout << "- Check account balance\n";
                cout << "- Apply for a loan\n";
                cout << "- Exit services\n";

                // Inner loop to handle service-related commands
                while (true) {
                    cout << "\nEnter a service: ";
                    getline(cin, specificCommand);

                    if (specificCommand == "Check account balance") {
                        checkBalance(); // Call function to check balance
                    } 
                    else if (specificCommand == "Apply for a loan") {
                        applyForLoan(); // Call function to apply for a loan
                    } 
                    else if (specificCommand == "Exit services") {
                        break; // Exit services section
                    } 
                    else {
                        cout << "Unknown service request.\n"; // Handle invalid input
                    }
                }
            } 
            else if (specificCommand == "Nearest Services") {
                showServiceCenters(); // Display available service centers
            } 
            else if (specificCommand == "Exit") {
                cout << "Exiting chatbot...\n"; // Exit program
                break;
            } 
            else {
                cout << "Unknown command. Try again.\n"; // Handle invalid input
            }
        }
    } 
    else if (languageInput == "Russian") {
        cout << "Russian version is not implemented yet.\n"; // Placeholder for future Russian support
    } 
    else {
        cout << "Invalid language choice.\n"; // Handle invalid language input
    }

    return 0; // End of program
}