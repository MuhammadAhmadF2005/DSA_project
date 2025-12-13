// VehicleMap.h
#include "Models.h"

const int TABLE_SIZE = 10;

class VehicleHashTable
{
private:
    Vehicle *table[TABLE_SIZE]; // Array of pointers

    int hashFunction(int id)
    {
        return id % TABLE_SIZE;
    }

public:
    VehicleHashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }

    void insert(int id, string type)
    {
        int idx = hashFunction(id);
        Vehicle *newV = new Vehicle{id, type, nullptr};

        // Head insertion (Chaining)
        if (table[idx] == nullptr)
        {
            table[idx] = newV;
        }
        else
        {
            newV->next = table[idx];
            table[idx] = newV;
        }
        cout << "Vehicle " << id << " added.\n";
    }

    void search(int id)
    {
        int idx = hashFunction(id);
        Vehicle *temp = table[idx];
        while (temp != nullptr)
        {
            if (temp->id == id)
            {
                cout << "Found Vehicle: " << temp->type << " (ID: " << id << ")\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Vehicle not found.\n";
    }

    // Note: Delete function is similar to Linked List delete
};