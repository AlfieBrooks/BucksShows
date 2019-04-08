#include "pch.h"
#include <iostream>
#include <string>
#include "user.h"
#include "show.h"
#include "seat.h"
#include "ticket.h"

using namespace std;

int main() {
	string selectedShowName,
		selectedShowDate,
		selectedShowTime;
	int seatQuantity;

	//Initilise Objects
	user User;
	show Show;
	seat Seat;
	ticket Ticket;

	//Prompt the user to login
	User.login();

	//Prompt the users firstName, lastName and address
	User.getProfileInfo();

	cout << "\n--------------------------- Welcome " << User.getFirstName() << " ---------------------------\n" << endl;

	//Prompt the user to select a show
	Show.selectShow(selectedShowName, selectedShowDate, selectedShowTime);

	//Prompts the user to enter number of seats
	seatQuantity = Seat.getSeatQuantity();

	//Displays the table of seats for the user to pick
	Seat.getSeatSelection();

	//Prompts the type of ticket the user will buy
	Ticket.getTicketType(seatQuantity);
	
	//Prints the tickets the user has chosen
	Ticket.printTicket(User.getFirstName(), User.getLastName(), User.getAddress(),
		Show.getSelectedShowName(), Show.getSelectedShowDate(), Show.getSelectedShowTime(), seatQuantity);
}
