#include <iostream>
#include <string>

using namespace std;

class ticket {
	public:
		ticket();
		void getTicketType(int seatQuantity);
		void printTicket(string firstName, string lastName, string address,
			string selectedShowName, string selectedShowDate, string selectedShowTime, int seatQuantity);
	private:
		void calculatePrice(int input);
	protected:
		double price;
};

ticket::ticket() {
	price = 0;
}

void ticket::getTicketType(int seatQuantity) {
	int input;

	cout << "\n-------------------------- TICKET TYPE --------------------------\n" << endl;

	for (int i = 0; i < seatQuantity; i++) {
		do {
			cout << "\nSelection for ticket number " << i + 1 << endl;
			cout << "1 - Child - " << (char)156 << "5" << endl;
			cout << "2 - Adult - " << (char)156 << "10" << endl;
			cout << "3 - Student - " << (char)156 << "7" << endl;
			cout << "4 - Senior Citizen - " << (char)156 << "7" << endl;
			cout << "Please pick the type of ticket you wish to buy: ";
			cin >> input;
		} while (input < 1 || input > 4);
		calculatePrice(input);
	}

	cout << "\nThe total price will be: " << (char)156 << price << endl;
}

void ticket::calculatePrice(int input) {
	switch (input) {
	case 1:
		price += 5;
		break;
	case 2:
		price += 10;
		break;
	case 3:
		price += 7;
		break;
	case 4:
		price += 7;
		break;
	}

	this->price = price;
}

void ticket::printTicket(string firstName, string lastName, string address,
	string selectedShowName, string selectedShowDate, string selectedShowTime, int seatQuantity) {
	cout << "\n-------------------------- TICKET SUMMARY --------------------------\n" << endl;
	cout << "              The Bucks Centre for the Performing Arts" << endl;
	cout << "\n--------------------------------------------------------------------" << endl;
	cout << "------------------------- SHOW INFORMATION -------------------------\n" << endl;
	cout << "Show: " << selectedShowName << endl;
	cout << "Date: " << selectedShowDate << endl;
	cout << "Time: " << selectedShowTime << endl;
	cout << "\n--------------------------------------------------------------------" << endl;
	cout << "--------------------------- YOUR DETAILS ---------------------------\n" << endl;
	cout << "Full name: " << firstName << " " << lastName << endl;
	cout << "Address: " << address << endl;
	cout << "\n--------------------------------------------------------------------" << endl;
	cout << "----------------------------- TICKETS -----------------------------\n" << endl;
	cout << "Number of seats: " << seatQuantity << endl;
	cout << "Total price: " << (char)156 << price << endl;
	cout << "\n--------------------------------------------------------------------" << endl;
}