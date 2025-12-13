// CityGraph.h
#include "Models.h"
#include <climits> // For INT_MAX

const int MAX_STATIONS = 100;

class CityGraph
{
private:
    Station *stations[MAX_STATIONS]; // Array to store station metadata
    Route *adjList[MAX_STATIONS];    // Adjacency List
    int stationCount;

public:
    CityGraph()
    {
        stationCount = 0;
        for (int i = 0; i < MAX_STATIONS; i++)
        {
            adjList[i] = nullptr;
            stations[i] = nullptr;
        }
    }

    void addStation(int id, string name)
    {
        if (id >= MAX_STATIONS)
        {
            cout << "ID too high!\n";
            return;
        }
        stations[id] = new Station{id, name, nullptr};
        stationCount++;
        cout << "Station " << name << " added.\n";
    }

    void addRoute(int src, int dest, int weight)
    {
        // Add edge src -> dest
        Route *newRoute = new Route{dest, weight, adjList[src]};
        adjList[src] = newRoute;

        // Add edge dest -> src (Undirected Graph)
        Route *newRoute2 = new Route{src, weight, adjList[dest]};
        adjList[dest] = newRoute2;
    }

    void BFS(int startID)
    {
        bool visited[MAX_STATIONS] = {false};
        int queue[MAX_STATIONS]; // Simple array based queue
        int front = 0, rear = 0;

        visited[startID] = true;
        queue[rear++] = startID;

        cout << "BFS Traversal: ";
        while (front < rear)
        {
            int curr = queue[front++];
            cout << curr << " ";

            Route *temp = adjList[curr];
            while (temp)
            {
                if (!visited[temp->destID])
                {
                    visited[temp->destID] = true;
                    queue[rear++] = temp->destID;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    // Dijkstra's Shortest Path
    void Dijkstra(int start, int end)
    {
        int dist[MAX_STATIONS];
        bool visited[MAX_STATIONS];
        int parent[MAX_STATIONS];

        for (int i = 0; i < MAX_STATIONS; i++)
        {
            dist[i] = INT_MAX;
            visited[i] = false;
            parent[i] = -1;
        }

        dist[start] = 0;

        for (int count = 0; count < MAX_STATIONS; count++)
        {
            // 1. Find min distance node not yet visited
            int min = INT_MAX, u = -1;
            for (int v = 0; v < MAX_STATIONS; v++)
            {
                if (!visited[v] && dist[v] <= min && stations[v] != nullptr)
                {
                    min = dist[v];
                    u = v;
                }
            }

            if (u == -1 || u == end)
                break;
            visited[u] = true;

            // 2. Relax neighbors
            Route *temp = adjList[u];
            while (temp)
            {
                if (!visited[temp->destID] && dist[u] != INT_MAX && dist[u] + temp->weight < dist[temp->destID])
                {
                    dist[temp->destID] = dist[u] + temp->weight;
                    parent[temp->destID] = u;
                }
                temp = temp->next;
            }
        }

        if (dist[end] == INT_MAX)
        {
            cout << "No path exists.\n";
        }
        else
        {
            cout << "Shortest Distance: " << dist[end] << "\nPath: ";
            // Backtrack path could be printed here using parent array
            int curr = end;
            while (curr != -1)
            {
                cout << curr << " <- ";
                curr = parent[curr];
            }
            cout << "Start\n";
        }
    }
};