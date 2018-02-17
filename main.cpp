#include <src/network.h>

int main(int argc, char *argv[])
{
    Network network;

    string outputPath = "output.txt";


    if (argc == 3) // just input file passed as command line argument
    {
        network.init(argv[1]);
    }
    else if (argc == 4) // input and output
    {
        network.init(argv[1]);
        outputPath = argv[2];
    }
    else // none
    {
        cout << "Usage: main.o <input file path>"
                " [<output file path>]\n";
        return 4;
    }

    if (network.mainFunc());

    return 0;
}
