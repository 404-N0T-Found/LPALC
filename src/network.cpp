#include "network.h"

Network::Network() : numberOfNodes(0)
{

}

bool Network::init(string inputPath)
{
    try
    {
        QFile inputFile(QString::fromStdString(inputPath));

        if (!inputFile.open(QFile::ReadOnly)) // try to open the file
            return false;




        // first loop to get the number of nodes
        while (!inputFile.atEnd()) // read until EOF
        {
            QString line = inputFile.readLine(); // read line by line
            line = line.replace("\r\n", "\0"); // remove the endl
            line = line.replace("\n", "\0"); // remove the endl

            QStringList list = line.split('\t'); // get two nodes

            int v1 = list.at(0).toInt(),
                    v2 = list.at(1).toInt();

            int value = (v2 > v1 ? v2 : v1);

            if (value > numberOfNodes)
                numberOfNodes = value;
        }


        // now get the edges
        inputFile.seek(0); // put the cursor at the beginning of the file


        // node labels start from zero so we should initializr from 1 to n
        edges = new SparseMatrix<int>(numberOfNodes);

        nodes = new Node[numberOfNodes + 1];
        for (int i = 1; i <= numberOfNodes; ++i)
            nodes[i].label = i;



        // second loop to get the edges
        while (!inputFile.atEnd()) // get number of nodes
        {
            QString line = inputFile.readLine();
            line = line.replace("\r\n", "\0");
            line = line.replace("\n", "\0");


            QStringList list = line.split('\t');


            int v1 = list.at(0).toInt(),
                    v2 = list.at(1).toInt();


            // indirected graph; having edge in both direction
            edges->set(v1, v2, 1);
            edges->set(v2, v1, 1);

            // add the corresponding degree
            nodes[v1].degree++;
            nodes[v2].degree++;

        }



        // close the reading file
        inputFile.close();

        return true;
    }
    catch (exception ex)
    {
        cerr << ex.what() << endl;
        return false;
    }
}

