#include <iostream>
#include <fstream>
#include <string>

#include "ArgumentManager.h"

using namespace std;

struct node 
{
    int value;
    int procnum = 0;
    int exittime = 0;
    int time = 0;
    int endtime = 0;
    int waittime = 0;
    int servercount = 0;
    int starttime = -1;

    node* next = nullptr;
};

class queue
{
private:
    int size = 0;
    int time2 = 0;
    int servers = 0;
    int sertime = 0;
    node* head = new node;

public:
    queue();
    ~queue();

    void serverSetting(int servernum, int servertime)
    {
        servernum = servers;
        servertime = sertime;
    }

    void size()
    {
        node* curr = head;
        curr = curr->next;
        while (curr != nullptr)
        {
            curr = curr->next;
            size++;
        }
    }

    void insert(int pos)
    {
        if (pos < 0 || pos >= size) { return; }
        
        node* curr = head;
        node* prev = head;
        node* fin = head;

        for (int i = 1; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = nullptr;

        while (fin->next != nullptr)
        {
            fin = fin->next;
        }
        fin->next = curr;
    }

    void addnode(int exectimes)
    {
        node* curr = head;
        node* temp = new node;

        temp->endtime = exectimes;
        temp->time = exectimes;
        temp->procnum = size + 1;

        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }

    bool openserv()
    {
        node* curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
            if (curr->procnum == 0)
            {
                return false;
            }
        }

        return true;
    }

    void serverfill()
    {
        node* curr = head;

        while (curr->next != nullptr)
        {
            curr = curr->next;
            if (openserv() && curr->procnum == 0)
            {
                curr->procnum = 1;
                if (curr->starttime == -1)
                {
                    curr->starttime = time2;
                }
            }
        }
    }
};

queue::~queue()
{
    delete head;
}

void print()
{/*
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
*/}

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    ifstream ifs(am.get("input"));
    ofstream ofs(am.get("output"));

    queue QL;

    int maxtime, numprocs, numservers, exectimes;

    if (!ifs.eof())
    {
        ifs >> maxtime >> numprocs >> numservers;
    }

    cout << "Max time: " << maxtime << endl;
    cout << "Number of processes: " << numprocs << endl;
    cout << "Number of servers: " << numservers << endl;
    ////////////////////////////////////////////////////
    ofs << "Max time: " << maxtime << endl;
    ofs << "Number of processes: " << numprocs << endl;
    ofs << "Number of servers: " << numservers << endl;

    for (int i = 0; i < numprocs; i++)
    {
        ifs >> exectimes;
        QL.addnode(exectimes);
    }
}