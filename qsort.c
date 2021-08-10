#include <stdio.h>

void quicksort(int *arr, int left, int right)
{
    int pivot, i, j, temp;
    if(left < right) //Set variable
    {
        pivot = left;
        i = left;
        j = right;
        while(i < j)
        {
            while(arr[i] <= arr[pivot] && j <= right)
                i++;
            
            while(arr[j] > arr[pivot] && j >= left)
                j--;
            if(i < j)
            {
                temp = arr[i]; //swap pos
                arr[i] = arr[j]; 
                arr[j] = temp;

            }
        }
        temp = arr[j];
        arr[j] = arr[pivot];
        arr[pivot] = temp;
        quicksort(arr, left, j-1);
        quicksort(arr, j+1, right);
    }
}