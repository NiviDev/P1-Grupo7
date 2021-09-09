#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define LSO 1
#define LSOBB 2

void menu(lista *l, int tipo);



void menu(lista *l,int tipo){
    int opc = 1, cantidadArt, exito;
    char codigoAlta[10], codigoBaja[10], codigoEvocar[10], codigoPertenece[10],tipoArt[22],marcaArt[32],descripcionArt[102];
    float precioArt;
    Articulo articulo1, articulo2;
    while((opc<7)||(opc>=0)){
        system("cls");
        if (tipo == LSO)
            printf("\n\t\tLISTA SECUENCIAL ORDENADA\n\n");
        else
            printf("\n\t\tLISTA SECUENCIAL ORDENADA BUSQUEDA BINARIA POR BISECCION\n\n");
        /*-----------------------Menu de opciones-----------------------*/
        printf("\t\t1 - Ingreso de nuevos articulos.\n\n\t\t2 - Eliminacipn de articulos existentes.\n\n\t\t3 - Consulta de articulos.\n\n\t\t4 - Consulta deposito.\n\n\t\t5 - Mostrar Estructura.\n\n\t\t6 - Memorizacion Previa.\n\n\t\t7 - Volver.\n\n\n\t\tIngrese la opcion: ");
        fflush(stdin);
        scanf("%d",&opc);
        if(opc==7)
            break;
        /*-----------------------Repeticion en caso de entrada incorrecta-----------------------*/
        while((opc>6)||(opc<=0)){
            system("cls");
            printf("\n\t\tOpcion invalida, ingrese nuevamente");
            if (tipo == LSO)
                printf("\n\t\tLISTA SECUENCIAL ORDENADA\n\n");
            else
                printf("\n\t\tLISTA SECUENCIAL ORDENADA BUSQUEDA BINARIA POR BISECCION\n\n");
            printf("\t\t1 - Ingreso de nuevos articulos.\n\n\t\t2 - Eliminación de articulos existentes.\n\n\t\t3 - Consulta de artículos.\n\n\t\t4 - Consulta deposito.\n\n\t\t5 - Mostrar Estructura.\n\n\t\t6 - Memorización Previa.\n\n\t\t7 - Volver.\n\n\n\t\tIngrese la opcion: ");
            fflush(stdin);
            scanf("%d",&opc);
        }
        /*-----------------------Switch de opciones-----------------------*/
        switch(opc){
            /********
              ALTA
            *********/
            case 1:{
                if(l->ult+1 == MAX){
                system("cls");
                printf("\n\t\tNo hay suficiente espacio para cargar una nueva persona\n");
                system("pause");
                break;
                }
                else{
                    do{
                        system("cls");
                        printf("\n\t\tIngrese los datos del nuevo articulo\n\n\t\tCodigo del Producto (8 digitos): ");
                        scanf("%10[^\n]",&codigoAlta);
                        getchar();
                    }while(strlen(codigoAlta)!=8);
                    strcpy(articulo1.codigo,codigoAlta);
                    //Ingresar tipo de articulo
                    printf("\n\t\tIngrese el tipo de articulo: ");
                    scanf("%22[^\n]",&tipoArt);
                    getchar();
                    strcpy(articulo1.tipo,tipoArt);
                    //Ingresar Marca
                    printf("\n\t\tIngrese la marca del articulo: ");
                    scanf("%32[^\n]",&marcaArt);
                    getchar();
                    strcpy(articulo1.marca,marcaArt);
                    //Ingresar Descripcion
                    printf("\n\t\tIngrese la descripcion del articulo: ");
                    scanf("%102[^\n]",&descripcionArt);
                    getchar();
                    strcpy(articulo1.descripcion,descripcionArt);
                    //Ingresar Precio
                    printf("\n\t\tIngrese el precio del articulo: ");
                    scanf("%f",&precioArt);
                    getchar();
                    articulo1.precio = precioArt;
                    //Ingresar cantidad en stock
                    printf("\n\t\tIngrese la cantidad en stock de este articulo: ");
                    scanf("%d",&cantidadArt);
                    getchar();
                    articulo1.cantidad = cantidadArt;
                    /*-----------------------Ejecucion de las altas-----------------------*/
                    if(tipo == LSO){
                        altaLSO(l, articulo1, &exito);
                    }
                    else{
                        altaLSOBB(l, articulo1, &exito);
                    }
                    if(exito ==1){
                        system("cls");
                        printf("\nAlta Exitosa.\n");
                        system("pause");
                    }
                    else{
                        system("cls");
                        printf("\nEl articulo con codigo %s ya se encuentra cargado en el sistema.\n",articulo1.codigo);
                        system("pause");
                    }
                    break;
                }
            }
            /********
              BAJA
            *********/
            case 2:{
                if(l->ult > -1){
                    printf("\n\t\tIngrese el codigo del articulo que desea eliminar\n\t\tCodigo (8 digitos): ");
                    scanf("%10[^\n]",&codigoBaja);
                    if(tipo == LSO)
                        bajaLSO(l,codigoBaja,&exito);
                    else
                        bajaLSOBB(l, codigoBaja, &exito);
                    if(exito==1){
                        system("cls");
                        printf("\nSe elimino correctamente.\n");
                        system("pause");
                    }
                    else{
                        if(exito==2){
                            system("cls");
                            printf("\nCancelo la eliminacion.\n");
                            system("pause");
                        }
                        else{
                            system("cls");
                            printf("\nNo se encuentra el articulo con ese codigo.\n");
                        }
                    }
                    break;
                }
                else{
                    system("cls");
                    printf("\n\t\tLista vacia\n");
                    system("pause");
                    break;
                }
            }
            /********
              EVOCAR
            *********/
            case 3:{
                if(l->ult > -1){
                    printf("\n\t\tIngrese el codigo del producto que esta buscando.\n\t\tCodigo (8 digitos): ");
                    scanf("%10[^\n]",&codigoEvocar);
                    if(tipo == LSO)
                        articulo2 = evocarLSO(l,codigoEvocar,&exito);
                    else{
                        articulo2 = evocarLSOBB(l,codigoEvocar,&exito);
                    }
                    if(exito==1){
                        mostrarArticulo(articulo2);
                        system("pause");
                        break;
                    }
                    else{
                        printf("\n\t\tNo se encontro el articulo con el codigo %s\n", codigoEvocar);
                        system("pause");
                        break;
                    }
                }
                else{
                    system("cls");
                    printf("\n\t\tLista vacia\n");
                    printf("pause");
                    break;
                }
            }
            /********
              PERTENECE
            *********/
            case 4:{
                if(l->ult > -1){
                    printf("\n\t\tIngrese el codigo del articulo\n\t\tCodigo (8 digitos): ");
                    scanf("%10[^\n]",&codigoPertenece);
                    if(tipo = LSO)
                        exito = perteneceLSO((*l),codigoPertenece);
                    else
                        localizarLSOBB(l,codigoPertenece,&exito);
                    if(exito)
                        printf("\n\t\tEl articulo con codigo %s SI se encuentra en el deposito\n",codigoPertenece);
                    else
                        printf("\n\t\tNo se encuentra el articulo con codigo %s.",codigoPertenece);
                }else{
                    system("cls");
                    printf("\n\t\tLista vacia\n");
                }
                system("pause");
                break;
            }
            /********
              MOSTRAR ESTRUCTURA
            *********/
            case 5:{
                if(l->ult > -1)
                    mostrarTodo(l);
                else{
                    system("cls");
                    printf("\n\t\tLista vacia\n");
                }
                system("pause");
                break;
            }
            /********
              MEMORIZACION PREVIA
            *********/
            case 6:{
                printf("Se realiza la memorizacion previa");
                system("pause");
                break;
            }
        }
    }
}




#endif // MENU_H_INCLUDED
