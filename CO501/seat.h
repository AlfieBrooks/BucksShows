#include <iostream>
#include <string>

using namespace std;

class seat {
	public:
		seat();
		~seat();
		int getSeatQuantity();
		void getSeatSelection();
	private:
		void setSeatSelection(char seatStatus);
		void displaySeatingPlan();
	protected:
		char seatingPlan[9][7];
		int seatQuantity;
};

seat::seat() {
	setSeatSelection('A');
	seatQuantity = 0;
}

seat::~seat() {
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
	cout << "\n          ----- Key -----          " << endl;
	cout << "             A = Available" << endl;
	cout << "                H = Held" << endl;
	cout << "\n          ---------------         \n " << endl;
}

void seat::getSeatSelection() {
	int row,
		col;

	row = 0;
	col = 0;

	displaySeatingPlan();

	for (int i = 0; i < seatQuantity; i++) {
		cout << "\nSelection for ticket number " << i + 1 << endl;
		do {
			cout << "Please enter a row number (1 - 9): ";
			cin >> row;
		} while (row < 1 || row > 9);

		do {
			cout << "Please enter a column number (1 - 7): ";
			cin >> col;
		} while (col < 1 || col > 7);
		seatingPlan[row - 1][col - 1] = 'H';
	}

	cout << "\n-------------------------- YOUR SELECTED SEATS --------------------------\n" << endl;
	displaySeatingPlan();
}
