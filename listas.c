#include <stdio.h>
#include <stdlib.h>

//Estructura nodo
typedef struct nodo
{
    int dato;               //Tipo de dato de la lista
    struct nodo* siguiente; //Apuntador al siguiente nodo o nulo
}nodo;

//Apuntadores para hacer referencias al primero y al ultimo elemento de la lista
nodo* primero = NULL;
nodo* ultimmo = NULL;

void insertarNodo();
void mostrarLista();
void buscarNodo();
void modificarNodo();
void eliminarNodo();



int main(){
	int opcionMenu = 0;
	do{
		printf("\n|-------------------------------------|");
		printf("\n|           ° LISTA SIMPLE °          |");
		printf("\n|------------------|------------------|");
		printf("\n| 1. Insertar      | 4. Eliminar      |");
		printf("\n| 2. Buscar       | 5. Desplegar     |");
		printf("\n| 3. Modificar     | 6. Salir         |");
		printf("\n|------------------|------------------|");
		printf("\n\n Escoja una Opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				printf("\n\n INSERTA NODO EN LA LISTA \n\n");
				insertarNodo();
				break;
			case 2:
				printf("\n\n BUSCAR UN NODO EN LA LISTA \n\n");
				buscarNodo();
				break;	
			case 3:
				printf("\n\n MODIFICAR UN NODO DE LA LISTA \n\n");
				modificarNodo();
				break;
			case 4:
				printf("\n\n ELIMINAR UN NODO DE LA LISTA \n\n");
				eliminarNodo();
				break;
			case 5:
				printf("\n\n DESPLEGAR LISTA DE NODOS \n\n");	
				mostrarLista();
				break;
			case 6:
				printf("\n\n Programa finalizado...");
				break;
			default:
				printf("\n\n Opcion No Valida \n\n");	
		}
	}while(opcionMenu != 6);
	return 0;
}




void insertarNodo(){
    //Creamos un nodo del temaño dinamico
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    printf("Ingresa el dato que contendra el nodo: ");
    scanf("%d",&nuevo->dato);
    //Revisamos si la lista ha sido creada
    if (primero == NULL)
    {
        primero = nuevo;
        primero->siguiente = NULL;
        ultimmo = nuevo;
    }else{
        ultimmo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        ultimmo = nuevo;
    }

    printf("\n Nodo ingresado con Exito\n\n");    
}

void mostrarLista(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    //Comprobamos si la lista esta vacia
    if(primero != NULL){
        while (actual != NULL)
        {
            printf("\n%d\n",actual->dato);
            actual = actual->siguiente;
        }
        
    }else{
        printf("\n La lista esta vacia.");
    }
    
}

void buscarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    int nodoBuscado = 0, encontrado = 0; //Cuando "encontrado" es 0, el nodo no se encontro, cuando "encontrado" es 1 el nodo fue encontrado
    printf("\nIngresa el dato del nodo a buscar: ");
    scanf("%d",&nodoBuscado);
    //Comprobamos si la lista esta vacia
    if(primero != NULL){
        while (actual != NULL && encontrado != 1)
        {
            //Vamos comparando cual de los datos es el buscado
            if(actual->dato == nodoBuscado){
                printf("\nEl nodo con el dato (%d) encontrado: ", nodoBuscado);
                encontrado = 1;
            }    
            actual = actual->siguiente;
        }
        //Si no encrontramos el nodo
        if(encontrado == 0){
            printf("\nEl nodo no se ha encontrado");
        }
        
    }else{
        printf("\n La lista esta vacia.");
    }
}

void modificarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    int nodoBuscado = 0, encontrado = 0; //Cuando "encontrado" es 0, el nodo no se encontro, cuando "encontrado" es 1 el nodo fue encontrado
    printf("\nIngresa el dato del nodo a buscar para modificar: ");
    scanf("%d",&nodoBuscado);
    //Comprobamos si la lista esta vacia
    if(primero != NULL){
        while (actual != NULL && encontrado != 1)
        {
            //Vamos comparando cual de los datos es el buscado
            if(actual->dato == nodoBuscado){
                printf("\nEl nodo con el datp (%d) encontrado: ", nodoBuscado);
                printf("\n Ingresa el nuevo dato para este nodo");
                scanf("%d", &actual->dato);
                printf("\n Nodo modificado con exito");
                encontrado = 1;
            }    
            actual = actual->siguiente;
        }
        //Si no encrontramos el nodo
        if(encontrado == 0){
            printf("\nEl nodo no se ha encontrado");
        }
        
    }else{
        printf("\n La lista esta vacia.");
    }
}

void eliminarNodo(){
    nodo* actual = (nodo*) malloc(sizeof(nodo));
    nodo* anterior = (nodo*) malloc(sizeof(nodo));
    actual = primero;
    anterior = NULL;
    int nodoBuscado = 0, encontrado = 0; //Cuando "encontrado" es 0, el nodo no se encontro, cuando "encontrado" es 1 el nodo fue encontrado
    printf("\nIngresa el dato del nodo a buscar para eliminar: ");
    scanf("%d",&nodoBuscado);
    //Comprobamos si la lista esta vacia
    if(primero != NULL){
        while (actual != NULL && encontrado != 1)
        {
            //Vamos comparando cual de los datos es el buscado
            if(actual->dato == nodoBuscado){
                printf("\nEl nodo con el dato (%d) encontrado: ", nodoBuscado);

                if(actual == primero){
                    primero = primero->siguiente;
                }else if(actual == ultimmo){
                    anterior->siguiente = NULL;
                    ultimmo = anterior;
                }else{
                    anterior->siguiente = actual->siguiente;
                }
                printf("\nNodo eliminado con exito.");

                encontrado = 1;
            }    
            anterior = actual;
            actual = actual->siguiente;
        }
        //Si no encrontramos el nodo
        if(encontrado == 0){
            printf("\nEl nodo no se ha encontrado");
        }else
        {
            free(anterior);
        }
        
        
    }else{
        printf("\n La lista esta vacia.");
    }  
}