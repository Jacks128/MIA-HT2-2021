
#include "HT2.h"

FILE *file = NULL;
void CrearArchivo()
{
    file = fopen("HT2.dk", "r"); //abrimos el archivo para leer con r

    if (file == NULL) //Verificamos si es nulo
    {
        file = fopen("HT2.dk", "w"); //si si hora si abrimos para escribir con w
        fseek(file, 2900, SEEK_SET);

        fseek(file, 0, SEEK_SET); // nos posiciones en 0

        for (int i = 0; i < 100; i++)
        {
            strcpy(personaT[i].nombre, ""); //llenamos primero con posiciones vacias
            personaT[i].edad = -1;          // y con edades -1
        }
        fwrite(&personaT, sizeof(personaT), 1, file); //luego escribimos en nuestro arreglo de 100
        fclose(file);                                 // y cerramos
        printf("ARCHIVO CREADO CORRECTAMENTE \n");
        return;
    }
    file = fopen("HT2.dk", "rb+"); // Caso contrario no este nulo solo lo abrimos para leer
}
persona personaTemporal;
int main()
{
    CrearArchivo();
    int menu = 0;

    while (menu != 5)
    {
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Crear" << endl;
        cout << "2. Modificar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Ver" << endl;
        cout << "5. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "Ingrese el nombre ";
            cin >> name;
            cout << "Ingrese la edad ";
            cin >> age;

            if (age <= 25) // verificaciones para ver en que cuadrante se ubica
            {
                posCuadrante = 0; //La posicion del cuadrante
            }
            else if (age <= 50 && age > 25)
            {
                posCuadrante = sizeof(personaTemporal) * 25 * 1; //Aqui se multiplico por 29 que es el size of de mi struct, luego por 25 que es el tamaño del primer cuadrante
            }
            else if (age <= 75 && age > 51)
            {
                posCuadrante = sizeof(persona) * 25 * 2; //Lo mismo aca, pero es por 2 por ser el cuadrante 3
            }
            else
            {
                posCuadrante = sizeof(persona) * 25 * 3;
            }
            fseek(file, posCuadrante, SEEK_SET); //Aqui nos posiciones en el cuadrante correspondiente a la edad
            personaTemporal.edad = age;          //Y en nuestra variable temporal guardamos la edad y el nombre recien ingresado
            strcpy(personaTemporal.nombre, name);

            if (file != NULL) // SI el archivo no esta vacio
            {

                fread(&personaCuadrante, sizeof(personaCuadrante), 1, file); //Primero leemos nuestro objeto cuadrnte y no tiene nada
                for (int i = 0; i < 25; i++)                                 //recorremos el cuadrante
                {
                    if (personaCuadrante[i].edad == -1) //y encontramos el primer espacio vacio
                    {
                        posPersona = sizeof(personaTemporal) * i;                   //la posicion donde se va ubicar, es el tamaño de mi struct por la posicion de mi cuadrante
                        fseek(file, posCuadrante + posPersona, SEEK_SET);           //y ahora nuestro puntero debe estar en el inicio de ese cuadrante mas los espacios donde se debe ubicar en ese cuadrante
                        fwrite(&personaTemporal, sizeof(personaTemporal), 1, file); // escribimos lo que tenemos en el struct
                        break;                                                      //y salimos
                    }
                }

                fclose(file); //cerramos el archivo
                //file = NULL;
                printf("Persona guardada correctamente \n");
            }
            else
            {
                printf("Error!\n No se puede acceder al archivo, no creado\n");
            }

            break;
        case 3:
            cout << "Ingrese el nombre de la persona que quiere eliminar";
            cin >> nombre;
           

            break;
        case 4:
            file = fopen("HT2.dk", "r"); //para verlo debemos volverlo a abrir
            fseek(file, 0, SEEK_SET);    //posicionarnos en cero

            //leemos el archivo binario y lo pasamos al arreglo temporal
            fread(&personaT, sizeof(personaT), 1, file); //leemos nuestro arreglo de 100
            for (int i = 0; i < 25; i++)
            {
                std::cout << "nombre: " << personaT[i].nombre << " edad: " << personaT[i].edad << " \n";
            }

            //cerramos el archivo y liberamos el puntero
            fclose(file);
            // file = NULL;

            break;
        default:
            cout << "Opcion no existente";
        }
    }

    return 0;
}
//JAsystem("clear");

/*    
        cin >> opcion;

        if(opcion==1)
        {
        

            cout << "Ingresar el numero de personas que se va a ingresar \n";
            cin >> cantpersonas;
            persona personas[cantpersonas];

            for (int i = 0; i < cantpersonas; i++)
            {
                cout << "Ingrese el nombre ";
                cin >> name;
                cout << "Ingrese la edad ";
                cin >> age;

                personas[i].edad = age;

                //sprintf(name, "Persona-%d", i + 1);
                strcpy(personas[i].nombre, name);
            }
            for (int i = 0; i < cantpersonas; i++)
            {

                cout << (i + 1) << ") nombre: " << personas[i].nombre << " edad: " << personas[i].edad << " \n";
            }
            fwrite(&personas, sizeof(personas), 1, file);

            //cerramos el archivo y liberamos el puntero
            fclose(file);
            file = NULL;
            main();


        }else if(opcion==4){


            // MOdificar

            

            char entrada[10];
            while (true)
            {
                std::cout << "\nObtener persona (del 1 al " << cantpersonas << ")\n";
                //guardamos la entrada de la consola en el arreglo
                scanf(" %[^\n]", entrada);
                //convertimos el arrglo a un entero
                int posicion = atoi(&entrada[0]) - 1;

                //abre el archivo binario(b) para lectura
                file = fopen("HT2.dk", "rb+");

                if (file == NULL)
                {
                    std::cout << "Ocurrio un error al acceder al archivo.\n";
                    return 0;
                }

                //arreglo temporal donde vamos a guardar el contenido del archivo bianrio
                persona tmp[cantpersonas];
                //posicionamos el puntero, (puntero al archivo, posicion del puntero del archivo, operacion)
                fseek(file, 0, SEEK_SET);
                //leemos el archivo binario y lo pasamos al arreglo temporal
                fread(&tmp, sizeof(tmp), 1, file);

                //cerramos el archivo y liberamos el puntero
                fclose(file);
                file = NULL;

                //obtenemos a la persona deseada
                cout << "nombre: " << tmp[posicion].nombre << " edad: " << tmp[posicion].edad << " \n";
            }

        }
    }*/