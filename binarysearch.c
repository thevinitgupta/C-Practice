#include <stdio.h>
int list[10] = {10,20,30,40,50,60,70,80,90,100};

void binary_search(int lo, int hi, int key)
{
    int mid;
 
    if (lo > hi)
    {
        printf("Key not found\n");
        return;
    }
    mid = (lo + hi) / 2;
    if (list[mid] == key)
    {
        printf("Key found\nAt location : %d",mid);
    }
    else if (list[mid] > key)
    {
        binary_search( lo, mid - 1, key);
    }
    else if (list[mid] < key)
    {
        binary_search( mid + 1, hi, key);
    }
}
int main()
{
    int key=80;
    binary_search( 0, 10, key);
}