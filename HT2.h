#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

using namespace std;
char name[25];
int age;

typedef struct
{                    //sizeof(29)
    char nombre[25]; //25 bytes
    int edad;        //4 bytes
} persona;

persona personaT[100];
persona personaE[100];
persona personaCuadrante[25];
int posCuadrante;
int posPersona;
int posPersona1;

char nombre[25];
int edadE;
char nombreE[25];

int edadM;
char nombreM[25];