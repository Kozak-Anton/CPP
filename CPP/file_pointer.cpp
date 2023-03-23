#include "mode.h"
#include "file_pointer_lib.h"

void file_pointer() {
    char mask[MAXLEN] = "";
    char command[MAXLEN] = " ";
    char input_name[MAXLEN] = "input_file.txt";     
    char output_name[MAXLEN] = "output_file.txt";   


    cout << "Mask defines which words are fit for editing. Mask format must include only 1 \"*\".\n";
    edit_mask(mask);

    cout << "Command list:\n";
    cout << "wi - write input file\n";
    cout << "ri - read input file\n";
    cout << "ai - append input file\n";
    cout << "ro - read output file\n";
    cout << "nm - input new mask\n";
    cout << "end - finish programm\n\n";

    while (strcmp(command, "end")) {
        cout << "Input command: ";
        cin >> command;
        cin.ignore();

        if (!strcmp(command, "wi")) {
            write_input(input_name);
            update_output(input_name, output_name, mask);
        }
        else if (!strcmp(command, "ri")) {
            read_file(input_name);
        }
        else if (!strcmp(command, "ai")) {
            append_input(input_name);
            update_output(input_name, output_name, mask);
        }
        else if (!strcmp(command, "ro")) {
            read_file(output_name);
        }
        else if (!strcmp(command, "nm")) {
            edit_mask(mask);
            update_output(input_name, output_name, mask);
        }
        else if (strcmp(command, "end")) {
            cout << "Incorrect input\n";
        }
    }

}