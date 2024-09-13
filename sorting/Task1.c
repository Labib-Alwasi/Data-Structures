#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Task1.h"
#include "Task2.h"

int number_swaps;
int number_comparisons;

// Fills the array with ascending, consecutive numbers, starting from 0.
void swaporder(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    //printf("%d || %d", xp, yp);
    number_swaps++;
}

void fill_ascending(int *array, int size)
{
    // TODO
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size - 1; i++)
    {
      // Find the minimum element in unsorted array
      min_idx = i;
      for (j = i + 1; j < size; j++)
            if (array[j] < array[min_idx]) {
              min_idx = j;
              number_comparisons++;
          }

      // Swap the found minimum element
      // with the first element
      swaporder(&array[min_idx], &array[i]);
    }
}
// Fills the array with descending numbers, starting from size-1
void fill_descending(int *array, int size)
{
    // TODO
       int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < size - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < size; j++)
            if (array[min_idx] < array[j])
                min_idx = j;

        // Swap the found minimum element with the first element
        swaporder(&array[min_idx], &array[i]);
    }
}

// Fills the array with uniform numbers.
void fill_uniform(int *array, int size)
{
    // TODO
    int constant = 1;
    for(int i = 0; i < size; i++) {
      array[i] = constant;
    }
}

// Fills the array with random numbers within 0 and size-1. Duplicates are allowed.
void fill_with_duplicates(int *array, int size)
{
    // TODO
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (size-1);
    }
}

// Fills the array with unique numbers between 0 and size-1 in a shuffled order. Duplicates are not allowed.
void fill_without_duplicates(int *array, int size)
{
    // TODO
    srand(time(NULL));
    //populate array first 
    for(int i = 0; i < size;i++) {
       array[i] = i;
    }
 
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = size-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
 
        // Swap arr[i] with the element at random index
        swaporder(&array[i], &array[j]);
    }
    
}

void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        //printf("issue is here ");
        printf("%d ", arr[i]);
    }
    printf("\n");
}











//305 for mdedian
//224 for last