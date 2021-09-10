/**
Practico de maquina 1
Grupo 7
Integrante: Wang Chih Wen
            Viluron Nicolas

**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <strings.h>
#include "articulo.h"
#include "LSO.h"
#include "LSOBB.h"
#include "menu.h"


int main(){
    int opc;
    lso.ult=-1; //inicializo la lista secuencial ordenada
    lsobb.ult=-1; //inicializo la lista secuencial ordenada busqueda binaria por biseccion

    while(1){
        do{
            system("cls");
            printf("\n\n\n\t\t1 - Lista Secuencial Ordenada(LSO)\n\n\t\t2 - Lista Secuencial Ordenada Buscada Binaria por Biseccion(LSOBB)\n\n\t\t3 - Salir\n\n\nIngrese la opcion: ");
        }while(!scanf("%d",&opc)||(opc>3)||(opc<=0));
        system("cls");
        switch(opc){
            case 1:{
                /// Menu LSO
                l=&lso;
                menu(l,opc);
                break;
            }
            case 2:{
                /// Menu LSOBB
                l=&lsobb;
                menu(l,opc);
                break;
            }
            case 3:{
                exit(1);
            }
        }
    }


    return 0;
}
