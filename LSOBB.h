#ifndef LSOBB_H_INCLUDED
#define LSOBB_H_INCLUDED

///Prototipo
int localizarLSOBB(lista *l, char codigo[10], int *exito);
void altaLSOBB(lista *l, Articulo articulo, int *exito);
void bajaLSOBB(lista *l, char codigo[10], int *exito);
Articulo evocarLSOBB(lista *l,char codigo[10], int *exito);
int perteneceLSOBB(lista *l, char codigo[10]);

///Funciones
int localizarLSOBB(lista *l, char codigo[10], int *exito){ //inclusivo, exclusivo, derecha, derecha
    int li = 0, ls = l->ult+1, t = 0, i;
    *exito = 0;
    if(ls!=0){
        while(li != (ls-1)){
            t=floor((li+ls)/2.0);
            if(strcasecmp(l->listaArticulo[t].codigo,codigo) <= 0){
                li=t;
            }else{
                ls=t;
            }

        }
        t=ls-1;
        if(strcasecmp(l->listaArticulo[t].codigo,codigo) == 0){
            *exito = 1;
        }else{
            if(t==-1){
                t++;
            }else{
                if(strcasecmp(l->listaArticulo[t].codigo,codigo) < 0){
                    t++;
                }
            }


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


void bajaLSOBB(lista *l, char codigo[10], int *exito){
    int pos, aux=0,i;
    pos=localizarLSOBB(l, codigo, exito);
    if(*exito == 1){
        mostrarArticulo(l->listaArticulo[pos]);
        printf("\n\t\tDesea eliminar el articulo?\n\t\t1 - Eliminar\n\t\t2 - Volver\n\n\t\tOpcion: ");
        fflush(stdin);
        scanf("%d",&aux);
        //fflush(stdin);
        //getchar();
        while(aux!=1&&aux!=2){
            system("cls");
            printf("\n\t\tOpcion invalido, ingrese nuevamente.\n\t\t1 - Eliminar\n\t\t2 - Volver\n\t\tOpcion: ");
            fflush(stdin);
            scanf("%d",&aux);
            //fflush(stdin);
            //getchar();
        }
        if(aux==1){ //decide eliminar
            for(i=pos; i<l->ult;i++){
                strcpy(l->listaArticulo[i].codigo,l->listaArticulo[i+1].codigo);
                strcpy(l->listaArticulo[i].tipo,l->listaArticulo[i+1].tipo);
                strcpy(l->listaArticulo[i].marca,l->listaArticulo[i+1].marca);
                strcpy(l->listaArticulo[i].descripcion,l->listaArticulo[i+1].descripcion);
                l->listaArticulo[i].precio = l->listaArticulo[i+1].precio;
                l->listaArticulo[i].cantidad = l->listaArticulo[i+1].cantidad;
            }
            l->ult--;
        }else{
            *exito = 2; // no decide eliminar
        }
    }
}

Articulo evocarLSOBB(lista *l,char codigo[10], int *exito){
    int pos;
    pos = localizarLSOBB(l, codigo, exito);
    if(*exito == 1){
        return l->listaArticulo[pos];
    }
}

int perteneceLSOBB(lista *l, char codigo[10]){
    int exito;
    localizarLSOBB(l,codigo,&exito);
    return exito;
}

#endif // LSOBB_H_INCLUDED
