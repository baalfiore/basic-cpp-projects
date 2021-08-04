#include <iostream>
using namespace std;

void showMenu(){
    cout << "*****Menu******" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "****************" << endl;
}

//acquires balance for the user.
double getBalance(double *bal)
{
    return *bal;
}

int main()
{
/*@Todo:
    X // 01: Check balance
    X // 02: Deposit
    X // 03: Withdraw
    X // 04: Show menu
    ** Extra **
    X // 05: Check for over draft fees.
    X // 06: Exit the system
*/
    int option;
    double balance = 500.47;
    double overdraft = 35.00;
    double* ptr = NULL;

    ptr = &balance;

    do
    {
        showMenu();
        cout << "Option: " << endl;
        cin >> option;
        switch (option)
        {
            case 1: cout << "\n Balance is: $" << getBalance(ptr)<< endl;
                    break;
            case 2: cout << "Deposit Amount: ";
                    double depositAmount; 
                    cin >> depositAmount;
                    system("cls");
                    *ptr += depositAmount;
                    break;
            case 3: cout << "Enter Withdrawal amount: " << endl;
                    double withdrawAmount;
                    cin >> withdrawAmount;
                    if (withdrawAmount <= balance)
                        *ptr -= withdrawAmount;
                    else
                        cout << "Warning! This action will result in an overdraft fee!" << endl;
                        cout << "do you wish to continue? Y/N";
                        char choice;
                        cin >> choice;
                        do
                        {
                            if (choice == 'y')
                            {
                                *ptr -= withdrawAmount + overdraft;
                                break;
                                
                            }
                            else if (choice == 'n')
                            {
                                cout << "Withdrawal cancelled, returning to menu..." << endl;
                                break;
                            };

                        } while (choice != 'n' || choice !='y');  
                    break;       
            case 4:
                    cout << "Logging out! Have a great day :)" << endl;
                    break;
            default:
                    break;
        }
    //system("pause>0");
    }  while(option !=4);
}