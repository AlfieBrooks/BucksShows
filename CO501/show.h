#include <iostream>
#include <string>

using namespace std;

class show {
	public:
		show();
		~show();
		void selectShow(string selectedShowName, string selectedShowDate, string selectedShowTime);
		string getSelectedShowName();
		string getSelectedShowDate();
		string getSelectedShowTime();
	private: 
		void getShows();
	protected:
		string selectedShowName;
		string selectedShowDate;
		string selectedShowTime;
};

show::show() {
	selectedShowName = "";
	selectedShowDate = "";
	selectedShowTime = "";
}

show::~show() {
}

void show::getShows() {
	cout << "1 - The Lion King (26/04/2019 - 6pm)" << endl;
	cout << "2 - Wicked (27/04/2019 - 7:30pm)" << endl;
	cout << "3 - Avengers: The Musical (28/04/2019 - 1pm)" << endl;
	cout << "4 - Aladdin (29/04/2019 - 7:30pm)" << endl;
}

void show::selectShow(string selectedShowName, string selectedShowDate, string selectedShowTime) {
	int input;
	char terminator;

	cout << "\n-------------------------- SELECT A SHOW --------------------------\n" << endl;

	getShows();

	cin.clear();
	cout << "Please enter a show number: ";
	cin >> input;

	while (input < 1 || input > 4) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid show number: ";
		cin >> input;
	}

	switch (input) {
	case 1:
		selectedShowName = "The Lion King";
		selectedShowDate = "26/04/2019";
		selectedShowTime = "6pm";
		break;
	case 2:
		selectedShowName = "Wicked";
		selectedShowDate = "27/04/2019";
		selectedShowTime = "7:30pm";
		break;
	case 3:
		selectedShowName = "Avengers: The Musical";
		selectedShowDate = "28/04/2019";
		selectedShowTime = "1pm";
		break;
	case 4:
		selectedShowName = "Aladdin";
		selectedShowDate = "29/04/2019";
		selectedShowTime = "7:30pm";
		break;
	}

	cout << "\nYou have selected the show '" << selectedShowName << "' on " << selectedShowDate << " at " << selectedShowTime << endl;

	this->selectedShowName = selectedShowName;
	this->selectedShowDate = selectedShowDate;
	this->selectedShowTime = selectedShowTime;

	cin.get(terminator);
}

string show::getSelectedShowName() {
	return selectedShowName;
}

string show::getSelectedShowDate() {
	return selectedShowDate;
}

string show::getSelectedShowTime() {
	return selectedShowTime;
}
