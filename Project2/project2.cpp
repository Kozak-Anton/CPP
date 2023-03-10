#include "lib.h"

int main()
{
	const string catalogue = "catalogue.txt";
	const string sorted_catalogue = "sorted_catalogue.txt";
	string command;

	string test1;
	getline(cin, test1);
	char test[MAX_INPUT];
	cin.getline(test, MAX_INPUT);
	cout <<"\n" << name_search(test1, test)<<"\n";
	cout << "\n" << int(test[30]) <<"111" << '\0' << "\n";

	while (command!="end") {
		cout << "Enter command: ";
		cin >> command;

		if (command == "wc") {
			write_catalogue(catalogue);
		}
		else if (command == "rc") {
			read_catalogue(catalogue);
		}
		else if (command == "ac") {
			append_catalogue(catalogue);
		}
		else if (command == "sa") {
			cout << "sa";
		}
		else if (command == "fa") {
			cout << "fa";
		}
		else if (command != "end") {
			cout << "Wrong input";
		}



	}

}