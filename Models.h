// Models.h
#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <iostream>
using namespace std;

// 1. Station (Node)
struct Station
{
    int id;
    string name;
    Station *next; // For linked lists
};

// 2. Route (Edge)
struct Route
{
    int destID;
    int weight;  // Distance or Time
    Route *next; // For adjacency list
};

// 3. Passenger
struct Passenger
{
    int id;
    string name;
    Passenger *next; // For Queue
};

// 4. Vehicle
struct Vehicle
{
    int id;
    string type;   // Bus, Train, Taxi
    Vehicle *next; // For Hash Table collision (Chaining)
};

// 5. History Log (For Undo Stack)
struct LogEntry
{
    string action; // e.g., "ADDED_STATION"
    int relatedID;
    LogEntry *next;
};

#endif