/** 
* Mock atm project given as a homework to Rbeee. 
* Combinedly made mostly by rbeee and purpleblueslime
* with me pitching in some effort.
*/
#include <iostream>
#include <string>

using namespace std;
// account_id = userinput accountid, account = account id to transfer to
// fee1 is withdraw, deposit, and transfer fee & fee2 is checkbalance fee
int amount, avail_balance = 10000, avail_balance2 = 5000, account, fee1 = 10,
        fee2 = 5, chances = 2, choice, account_id;
string accnumber, pincode;
bool condition = true;

// returns false if amount entered exceeds available balance
// otherwise return true
bool amountallowed(int amount, int avail_balance) {
        if (amount > avail_balance) {
                return true;
        } 
        return false;
}
// withdraw, deposit, transfer, checkbal, quit functions
void withdraw() {
        cout << "ENTER AMOUNT TO WITHDRAW: ";
        cin >> amount;
        cout << endl;
        if (amountallowed(amount, avail_balance)) {
                cout << "INPUT AMOUNT INVALID, PLEASE RETRY." << endl << endl;
        } else {
                avail_balance -= (amount + fee1);
                cout << endl << "AVAILABLE BALANCE LEFT IS: " << avail_balance << endl;
        }
}

void deposit() {
        cout << "ENTER AMOUNT TO DEPOSIT: ";
        cin >> amount;
        cout << endl;
        avail_balance += (amount - fee1);
        cout << endl << "UPDATE BALANCE: " << avail_balance << endl;
}

void transfer() {
        cout << "ENTER ACCOUNT ID TO TRANSFER MONEY TO: ";
        cin >> account;
        if (account == 2) {
                cout << "ENTER AMOUNT TO TRANSFER TO ACCOUNT 2: ";
                cin >> amount;
                if (amountallowed(amount, avail_balance)) {
                        cout << endl << "INPUT AMOUNT INVALID. PLEASE RETRY." << endl << endl;
                } else {
                        avail_balance2 += amount;
                        avail_balance -= (amount + fee2);
                        cout << endl <<
                                "YOUR ACCOUNT'S AVAILABLE BALANCE LEFT IS: " << avail_balance <<
                                endl;
                        cout << "ACCOUNT# " << account <<
                                "UPDATED BALANCE IS: " << avail_balance2 << endl;
                }
        }
}

void checkbal() {
        cout << "ACCOUNT ID:" << accnumber << endl;
        avail_balance -= fee2;
        cout << "AVAILABLE BALANCE: " << avail_balance << endl;
}

void quit() {
        cout << "THANK YOU FOR USING OUR ATM.";
        condition = false;
        return;
}
// selection main screen
void selection() {
        int choice;
        cout << "*** AUTOMATED TELLER MACHINE***" << endl;
        cout << endl << "SELECT THE CORRESPONDING NUMBER FOR EACH OPTION" << endl;
        cout << "1 - WITHDRAW " << endl;
        cout << "2 - DEPOSIT " << endl;
        cout << "3 - TRANSFER " << endl;
        cout << "4 - CHECK ACCOUNT BALANCE " << endl;
        cout << "5 - QUIT" << endl;
        cout << "WHAT WOULD YOU LIKE TO DO? ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
                withdraw();
                break;
        case 2:
                deposit();
                break;
        case 3:
                transfer();
                break;
        case 4:
                checkbal();
                break;
        case 5:
                quit();
                break;
        default:
                cout << "INVALID INPUT, PLEASE RETRY. \n";
        }
}

int main() {
        cout << "WELCOME!!" << endl;
        cout << "ENTER YOUR ACCOUNT ID: ";
        getline(cin, accnumber);

        do {
                // Account Pincode
                cout << "ENTER YOUR ACCOUNT PINCODE: ";
                cin >> pincode;
                if (pincode == "1234") break;
                // Pin Attempts
                if (chances != 0) {
                        cout << endl;
                        cout << "INVALID PINCODE" << endl;
                        cout << "YOU HAVE " << chances-- << " TRIES REMAINING. \n";
                        continue;
                } else {
                        cerr << "INVALID PINCODE \n";
                        return -1;
                }
        } while (true);
        cout << "ACCOUNT ACCESS GRANTED.\n" << endl;
        while (condition) {
                selection();
        }
}