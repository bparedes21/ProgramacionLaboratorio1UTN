#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void muestraMenu();
void funcion01();
void funcion02();
void funcion03();
int cargaArreglo(int a[], int v, int dim);
void mostrarArreglo(int a[], int v);

const char ESC = 27;

int main(){
    char opcion;

    do{
        system("cls");
        muestraMenu();
        opcion=getch();
        system("cls");

        switch(opcion){
            case 49: /// 49 es el codigo ASCII de la tecla 1  - tambi�n pueden usar '1'
                    funcion01();
                    break;
            case 50:
                    funcion02();
                    break;
            case 51 ... 53:
                    funcion03();
                    break;
            case 'a': /// 97
                    break;
            case 'A':  /// 65
                    break;
        }
        system("pause");
    }
    while(opcion!=ESC);

    printf("Hasta la vista Baby!!!!!\n");
    return 0;
}

void muestraMenu(){
    printf("\t\t\t<<< Mi Primer Menu >>>");
    printf("\n\n");
    printf("\n\t 1 - Ejercicio 1");
    printf("\n\t 2 - Ejercicio 2");
    printf("\n\t 3 a 5 - Ejercicio 3 al 5");
    printf("\n\t a - Ejercicio a");
    printf("\n\n");
    printf("ESC para salir ");
}

void funcion01(){
    printf("Ej 1");
     /// aca va el codigo del ej 1
    printf("\n\n\n");
}

void funcion02(){
    printf("Ej 2");
     /// aca va el codigo del ej 2
    printf("\n\n\n");
}

void funcion03(){
    printf("Ej 3");
     /// aca va el codigo del ej 3
    printf("\n\n\n");
}



