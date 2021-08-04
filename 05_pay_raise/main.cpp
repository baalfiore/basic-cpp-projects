#include <iostream>
using namespace std;

/**
 * 05: Pay raise
 * use arrays to track budget
 * 
 * 
 * */

int main(){

    float monthsArray[] = { 100, 220, 300, 300, 80 };
    float total = 0;
    int arrSize = (sizeof(monthsArray)/sizeof(monthsArray[0]));

    for (int i=0; i !=arrSize; ++i)
    {
        cout << "Enter amount for entry #" << i+1 << endl;
        cin >> monthsArray[i];
        total += monthsArray[i];
    } 

    cout << "Total:" << total << endl;
    cout << "Average: " << total/arrSize <<endl;
}