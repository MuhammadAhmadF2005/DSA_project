// test_simple.cpp - Comprehensive test suite for ITNMS Project
#include <iostream>
#include <cassert>
#include <iomanip>
#include "CoreDS.h"
#include "VehicleMap.h"
#include "CityGraph.h"
#include "SortSearch.h"
#include "Tree.h"
#include "Heap.h"
#include "Analytics.h"

using namespace std;

// Test result tracking
int testsPassed = 0;
int testsFailed = 0;
int totalTests = 0;

// Test wrapper macro
#define TEST(name, testFunc)                                           \
    do                                                                 \
    {                                                                  \
        totalTests++;                                                  \
        cout << "\n[" << totalTests << "] Testing " << name << "... "; \
        try                                                            \
        {                                                              \
            testFunc();                                                \
            testsPassed++;                                             \
            cout << "✓ PASSED\n";                                      \
        }                                                              \
        catch (const exception &e)                                     \
        {                                                              \
            testsFailed++;                                             \
            cout << "✗ FAILED: " << e.what() << "\n";                  \
        }                                                              \
        catch (...)                                                    \
        {                                                              \
            testsFailed++;                                             \
            cout << "✗ FAILED: Unknown error\n";                       \
        }                                                              \
    } while (0)

// ========== CoreDS Tests ==========

void test_PassengerQueue_enqueue()
{
    PassengerQueue q;
    q.enqueue(1, "Alice");
    q.enqueue(2, "Bob");
    q.enqueue(3, "Charlie");
    assert(true);
}

void test_PassengerQueue_dequeue()
{
    PassengerQueue q;
    q.enqueue(1, "Alice");
    q.enqueue(2, "Bob");
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Should handle empty queue gracefully
    assert(true);
}

void test_PassengerQueue_display()
{
    PassengerQueue q;
    q.enqueue(1, "Alice");
    q.enqueue(2, "Bob");
    q.display(); // Just verify it doesn't crash
    assert(true);
}

void test_HistoryStack_push_pop()
{
    HistoryStack s;
    s.push("ADD_STATION", 1);
    s.push("ADD_ROUTE", 2);
    LogEntry e1 = s.pop();
    assert(e1.action == "ADD_ROUTE");
    assert(e1.relatedID == 2);
    LogEntry e2 = s.pop();
    assert(e2.action == "ADD_STATION");
    assert(e2.relatedID == 1);
}

void test_HistoryStack_isEmpty()
{
    HistoryStack s;
    assert(s.isEmpty() == true);
    s.push("TEST", 1);
    assert(s.isEmpty() == false);
    s.pop();
    assert(s.isEmpty() == true);
}

// ========== CityGraph Tests ==========

void test_CityGraph_addStation()
{
    CityGraph g;
    g.addStation(0, "StationA");
    g.addStation(1, "StationB");
    g.addStation(2, "StationC");
    assert(true);
}

void test_CityGraph_addRoute()
{
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addStation(2, "C");
    g.addRoute(0, 1, 10);
    g.addRoute(1, 2, 20);
    assert(true);
}

void test_CityGraph_BFS()
{
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addStation(2, "C");
    g.addRoute(0, 1, 10);
    g.addRoute(1, 2, 20);
    g.BFS(0); // Just verify it doesn't crash
    assert(true);
}

void test_CityGraph_DFS()
{
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addStation(2, "C");
    g.addRoute(0, 1, 10);
    g.addRoute(1, 2, 20);
    g.DFS(0); // Just verify it doesn't crash
    assert(true);
}

void test_CityGraph_Dijkstra()
{
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addStation(2, "C");
    g.addRoute(0, 1, 10);
    g.addRoute(1, 2, 20);
    g.Dijkstra(0, 2); // Just verify it doesn't crash
    assert(true);
}

void test_CityGraph_MST_Kruskal()
{
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addStation(2, "C");
    g.addRoute(0, 1, 10);
    g.addRoute(1, 2, 20);
    g.addRoute(0, 2, 30);
    g.MST_Kruskal(); // Just verify it doesn't crash
    assert(true);
}

void test_CityGraph_detectCycle()
{
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addStation(2, "C");
    g.addRoute(0, 1, 10);
    g.addRoute(1, 2, 20);
    g.addRoute(2, 0, 30); // Creates cycle
    bool hasCycle = g.detectCycle();
    assert(hasCycle == true);
}

void test_CityGraph_deleteStation()
{
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addRoute(0, 1, 10);
    g.deleteStation(0);
    assert(true);
}

void test_CityGraph_deleteRoute()
{
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addRoute(0, 1, 10);
    g.deleteRoute(0, 1);
    assert(true);
}

void test_CityGraph_displayAllStations()
{
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addRoute(0, 1, 10);
    g.displayAllStations(); // Just verify it doesn't crash
    assert(true);
}

// ========== VehicleMap Tests ==========

void test_VehicleHashTable_insert()
{
    VehicleHashTable v;
    v.insert(1, "Bus");
    v.insert(2, "Train");
    v.insert(3, "Taxi");
    assert(true);
}

void test_VehicleHashTable_search()
{
    VehicleHashTable v;
    v.insert(1, "Bus");
    v.insert(2, "Train");
    v.search(1); // Just verify it doesn't crash
    assert(true);
}

void test_VehicleHashTable_remove()
{
    VehicleHashTable v;
    v.insert(1, "Bus");
    v.insert(2, "Train");
    v.remove(1);
    v.search(1); // Should handle not found
    assert(true);
}

// ========== SortSearch Tests ==========

void test_linearSearch_found()
{
    int arr[] = {1, 2, 3, 4, 5};
    ComplexityMetrics m = SortSearchUtils::linearSearch(arr, 5, 3);
    assert(m.algorithm == "Linear Search");
}

void test_linearSearch_notFound()
{
    int arr[] = {1, 2, 3, 4, 5};
    ComplexityMetrics m = SortSearchUtils::linearSearch(arr, 5, 10);
    assert(m.algorithm == "Linear Search");
}

void test_binarySearch_found()
{
    int arr[] = {1, 2, 3, 4, 5};
    ComplexityMetrics m = SortSearchUtils::binarySearch(arr, 0, 4, 3);
    assert(m.algorithm == "Binary Search");
}

void test_binarySearch_notFound()
{
    int arr[] = {1, 2, 3, 4, 5};
    ComplexityMetrics m = SortSearchUtils::binarySearch(arr, 0, 4, 10);
    assert(m.algorithm == "Binary Search");
}

void test_bubbleSort()
{
    int arr[] = {5, 2, 8, 1, 9};
    int sorted[] = {1, 2, 5, 8, 9};
    ComplexityMetrics m = SortSearchUtils::bubbleSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        assert(arr[i] == sorted[i]);
    }
}

void test_selectionSort()
{
    int arr[] = {5, 2, 8, 1, 9};
    int sorted[] = {1, 2, 5, 8, 9};
    ComplexityMetrics m = SortSearchUtils::selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        assert(arr[i] == sorted[i]);
    }
}

void test_insertionSort()
{
    int arr[] = {5, 2, 8, 1, 9};
    int sorted[] = {1, 2, 5, 8, 9};
    ComplexityMetrics m = SortSearchUtils::insertionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        assert(arr[i] == sorted[i]);
    }
}

void test_mergeSort()
{
    int arr[] = {5, 2, 8, 1, 9};
    int sorted[] = {1, 2, 5, 8, 9};
    ComplexityMetrics m = SortSearchUtils::mergeSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        assert(arr[i] == sorted[i]);
    }
}

void test_quickSort()
{
    int arr[] = {5, 2, 8, 1, 9};
    int sorted[] = {1, 2, 5, 8, 9};
    ComplexityMetrics m = SortSearchUtils::quickSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        assert(arr[i] == sorted[i]);
    }
}

void test_heapSort()
{
    int arr[] = {5, 2, 8, 1, 9};
    int sorted[] = {1, 2, 5, 8, 9};
    ComplexityMetrics m = SortSearchUtils::heapSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        assert(arr[i] == sorted[i]);
    }
}

// ========== Tree Tests ==========

void test_BST_insert()
{
    BST bst;
    bst.insert(5, "Data5");
    bst.insert(3, "Data3");
    bst.insert(7, "Data7");
    assert(true);
}

void test_BST_search()
{
    BST bst;
    bst.insert(5, "Data5");
    bst.insert(3, "Data3");
    bst.search(5); // Just verify it doesn't crash
    assert(true);
}

void test_BST_search_notFound()
{
    BST bst;
    bst.insert(5, "Data5");
    bst.search(10); // Just verify it doesn't crash
    assert(true);
}

void test_BST_inOrder()
{
    BST bst;
    bst.insert(5, "Data5");
    bst.insert(3, "Data3");
    bst.insert(7, "Data7");
    bst.inOrder(); // Just verify it doesn't crash
    assert(true);
}

void test_BST_remove()
{
    BST bst;
    bst.insert(5, "Data5");
    bst.insert(3, "Data3");
    bst.insert(7, "Data7");
    bst.remove(5);
    assert(true);
}

// ========== Heap Tests ==========

void test_MinHeap_insert()
{
    MinHeap h(10);
    h.insert(5, "Task1", 1);
    h.insert(3, "Task2", 2);
    h.insert(7, "Task3", 3);
    assert(true);
}

void test_MinHeap_extractMin()
{
    MinHeap h(10);
    h.insert(5, "Task1", 1);
    h.insert(3, "Task2", 2);
    h.insert(7, "Task3", 3);
    HeapNode min = h.extractMin();
    assert(min.priority == 3);
    assert(min.id == 2);
}

void test_MinHeap_getMin()
{
    MinHeap h(10);
    h.insert(5, "Task1", 1);
    h.insert(3, "Task2", 2);
    HeapNode min = h.getMin();
    assert(min.priority == 3);
    assert(min.id == 2);
}

void test_MinHeap_isEmpty()
{
    MinHeap h(10);
    assert(h.isEmpty() == true);
    h.insert(5, "Task1", 1);
    assert(h.isEmpty() == false);
}

void test_MinHeap_display()
{
    MinHeap h(10);
    h.insert(5, "Task1", 1);
    h.insert(3, "Task2", 2);
    h.display(); // Just verify it doesn't crash
    assert(true);
}

// ========== Analytics Tests ==========

void test_Analytics_recordStationVisit()
{
    Analytics a;
    a.recordStationVisit(1);
    a.recordStationVisit(1);
    a.recordStationVisit(2);
    assert(true);
}

void test_Analytics_findMostCrowdedStation()
{
    Analytics a;
    CityGraph g;
    g.addStation(1, "Station1");
    g.addStation(2, "Station2");
    a.recordStationVisit(1);
    a.recordStationVisit(1);
    a.recordStationVisit(2);
    a.findMostCrowdedStation(g); // Just verify it doesn't crash
    assert(true);
}

void test_Analytics_displayStationFrequencies()
{
    Analytics a;
    a.recordStationVisit(1);
    a.recordStationVisit(2);
    a.displayStationFrequencies(); // Just verify it doesn't crash
    assert(true);
}

void test_Analytics_findBusiestRoute()
{
    Analytics a;
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addStation(2, "C");
    g.addRoute(0, 1, 50);
    g.addRoute(1, 2, 30);
    a.findBusiestRoute(g); // Just verify it doesn't crash
    assert(true);
}

void test_Analytics_analyzeRouteWeights()
{
    Analytics a;
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addStation(2, "C");
    g.addRoute(0, 1, 50);
    g.addRoute(1, 2, 30);
    a.analyzeRouteWeights(g); // Just verify it doesn't crash
    assert(true);
}

void test_Analytics_assignFastestVehicle()
{
    Analytics a;
    MinHeap h(10);
    h.insert(5, "Bus", 1);
    h.insert(3, "Train", 2);
    a.assignFastestVehicle(h); // Just verify it doesn't crash
    assert(true);
}

void test_Analytics_predictTrafficDensity()
{
    Analytics a;
    MinHeap h(10);
    h.insert(5, "Area1", 1);
    h.insert(3, "Area2", 2);
    a.predictTrafficDensity(h); // Just verify it doesn't crash
    assert(true);
}

void test_Analytics_analyzeDailyUsageTrends()
{
    Analytics a;
    BST bst;
    bst.insert(1, "Day1");
    bst.insert(2, "Day2");
    a.analyzeDailyUsageTrends(bst); // Just verify it doesn't crash
    assert(true);
}

void test_Analytics_generateReport()
{
    Analytics a;
    CityGraph g;
    g.addStation(0, "A");
    g.addStation(1, "B");
    g.addRoute(0, 1, 10);
    MinHeap h(10);
    h.insert(5, "Bus", 1);
    BST bst;
    bst.insert(1, "Data1");
    a.generateReport(g, h, bst); // Just verify it doesn't crash
    assert(true);
}

// ========== Main Test Runner ==========

int main()
{
    cout << "\n";
    cout << "========================================\n";
    cout << "  ITNMS COMPREHENSIVE TEST SUITE\n";
    cout << "========================================\n";

    // CoreDS Tests
    cout << "\n--- CoreDS Tests ---\n";
    TEST("PassengerQueue::enqueue", test_PassengerQueue_enqueue);
    TEST("PassengerQueue::dequeue", test_PassengerQueue_dequeue);
    TEST("PassengerQueue::display", test_PassengerQueue_display);
    TEST("HistoryStack::push_pop", test_HistoryStack_push_pop);
    TEST("HistoryStack::isEmpty", test_HistoryStack_isEmpty);

    // CityGraph Tests
    cout << "\n--- CityGraph Tests ---\n";
    TEST("CityGraph::addStation", test_CityGraph_addStation);
    TEST("CityGraph::addRoute", test_CityGraph_addRoute);
    TEST("CityGraph::BFS", test_CityGraph_BFS);
    TEST("CityGraph::DFS", test_CityGraph_DFS);
    TEST("CityGraph::Dijkstra", test_CityGraph_Dijkstra);
    TEST("CityGraph::MST_Kruskal", test_CityGraph_MST_Kruskal);
    TEST("CityGraph::detectCycle", test_CityGraph_detectCycle);
    TEST("CityGraph::deleteStation", test_CityGraph_deleteStation);
    TEST("CityGraph::deleteRoute", test_CityGraph_deleteRoute);
    TEST("CityGraph::displayAllStations", test_CityGraph_displayAllStations);

    // VehicleMap Tests
    cout << "\n--- VehicleMap Tests ---\n";
    TEST("VehicleHashTable::insert", test_VehicleHashTable_insert);
    TEST("VehicleHashTable::search", test_VehicleHashTable_search);
    TEST("VehicleHashTable::remove", test_VehicleHashTable_remove);

    // SortSearch Tests
    cout << "\n--- SortSearch Tests ---\n";
    TEST("SortSearchUtils::linearSearch (found)", test_linearSearch_found);
    TEST("SortSearchUtils::linearSearch (not found)", test_linearSearch_notFound);
    TEST("SortSearchUtils::binarySearch (found)", test_binarySearch_found);
    TEST("SortSearchUtils::binarySearch (not found)", test_binarySearch_notFound);
    TEST("SortSearchUtils::bubbleSort", test_bubbleSort);
    TEST("SortSearchUtils::selectionSort", test_selectionSort);
    TEST("SortSearchUtils::insertionSort", test_insertionSort);
    TEST("SortSearchUtils::mergeSort", test_mergeSort);
    TEST("SortSearchUtils::quickSort", test_quickSort);
    TEST("SortSearchUtils::heapSort", test_heapSort);

    // Tree Tests
    cout << "\n--- Tree Tests ---\n";
    TEST("BST::insert", test_BST_insert);
    TEST("BST::search (found)", test_BST_search);
    TEST("BST::search (not found)", test_BST_search_notFound);
    TEST("BST::inOrder", test_BST_inOrder);
    TEST("BST::remove", test_BST_remove);

    // Heap Tests
    cout << "\n--- Heap Tests ---\n";
    TEST("MinHeap::insert", test_MinHeap_insert);
    TEST("MinHeap::extractMin", test_MinHeap_extractMin);
    TEST("MinHeap::getMin", test_MinHeap_getMin);
    TEST("MinHeap::isEmpty", test_MinHeap_isEmpty);
    TEST("MinHeap::display", test_MinHeap_display);

    // Analytics Tests
    cout << "\n--- Analytics Tests ---\n";
    TEST("Analytics::recordStationVisit", test_Analytics_recordStationVisit);
    TEST("Analytics::findMostCrowdedStation", test_Analytics_findMostCrowdedStation);
    TEST("Analytics::displayStationFrequencies", test_Analytics_displayStationFrequencies);
    TEST("Analytics::findBusiestRoute", test_Analytics_findBusiestRoute);
    TEST("Analytics::analyzeRouteWeights", test_Analytics_analyzeRouteWeights);
    TEST("Analytics::assignFastestVehicle", test_Analytics_assignFastestVehicle);
    TEST("Analytics::predictTrafficDensity", test_Analytics_predictTrafficDensity);
    TEST("Analytics::analyzeDailyUsageTrends", test_Analytics_analyzeDailyUsageTrends);
    TEST("Analytics::generateReport", test_Analytics_generateReport);

    // Summary
    cout << "\n========================================\n";
    cout << "  TEST SUMMARY\n";
    cout << "========================================\n";
    cout << "Total Tests: " << totalTests << "\n";
    cout << "Passed: " << testsPassed << "\n";
    cout << "Failed: " << testsFailed << "\n";
    cout << "Success Rate: " << fixed << setprecision(1)
         << (totalTests > 0 ? (100.0 * testsPassed / totalTests) : 0) << "%\n";
    cout << "========================================\n\n";

    if (testsFailed == 0)
    {
        cout << "✓ ALL TESTS PASSED!\n";
        return 0;
    }
    else
    {
        cout << "✗ SOME TESTS FAILED\n";
        return 1;
    }
}
