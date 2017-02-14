// Name:Abhijeet Solanki,  CSCI 2170-001, Due: 02/10/2017
// PROGRAM ID: main.cpp / Amortization Schedules
// AUTHOR: Abhijeet Solanki
// INSTALLATION:  MTSU
// REMARKS: For this project, you will write a C++ program in CodeLite to
// calculate an amortization schedule based on loan terms read from a file.
// To be flexible, your program will read in a filename,
// and then open that file (and verify that it successfully opened the file).
// That file will contain loan terms with the following syntax:
// <loan amount><tab character><number of years><tab character><annual interest rate>
// Additionally, only display the amortization schedule for the first and last six months.
// Finally, if your program cannot open a file, then display an error
// message and exit (see below for exact syntax).


# include <iostream>
# include <fstream>   // This header is used for files.
# include <cmath>     // Header <cmath> declares a set of functions to compute common mathematical operations.
# include <iomanip>   // Header providing parametric manipulators:
# include <string>    // Header used for string.

using namespace std;

int main(){
    double P = 0.00;  //P is the initial amount of the loan
    double R = 0.00;  //R is the annual interest rate
    double N = 0.00;  //N is the number of compounding periods in a Years
    double J = 0.00;  //J is the monthly interest rate
    int    T = 0.0;  //T is the number of years
    double A = 0.00;   //Interest
    double L = 0.0;   //Principle
    double M = 0.0;   //Amount paid each month
    double B = 0.0;   //Balance
    double middle = 0.0;


    ifstream myIn;
    string file_open = " ";

    //Ask for file to open
    cout << "Please enter a filename to read in the loan terms:" << endl;
    cin >> file_open;

    //Open a file
    myIn.open(file_open.c_str());

    //Check if file oppened correctly or not
    if (!myIn)
    {
        cout << "You entered " << file_open << endl; // Print You entered... file location or file name
        cout<<endl;
        cerr << "Unable to open " << file_open <<"!"<<endl; // Print unable to open the file
        return -1;
    }
    else
    {
        cout << "You entered " << file_open << endl; // Print You entered... file location or file name
    }


    //Get variable from file
    myIn >> P >> T >> R;


    N = 12.00; //Set no of compounding period to 12 month
    J = R / N; //J is the monthly interest rate = annual interest rate / the number of compounding periods in a Years

    M = P * (J + (J / (pow((1 + J), (N * T)) - 1))); //Calculating Monthly Payment

    cout << endl //print Intial balance, ApR, Number of periods, Years and monthly payment
        << fixed << setprecision(2) << setw(20) << "Initial Balance:" << " $" << setw(11) << P << endl
        << fixed << setprecision(2) << setw(20) << "APR:" << setw(13)<<setprecision(3)<<  R << endl
        << fixed << setprecision(2) << setw(20) << "Number of Periods:" << setw(13) << "12" << endl
        << fixed << setprecision(2) << setw(20) << "Years:" << setw(13) << T << endl
        << fixed << setprecision(2) << setw(20) << "Monthly Payment:" << " $" << setw(11) << M << endl
        <<endl;


    middle = (N * T) - 12;  //Middle (or last 6ix) = (month * year) -12
    A = J * P ; // Interest = Monthly interest rate * P is the initial amount of the loan
    L = M - A; // Principle = Amount paid each month - Interest
    B = P - L; // Balance= P is the initial amount of the loan- Principle
    T = T * 12; // T= Year * 12(month)

    int last = middle + 7;    // (middle + 6) + 1

    //Printing the Heading for the table Month, Interest, Principle, and Balance
    cout << setw(5) << "Month" << setw(14) << setprecision(2) << "Interest"<< setw(14) << setprecision(2) << "Principle"<< setw(14) << setprecision(2) << "Balance" << endl;

    //For loop to print calculte first six value
    for (int count = 1; count <= 6; count++){
        cout << setw(5) << count << " $" << setw(12) << setprecision(2) << A << " $" << setw(12) << setprecision(2) << L << " $" << setw(12) << setprecision(2) << B;
        cout << endl;

        A = J * B; //Interest = Monthly interest rate * P is the initial amount of the loan
        L = M - A; //Principle = Amount paid each month - Interest
        B = B - L; //Balance= P is the initial amount of the loan- Principle

    }
    for (int countm = 1; countm <= middle; countm++)
    {
        A = J * B; //Interest = Monthly interest rate * P is the initial amount of the loan
        L = M - A; //Principle = Amount paid each month - Interest
        B = B - L; //Balance= P is the initial amount of the loan- Principle
        //N = N + 1;
    }
    cout<<"..."<<endl;// Print ... dots between first 6 and last six
    for (int cn = last; cn <= T; cn++){ //for loop to print last 6
        cout << setw(5) << cn << " $" << setw(12) << setprecision(2) << A << " $" << setw(12) << setprecision(2) << L << " $" << setw(12) << setprecision(2) << B;
        cout << endl;

        A = J * B; //Interest = Monthly interest rate * P is the initial amount of the loan
        L = M - A; //Principle = Amount paid each month - Interest
        B = B - L; //Balance= P is the initial amount of the loan- Principle
    }

    return 0; //Program will return 0

}
