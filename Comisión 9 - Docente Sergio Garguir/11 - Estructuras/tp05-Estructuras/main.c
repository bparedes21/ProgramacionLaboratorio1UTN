#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include "registroCliente.h"
#include "pila.h"

#define arCliente "clientes.dat"

#define ESC 27
#define DIM_CLI 100

void muestraMenu();
int funcion00(stCliente c[], int v, int dim);
void funcion03(stCliente c[], int v);
void funcion56();
stCliente cargaUnCliente();
int cargaClientes(stCliente c[], int v, int dim);
void muestraClientes(stCliente c[], int v);
void muestraUnCliente(stCliente c);
int buscaUnClienteApellido(stCliente c[], int v, char apellido[]);
int buscaPosMenorApellido(stCliente c[], int v, int inicio);
void intercambiaClientes(stCliente *a, stCliente *b);
void ordPorSelApellido(stCliente c[], int v);
void arregloClientes2Pila(stCliente c[], int v, Pila *p);
void guardaUnCliente(stCliente c);
void cargaArchivoClientes();
void muestraArchClientes();
int buscaUnClienteDNIArchivo(int dni);
stCliente buscaUnClienteApellidoArchivo(char apellido[]);
int validaEmail(char email[]);

int main(){
    Pila dni;
    inicpila(&dni);
    char opcion;
    stCliente clientes[DIM_CLI];
    int vClientes=0;

    do{
        system("cls");
        muestraMenu();
        opcion=getch();
        system("cls");

        switch(opcion){
            case 48:
                    vClientes=funcion00(clientes, vClientes, DIM_CLI);
                    break;
            case 49:
                    vClientes=cargaClientes(clientes, vClientes, DIM_CLI);
                    break;
            case 50:
                    muestraClientes(clientes, vClientes);
                    break;
            case 51:
                    funcion03(clientes, vClientes);
                    break;
            case 52:
                    ordPorSelApellido(clientes, vClientes);
                    break;
            case 53:
                    arregloClientes2Pila(clientes, vClientes, &dni);
                    mostrar(&dni);
                    break;
            case 54:
                    cargaArchivoClientes();
                    break;
            case 55:
                    muestraArchClientes();
                    break;
            case 56:
                    funcion56();
        }
        system("pause");
    }
    while(opcion!=ESC);

    printf("Hasta la vista Baby!!!!!\n");

    return 0;
}

void muestraMenu(){
    printf("\t\t\t<<< TP 5 - Esctructuras >>>");
    printf("\n\n");
    printf("\n\t 0 - Carga un arreglo de Clientes al azar");
    printf("\n\t 1 - Carga un arreglo de Clientes");
    printf("\n\t 2 - Muestra un arreglo de Clientes");
    printf("\n\t 3 - Busca un Cliente");
    printf("\n\t 4 - Ordena un Arreglo de Clientes");
    printf("\n\t 5 - Pasa dnis del arreglo a la pila");
    printf("\n\t 6 - Carga archivo de clientes");
    printf("\n\t 7 - Muestra archivo de clientes");

    printf("\n\n\n");
    printf("ESC para salir ");
}

int funcion00(stCliente c[], int v, int dim){
    int i;
    printf("\n Cargando arreglo de Clientes");
    for(i=0;i<dim/2;i++){
        c[i]=cargoRegistroClienteRandom();
        c[i].id=i;
        printf(".");
        Sleep(50);
    }
    printf("\n Arreglo cargado exitosamente...\n");
    return i;
}

void funcion03(stCliente c[], int v){
    char apellido[30];
    int encontrado;

    system("cls");
    printf("\n Ingrese un apellido para buscar en el arreglo: ");
    fflush(stdin);
    gets(apellido);

    encontrado = buscaUnClienteApellido(c, v, apellido);

    if(encontrado>-1){
        printf("\n El cliente %s se encuentra en el arreglo\n", apellido);
        muestraUnCliente(c[encontrado]);
    }
    else{
        printf("\n El cliente %s NO se encuentra en el arreglo\n", apellido);
    }
    printf("\n");
}

void funcion56(){
    char apellido[30];
    stCliente encontrado;

    system("cls");
    printf("\n Ingrese un apellido para buscar en el archivo: ");
    fflush(stdin);
    gets(apellido);

    encontrado = buscaUnClienteApellidoArchivo(apellido);

    if(encontrado.id>-1){
        printf("\n El cliente %s se encuentra en el arreglo\n", apellido);
        muestraUnCliente(encontrado);
    }
    else{
        printf("\n El cliente %s NO se encuentra en el arreglo\n", apellido);
    }
    printf("\n");
}

/*********************************************************//**
*
* \brief Funcion de carga de un Cliente
* \return stCliente
*
*************************************************************/
stCliente cargaUnCliente(){
    stCliente c;

    do{
        printf("\n Ingrese el nro de Cliente..........: ");
        scanf("%d", &c.nroCliente);
    }
    while(c.nroCliente<0 || c.nroCliente>9999999);
    printf(" Ingrese el Nombre..................: ");
    fflush(stdin);
    gets(c.nombre);
    printf(" Ingrese el Apellido................: ");
    fflush(stdin);
    gets(c.apellido);
    printf(" Ingrese el DNI.....................: ");
    scanf(" %d", &c.dni);
    do{
        printf(" Ingrese el EMail...................: ");
        fflush(stdin);
        gets(c.email);
    }while(!validaEmail(c.email));
    printf(" Ingrese la Domicilio...................: ");
    fflush(stdin);
    gets(c.domicilio);
    printf(" Ingrese el Numero de celular...........: ");
    scanf(" %d", &c.movil);
    c.baja=0;
    return c;
}

/*********************************************************************//**
*
* \brief Valida si existe una @ en un string
* \param char email[]
* \return int 0 si no existe - 1 si existe
*
**************************************************************************/
int validaEmail(char email[]){
    int v=strlen(email);
    int i=0;
    int flag=0;
    while(i<v && flag == 0){
        if(email[i]==64){ /// =='@'
            flag=1;
        }
        i++;
    }
    return flag;
}

/*********************************************************//**
*
* \brief Funcion de carga de un arreglo de Clientes
* \param arreglo stCliente
* \param int validos
* \param int dimension
* \return int validos
*
*************************************************************/
int cargaClientes(stCliente c[], int v, int dim){
    char opcion=0;

    while(v<dim && opcion!=27){
        system("cls");
        printf("\n Carga de Clientes \n");
        c[v]=cargaUnCliente();
        c[v].id=v;
        v++;

        printf("\n\n ESC para salir ");
        opcion=getch();
    }
    return v;
}

/*********************************************************//**
*
* \brief Funcion que muestra un arreglo de Clientes
* \param arreglo stCliente
* \param int validos
* \return void
*
*************************************************************/
void muestraClientes(stCliente c[], int v){
    printf("\n\t\t Listado de Clientes");
    for(int i=0;i<v;i++){
        muestraUnCliente(c[i]);
    }
    printf("\n");
}

/*********************************************************//**
*
* \brief Funcion que muestra un Cliente
* \param arreglo stCliente
* \param int validos
* \return void
*
*************************************************************/
void muestraUnCliente(stCliente c){
    printf("\n  -----------------------------------------------------------------");
    printf("\n  ID......................: %d", c.id);
    printf("\n  Nro de Cliente..........: %d", c.nroCliente);
    printf("\n  Nombre..................: %s", c.nombre);
    printf("\n  Apellido................: %s", c.apellido);
    printf("\n  DNI.....................: %d", c.dni);
    printf("\n  EMail...................: %s", c.email);
    printf("\n  Calle...................: %s", c.domicilio);
    printf("\n  Nro de Celular..........: %d", c.movil);
    printf("\n  Activo s/n..............: %s", (c.baja)?"NO":"SI");
}

/*********************************************************//**
*
* \brief Funcion que busca un Cliente en el arreglo
* \param arreglo stCliente
* \param int validos
* \param char apellido[]
* \return int la posici�n o -1 si no lo encuentra
*
*************************************************************/
int buscaUnClienteApellido(stCliente c[], int v, char dato[]){
    int i=0;
    int flag=-1;
    while(i<v && flag==-1){
        if(strcmp(c[i].apellido,dato)==0){
            flag=i;
        }
        i++;
    }
    return flag;
}

/*************************************************************************//**
*
* \brief Busca la posicion del menor elemento en un arreglo de tipo stCliente
* \param arreglo de stCliente
* \param sus validos
* \param el inicio
* \return la posicion del menor elemento
*
*****************************************************************************/
int buscaPosMenorApellido(stCliente c[], int v, int inicio){
    int posMenor = inicio;
    int i = inicio + 1;
    while(i<v){
        if(strcmp(c[i].apellido,c[posMenor].apellido)<0){
            posMenor=i;
        }
        i++;
    }
    return posMenor;
}

/*********************************************************************//**
*
* \brief Intercambia contenido de 2 Clientes
* \param stCliente a
* \param stCliente b
* \return void
*
**************************************************************************/
void intercambiaClientes(stCliente *a, stCliente *b){
    stCliente aux;
    aux=*a;
    *a=*b;
    *b=aux;
}

/*********************************************************************//**
*
* \brief Ordena por Seleccion un arreglo de tipo stCliente por Apellido
* \param arreglo de stCliente
* \param sus validos
* \return void
*
**************************************************************************/
void ordPorSelApellido(stCliente c[], int v){
    int posMenor;
    int i=0;

    while(i<v-1){
        posMenor=buscaPosMenorApellido(c,v,i);
        intercambiaClientes(&c[i],&c[posMenor]);
        i++;
    }
}

/*********************************************************************//**
*
* \brief Copia los dnis de un arreglo de tipo stCliente a una Pila
* \param arreglo de stCliente
* \param sus validos
* \param *pila
* \return void
*
**************************************************************************/
void arregloClientes2Pila(stCliente c[], int v, Pila *p){
    int i=0;
    while(i<v && i<50){
        apilar(p,c[i].dni);
        i++;
    }
}

/*********************************************************************//**
*
* \brief Guarda un dato de tipo stCliente en un archivo
* \param stCliente c
* \return void
*
**************************************************************************/
void guardaUnCliente(stCliente c){
    FILE *pArchCliente = fopen(arCliente,"ab");
    if(pArchCliente != NULL){  /// if(pArchCliente)
        fwrite(&c,sizeof(stCliente),1,pArchCliente);
        fclose(pArchCliente);
    }
}

/*********************************************************************//**
*
* \brief Carga datos de tipo stCliente usando la funcion cargaUnCliente()
*  y lo guarda en un archivo usando la funcion guardaUnCliente()
* \return void
*
**************************************************************************/
void cargaArchivoClientes(){
    char opcion=0;
    stCliente c;
    while(opcion!=27){
        system("cls");
        printf("\n Carga de Clientes \n");
        c=cargaUnCliente();
//        c.id=buscaUltimoId()+1;
        guardaUnCliente(c);

        printf("\n\n ESC para salir ");
        opcion=getch();
    }
}

/*********************************************************************//**
*
* \brief Muestra los datos de un archivo de tipo stCliente
*  itera el archivo y llama a la funcion muestraUnCliente()
* \return void
*
**************************************************************************/
void muestraArchClientes(){
    stCliente c;
    FILE *pArchCliente = fopen(arCliente,"rb");
    if(pArchCliente){
        while(fread(&c,sizeof(stCliente),1,pArchCliente) > 0){
            muestraUnCliente(c);
        }
    }
    printf("\n");
}

/*********************************************************************//**
*
* \brief Busca en un archivo de tipo stCliente un dni
* \param int dni
* \return int 0 si no existe / 1 si existe
*
**************************************************************************/
int buscaUnClienteDNIArchivo(int dni){
    int flag = 0;
    stCliente c;
    FILE *pArchCliente = fopen(arCliente, "rb");
    if(pArchCliente){
        while(fread(&c, sizeof(stCliente),1,pArchCliente) > 0 && flag == 0){
            if(c.dni==dni){
                flag=1;
            }
        }
        fclose(pArchCliente);
    }
    return flag;
}

/*********************************************************************//**
*
* \brief Busca en un archivo de tipo stCliente un apellido
* \param char apellido[]
* \return stCliente (con valor -1 en campo if si no existe)
*
**************************************************************************/
stCliente buscaUnClienteApellidoArchivo(char apellido[]){
    stCliente c;
    int flag=0;
    FILE *pArchCliente = fopen(arCliente,"rb");
    if(pArchCliente){
        while( flag == 0 && fread(&c, sizeof(stCliente), 1, pArchCliente) > 0){
            if(strcmp(c.apellido, apellido) == 0){
                flag=1;
            }
        }
        fclose(pArchCliente);
    }
    if(flag==0){
        c.id=-1;
    }

    return c;
}


