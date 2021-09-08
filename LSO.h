#ifndef LSO_H_INCLUDED
#define LSO_H_INCLUDED

///Prototipo
void altaLSO(lista *l, Articulo articulo1, int *exito);
void bajaLSO(lista *l, char codigo1[10], int *exito);
Articulo evocarLSO(lista l,int codigo, int *exito);
int perteneceLSO(lista l, char codigo[10]);
int localizarLSO(lista l, char codigo[10], *exito);

void altaLSO(lista *l, Articulo articulo1, int *exito){
    printf("Ejecuta la alta version 3.0\n");
}

void bajaLSO(lista *l, char codigo1[10], int *exito){
    printf("Ejecuta la baja\n");
}

Articulo evocarLSO(lista l,int codigo, int *exito){
    Articulo nulo;
    printf("Ejecuta el evocar\n");
    return nulo;
}

int perteneceLSO(lista l, char codigo[10]){
    printf("Pertenece\n");
    return 0;
}
#endif // LSO_H_INCLUDED
