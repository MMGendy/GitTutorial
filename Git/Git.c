//
//  main.c
//  Git
//  Program to help demonstrate how to create a Git repository and push to GitHub
//  Created by Marttina Gendy on 11/26/23.
//


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int binarySearch(int arr[], int target, int n, int *where);
void displaySearchResult(int target, int found, int where);

int main()
{
    int list[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31};
    int target = 5, sizeList = 16, found = 0, where = 0;

    found = binarySearch(list, target, sizeList - 1, &where);
    displaySearchResult(target, found, where);

    target = 6;
    found = binarySearch(list, target, sizeList - 1, &where);
    displaySearchResult(target, found, where);

    target = 29;
    found = binarySearch(list, target, sizeList - 1, &where);
    displaySearchResult(target, found, where);

    getchar();
    getchar();

    return 0;
}

int binarySearch(int arr[], int target, int n, int *where)
{
    int found = 0;
    int low = 0, high = n, mid = 0;

    while (!found && low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            found = 1;
            *where = mid;
        }

        if (arr[mid] < target)
            low = mid + 1;

        if (arr[mid] > target)
            high = mid - 1;
    }

    return found;
}

void displaySearchResult(int target, int found, int where)
{
    if (found)
        printf("The location of the value %d is at %d.\n", target, where);
    else
        printf("Key value %d is not in the list.\n", target);
}
