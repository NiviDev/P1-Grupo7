#ifndef LSOBB_H_INCLUDED
#define LSOBB_H_INCLUDED

///Prototipo
int localizarLSOBB(lista *l, char codigo[10], int *exito);
void altaLSOBB(lista *l, Articulo articulo, int *exito);
void bajaLSOBB(lista *l, char codigo1[10], int *exito);
Articulo evocarLSOBB(lista l,int codigo, int *exito);
int perteneceLSOBB(lista l, int codigo);

///Funciones
int localizarLSOBB(lista *l, char codigo[10], int *exito){ //li inclusivo, ls exclusivo, derecha, derecha
    int li = 0, ls = l->ult+1, t = 0, pos, i;
    *exito = 0;
    if(l->ult != -1){
        while(li < (ls-1)){
        t=floor((li+ls)/2.0);
        /*
        if(){ //Si el elemento buscado es mayor que t
            li=t;
        }else{
            ls=t;
        }
        */
        }
        t=li;
        if(strcmp(l->listaArticulo[li].codigo,codigo)){
            *exito = 1;
        }else{
            /*
            if(){ // Si el elemento buscado es mayor que t
                t++;
            }
            */

        }
    }
    return t;
}



void altaLSOBB(lista *l, Articulo articulo, int *exito){
    int pos, i;
    pos = localizarLSOBB(l,articulo.codigo,exito);
    if(*exito == 0){
        for(i=l->ult+1; i>=pos+1; i--){
            strcpy(l->listaArticulo[i].codigo,l->listaArticulo[i-1].codigo);
            strcpy(l->listaArticulo[i].tipo,l->listaArticulo[i-1].tipo);
            strcpy(l->listaArticulo[i].marca,l->listaArticulo[i-1].marca);
            strcpy(l->listaArticulo[i].descripcion,l->listaArticulo[i-1].descripcion);
            l->listaArticulo[i].precio = l->listaArticulo[i-1].precio;
            l->listaArticulo[i].cantidad = l->listaArticulo[i-1].cantidad;
        }
        l->ult++;
        strcpy(l->listaArticulo[i].codigo, articulo.codigo);
        strcpy(l->listaArticulo[i].tipo, articulo.tipo);
        strcpy(l->listaArticulo[i].marca, articulo.marca);
        strcpy(l->listaArticulo[i].descripcion, articulo.descripcion);
        l->listaArticulo[i].precio = articulo.precio;
        l->listaArticulo[i].cantidad = articulo.cantidad;
        *exito = 1;
    }else{
        *exito = 0;
    }
}


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
