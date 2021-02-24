#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

using namespace std;
int tam;
char name[25];
int cantpersonas = 1;

int age;

typedef struct
{                    //sizeof(29)
    char nombre[25]; //25 bytes
    int edad;        //4 bytes
} persona;

persona personaT[100];
persona personaCuadrante[25];
int posCuadrante;
int posPersona;

char nombre[25];