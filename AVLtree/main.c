#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"
#include "niz.h"
#define MAX 50

int main()
{
    const char ulazna1[10]="ulaz1.txt";
    const char duplikati1[15]="duplikati1.txt";
    const char ulazna2[10]="ulaz2.txt";
    const char duplikati2[15]="duplikati2.txt";

    printf("SIMULACIJA BR.1\n");
    FILE* fp1;
    CVOR* korijen1=NULL;
    int brdpl1=0;
    if(fp1=fopen(ulazna1,"r"))
    {
        FILE* fp2;
        if(fp2=fopen(duplikati1,"w"))
        {
            char rijec[MAX];
            while(fscanf(fp1,"%s",rijec)==1)
                korijen1=dodaj(korijen1,rijec,fp2,&brdpl1);

            fclose(fp2);
        }
        fclose(fp1);
    }
    int niz1[MAX];
    int duzina1=0;
    printf("\nRezultat inorder obilaska:\n");
    inorder(korijen1,niz1,&duzina1);
    printf("\n--------------------------------------------------\n");

    printf("Niz duzina: ");
    ispisiNiz(niz1,duzina1);
    printf("--------------------------------------------------\n");

    printf("Niz sortiran po rastucem redoslijedu:\n");
    bubbleSort(niz1,duzina1);
    ispisiNiz(niz1,duzina1);
    printf("--------------------------------------------------\n");

    printf("Niz sortiran po opadajucem redoslijedu:\n");
    insertionSort(niz1,duzina1);
    ispisiNiz(niz1,duzina1);
    printf("--------------------------------------------------\n");

    printf("Broj duplikata: %d", brdpl1);

    freeAVL(korijen1);

    printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("SIMULACIJA BR.2\n");
    FILE* fp3;
    CVOR* korijen2=NULL;
    int brdpl2=0;
    if(fp3=fopen(ulazna2,"r"))
    {
        FILE* fp4;
        if(fp4=fopen(duplikati2,"w"))
        {
            char rijec[MAX];
            while(fscanf(fp1,"%s",rijec)==1)
                korijen2=dodaj(korijen2,rijec,fp4,&brdpl2);

            fclose(fp4);
        }
        fclose(fp3);
    }
    int niz2[MAX];
    int duzina2=0;
    printf("\nRezultat inorder obilaska:\n");
    inorder(korijen2,niz2,&duzina2);
    printf("\n--------------------------------------------------\n");

    printf("Niz duzina: ");
    ispisiNiz(niz2,duzina2);
    printf("--------------------------------------------------\n");

    printf("Niz sortiran po rastucem redoslijedu:\n");
    bubbleSort(niz2,duzina2);
    ispisiNiz(niz2,duzina2);
    printf("--------------------------------------------------\n");

    printf("Niz sortiran po opadajucem redoslijedu:\n");
    insertionSort(niz2,duzina2);
    ispisiNiz(niz2,duzina2);
    printf("--------------------------------------------------\n");

    printf("Broj duplikata: %d", brdpl2);

    freeAVL(korijen2);
    return 0;
}