#include <iostream>
#include <stdio.h>
#include <chrono>
#include <time.h>
using namespace std;
// Function to display sorted array (need to uncomment function call in main)
void display(long int a[], long int n)
{
    cout<<"\n The array sorted in ascending order is as follows :";
    for(int i = 0; i<n; i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
// swap function to swap two values
void swap(long int* a, long int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// Bubble sort function
void bubbleSort(long int a[], long int n)
{
    int flag=0;
    for(long int i = 0; i<n-1; i++)
    {
        for(long int j = 0; j<n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                flag=1;
                swap(&a[j], &a[j+1]);
            }
        }
        if(flag == 0)
            break;
    }
}
int main()
{
    long int number = 1000;
    int it = 0;
    char fileName[25];
    FILE* fptr;
    while(it++ < 10)
    {
        long int a[number];
        sprintf(fileName,"%li_random_numbers.txt",number);
        fptr = fopen(fileName, "r");
        int n = 0;
        // Collecting numbers from file into array
        int i=0;
        while(fscanf(fptr, "%li", &a[i]) != EOF)
        {
            n++;
            i++;
        };
        fclose(fptr);
        a[i] = '\0';
        // Here cpu clock is checked before sorting and after sorting and stored in seperate variables
        auto t_start = std::chrono::high_resolution_clock::now();
        bubbleSort(a, n);
        auto t_stop = std::chrono::high_resolution_clock::now();

        // Uncomment next line to display Sorted array
        //display(a, n);

        // here diffrence two cpu clock time is calculated to get the time taken by algo
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_stop - t_start);
        cout<<"\nExecution Time of "<<fileName<<": "<<duration.count()<<"\n";
        number += 1000;
    }
    return 0;
}
