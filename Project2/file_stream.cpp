#include "mode.h"
#include "file_stream_lib.h"

void file_stream() {
	const string catalogue = "catalogue.txt";                   //Input catalogue
	const string sorted_catalogue = "sorted_catalogue.txt";     //Author sorted catalogue
	string command;                                             //Command input

	cout << "Command list:\n";
	cout << "wc - write catalogue file\n";
	cout << "rc - read catalogue file\n";
	cout << "ac - append catalogue file\n";
	cout << "sa - search titles by athor\n";
	cout << "fa - filter catalogue by author\n";
	cout << "end - finish programm\n\n";

	while (command != "end") {
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
			search_author(catalogue);
		}
		else if (command == "fa") {
			filter_author(catalogue, sorted_catalogue);
			read_catalogue(sorted_catalogue);
		}
		else if (command != "end") {
			cout << "Wrong input\n";
		}

	}
}