#include <iostream>
#include <string>

using namespace std;

class user {
	public:
		user();
		~user();
		void login();
		void getProfileInfo();
		string getFirstName();
		string getLastName();
		string getAddress();
	protected:
		string firstName;
		string lastName;
		string address;
};

user::user() {
	firstName = "";
	lastName = "";
	address = "";
}

user::~user() {}

void user::login() {
	string username;
	string password;

	cout << "\n--------------------------------------------------------------------" << endl;
	cout << "              The Bucks Centre for the Performing Arts" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "------------------------------- LOGIN ------------------------------\n" << endl;
	cout << "Username: ";
	getline(cin, username);

	cout << "Password: ";
	getline(cin, password);
	while (password.length() < 5) {
		cout << "Your password should be more than 5 charcters" << endl;
		cout << "Re-enter password: ";
		getline(cin, password);
	}
}

void user::getProfileInfo() {
	cout << "\n--------------------------- PROFILE INFO ---------------------------\n" << endl;
	cout << "First name: ";
	getline(cin, firstName);

	cout << "Last name: ";
	getline(cin, lastName);

	cout << "Address: ";
	getline(cin, address);

	this->firstName = firstName;
	this->lastName = lastName;
	this->address = address;
}

string user::getFirstName() {
	return firstName;
}

string user::getLastName() {
	return lastName;
}

string user::getAddress() {
	return address;
}
