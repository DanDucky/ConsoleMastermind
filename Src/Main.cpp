/*
 * Main.cpp
 *
 *  Created on: Apr 9, 2022
 *      Author: danducky
 */

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

string name (int playerNumber) {
	int numberOfLetters;
	string name;

	while (numberOfLetters != -1) {
		cout << "Enter Player " << playerNumber << "'s Name: ";
		cin >> name;
		numberOfLetters = name.length();
		if (numberOfLetters >= 12) {
			cout << "Name cannot be above 12 letters! Try again\n";
		} else {
			numberOfLetters = -1;
		}
	}
	return name;
}

int main () {
	/*
	cout << "\033[31mred text\033[0m\n";
	colored text ^^^ also more info in screenshot in downloads
	*/
	int maxGuesses = 12;
	int numberOfColors = 8;
	int lengthOfCode = 5;
	string firstPlayer;
	string playerOneName = name(1);
	cout << "Player 1's name is " << playerOneName << "!\n";
	string playerTwoName = name(2);
	cout << "Player 2's name is " << playerTwoName << "!\n\n";
	cout << "Who would like to begin as the guesser? Type \"R\" for a coin flip, or type either the player's username or their player number to decide: ";
	cin >> firstPlayer;
	if (firstPlayer == playerOneName || firstPlayer == "1") {
		cout << playerOneName << " is guessing first!\n";
		firstPlayer = playerTwoName;
	} else if (firstPlayer == playerTwoName || firstPlayer == "2") {
		cout << playerTwoName << " is guessing first!\n";
		firstPlayer = playerOneName;
	} else if (firstPlayer == "R" || firstPlayer == "r") {
		//random number for random guesser
		srand(time(0));
		int randomStart = (rand() % 2);
		switch(randomStart) {
		case 0:
			cout << playerOneName << " is guessing first!\n";
			firstPlayer = playerTwoName;
			break;
		case 1:
			cout << playerTwoName <<" is guessing first!\n";
			firstPlayer = playerOneName;
			break;
		}
	}
	do {
		//extra line below
		cout << "\n";
		cout << "How many guesses would you like to allow? 12 is normal ";
		cin >> maxGuesses;
		cout << "How many colors would you like to allow? 8 is normal, 10 is maximum ";
		cin >> numberOfColors;
		cout << "How long would you like the code to be? 5 is normal ";
		cin >> lengthOfCode;
		cout << "Enter the secret code " << firstPlayer << "!\nUse numbers 1-";
	} while (-1 == -1);
	return 0;
}
