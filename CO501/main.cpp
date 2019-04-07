#include "pch.h"
#include <iostream>
#include <string>
#include "show.h"
#include "seat.h"

using namespace std;

int main() {
	string selectedShowName,
		selectedShowDate,
		selectedShowTime;
	int seatQuantity;
	double seatSelection;
	char input,
		terminator;
	show Show;
	seat Seat;

	//Customer.Login();
	//Consumer.profileInfo();

	cout << "\n-------------------------- WELCOME --------------------------\n" << endl;
	do {
		Show.selectShow(selectedShowName, selectedShowDate, selectedShowTime);

		do {
			cout << "\nPlease confirm your choice (Y = Yes, N = No): ";
			cin.get(input);
		} 
		while (input != 'Y' && input != 'y' && input != 'N' && input != 'n');
		cin.get(terminator);
	} 
	while (input == 'N' && input == 'n');

	Seat.setSeatSelection('A');
	seatQuantity = Seat.getSeatQuantity();
	seatSelection = Seat.getSeatSelection();
}
