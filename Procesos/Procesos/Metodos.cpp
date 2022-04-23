#include "Metodos.h"

Metodos::Metodos()
{

}

void Metodos::gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Metodos::SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }

    return;
}

string Metodos::removerEspacios(string resp)
{
    string value = "";
    for (size_t i(0) ; i < resp.size() ; ++i)
    {
        if (resp.at(i) != ' ')
            value += resp.at(i);
    }
    return value;
}

int Metodos::agregarProcesoMan(int procesosRestantes, vector<Proceso> &procesos)
{
    // Manda a llamar a la clase Menu
    Menu m;
    // Manda a llamar a la clase Advertencias
    Advertencias ad;
    // Manda a llamar a la clase de Validaciones
    Validaciones val;

    string resp = "";
    int procesosAux = procesosRestantes, inicio = 0, duracion = 0;
    if (procesosRestantes == 0)
    {
        ad.advertenciaErrorMaximoProcesos();
    }
    else
    {
        m.limpiarMenu();

        // Titulo
        gotoxy(60,3); cout<<"Agregar";

        // Inicio - Entrada

        gotoxy(55, 5); cout<<"Inicio (0-67): ";
        gotoxy(69, 5); getline(cin, resp);
        fflush(stdin);

        resp = removerEspacios(resp);
        if (val.validarEntradaProceso(resp, 1, 67))
        {
            do
            {
                resp = "";
                ad.advertenciaErrorProcesos(1, procesos, 67);
                gotoxy(69, 5); getline(cin, resp);
                fflush(stdin);
                resp = removerEspacios(resp);
            }while (val.validarEntradaProceso(resp, 1, 68) != false);
        }
        inicio = stoi(resp);

        // Duracion - Entrada
        int limSup = 69 - inicio;
        gotoxy(55, 7); printf("Duraci\242n (2-%d): ",limSup);
        gotoxy(71, 7); getline(cin, resp);
        fflush(stdin);

        resp = removerEspacios(resp);
        if (val.validarEntradaProceso(resp, 2, limSup))
        {
            do
            {
                resp = "";
                ad.advertenciaErrorProcesos(2, procesos, limSup);
                gotoxy(71, 7); getline(cin, resp);
                fflush(stdin);
                resp = removerEspacios(resp);
            }while (val.validarEntradaProceso(resp, 2, limSup) != false);
        }
        duracion = stoi(resp);

        Proceso p;
        p.setInicio(inicio);
        p.setDuracion(duracion);
        string id = "P" + to_string(procesos.size() + 1);
        int posCol = 0;

        if (procesos.size() == 0)
            posCol = 7;
        else
            posCol = procesos.back().getColT() + 2;

        p.setColorB(procesos.size() + 1);
        p.setFilT(2);
        p.setColT(posCol);
        p.setIdP(id);
        p.setFilB(46+p.getInicio());
        p.setColB(posCol);
        p.setMaxVal(inicio + duracion);

        procesos.push_back(p);

        --procesosAux;
    }

    return procesosAux;
}

int Metodos::agregarProcesoAut(int procesosRestantes, vector<Proceso> &procesos)
{
    // Manda a llamar a la clase Menu
    Menu m;
    // Manda a llamar a la clase Advertencias
    Advertencias ad;

    int procesosAux = procesosRestantes;
    if (procesosRestantes == 0)
    {
        ad.advertenciaErrorMaximoProcesos();
    }
    else
    {
        m.limpiarMenu();

        Proceso p;
        int inicio = rand() % 67;
        p.setInicio(inicio);

        int duracion = 69 - inicio;
        int al = 0 + rand()% (duracion + 1 - 0);
        p.setDuracion(al);
        string id = "P" + to_string(procesos.size() + 1);
        int posCol = 0;

        if (procesos.size() == 0)
            posCol = 7;
        else
            posCol = procesos.back().getColT() + 2;

        p.setColorB(procesos.size() + 1);
        p.setFilT(2);
        p.setColT(posCol);
        p.setFilB(46+p.getInicio());
        p.setColB(posCol);
        p.setIdP(id);
        p.setMaxVal(inicio + al);
        procesos.push_back(p);

        --procesosAux;
    }

    return procesosAux;
}

void Metodos::modificarProceso(int procesosRestantes, int cantidadMaxProc, vector<Proceso> &procesos)
{
    // Manda a llamar a la clase Menu
    Menu m;
    // Manda a llamar a la clase Advertencias
    Advertencias ad;
    // Manda a llamar a la clase de Validaciones
    Validaciones val;

    string resp = "";
    int opcion = 0;
    if ( (cantidadMaxProc - procesosRestantes) == 0)
    {
        ad.advertenciaNoProcesos();
    }
    else
    {
        m.limpiarMenu();

        // Titulo
        gotoxy(65,3); cout<<"Modificar";

        // Inicio - Entrada

        gotoxy(55, 5); cout<<"1) Ingresar el id del proceso";
        gotoxy(55, 6); cout<<"2) Cancelar";
        gotoxy(55, 7); cout<<"Respuesta: ";
        gotoxy(65, 7); getline(cin, resp);
        fflush(stdin);

        resp = removerEspacios(resp);
        if (val.validarEntradaModificar(resp))
        {
            do
            {
                resp = "";
                ad.advertenciaErrorProcesos(3, procesos, 0);
                gotoxy(65, 7); getline(cin, resp);
                fflush(stdin);
                resp = removerEspacios(resp);
            }while (val.validarEntradaModificar(resp) != false);
        }
        opcion = stoi(resp); // String to Int

        if (opcion == 1)
        {
            // Limpiar menu-modificar
            for (int i (55); i < 119 ; ++i)
                for (int j(5); j < 10 ; ++j)
                {
                    gotoxy(i,j); cout<<" ";
                }

            modificar(procesos);
        }
        else
            m.limpiarMenu();

    }
}

void Metodos::modificar(vector<Proceso> &procesos)
{
    // Manda a llamar a la clase Menu
    Menu m;
    // Manda a llamar a la clase Advertencias
    Advertencias ad;
    // Manda a llamar a la clase de Validaciones
    Validaciones val;

    string id = "";
    int err = 0, pos = 0;

    // ID - Entrada
    gotoxy(55, 5); cout<<"ID: P";
    gotoxy(60, 5); getline(cin, id);
    fflush(stdin);

    id = removerEspacios(id);
    val.validarProcesoExistente(id, procesos, &pos, &err);
    if (err != 0)
    {
        do
        {
            id = "";
            ad.advertenciaErrorProcesos(err, procesos,0);
            gotoxy(60, 5); getline(cin, id);
            fflush(stdin);
            id = removerEspacios(id);
            err = 0;
            pos = 0;
            val.validarProcesoExistente(id, procesos, &pos, &err);
        }while (err != 0);
    }

    string resp = "";
    int inicio = 0, duracion = 0;
    // Limpiar menu modificar
    for (int i (55); i < 119 ; ++i)
        for (int j(5); j < 10 ; ++j)
        {
            gotoxy(i,j); cout<<" ";
        }

    // Inicio - Entrada

    gotoxy(55, 5); cout<<"Inicio (0-67): ";
    gotoxy(69, 5); getline(cin, resp);
    fflush(stdin);

    resp = removerEspacios(resp);
    if (val.validarEntradaProceso(resp, 1,67))
    {
        do
        {
            resp = "";
            ad.advertenciaErrorProcesos(1, procesos,67);
            gotoxy(69, 5); getline(cin, resp);
            fflush(stdin);
            resp = removerEspacios(resp);
        }while (val.validarEntradaProceso(resp, 1, 67) != false);
    }
    inicio = stoi(resp);

    int limSup = 69 - inicio;
    // Duracion - Entrada

    gotoxy(55, 7); printf("Duraci\242n (2-%d): ",limSup);
    gotoxy(71, 7); getline(cin, resp);
    fflush(stdin);

    resp = removerEspacios(resp);
    if (val.validarEntradaProceso(resp, 2, limSup))
    {
        do
        {
            resp = "";
            ad.advertenciaErrorProcesos(2, procesos, limSup);
            gotoxy(71, 7); getline(cin, resp);
            fflush(stdin);
            resp = removerEspacios(resp);
        }while (val.validarEntradaProceso(resp, 2, limSup) != false);
    }
    duracion = stoi(resp);

    // Verificar si existe el proceso (ID) iterando en la lista

    if (procesos.at(pos).getIdP() == "P" + id)
    {
        procesos.at(pos).setInicio(inicio);
        procesos.at(pos).setDuracion(duracion);
        procesos.at(pos).setMaxVal(inicio + duracion);
        procesos.at(pos).setFilB(46+inicio);

        Proceso p;

        p = procesos.at(pos);
        m.mostrarProcesosAgregados(p, "mod", procesos.size());
    }
}

void Metodos::sortAscending(vector<Proceso> &procesos)
{
    struct ascendingData{
        inline bool operator () (const Proceso& p1, const Proceso p2){
            return (p1.getMaxVal() < p2.getMaxVal());
        }
    };

    sort(procesos.begin(), procesos.end(), ascendingData());
}

int Metodos::valoresInferioresProcesos(vector<Proceso> procesos)
{
    vector <Proceso> proAux = procesos;

    gotoxy(46, procesos.at(procesos.size()-1).getColT() + 2); cout<<"0";

    sortAscending(proAux);

    float tme = proAux.at(proAux.size() - 1).getMaxVal();

    // Sacar mitad del proceso con mayor inicio y duración
    float mitad = tme / 2;
    string m = to_string(mitad);
    bool val = false;
    for (size_t i(0) ; i < m.size(); ++i)
        if (m.at(i) == '.' && m.at(i + 1) == '0')
        {
            val = true;
            break;
        }

    if (val)
    {
        if(m.find('.') != std::string::npos)
        {
            // Remove trailing zeroes
            m = m.substr(0, m.find_last_not_of('0')+1);
            // If the decimal point is now the last character, remove that as well
            if(m.find('.') == m.size()-1)
            {
                m = m.substr(0, m.size()-1);
            }
        }
        gotoxy(46 + mitad, procesos.at(procesos.size()-1).getColT() + 2); cout<< m;
    }
    else
    {
        gotoxy(46 + mitad, procesos.at(procesos.size()-1).getColT() + 2); printf("%.1f", mitad);
    }

    gotoxy(47 + tme, procesos.at(procesos.size()-1).getColT() + 2); cout<<""<<tme;

    return tme;
}

void Metodos::runnable(int x, int y)
{
    gotoxy(x, y); printf("%c",219);
}

void Metodos::actualizarTablaProcesos(Proceso p)
{
    for (int i(33) ; i < 43 ; ++i)
    {
        gotoxy(i, p.getColT()); cout<<" ";
    }
    SetColor(15); // Blanco
    // Datos
    gotoxy(37, p.getColT()); cout<<p.getInicio() + p.getTiempoTranscurrido();
}

void Metodos::imprimirContador(int con, int posY)
{
    int d = con / 10;
    int inc = 0;
    while(inc <= 3)
    {
        switch(d)
        {
            case 0:
                gotoxy(14 + inc, posY);
                printf("%c%c%c", 218, 196, 191);
                gotoxy(14 + inc, posY + 1);
                printf("%c %c", 179, 179);
                gotoxy(14 + inc, posY + 2);
                printf("%c%c%c", 192, 196, 217);
                break;
            case 1:
                gotoxy(14 + inc, posY);
                printf(" %c ", 191);
                gotoxy(14 + inc, posY + 1);
                printf(" %c ", 179);
                gotoxy(14 + inc, posY + 2);
                printf(" %c ", 193);
                break;
            case 2:
                gotoxy(14 + inc, posY);
                printf("%c%c%c", 218, 196, 191);
                gotoxy(14 + inc, posY + 1);
                printf("%c%c%c", 218, 196, 217);
                gotoxy(14 + inc, posY + 2);
                printf("%c%c%c", 192, 196, 217);
                break;
            case 3:
                gotoxy(14 + inc, posY);
                printf("%c%c%c", 196, 196, 191);
                gotoxy(14 + inc, posY + 1);
                printf("%c%c%c", 196, 196, 180);
                gotoxy(14 + inc, posY + 2);
                printf("%c%c%c", 196, 196, 217);
                break;
            case 4:
                gotoxy(14 + inc, posY);
                printf("%c %c", 179, 179);
                gotoxy(14 + inc, posY + 1);
                printf("%c%c%c", 192, 196, 180);
                gotoxy(14 + inc, posY + 2);
                printf("  %c", 179);

                break;
            case 5:
                gotoxy(14 + inc, posY);
                printf("%c%c%c", 218, 196, 191);
                gotoxy(14 + inc, posY + 1);
                printf("%c%c%c", 192, 196, 191);
                gotoxy(14 + inc, posY + 2);
                printf("%c%c%c", 192, 196, 217);
                break;
            case 6:
                gotoxy(14 + inc, posY);
                printf("%c%c%c", 218, 196, 191);
                gotoxy(14 + inc, posY + 1);
                printf("%c%c%c", 179, 196, 191);
                gotoxy(14 + inc, posY + 2);
                printf("%c%c%c", 192, 196, 217);
                break;
            case 7:
                gotoxy(14 + inc, posY);
                printf("%c%c%c", 196, 196, 191);
                gotoxy(14 + inc, posY + 1);
                printf(" %c%c", 196, 180);
                gotoxy(14 + inc, posY + 2);
                printf("  %c", 179);
                break;
            case 8:
                gotoxy(14 + inc, posY);
                printf("%c%c%c", 218, 196, 191);
                gotoxy(14 + inc, posY + 1);
                printf("%c%c%c", 195, 196, 180);
                gotoxy(14 + inc, posY + 2);
                printf("%c%c%c", 192, 196, 217);
                break;
            case 9:
                gotoxy(14 + inc, posY);
                printf("%c%c%c", 218, 196, 191);
                gotoxy(14 + inc, posY + 1);
                printf("%c%c%c", 192, 196, 180);
                gotoxy(14 + inc, posY + 2);
                printf("  %c", 179);
                break;
        }
        d = con%10;
        inc += 3;
    }

}

void Metodos::run(vector<Proceso> procesos, vector<Proceso> procesosAux)
{
    vector <Proceso> proAux = procesos;

    // Imprimir el título del contador global
    gotoxy(9, procesos.at(procesos.size()-1).getColT() + 2); cout<<"Contador Global";

    sortAscending(proAux); // Ordenar los procesos auxiliares

    int tme = proAux.at(proAux.size() - 1).getMaxVal()+1;
    int cont = tme - 1;
    int x = 0, y = 0;
    int inicio = 0, final = 0;

    // Imprimir los identificadores de los procesos en pantalla
    for (size_t i (0) ; i < procesos.size() ; ++i)
    {
        SetColor(15); // Blanco
        x = procesosAux.at(i).getFilB() + procesosAux.at(i).getDuracion() + 1;
        y = procesosAux.at(i).getColB() -1;
        gotoxy(x, y); cout<<procesosAux.at(i).getIdP();
        procesos.at(i).setTiempoTranscurrido(0);
    }

    // Imprimir el contador
    imprimirContador(cont, procesos.at(procesos.size()-1).getColT() + 3);

    Proceso p;
    bool band = false;

    // Ejecución de los procesos
    for (int i(0) ; i < tme ; ++i)
    {
        band = false;
        for (size_t k (0) ; k < procesos.size() ; ++k)
        {
            inicio = procesos.at(k).getInicio(); // Donde inicia el proceso
            final = procesos.at(k).getMaxVal();  // Donde termina
            if (i >= inicio && i <= final)
            {
                band = true;
                p = procesos.at(k);
                actualizarTablaProcesos(p);
                x = procesos.at(k).getFilB() + procesos.at(k).getTiempoTranscurrido();
                y = procesos.at(k).getColB() - 1;
                SetColor(procesos.at(k).getColorB()); // Colorear barra
                runnable(x,y);
                procesos.at(k).setTiempoTranscurrido(procesos.at(k).getTiempoTranscurrido() + 1);
            }
        }

        if (band)
            Sleep(1000);
        else if (!band)
            Sleep(150);

        --cont;
        SetColor(15); // Blanco
        // Actualizar el contador
        imprimirContador(cont, procesos.at(procesos.size()-1).getColT() + 3);
    }

    SetColor(15); // Blanco
    gotoxy(28,procesos.at(procesos.size()-1).getColT() + 4); cout<<"Presione cualquier tecla para continuar (se limpiar\240n todos los procesos)";
    gotoxy(50,procesos.at(procesos.size()-1).getColT() + 5); system("pause");

}

