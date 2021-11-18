// ECCS 1611 - Programming 1 - Fall Semester 2021
// Machine Problem 3 (MP3) - 'Cause I'm Leavin' on a Jet Plane
// 
// MP3.cpp
// 
// Last Updated: November 18, 2021
// Hailey M. Wendt
// 
// This program allows someone to reserve seats on a CRJ 200 plane. 
// Each seat is designated by a number (1-13) and a letter (A-D). 
// The program will display the seat pattern, then accept seat requests 
// one at a time and replacing the requested seat with an X. The program 
// will contine until all seats are filled or the user signals the program 
// to end.
// 

#include <iostream>
#include <string>
using namespace std;

//Function Prototypes
void displaySeats(string seats[][13]);
void breakInput(string input);
int findRowIndex();
int findSeatIndex(string seats[][13]);
void displaySeatColumn(string seats[7][13], int column);

// Defining variables that are used in functions and int main
int column;
int thisSeat;
int thisRow;
string seatNumber;
string seatLetter;

int main() {
    // Initializing variables to use in int main
    string seats[7][13];
    string input = " ";

    // Creates the array that is used to identify the seat of the passenger
    for (int column = 0; column < 13; column++) {
        seats[0][column] = "D";
        seats[1][column] = "C";
        seats[2][column] = " ";
        seats[3][column] = to_string(column + 1);
        seats[4][column] = " ";
        seats[5][column] = "B";
        seats[6][column] = "A";
        seats[0][12] = " ";
        seats[1][12] = " ";
    }

    bool done = false;
    while (done != true) {
        // Displays the array
        displaySeats(seats);
        
        // Asks for user to enter a seat and reads that input
        cout << endl;
        cout << "Enter a seat or Q to quit: ";
        cin >> input;
        
        // Determines if the input is valid or not, checks to quit
        if (input == "Q" || input == "q") {
            done = true;
            break;
        }

        // Purposes of functions explained in Function Definitions/Comments
        breakInput(input);
        findRowIndex();
        findSeatIndex(seats);

        // Prevents a seat from being chosen more than once
        if (seats[thisRow][thisSeat] == "X") {
            cout << "Sorry, no such seat exists on the CRJ 200." << endl;
        }

        // Displays that a seat has been chosen
        displaySeatColumn(seats, column);
    }
}

/**
displaySeats: displays the array of seats
@param seats[][13] - reference to a 2-D string array
*/
void displaySeats(string seats[][13]) {
    cout << endl;
    for (int rows = 0; rows < 7; rows++) {
        for (int columns = 0; columns < 13; columns++) {
            cout << seats[rows][columns] << " ";
            if (columns < 9 || rows != 3) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

/**
breakInput: determines length of string for user's input and assigns seat numbers and letters to the input
@param input - user input that determines length of string
*/
void breakInput(string input) {
    seatNumber = " ";
    seatLetter = " ";
    if (input.length() == 2) {
        seatNumber = input[0];
        seatLetter = input[1];
    }
    else if (input.length() == 3) {
        seatNumber = input.substr(0, 2);
        seatLetter = input[2];
    }
    else {
        cout << "Sorry, no such seat exists on the CRJ 200." << endl;
    }
}

/**
findRowIndex: given user input, returns appropriate row index into arrays.
@return appropriate index into 2-D array if the specified row is valid, ERROR otherwise
*/ 
int findRowIndex() {
    if (seatLetter == "A") {
        return thisRow = 6;
    }
    else if (seatLetter == "B") {
        return thisRow = 5;
    }
    else if (seatLetter == "C") {
        return thisRow = 1;
    }
    else if (seatLetter == "D") {
        return thisRow = 0;
    }
    else {
        cout << "Sorry, no such seat exists on the CRJ 200." << endl;
    }
}

/**
findSeatIndex: given user input, returns appropriate column index into seating chart array.
@param seats[][13] - reference to a 2-D string array
@return appropriate index into 2-D array if the specified seat is valid, 0 otherwise
*/
int findSeatIndex(string seats[][13]) {
    int i = 0;
    while (i < 13) {
        if (seats[3][i] == seatNumber) {
            return thisSeat = i;
        }
        i++;
    }
    if (thisSeat > 13){
        cout << "Sorry, no such seat exists on the CRJ 200." << endl;
        return 0;
    }
}

/**
displaySeatColumn: given a 2 - D mapping of the seating chart in the form[rows][columns],
will print out a "column" of seats on one row of output (i.e., seat 'A' for all rows in the plane)
@param seats[8][13] - reference to a 2-D string array
@param column - reference to which column of seats to display
*/
void displaySeatColumn(string seats[7][13], int column) {
    if (thisRow == 0 && thisSeat == 12) {
        cout << "Sorry, no such seat exists on the CRJ 200." << endl;
    }
    else if (thisRow == 1 && thisSeat == 12) {
        cout << "Sorry, no such seat exists on the CRJ 200." << endl;
    }
    else {
        seats[thisRow][thisSeat] = 'X';
    }
}