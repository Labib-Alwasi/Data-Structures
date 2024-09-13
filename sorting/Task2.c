#include <stdio.h>
#include "Task2.h"
#include "Task1.h"
#include <stdbool.h>

int number_comparisons = 0;
int number_swaps = 0;

int sorted = 0;

// bool check(const int array[], int n)
// {
//     const int a0 = array[0];
//     // printf("enters checking\n");
//     for (int i = 1; i < n; i++)
//     {
//         if (array[i] != a0)
//         {
//             number_comparisons++;
//             return true;
//         }
//     }
//     return false;
// }

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    // printf("%d || %d", xp, yp);
    number_swaps++;
}

void selectionSort(int arr[], int size)
{
    // TODO
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size - 1; i++)
    { // selection sort

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            number_comparisons++;
            if (arr[j] <= arr[min_idx])
            { // for ascending order
                min_idx = j;
                // number_comparisons++; // increment
            }
        }
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int size)
{
    // TODO
    // int key, i;
    for (int value = 0; value < size - 1; value++)
    {
        // number_comparisons++;
        // key = arr[value];
        // i = value;

        // while( i > 0 && arr[i-1] > key) {
        //   number_comparisons++;
        //   number_swaps++;
        //   arr[i] = arr[i-1];
        //   i--;
        // }

        for (int i = value + 1; i >= 0; i--)
        {
            number_comparisons++;

            if (arr[i - 1] > arr[i])
            {
                // number_comparisons++;
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                number_swaps++;
            }
            else
            {
                break;
            }
        }
    }
}

int partition(int arr[], int low, int high)
{
    if (low == high)
    {
        number_comparisons++;
        return low;
    }
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {

        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            number_comparisons++;
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
        else
        {
            number_comparisons++;
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

int partition_median(int array[], int low, int high)
{
    // printf("middle sorted\n");

    int pivot;
    int mid = (low + high) / 2;

    if (array[mid] <= array[low])
    {
        swap(&array[mid], &array[low]);

        number_comparisons++;
    }

    if (array[high] <= array[low])
    {
        swap(&array[high], &array[low]);

        number_comparisons++;
    }

    if (array[high] <= array[mid])
    {
        swap(&array[high], &array[mid]);
        number_comparisons++;
    }

    swap(&array[mid], &array[high]); //&array[high - 1]);

    pivot = array[high]; // array[high - 1];

    return partition(array, low, high);
}

void qSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition_median(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        // int leftpivot = (pi - 1) - low;   // size of left pivot
        // int rightpivot = high - (pi + 1); // size of right pivot

        qSort(arr, low, pi - 1);
        qSort(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int size)
{

    qSort(arr, 0, size - 1);
    // printf("\nsorted %d\n", sorted);
}
