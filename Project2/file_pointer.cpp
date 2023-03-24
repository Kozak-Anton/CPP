#include "mode.h"
#include "file_pointer_lib.h"

void file_pointer() {

	char catalogue[MAX_INPUT] = "catalogue.txt";                  //Input catalogue
	char sorted_catalogue[MAX_INPUT] = "sorted_catalogue.txt";    //Author sorted catalogue
	char command[MAX_INPUT] = " ";                                //Command input

	cout << "Command list:\n";
	cout << "wc - write catalogue file\n";
	cout << "rc - read catalogue file\n";
	cout << "ac - append catalogue file\n";
	cout << "sa - search titles by athor\n";
	cout << "fa - filter catalogue by author\n";
	cout << "end - finish programm\n\n";

	while (strcmp(command, "end")) {
		cout << "Enter command: ";
		cin >> command;

		if (!strcmp(command, "wc")) {
			write_catalogue(catalogue);
		}
		else if (!strcmp(command, "rc")) {
			read_catalogue(catalogue);
		}
		else if (!strcmp(command, "ac")) {
			append_catalogue(catalogue);
		}
		else if (!strcmp(command, "sa")) {
			search_author(catalogue);
		}
		else if (!strcmp(command, "fa")) {
			filter_author(catalogue, sorted_catalogue);
			read_catalogue(sorted_catalogue);
		}
		else if (strcmp(command, "end")) {
			cout << "Wrong input\n";
		}

	}
}