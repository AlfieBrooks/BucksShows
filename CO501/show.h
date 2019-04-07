#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class show {
public:
	show();
	void getShows();
	void selectShow(string selectedShowName, string selectedShowDate, string selectedShowTime);
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

void show::getShows() {
	cout << "1 - The Lion King (26/04/2019 - 6pm)" << endl;
	cout << "2 - Wicked (27/04/2019 - 7:30pm)" << endl;
	cout << "3 - Avengers: The Musical (28/04/2019 - 1pm)" << endl;
}

void show::selectShow(string selectedShowName, string selectedShowDate, string selectedShowTime) {
	char input;
	char terminator;

	cout << "\n-------------------------- SELECT A SHOW --------------------------\n" << endl;

	getShows();

	cin.clear();
	cout << "Please enter a show number: ";
	cin.get(input);

	while (input != '1' && input != '2' && input != '3') {
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please enter a valid show number: ";
		cin.get(input);
	}

	switch (input) {
	case '1':
		selectedShowName = "The Lion King";
		selectedShowDate = "26/04/2019";
		selectedShowTime = "6pm";
		break;
	case '2':
		selectedShowName = "Wicked";
		selectedShowDate = "27/04/2019";
		selectedShowTime = "7:30pm";
		break;
	case '3':
		selectedShowName = "Avengers: The Musical";
		selectedShowDate = "28/04/2019";
		selectedShowTime = "1pm";
		break;
	}

	cout << "\nYou have selected the show '" << selectedShowName << "' on " << selectedShowDate << " at " << selectedShowTime;

	this -> selectedShowName = selectedShowName;
	this -> selectedShowDate = selectedShowDate;
	this -> selectedShowTime = selectedShowTime;

	cin.get(terminator);
}
