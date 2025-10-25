#pragma once
#include <stdio.h>
#include <stdlib.h>

void ispisiNiz(int* niz, int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", niz[i]);
    printf("\n");
}

void bubbleSort(int* niz, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(niz[j]>niz[j+1])
            {
                int temp=niz[j];
                niz[j]=niz[j+1];
                niz[j+1]=temp;
            }
        }
    }
}

void insertionSort(int* niz, int n)
{
    int j, key;
    for(int i=1;i<n;i++)
    {
        key=niz[i];
        j=i-1;
        
        while(j>=0 && niz[j]<key)
        {
            niz[j+1]=niz[j];
            j=j-1;
        }
        niz[j+1]=key;
    }
}