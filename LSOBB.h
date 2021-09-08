#ifndef LSOBB_H_INCLUDED
#define LSOBB_H_INCLUDED

///Prototipo
void altaLSOBB(lista *l, Articulo articulo1, int *exito);
void bajaLSOBB(lista *l, char codigo1[10], int *exito);
Articulo evocarLSOBB(lista l,int codigo, int *exito);
int perteneceLSOBB(lista l, int codigo);

//Comentario
void altaLSOBB(lista *l, Articulo articulo1, int *exito){
    printf("Ejecuta la alta de lista SOBB 2.0, WEN");
}
// PROBANDO

void bajaLSOBB(lista *l, char codigo1[10], int *exito){
    printf("Ejecuta la baja");
}

Articulo evocarLSOBB(lista l,int codigo, int *exito){
    Articulo nulo;
    printf("Ejecuta el evocar\n");
    return nulo;
}

int perteneceLSOBB(lista l, int codigo){
    printf("Pertenece\n");
    return 0;
}
#endif // LSOBB_H_INCLUDED
