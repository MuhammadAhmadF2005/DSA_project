// SortSearch.h
#include <iostream>
using namespace std;

class SortSearchUtils
{
public:
    // 1. Bubble Sort
    static void bubbleSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // 2. Binary Search
    static int binarySearch(int arr[], int l, int r, int x)
    {
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (arr[m] == x)
                return m;
            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

    // You can add Merge/Quick sort here following the same static pattern
};