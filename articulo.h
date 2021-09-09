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

void mostrarArticulo(Articulo a){
    printf("\n\t\t- Informacion del Articulo -");
    printf("\n\t\tCodigo: %s",a.codigo);
    printf("\n\t\tTipo: %s",a.tipo);
    printf("\n\t\tMarca: %s",a.marca);
    printf("\n\t\tDescripcion: %s",a.descripcion);
    printf("\n\t\tPrecio: %f",a.precio);
    printf("\n\t\tCantidad: %d\n",a.cantidad);
}


void mostrarTodo(lista l){
    printf("Muestra la lista\n");
}
#endif // ARTICULO_H_INCLUDED
