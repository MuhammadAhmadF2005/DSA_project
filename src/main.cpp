// main.cpp
#include <iostream>
#include "CoreDS.h"
#include "VehicleMap.h"
#include "CityGraph.h"
#include "SortSearch.h"
#include "Tree.h"
#include "Heap.h"
#include "Analytics.h"

using namespace std;

void displayMainMenu()
{
    cout << "\n=== ITNMS Main Menu ===\n";
    cout << "--- Graph Operations ---\n";
    cout << "1. Add Station\n";
    cout << "2. Add Route\n";
    cout << "3. Delete Station\n";
    cout << "4. Delete Route\n";
    cout << "5. Display All Stations\n";
    cout << "6. BFS Traversal\n";
    cout << "7. DFS Traversal\n";
    cout << "8. Find Shortest Path (Dijkstra)\n";
    cout << "9. Minimum Spanning Tree (Kruskal)\n";
    cout << "10. Detect Cycle\n";
    cout << "\n--- Passenger Queue ---\n";
    cout << "11. Register Passenger\n";
    cout << "12. Process Passenger\n";
    cout << "13. Display Queue\n";
    cout << "\n--- Vehicle Hash Table ---\n";
    cout << "14. Add Vehicle\n";
    cout << "15. Search Vehicle\n";
    cout << "16. Remove Vehicle\n";
    cout << "\n--- History Stack ---\n";
    cout << "17. Undo Last Action\n";
    cout << "\n--- Binary Search Tree ---\n";
    cout << "18. Insert into BST\n";
    cout << "19. Search in BST\n";
    cout << "20. Remove from BST\n";
    cout << "21. Display BST (In-Order)\n";
    cout << "\n--- Heap (Priority Queue) ---\n";
    cout << "22. Insert into Heap\n";
    cout << "23. Extract Minimum\n";
    cout << "24. Display Heap\n";
    cout << "\n--- Searching & Sorting ---\n";
    cout << "25. Linear Search\n";
    cout << "26. Binary Search\n";
    cout << "27. Bubble Sort\n";
    cout << "28. Selection Sort\n";
    cout << "29. Insertion Sort\n";
    cout << "30. Merge Sort\n";
    cout << "31. Quick Sort\n";
    cout << "32. Heap Sort\n";
    cout << "\n--- Analytics & Reporting (Advanced DSA) ---\n";
    cout << "33. Record Station Visit (Frequency Count)\n";
    cout << "34. Find Most Crowded Station\n";
    cout << "35. Display Station Frequencies\n";
    cout << "36. Find Busiest Route\n";
    cout << "37. Analyze Route Weights\n";
    cout << "38. Assign Fastest Vehicle (Min-Heap)\n";
    cout << "39. Predict Traffic Density (Heap Sort)\n";
    cout << "40. Analyze Daily Usage Trends (BST)\n";
    cout << "41. Generate Comprehensive Report\n";
    cout << "\n0. Exit\n";
    cout << "Enter choice: ";
}

int main()
{
    CityGraph city;
    PassengerQueue pQueue;
    VehicleHashTable vTable;
    HistoryStack history;
    BST bst;
    MinHeap heap(100);
    MinHeap trafficHeap(100); // For traffic density prediction
    Analytics analytics;

    int choice;
    do
    {
        displayMainMenu();
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
            history.push("ADD_ROUTE", src);
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter Station ID to delete: ";
            cin >> id;
            city.deleteStation(id);
            history.push("DELETE_STATION", id);
            break;
        }
        case 4:
        {
            int src, dest;
            cout << "Enter Source ID and Dest ID: ";
            cin >> src >> dest;
            city.deleteRoute(src, dest);
            history.push("DELETE_ROUTE", src);
            break;
        }
        case 5:
            city.displayAllStations();
            break;
        case 6:
        {
            int start;
            cout << "Enter Start Station ID: ";
            cin >> start;
            city.BFS(start);
            break;
        }
        case 7:
        {
            int start;
            cout << "Enter Start Station ID: ";
            cin >> start;
            city.DFS(start);
            break;
        }
        case 8:
        {
            int start, end;
            cout << "Enter Start ID and End ID: ";
            cin >> start >> end;
            city.Dijkstra(start, end);
            break;
        }
        case 9:
            city.MST_Kruskal();
            break;
        case 10:
        {
            if (city.detectCycle())
                cout << "Cycle detected in the graph.\n";
            else
                cout << "No cycle detected.\n";
            break;
        }
        case 11:
        {
            int pid;
            string pname;
            cout << "Enter ID and Name: ";
            cin >> pid >> pname;
            pQueue.enqueue(pid, pname);
            break;
        }
        case 12:
            pQueue.dequeue();
            break;
        case 13:
            pQueue.display();
            break;
        case 14:
        {
            int vid;
            string vtype;
            cout << "Enter ID and Type: ";
            cin >> vid >> vtype;
            vTable.insert(vid, vtype);
            break;
        }
        case 15:
        {
            int vid;
            cout << "Enter Vehicle ID: ";
            cin >> vid;
            vTable.search(vid);
            break;
        }
        case 16:
        {
            int vid;
            cout << "Enter Vehicle ID to remove: ";
            cin >> vid;
            vTable.remove(vid);
            break;
        }
        case 17:
        {
            LogEntry last = history.pop();
            if (last.action == "EMPTY")
                cout << "Nothing to undo.\n";
            else
                cout << "Undid action: " << last.action << " on ID: " << last.relatedID << endl;
            break;
        }
        case 18:
        {
            int key;
            string data;
            cout << "Enter key and data: ";
            cin >> key >> data;
            bst.insert(key, data);
            break;
        }
        case 19:
        {
            int key;
            cout << "Enter key to search: ";
            cin >> key;
            bst.search(key);
            break;
        }
        case 20:
        {
            int key;
            cout << "Enter key to remove: ";
            cin >> key;
            bst.remove(key);
            break;
        }
        case 21:
            bst.inOrder();
            break;
        case 22:
        {
            int priority, id;
            string data;
            cout << "Enter Priority, ID, and Data: ";
            cin >> priority >> id >> data;
            heap.insert(priority, data, id);
            break;
        }
        case 23:
        {
            HeapNode min = heap.extractMin();
            if (min.id != -1)
                cout << "Extracted: [" << min.id << ": " << min.data << "] Priority: " << min.priority << "\n";
            else
                cout << "Heap is empty.\n";
            break;
        }
        case 24:
            heap.display();
            break;
        case 25:
        {
            int n, x;
            cout << "Enter array size: ";
            cin >> n;
            int *arr = new int[n];
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Enter element to search: ";
            cin >> x;
            ComplexityMetrics m = SortSearchUtils::linearSearch(arr, n, x);
            m.display();
            delete[] arr;
            break;
        }
        case 26:
        {
            int n, x;
            cout << "Enter sorted array size: ";
            cin >> n;
            int *arr = new int[n];
            cout << "Enter " << n << " sorted elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Enter element to search: ";
            cin >> x;
            ComplexityMetrics m = SortSearchUtils::binarySearch(arr, 0, n - 1, x);
            m.display();
            delete[] arr;
            break;
        }
        case 27:
        {
            int n;
            cout << "Enter array size: ";
            cin >> n;
            int *arr = new int[n];
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Original: ";
            SortSearchUtils::printArray(arr, n);
            ComplexityMetrics m = SortSearchUtils::bubbleSort(arr, n);
            cout << "Sorted: ";
            SortSearchUtils::printArray(arr, n);
            m.display();
            delete[] arr;
            break;
        }
        case 28:
        {
            int n;
            cout << "Enter array size: ";
            cin >> n;
            int *arr = new int[n];
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Original: ";
            SortSearchUtils::printArray(arr, n);
            ComplexityMetrics m = SortSearchUtils::selectionSort(arr, n);
            cout << "Sorted: ";
            SortSearchUtils::printArray(arr, n);
            m.display();
            delete[] arr;
            break;
        }
        case 29:
        {
            int n;
            cout << "Enter array size: ";
            cin >> n;
            int *arr = new int[n];
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Original: ";
            SortSearchUtils::printArray(arr, n);
            ComplexityMetrics m = SortSearchUtils::insertionSort(arr, n);
            cout << "Sorted: ";
            SortSearchUtils::printArray(arr, n);
            m.display();
            delete[] arr;
            break;
        }
        case 30:
        {
            int n;
            cout << "Enter array size: ";
            cin >> n;
            int *arr = new int[n];
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Original: ";
            SortSearchUtils::printArray(arr, n);
            ComplexityMetrics m = SortSearchUtils::mergeSort(arr, n);
            cout << "Sorted: ";
            SortSearchUtils::printArray(arr, n);
            m.display();
            delete[] arr;
            break;
        }
        case 31:
        {
            int n;
            cout << "Enter array size: ";
            cin >> n;
            int *arr = new int[n];
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Original: ";
            SortSearchUtils::printArray(arr, n);
            ComplexityMetrics m = SortSearchUtils::quickSort(arr, n);
            cout << "Sorted: ";
            SortSearchUtils::printArray(arr, n);
            m.display();
            delete[] arr;
            break;
        }
        case 32:
        {
            int n;
            cout << "Enter array size: ";
            cin >> n;
            int *arr = new int[n];
            cout << "Enter " << n << " elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Original: ";
            SortSearchUtils::printArray(arr, n);
            ComplexityMetrics m = SortSearchUtils::heapSort(arr, n);
            cout << "Sorted: ";
            SortSearchUtils::printArray(arr, n);
            m.display();
            delete[] arr;
            break;
        }
        case 33:
        {
            int stationID;
            cout << "Enter Station ID to record visit: ";
            cin >> stationID;
            analytics.recordStationVisit(stationID);
            cout << "Visit recorded for station " << stationID << ".\n";
            break;
        }
        case 34:
            analytics.findMostCrowdedStation(city);
            break;
        case 35:
            analytics.displayStationFrequencies();
            break;
        case 36:
            analytics.findBusiestRoute(city);
            break;
        case 37:
            analytics.analyzeRouteWeights(city);
            break;
        case 38:
            analytics.assignFastestVehicle(heap);
            break;
        case 39:
            analytics.predictTrafficDensity(trafficHeap);
            break;
        case 40:
            analytics.analyzeDailyUsageTrends(bst);
            break;
        case 41:
            analytics.generateReport(city, heap, bst);
            break;
        }
    } while (choice != 0);

    return 0;
}