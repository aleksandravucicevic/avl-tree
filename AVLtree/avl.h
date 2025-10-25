#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct cvor
{
    char* info;
    struct cvor* lijevi;
    struct cvor* desni;
    int visina;
} CVOR;

int visinaCvora(CVOR* cvor)
{
    if(cvor==NULL)
        return 0;
    return cvor->visina;
}

int balansCvora(CVOR* cvor)
{
    if(cvor==NULL)
        return 0;
    return visinaCvora(cvor->lijevi)-visinaCvora(cvor->desni);
}

//Formiranje novog cvora stabla
CVOR* noviCvor(char* info)
{
    CVOR* novi=(CVOR*)malloc(sizeof(CVOR));
    novi->info=strdup(info);
    novi->desni=novi->lijevi=NULL;
    novi->visina=1;
    return novi;
}

//Desna jednostruka rotacija
CVOR* rightRotation(CVOR* x)
{
    CVOR* y=x->lijevi;
    CVOR* tmp=y->desni;

    y->desni=x;
    x->lijevi=tmp;

    x->visina=1+ ((visinaCvora(x->lijevi) > visinaCvora(x->desni))? visinaCvora(x->lijevi) : visinaCvora(x->desni));
    y->visina=1+ ((visinaCvora(y->lijevi) > visinaCvora(y->desni))? visinaCvora(y->lijevi) : visinaCvora(y->desni));

    return y;
}

//Lijeva jednostruka rotacija
CVOR* leftRotation(CVOR* x)
{
    CVOR* y=x->desni;
    CVOR* tmp=y->lijevi;

    y->lijevi=x;
    x->desni=tmp;

    x->visina=1+ ((visinaCvora(x->lijevi) > visinaCvora(x->desni))? visinaCvora(x->lijevi) : visinaCvora(x->desni));
    y->visina=1+ ((visinaCvora(y->lijevi) > visinaCvora(y->desni))? visinaCvora(y->lijevi) : visinaCvora(y->desni));

    return y;
}

//Formiranje AVL stabla
CVOR* dodaj(CVOR* cvor, char* info, FILE* duplicates,int* dupl)
{
    if(cvor==NULL)
        return noviCvor(info);

    int poredjenje=strcmp(info,cvor->info);

    if(poredjenje<0)
        cvor->lijevi=dodaj(cvor->lijevi,info,duplicates,dupl);
    else if(poredjenje>0)
        cvor->desni=dodaj(cvor->desni,info,duplicates,dupl);
    else
    {
        (*dupl)++;
        fprintf(duplicates,"%d.) %s\n", *dupl, info);
        return cvor;
    }

    cvor->visina=1+ ((visinaCvora(cvor->lijevi) > visinaCvora(cvor->desni))? visinaCvora(cvor->lijevi) : visinaCvora(cvor->desni));

    int balans=balansCvora(cvor);

    if(balans>1)
    {
        if(strcmp(info,cvor->lijevi->info) < 0)
            return rightRotation(cvor);
        else
        {
            cvor->lijevi=leftRotation(cvor->lijevi);
            return rightRotation(cvor);
        }
    }
    if(balans<-1)
    {
        if(strcmp(info,cvor->desni->info) > 0)
            return leftRotation(cvor);
        else
        {
            cvor->desni=rightRotation(cvor->desni);
            return leftRotation(cvor);
        }
    }

    return cvor;
}

//Duzina rijeci bez interpunkcijskih znakova
int duzinaRijeci(char* rijec)
{
    int duzina=0;
    for(int i=0;rijec[i]!='\0';i++)
        if(isalpha(rijec[i]))
            duzina++;
    return duzina;
}

//Inorder obilazak + formiranje niza duzina
void inorder(CVOR* korijen, int* niz, int* idx)
{
    if(korijen!=NULL)
    {
        inorder(korijen->lijevi,niz,idx);
        printf("%s ", korijen->info);
        niz[(*idx)++]=strlen(korijen->info);
        inorder(korijen->desni,niz,idx);
    }
}

void freeAVL(CVOR* korijen)
{
    if(korijen!=NULL)
    {
        freeAVL(korijen->lijevi);
        freeAVL(korijen->desni);
        free(korijen->info);
        free(korijen);
    }
}