/*
Козак А.М. ІП-23
Варінт 34
*/

#include "mode.h"

int main(int argc, char* argv[])
{
    bool arg_mode, pointer_mode, stream_mode;

    if (argc != 3) {
        cout << "Invalid number of arguments\n Usage: program_name [ -mode ] [ FilePointer | FileStream ]\n";
        return 1;
    }

    arg_mode = !strcmp(argv[1], "-mode");
    pointer_mode = !strcmp(argv[2], "FilePointer");
    stream_mode = !strcmp(argv[2], "FileStream");

    if (!arg_mode) {
        cout << "Invalid arguments\n Usage: program_name [ -mode ] [ FilePointer | FileStream ]\n";
        return 1;
    }
    else if (!pointer_mode && !stream_mode) {
        cout << "Invalid arguments\n Usage: program_name -mode [ FilePointer | FileStream ]\n";
        return 1;
    }
    else if (pointer_mode) {
        file_pointer();
    }
    else {
        file_stream();
    }

    return 0;
}


