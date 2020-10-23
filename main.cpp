#include <iostream>
#include <fstream>
#include <string>

#include "ArgumentManager.h"

using namespace std;

struct node 
{
    int value;
    node* next = nullptr;
};

class queue
{
private:
    int size = 0;


public:
    queue();
    ~queue();

    void dequeue();
    void enqueue();
    int front();
    int size();
    bool isEmpty();
    bool isFull();

};

queue::queue()
{

}

void print()
{
    cout << "Max time: " << maxtime << endl;
    cout << "Number of processes: " << numprocs << endl;
    cout << "Number of servers: " << numservers << endl;
    ////////////////////////////////////////////////////
    ofs << "Max time: " << maxtime << endl;
    ofs << "Number of processes: " << numprocs << endl;
    ofs << "Number of servers: " << numservers << endl;

    for (int i = 1; i <= numprocs; i++)
    {
        cout << "Process: " << i << endl;
        cout << "Execution time: " << exectimes << endl;
        cout << "Wait Time: " << waittime << endl; // not added
        cout << "Start Time: " << starttime << endl; // not added
        cout << "End Time: " << endtime << endl; // not added
        ////////////////////////////////////////////////////
        ofs << "Process: " << i << endl;
        ofs << "Execution time: " << exectimes << endl;
        ofs << "Wait Time: " << waittime << endl; // not added
        ofs << "Start Time: " << starttime << endl; // not added
        ofs << "End Time: " << endtime << endl; // not added
    }
}

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    ifstream ifs(am.get("input"));
    ofstream ofs(am.get("output"));

    int maxtime, numprocs, numservers;
    string exectimes;

    if (!ifs.eof())
    {
        ifs >> maxtime >> numprocs >> numservers;
    }

    for (int i = 0; i < numprocs; i++)
    {

    }
}