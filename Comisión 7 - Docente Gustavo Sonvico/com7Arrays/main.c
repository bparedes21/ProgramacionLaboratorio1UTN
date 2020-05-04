#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarArregloInt(int A[], int dim);

void mostrarArregloInt(int A[], int cantVal);

void mostrarArregloChar(char A[], int cantVal);

char buscarCharMax(char A[], int cantVal);

void cargaRandomMatrizInt(int filas, int columnas, int M[filas][columnas]);

void mostrarMatrizInt(int filas, int columnas, int M[filas][columnas]);

int cargarArregloPalabras(int dim, int dimCaracteres, char p[][dimCaracteres]);

void mostrarArregloPalabras(int cantVal, int dimCaracteres, char p[][dimCaracteres]);

int agregaCharEnOrden (char A[], int validos, char dato);

const int MAXEMPLE=100;

int main()
{

    printf("Hello arrays!\n");

    int matriz[10][4];


/// declaro el arreglo

    int idEmpleados[MAXEMPLE];

/// el compilador ve esto.
/// int * idEmpleados=malloc(sizeof(int)*100);

/// variable para saber cuantos elementos se cargaron en el arreglo
    int cantEmpleados=0;


    int aux;
    int a[10];
    int cantVal=0;
    int i;

    printf("Vamos a cargar el arreglo desde el main: \n");
    for(i=0; i<10; i++)
    {
        printf("Ingrese un valor: ");
        scanf("%d", &a[i]);
    }

    cantVal=i;

    printf("Contenido del arreglo (mostrado desde el main):\n");
    for(i=0; i<cantVal; i++)
    {
        printf("%d ", a[i]);
    }

    system("pause");
    system("cls");

/// invocamos la fn para cargar, enviamos el array de empleados y su dimension
/// la variable cantEmpleados va a contener la cantidad de datos que cargo el usr
    cantEmpleados=cargarArregloInt(idEmpleados, MAXEMPLE);

/// ahora mostramos el contenido del arreglo desde la fn, le enviamos el arreglo y
/// la cantidad que se cargo con la fn de carga
    mostrarArregloInt(idEmpleados, cantEmpleados);



    char unaPalabra[5];

    printf("direccion de memoria del arreglo %p\n", unaPalabra);

    system("pause");

    printf("Ingrese una palabra: ");
    fflush(stdin);

///   scanf("%s", unaPalabra);
    gets(unaPalabra);

    printf("La palabra escaneada es %s\n", unaPalabra);

/// mostrarArregloChar(unArregloDeChar, 10);

    system("pause");

    char miArreglo[7]= {"pomlfai"};

    int validos=7;

    mostrarArregloChar(miArreglo, validos);

    char caracterMaximo = buscarCharMax(miArreglo,validos);

    printf("El maximo caracter es %c \n", caracterMaximo);

    int matrix [5][6];

    cargaRandomMatrizInt(5,6,matrix);

    mostrarMatrizInt(5,6,matrix);

    char palabras[10][30];

    int val=cargarArregloPalabras(10, 30, palabras);

    mostrarArregloPalabras(val, 30, palabras);

    return 0;
}


int cargarArregloInt(int A[], int dim)
{
    int i=0;
    char control='s';

    while(i<dim && control=='s')
    {
        printf("Ingrese un valor entero: ");
        scanf("%d",&A[i]);

        printf("Desea continuar? s/n\n");
        fflush(stdin);
        scanf("%c", &control);
        i++;
    }
    /// retornamos el valor de i, que es la cantidad de valores que se cargaron en el array

    return i;
}

void mostrarArregloInt(int A[], int cantVal)
{
    int i;

    printf("Contenido del arreglo de int:\n");

    for(i=0; i<cantVal; i++)
    {
        printf("%d ", A[i]);
    }
}

void mostrarArregloChar(char A[], int cantVal)
{
    int i;

    printf("Contenido del arreglo de char:\n");

    for(i=0; i<cantVal; i++)
    {
        printf("%c ", A[i]);
    }
}

char buscarCharMax(char A[], int cantVal)
{
    int i=0;

    char charMax=A[i];


    for(i=1; i<cantVal; i++)
    {
        if(A[i]>charMax)
        {
            charMax=A[i];
        }
    }

    return charMax;
}

int buscaPosMenor(int A[], int cantVal, int pos)
{
    int menor = A[pos];

    int posMenor=pos;

    int i = pos+1;

    while(i<cantVal)
    {
        if(A[i]<menor)
        {
            menor=A[i];
            posMenor=i;
        }
        i++;
    }

    return posMenor;
}

void cargaRandomMatrizInt(int filas, int columnas, int M[filas][columnas])
{
    int i, j;

    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            M[i][j]=rand()%100;
        }
    }
}

void mostrarMatrizInt(int filas, int columnas, int M[filas][columnas])
{
    int i, j;

    printf("Contenido de la matriz: \n");
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}


int cargarArregloPalabras(int dim, int dimCaracteres, char p[][dimCaracteres])
{
    int i=0;
    char control='s';

    while(i<dim && control=='s')
    {
        printf("Ingrese una palabra: (maximo 30 chars)\n");

        fflush(stdin);
        scanf("%s", p[i]);

        printf("Desea continuar? s/n\n");
        fflush(stdin);
        scanf("%c", &control);
        i++;
    }
    /// retornamos el valor de i, que es la cantidad de valores que se cargaron en el array

    return i;

}

void mostrarArregloPalabras(int cantVal, int dimCaracteres, char p[][dimCaracteres])
{

    int i;

    printf("Contenido del arreglo de palabras:\n");

    for(i=0; i<cantVal; i++)
    {
        printf("%s\n", p[i]);
    }
}

int agregaCharEnOrden (char A[], int validos, char dato)
{
    int i = validos-1;
    while (i>=0 && dato<A[i])
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]= dato;
    return validos+1;
}
