// main.cpp
#include <iostream>
#include "CoreDS.h"
#include "VehicleMap.h"
#include "CityGraph.h"
#include "SortSearch.h"

using namespace std;

int main()
{
    CityGraph city;
    PassengerQueue pQueue;
    VehicleHashTable vTable;
    HistoryStack history;

    int choice;
    do
    {
        cout << "\n=== ITNMS Main Menu ===\n";
        cout << "1. Add Station\n";
        cout << "2. Add Route\n";
        cout << "3. Find Shortest Path (Dijkstra)\n";
        cout << "4. Register Passenger (Queue)\n";
        cout << "5. Process Passenger\n";
        cout << "6. Add Vehicle (Hash)\n";
        cout << "7. Search Vehicle\n";
        cout << "8. Undo Last Action\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name;
            cout << "Enter ID and Name: ";
            cin >> id >> name;
            city.addStation(id, name);
            history.push("ADD_STATION", id);
            break;
        }
        case 2:
        {
            int src, dest, w;
            cout << "Enter Source ID, Dest ID, Weight: ";
            cin >> src >> dest >> w;
            city.addRoute(src, dest, w);
            break;
        }
        case 3:
        {
            int start, end;
            cout << "Enter Start ID and End ID: ";
            cin >> start >> end;
            city.Dijkstra(start, end);
            break;
        }
        case 4:
        {
            int pid;
            string pname;
            cout << "Enter ID and Name: ";
            cin >> pid >> pname;
            pQueue.enqueue(pid, pname);
            break;
        }
        case 5:
            pQueue.dequeue();
            break;
        case 6:
        {
            int vid;
            string vtype;
            cout << "Enter ID and Type: ";
            cin >> vid >> vtype;
            vTable.insert(vid, vtype);
            break;
        }
        case 7:
        {
            int vid;
            cout << "Enter Vehicle ID: ";
            cin >> vid;
            vTable.search(vid);
            break;
        }
        case 8:
        {
            LogEntry last = history.pop();
            if (last.action == "EMPTY")
                cout << "Nothing to undo.\n";
            else
                cout << "Undid action: " << last.action << " on ID: " << last.relatedID << endl;
            // Note: Real logic would require implementing a 'delete' function in CityGraph
            break;
        }
        }
    } while (choice != 0);

    return 0;
}