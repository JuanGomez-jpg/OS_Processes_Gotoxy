#include "Menu.h"

Menu::Menu()
{

}

void Menu::invocarInterfaz()
{
    // Imprimir las filas de los bordes
    SetColor(4); // Rojo
    for (int i(1) ; i < 119 ; ++i)
    {
        gotoxy(i,0); printf("%c",205);
        gotoxy(i,2); printf("%c", 205);
        gotoxy(i,29); printf("%c", 205);
    }
    // Imprimir las columnas de los bordes
    SetColor(6); // Amarillo
    for (int i (1) ; i < 29 ; ++i)
    {
        gotoxy(0,i); printf("%c", 186);
        gotoxy(119,i); printf("%c", 186);
    }

    SetColor(15); // Blanco
    // Título
    gotoxy(48,1); printf("Administraci%cn de Procesos", 162);

    SetColor(4); // Rojo
    //Esquina sup. izquierda
    gotoxy(0,0); printf("%c",201);
    //Inter. ziquierda
    gotoxy(0,2); printf("%c",204);
    //Esquina inf. izquierda
    gotoxy(0,29); printf("%c", 200);

    //Esquina sup. derecha
    gotoxy(119,0); printf("%c",187);
    //Inter. derecha
    gotoxy(119,2); printf("%c",185);
    //Esquina inf. derecha
    gotoxy(119,29); printf("%c", 188);

    // Cuadro de los procesos
    for (int i(2) ; i < 27 ; ++i)
    {
        gotoxy(i,4); printf("%c",205);
        gotoxy(i,6); printf("%c",205);
    }

    // Columnas de los procesos
    gotoxy(1,5); printf("%c",186);
    gotoxy(6,5); printf("%c",186);
    gotoxy(15,5); printf("%c",186);
    gotoxy(26,5); printf("%c",186);

    // Intersecciones de los procesos lado izquierdo
    gotoxy(1,4); printf("%c",201);
    gotoxy(1,6); printf("%c",200);
    // Intersecciones de los procesos lado derecho
    gotoxy(26,4); printf("%c",187);
    gotoxy(26,6); printf("%c",188);
    // Intersecciones de los procesos
    gotoxy(6,4); printf("%c",203);
    gotoxy(6,6); printf("%c",202);
    gotoxy(15,4); printf("%c",203);
    gotoxy(15,6); printf("%c",202);

    SetColor(15); // Blanco
    //Datos de los Procesos
    gotoxy(4,3); cout<<"Datos de los procesos";
    gotoxy(3,5); cout<<"ID";
    gotoxy(8,5); cout<<"Inicio";
    gotoxy(17,5); cout<<"Duraci\242n";

}

void Menu::gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Menu::SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
   } //End

    return;
}

void Menu::procesosEjecucion(vector<Proceso> procesos)
{
    SetColor(15); // Blanco
    // Titulos
    gotoxy(27, 3); cout<<"Orden de ejecuci\242n";
    gotoxy(29, 5); cout<<"ID";
    gotoxy(34, 5); cout<<"Ejecuci\242n";

    SetColor(8); // Gris
    // Cuadro de los procesos
    for (int i(28) ; i < 44 ; ++i)
    {
        gotoxy(i,4); printf("%c",205);
        gotoxy(i,6); printf("%c",205);
    }
    // Columnas de los procesos
    gotoxy(27,5); printf("%c",186);
    gotoxy(32,5); printf("%c",186);
    gotoxy(44,5); printf("%c",186);

    // Intersecciones de los procesos lado izquierdo
    gotoxy(27,4); printf("%c",201);
    gotoxy(27,6); printf("%c",204);
    // Intersecciones de los procesos lado derecho
    gotoxy(44,4); printf("%c",187);
    gotoxy(44,6); printf("%c",185);
    // Intersecciones de los procesos
    gotoxy(32,4); printf("%c",203);
    gotoxy(32,6); printf("%c",202);

    for (size_t i(0) ; i < procesos.size() ; ++i)
    {
        SetColor(8); // Gris
        // Columnas
        gotoxy(27, procesos.at(i).getColT()); printf("%c",186);
        gotoxy(32, procesos.at(i).getColT()); printf("%c",186);
        gotoxy(44, procesos.at(i).getColT()); printf("%c",186);

        SetColor(15); // Blanco
        // Datos
        gotoxy(29, procesos.at(i).getColT()); cout<<""<<procesos.at(i).getIdP();
        gotoxy(37, procesos.at(i).getColT()); cout<<""<<procesos.at(i).getInicio();

        SetColor(8); // Gris
        // Filas
        for (int j (28) ; j < 44 ; ++j)
        {
            gotoxy(j, procesos.at(i).getColT() - 1); printf("%c",205);
            gotoxy(j, procesos.at(i).getColT() + 1); printf("%c",205);
        }

        // Esquinas - Izquierda
        gotoxy(27, procesos.at(i).getColT() - 1); printf("%c",204);
        gotoxy(27, procesos.at(i).getColT() + 1); printf("%c",200);

        // Esquinas - Izquierda + 1
        gotoxy(32, procesos.at(i).getColT() - 1); printf("%c",206);
        gotoxy(32, procesos.at(i).getColT() + 1); printf("%c",202);

        // Esquinas - Izquierda + 2
        gotoxy(44, procesos.at(i).getColT() - 1); printf("%c",185);
        gotoxy(44, procesos.at(i).getColT() + 1); printf("%c",188);

        // Rescatar el ID del proceso en un string
        string id = "";
        for (size_t k(1) ; k < procesos.at(i).getIdP().size() ; ++k)
        {
            id += procesos.at(i).getIdP().at(k);
        }

        // Comparar si el proceso a modificar no es el último de la tabla
        // Si lo es, entra al if y modificar los contornos de la tabla
        int p = procesos.size();
        if (p > atoi(id.c_str()))
        {
            gotoxy(27, procesos.at(i).getColT() + 1); printf("%c",204);
            gotoxy(32, procesos.at(i).getColT() + 1); printf("%c",206);
            gotoxy(44, procesos.at(i).getColT() + 1); printf("%c",185);
        }
    }
}

void Menu::cuadroProcesosEjecucion()
{
    SetColor(9); // Azul claro
    // Filas
    for (int i(46) ; i < 119 ; ++i)
    {
        gotoxy(i,4); printf("%c",205);
        gotoxy(i,24); printf("%c",205);
        Sleep(1);
    }
    // Columnas
    for (int i(5); i < 24; ++i)
    {
        gotoxy(45,i); printf("%c",186);
        gotoxy(118,i); printf("%c",186);
        Sleep(1);
    }

    // Esquinas superiores
    gotoxy(45,4); printf("%c",201);
    gotoxy(118,4); printf("%c",187);
    // Esquinas inferiores
    gotoxy(45,24); printf("%c",200);
    gotoxy(118,24); printf("%c",188);

    SetColor(15); // Blanco
    // Titulo
    gotoxy(48, 3); cout<<"Ejecuci\242n de procesos";
}

void Menu::limpiarMenu()
{

    for (int j(3) ; j < 10 ; ++j)
    {
        for (int i(55) ; i < 93; ++i)
        {
            gotoxy(i,j); cout<<" ";
                //Sleep(1);
        }
    }

}

int Menu::MenuOpc(int procesosRestantes, int maxProcesos)
{
    // Llama a la clase Metodos
    Metodos me;
    // Llama a la clase Validaciones
    Validaciones val;
    // Llama a la clase Advertencias
    Advertencias ad;

    int opc = 0;
    string resp = "";

    // Blanco
    SetColor(15);
    gotoxy(73, 3); cout<<"Men\243";

    if (procesosRestantes == 0)
    {   // Rojo
        SetColor(4);
        gotoxy(60, 4); cout<<"1) A\244adir proceso manualmente";
        gotoxy(60, 5); cout<<"2) A\244adir proceso autom\240ticamente";
    }
    else
    {
        // Blanco
        SetColor(15);
        gotoxy(60, 4); cout<<"1) A\244adir proceso manualmente";
        gotoxy(60, 5); cout<<"2) A\244adir proceso autom\240ticamente";
    }

    if (procesosRestantes == maxProcesos)
    {   // Rojo
        SetColor(4);
        gotoxy(60, 6); cout<<"3) Modificar un proceso";
        gotoxy(60, 7); cout<<"4) Comenzar";
        // Blanco
        SetColor(15);
    }
    else
    {
        // Blanco
        SetColor(15);
        gotoxy(60, 6); cout<<"3) Modificar un proceso";
        gotoxy(60, 7); cout<<"4) Comenzar";
    }
    gotoxy(60, 8); cout<<"5) Salir";
    gotoxy(60, 9); cout<<"Respuesta: ";

    gotoxy(70, 9); getline(cin, resp);
    fflush(stdin);

    resp = me.removerEspacios(resp);
    if (val.validarEntradaMenu(resp))
    {
        do
        {
            resp = "";
            ad.advertenciaErrorMenu();
            gotoxy(70, 9); getline(cin, resp);
            fflush(stdin);
            resp = me.removerEspacios(resp);
        }while (val.validarEntradaMenu(resp) != false);
    }
    opc = stoi(resp);

    return opc;
}

void Menu::mostrarProcesosAgregados(Proceso p, string action, int size)
{
    SetColor(15); // Blanco

    for (int i(8) ; i < 14 ; ++i)
    {
        gotoxy(i, p.getColT()); cout<<" ";
        gotoxy(i*2, p.getColT()); cout<<" ";
    }

    gotoxy(3, p.getColT()); cout<<""<<p.getIdP();
    gotoxy(10, p.getColT()); cout<<""<<p.getInicio();
    gotoxy(20, p.getColT()); cout<<""<<p.getDuracion();

    SetColor(4); // Rojo
    // Mostrar cuadro, columnas
    gotoxy(1, p.getColT()); printf("%c",186);
    gotoxy(6, p.getColT()); printf("%c",186);
    gotoxy(15, p.getColT()); printf("%c",186);
    gotoxy(26, p.getColT()); printf("%c",186);

    for (int i (2) ; i < 26 ; ++i)
    {
        gotoxy(i, p.getColT() + 1); printf("%c",205);
    }

    // Esquinas - Izquierda
    gotoxy(1, p.getColT() - 1); printf("%c",204);
    gotoxy(1, p.getColT() + 1); printf("%c",200);

    // Esquinas - Izquierda + 1
    gotoxy(6, p.getColT() - 1); printf("%c",206);
    gotoxy(6, p.getColT() + 1); printf("%c",202);

    // Esquinas - Izquierda + 2
    gotoxy(15, p.getColT() - 1); printf("%c",206);
    gotoxy(15, p.getColT() + 1); printf("%c",202);

    // Esquinas - Izquierda + 2
    gotoxy(26, p.getColT() - 1); printf("%c",185);
    gotoxy(26, p.getColT() + 1); printf("%c",188);


    // Rescatar el ID del proceso en un string
    string id = "";
    for (size_t i(1) ; i < p.getIdP().size() ; ++i)
    {
        id += p.getIdP().at(i);
    }

    // Comparar si el proceso a modificar no es el último de la tabla
    // Si lo es, entra al if y modificar los contornos de la tabla
    if (action == "mod" && size > atoi(id.c_str()))
    {
        gotoxy(1, p.getColT() + 1); printf("%c",204);
        gotoxy(6, p.getColT() + 1); printf("%c",206);
        gotoxy(15, p.getColT() + 1); printf("%c",206);
        gotoxy(26, p.getColT() + 1); printf("%c",185);
    }

    SetColor(15); // Blanco
}

void bubbleSort(vector<Proceso> &procesos)
{
    Proceso pTemp;
    int size = procesos.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (procesos.at(j).getInicio() < procesos.at(i).getInicio()) {

              pTemp.setIdP(procesos.at(i).getIdP());
              pTemp.setDuracion(procesos.at(i).getDuracion());
              pTemp.setInicio(procesos.at(i).getInicio());

              procesos.at(i).setIdP(procesos.at(j).getIdP());
              procesos.at(i).setDuracion(procesos.at(j).getDuracion());
              procesos.at(i).setInicio(procesos.at(j).getInicio());

              procesos.at(j).setIdP(pTemp.getIdP());
              procesos.at(j).setDuracion(pTemp.getDuracion());
              procesos.at(j).setInicio(pTemp.getInicio());
            }
        }
    }
}

void Menu::init()
{
    Metodos me;
    int opc = 0;
    const int cantidadMaximaProcesos = PROCESOS_RESTANTES;
    int procesosRestantes = PROCESOS_RESTANTES;

    cout<<"Antes de comenzar, procura seleccionar el tama\244o de la fuente 36, fuente Consolas,"<<endl
        <<"el tama\244o del buffer de la ventana: 120, 9001"<<endl
        <<"el tama\244o de la ventana: 120, 30"<<endl
        <<"para el correcto funcionamiento del programa."<<endl<<endl
        <<"Una vez hecho esto, presione cualquier tecla para comenzar."<<endl<<endl;
    system("pause");
    system("cls");

    invocarInterfaz();

    do{
        gotoxy(28,4); cout<<"Procesos Restantes: "<<procesosRestantes<<" ";

        opc = MenuOpc(procesosRestantes, cantidadMaximaProcesos);

        switch (opc) {
            case 1:
                procesosRestantes = me.agregarProcesoMan(procesosRestantes, procesos);
                limpiarMenu();
                mostrarProcesosAgregados(procesos.back(), "", procesos.size());
                procesosAux = procesos;
                break;

            case 2:
                procesosRestantes = me.agregarProcesoAut(procesosRestantes, procesos);
                limpiarMenu();
                mostrarProcesosAgregados(procesos.back(), "", procesos.size());
                procesosAux = procesos;
                break;

            case 3:
                me.modificarProceso(procesosRestantes, cantidadMaximaProcesos, procesos);
                limpiarMenu();
                procesosAux = procesos;
                break;

            case 4:
                gotoxy(28,4); cout<<"                       ";
                bubbleSort(procesos);
                limpiarMenu();
                procesosEjecucion(procesos);

                cuadroProcesosEjecucion();
                getchar();
                break;

            case 5:
                break;
        }

    }while(opc != 5);
}


