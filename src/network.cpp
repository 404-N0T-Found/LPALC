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

        nodes = new vector<Node>(numberOfNodes + 1);
        for (int i = 1; i <= numberOfNodes; ++i)
        {
            nodes->at(i).label = i;
            nodes->at(i).degree = 0;
            nodes->at(i).newLabel = i;
        }


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
            nodes->at(v1).degree++;
            nodes->at(v2).degree++;

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

bool Network::mainFunc()
{
    int t = 1;
    while (NMI() >= exp(1)
           && (t <= numberOfNodes))
    {
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(nodes->begin() + 1, nodes->end(), default_random_engine(seed));


        for (int i = 1; i <= numberOfNodes; ++i)
        {
            vector<int> neighbors = edges->getNeighbors(i);



            /* the calculations are based on the labels or as we call it 'newLabel'
             * not the node number itself which is just a distinction of nodes
             */
            for (int i = 0; i < neighbors.size(); i++)
            {
                int tmp = neighbors.at(i);
                neighbors.at(i) = nodes->at(tmp).newLabel;
            }



            map<int, int> neighborFreq;
            foreach (int j, neighbors)
                if (neighborFreq.count(j) == 0)
                    neighborFreq.insert(make_pair(j, count(neighbors.begin(),
                                                           neighbors.end(),
                                                           j)));


            map<int, int>::iterator iter = neighborFreq.begin();

            int numberOfMax = 1;
            int maxIndex = iter->first,
                    maxFreq = iter->second;
            iter++;

            for (; iter != neighborFreq.end(); iter++)
            {
                if (iter->second > maxFreq)
                {
                    numberOfMax = 1;
                    maxIndex = iter->first;
                    maxFreq = iter->second;
                }
                else if (iter->second == maxFreq)
                    numberOfMax++;
            }

            /* difference between LPA and LPACL happens here cause it looks
             * for cycles in case of multiple labels having the same number
             * of repetition in a node's neighbors list
             */
            if (numberOfMax > 1)
            {

            }
            else // only one type of labels are in the node's neighbors list
            {

            }

        }
        t++;
    }
}

int Network::NMI()
{
    return 10;
}
