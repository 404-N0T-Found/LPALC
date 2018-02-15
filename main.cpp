#include <src/network.h>

int main(int argc, char *argv[])
{
    Network network;

    string outputPath = "output.txt";


    if (argc == 3) // just input file passed as command line argument
    {
        network.init(argv[1], strtol(argv[2], '\0', 10));
    }
    else if (argc == 4) // input and output
    {
        network.init(argv[1], strtol(argv[2], '\0', 10));
        outputPath = argv[3];
    }
    else // none
    {
        cout << "Usage: main.o <input file path> <number of real clusters>"
                " [<output file path>]\n";
        return 4;
    }

    if (network.mainFunc());

    return 0;
}
