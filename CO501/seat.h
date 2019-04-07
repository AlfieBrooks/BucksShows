#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class seat {
	public:
		seat();
		void setSeatSelection(char seatStatus);
		int getSeatQuantity();
		double getSeatSelection();
	private:
		void displaySeatingPlan();
		void calculatePrice();
	protected:
		char seatingPlan[9][7];
		int seatQuantity;
		int rowNum;
		double price;
};

seat::seat() {
	setSeatSelection('0');
	seatQuantity = 0;
	rowNum = 0;
	price = 0;
}

void seat::setSeatSelection(char seatStatus) {
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 7; col++) {
			seatingPlan[row][col] = seatStatus;
		}
	}
}

int seat::getSeatQuantity() {
	cout << "\n-------------------------- SEAT SELECTION --------------------------\n" << endl;

	do {
		cin.clear();
		cout << "How many tickets would you like to buy (Maximum: 4)?: ";
		cin >> seatQuantity;
		cout << endl;
	} while (seatQuantity < 0 || seatQuantity > 4);
	return seatQuantity;
}

void seat::displaySeatingPlan() {
	cout << "     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |" << endl;
	cout << "~~~~~+~~~~~+~~~~~+~~~~~+~~~~~+~~~~~+~~~~~+~~~~~~" << endl;

	for (int row = 0; row < 9; row++) {
		cout << "  " << row + 1 << "  |  ";
		for (int col = 0; col < 7; col++) {
			cout << seatingPlan[row][col] << "  |  ";
		}
		if (row != 8) cout << "\n~~~~~+-----+-----+-----+-----+-----+-----+------";
		cout << endl;
	}
	cout << "~~~~~-------------------------------------------" << endl;
}

double seat::getSeatSelection() {
	char input;
	int row,
		col;
	char terminator;

	row = 0;
	col = 0;

	displaySeatingPlan();

	do {
		for (int i = 0; i < seatQuantity; i++) {
			cout << "\nSelection for ticket number " << i + 1 << endl;
			do {
				cout << "Please enter a row number (1 - 9): ";
				cin >> row;
			} while (row < 0 || row > 9);
			rowNum = row;

			do {
				cout << "Please enter a column number (1 - 7): ";
				cin >> col;
			} while (col < 0 || col > 7);
			cin.get(terminator);
		}

		while (seatingPlan[row][col] == 'H') {
			cout << "Sorry, That seat is unavailable" << endl;
			do {
				cout << "Please enter another row number (1 - 9): ";
				cin >> row;
			} while (row < 0 || row > 9);

			do {
				cout << "Please enter another column number (1 - 7): ";
				cin >> col;
			} while (col < 0 || col > 7);
		}
		cin.get(terminator);

		do {
			cout << "\nPlease confirm your choice (Y = Yes, N = No): ";
			cin.get(input);
		} while (input != 'Y' && input != 'y' && input != 'N' && input != 'n');
		cin.get(terminator);
	} while (input == 'N' && input == 'n');

	seatingPlan[row][col] = 'H';
	displaySeatingPlan();
	return 20;
}

//void seat::calculatePrice() {

//}