#include "mode.h"
#include "file_stream_lib.h"

void file_stream() {
    string mask;                                    //Mask for word search
    string command = "";                            //Command input
    const string input_name = "input_file.txt";     //Input text file name
    const string output_name = "output_file.txt";   //Editet text file name

    cout << "Mask defines which words are fit for editing. Mask format must include only 1 \"*\".\n";
    edit_mask(mask);

    cout << "Command list:\n";
    cout << "wi - write input file\n";
    cout << "ri - read input file\n";
    cout << "ai - append input file\n";
    cout << "ro - read output file\n";
    cout << "nm - input new mask\n";
    cout << "end - finish programm\n\n";

    while (command != "end") {
        cout << "Input command: ";
        cin >> command;
        cin.ignore();

        if (command == "wi") {
            write_input(input_name);
            update_output(input_name, output_name, mask);
        }
        else if (command == "ri")
            read_file(input_name);
        else if (command == "ai") {
            append_input(input_name);
            update_output(input_name, output_name, mask);
        }
        else if (command == "ro")
            read_file(output_name);
        else if (command == "nm") {
            edit_mask(mask);
            update_output(input_name, output_name, mask);
        }
        else if (command != "end")
            cout << "Incorrect input\n";
    }
}