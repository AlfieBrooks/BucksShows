#include "pch.h"
#include <iostream>
#include <string>
#include "show.h"

int main() {
	string a,
		b,
		c;
	char input,
		terminator;
	show Show;

	//Customer.Login();
	//Consumer.profileInfo();

	cout << "\n-------------------------- WELCOME --------------------------\n" << endl;
	do {
		Show.selectShow(a, b, c);

		do {
			cout << "\nPlease confirm your choice (Y = Yes, N = No): ";
			cin.get(input);
		} 
		while (tolower(input == 'y') && tolower(input == 'n'));
		cin.get(terminator);
	} 
	while (tolower(input == 'n'));

	//Seat.initialiseSeatSelection();
}
