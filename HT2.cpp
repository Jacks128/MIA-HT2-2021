
#include "HT2.h"

FILE *file = NULL;
void CrearArchivo()
{
    file = fopen("HT2.dk", "r");
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
        /*-------------------------------------------------------------------------*/
        case 1:
            cout << "Ingrese el nombre ";
            cin >> name;
            cout << "Ingrese la edad ";
            cin >> age;

            if (age <= 25) // verificaciones para ver en que cuadrante se ubica
            {
                posCuadrante = 0; //La posicion del cuadrante
            }
            else if (age <= 50 )
            {
                posCuadrante = sizeof(persona) * 25 * 1; //Aqui se multiplico por 29 que es el size of de mi struct, luego por 25 que es el tamaño del primer cuadrante
            }
            else if (age <= 75 )
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
                printf("Persona guardada correctamente \n");
            }
            else
            {
                printf("Error!\n No se puede acceder al archivo, no creado\n");
            }
            break;
             /*-------------------------------------------------------------------------*/
        case 2:
        file = fopen("HT2.dk", "rb+");
            cout << "Ingrese la edad a modificar ";
            cin >> age;
            cout << "Ingrese el nuevo nombre";
            cin >> nombreM;
            cout<<"INgrese la nueva edad";
            cin>>edadM;
            
            
            cout<<age;
            fseek(file, 0, SEEK_SET); //Aqui nos posiciones en el cuadrante correspondiente a la edad
            personaTemporal.edad = edadM;          //Y en nuestra variable temporal guardamos la edad y el nombre recien ingresado
            strcpy(personaTemporal.nombre, nombreM);

            if (file != NULL) // SI el archivo no esta vacio
            {
                fread(&personaT, sizeof(personaT), 1, file); //Primero leemos nuestro objeto cuadrnte y no tiene nada
                for (int i = 0; i <100; i++)                                 //recorremos el cuadrante
                {
                    if (personaT[i].edad == age) //y encontramos el primer espacio vacio
                    {
                        cout<<"encontramos la edad perra";
                        cout << "\n edad en esa posicion";
                        cout<< personaT[i].edad ;
                        cout << "\n ";
                        posPersona = sizeof(persona) * i;                   //la posicion donde se va ubicar, es el tamaño de mi struct por la posicion de mi cuadrante
                        fseek(file,  posPersona, SEEK_SET);      
                        cout<<personaTemporal.nombre;  
                        cout << "\n";
                         cout<<personaTemporal.edad;     
                         cout << "\n pos ";
                         cout<<posPersona;
                         cout << "\n";           //y ahora nuestro puntero debe estar en el inicio de ese cuadrante mas los espacios donde se debe ubicar en ese cuadrante
                        fwrite(&personaTemporal, sizeof(personaTemporal), 1, file); // escribimos lo que tenemos en el struct
                        break;                                                      //y salimos
                    }
                }
                fclose(file); //cerramos el archivo
                printf("Persona modificADA correctamente \n");
            }
            else
            {
                printf("Error!\n No se puede acceder al archivo, no creado\n");
            }
            break;
        /*-------------------------------------------------------------------------*/
        /*-------------------------------------------------------------------------*/
        case 3:
        file = fopen("HT2.dk", "rb+");
        cout << "Ingrese la edad a eliminar ";
            cin >> age;
            edadE=-1;
            strcpy(nombreE,"");

            if (age <= 25) // verificaciones para ver en que cuadrante se ubica
            {
                posCuadrante = 0; //La posicion del cuadrante
            }
            else if (age <= 50 )
            {
                posCuadrante = sizeof(persona) * 25 * 1; //Aqui se multiplico por 29 que es el size of de mi struct, luego por 25 que es el tamaño del primer cuadrante
            }
            else if (age <= 75 )
            {
                posCuadrante = sizeof(persona) * 25 * 2; //Lo mismo aca, pero es por 2 por ser el cuadrante 3
            }
            else
            {
                posCuadrante = sizeof(persona) * 25 * 3;
            }
            fseek(file, posCuadrante, SEEK_SET); //Aqui nos posiciones en el cuadrante correspondiente a la edad
            personaTemporal.edad = edadE;          //Y en nuestra variable temporal guardamos la edad y el nombre recien ingresado
            strcpy(personaTemporal.nombre, nombreE);

            if (file != NULL) // SI el archivo no esta vacio
            {
                fread(&personaCuadrante, sizeof(personaCuadrante), 1, file); //Primero leemos nuestro objeto cuadrnte y no tiene nada
                for (int i = 0; i < 25; i++)                                 //recorremos el cuadrante
                {
                    if (personaCuadrante[i].edad == age) //y encontramos el primer espacio vacio
                    {
                        cout<<"si entre";
                        posPersona = sizeof(personaTemporal) * i;                   //la posicion donde se va ubicar, es el tamaño de mi struct por la posicion de mi cuadrante
                        fseek(file, posCuadrante + posPersona, SEEK_SET);           //y ahora nuestro puntero debe estar en el inicio de ese cuadrante mas los espacios donde se debe ubicar en ese cuadrante
                        fwrite(&personaTemporal, sizeof(personaTemporal), 1, file); // escribimos lo que tenemos en el struct
                        break;                                                      //y salimos
                    }
                }
                fclose(file); //cerramos el archivo
                printf("Persona eliminada correctamente \n");
            }
            else
            {
                printf("Error!\n No se puede acceder al archivo, no creado\n");
            }
            break;

        /*-------------------------------------------------------------------------*/
        case 4:
            cout << "\n\n\n";
            file = fopen("HT2.dk", "rb+"); //para verlo debemos volverlo a abrir
            fseek(file, 0, SEEK_SET);    //posicionarnos en cero

            //leemos el archivo binario y lo pasamos al arreglo temporal
            fread(&personaT, sizeof(personaT), 1, file); //leemos nuestro arreglo de 100
            cout << "Edades de 0-25\n";
            for (int i = 0; i < 25; i++)
            {
                if (personaT[i].nombre != "" && personaT[i].edad != -1)
                {
                    std::cout << "nombre: " << personaT[i].nombre << " edad: " << personaT[i].edad << " \n";
                }
            }
            cout << "\n\n\n";
            
            cout << "Edades de 26-50\n";
            for (int j = 25; j < 50; j++)
            {
                if (personaT[j].nombre != "" && personaT[j].edad != -1)
                {
                    std::cout << "nombre: " << personaT[j].nombre << " edad: " << personaT[j].edad << " \n";
                }
            }
            cout << "\n\n\n";
            
            cout << "Edades de 51-75\n";
            for (int k = 50; k <75; k++)
            {
                if (personaT[k].nombre != "" && personaT[k].edad != -1)
                {
                    std::cout << "nombre: " << personaT[k].nombre << " edad: " << personaT[k].edad << " \n";
                }
            }
            cout << "\n\n\n";
           
            cout << "Edades de 76-100\n";
            for (int l = 75; l <100; l++)
            {
                if (personaT[l].nombre != "" && personaT[l].edad != -1)
                {
                    std::cout << "nombre: " << personaT[l].nombre << " edad: " << personaT[l].edad << " \n";
                }
            }
            cout << "\n\n\n";
            fclose(file);

            break;
        default:
            cout << "Opcion no existente";
        }
    }

    return 0;
}
