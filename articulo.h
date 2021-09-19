#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED

#define MAX 250

typedef struct{ // a todos le sumo 2 porque en el scanf cuando pulso enter(\n) ocupa 2 caracter.
    char codigo[10]; //a lo sumo 8
    char tipo[22]; //a lo sumo 20
    char marca[32]; //a lo sumo 30
    char descripcion[102]; //a lo sumo 100 caracteres
    float precio; //El valor del articulo es un valor real positivo.
    int cantidad; //La cantidad es un numero entero positivo.
}Articulo;


typedef struct{
    int ult;
    Articulo listaArticulo[MAX];
} lista;

lista *l;
lista lso;
lista lsobb;

void mostrarArticulo(Articulo art){
    printf("\n******************\n");
    printf("Codigo: %s\n",art.codigo);
    printf("Tipo de Articulo: %s\n",art.tipo);
    printf("Marca: %s\n",art.marca);
    printf("Descripcion: %s\n",art.descripcion);
    printf("Precio: $%f\n",art.precio);
    printf("Cantidad en Deposito: %d\n",art.cantidad);
    printf("\n******************\n");
}
void mostrarTodo(lista *l){
    system("cls");
    int i;
    for (i=0; i<=l->ult; i++) {
        printf("\n\t\tPosicion en la lista: %d",i);
        mostrarArticulo(l->listaArticulo[i]);
        printf("\n-------------------------------------------\n");
    }
}

void memorizacion(lista *l, int tipo){
    int aux;
    Articulo nuevo;
    FILE *fp = NULL;
    char* nombreArchivo = "Articulos.txt";

    if((fp = fopen(nombreArchivo,"r")) == NULL){
        printf("\n\n\t\tERROR: no se pudo abrir el archivo\n");
        system("pause");
    }
    else{
        while(!(feof(fp))){
            fscanf(fp,"%[^\n]s",&nuevo.codigo);
            fgetc(fp);
            fscanf(fp,"%[^\n]s",&nuevo.tipo);
            fgetc(fp);
            fscanf(fp,"%[^\n]s",&nuevo.marca);
            fgetc(fp);
            fscanf(fp,"%[^\n]s",&nuevo.descripcion);
            fgetc(fp);
            fscanf(fp,"%f",&nuevo.precio);
            fgetc(fp);
            fscanf(fp,"%d",&nuevo.cantidad);
            fgetc(fp);
            if(tipo == 1)
                altaLSO(l,nuevo,&aux);
            else
                altaLSOBB(l,nuevo,&aux);
        }
        fclose(fp);
        printf("\n\n\t\tCarga exitosa\n");
    }
}
#endif // ARTICULO_H_INCLUDED
