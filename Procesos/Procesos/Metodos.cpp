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
   } //End

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

        gotoxy(55, 5); cout<<"Inicio (0-70): ";
        gotoxy(69, 5); getline(cin, resp);
        fflush(stdin);

        resp = removerEspacios(resp);
        if (val.validarEntradaProceso(resp, 1))
        {
            do
            {
                resp = "";
                ad.advertenciaErrorProcesos(1, procesos);
                gotoxy(69, 5); getline(cin, resp);
                fflush(stdin);
                resp = removerEspacios(resp);
            }while (val.validarEntradaProceso(resp, 1) != false);
        }
        inicio = stoi(resp);

        // Duracion - Entrada

        gotoxy(55, 7); cout<<("Duraci\242n (2-70): ");
        gotoxy(71, 7); getline(cin, resp);
        fflush(stdin);

        resp = removerEspacios(resp);
        if (val.validarEntradaProceso(resp, 2))
        {
            do
            {
                resp = "";
                ad.advertenciaErrorProcesos(2, procesos);
                gotoxy(71, 7); getline(cin, resp);
                fflush(stdin);
                resp = removerEspacios(resp);
            }while (val.validarEntradaProceso(resp, 2) != false);
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

        p.setBarra(0);
        p.setFilT(2);
        p.setColT(posCol);
        p.setIdP(id);
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
        p.setInicio(rand() % 70);
        p.setDuracion(1 + rand() % 70);
        string id = "P" + to_string(procesos.size() + 1);
        int posCol = 0;

        if (procesos.size() == 0)
            posCol = 7;
        else
            posCol = procesos.back().getColT() + 2;

        p.setBarra(0);
        p.setFilT(2);
        p.setColT(posCol);
        p.setIdP(id);
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
                ad.advertenciaErrorProcesos(3, procesos);
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
            ad.advertenciaErrorProcesos(err, procesos);
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

    gotoxy(55, 5); cout<<"Inicio (0-70): ";
    gotoxy(69, 5); getline(cin, resp);
    fflush(stdin);

    resp = removerEspacios(resp);
    if (val.validarEntradaProceso(resp, 1))
    {
        do
        {
            resp = "";
            ad.advertenciaErrorProcesos(1, procesos);
            gotoxy(69, 5); getline(cin, resp);
            fflush(stdin);
            resp = removerEspacios(resp);
        }while (val.validarEntradaProceso(resp, 1) != false);
    }
    inicio = stoi(resp);

    // Duracion - Entrada

    gotoxy(55, 7); cout<<("Duraci\242n (2-70): ");
    gotoxy(71, 7); getline(cin, resp);
    fflush(stdin);

    resp = removerEspacios(resp);
    if (val.validarEntradaProceso(resp, 2))
    {
        do
        {
            resp = "";
            ad.advertenciaErrorProcesos(2, procesos);
            gotoxy(71, 7); getline(cin, resp);
            fflush(stdin);
            resp = removerEspacios(resp);
        }while (val.validarEntradaProceso(resp, 2) != false);
    }
    duracion = stoi(resp);

    // Verificar si existe el proceso (ID) iterando en la lista

    if (procesos.at(pos).getIdP() == "P" + id)
    {
        procesos.at(pos).setInicio(inicio);
        procesos.at(pos).setDuracion(duracion);

        Proceso p;

        p = procesos.at(pos);
        m.mostrarProcesosAgregados(p, "mod", procesos.size());
    }
}

void Metodos::inicializarProcesos(vector<Proceso> &procesos)
{
    gotoxy(46, procesos.at(procesos.size()-1).getColT() + 2); cout<<""<<procesos.at(0).getInicio();

    int tme = procesos.at(procesos.size()-1).getInicio() + procesos.at(procesos.size()-1).getDuracion();

    // Sacar mitad del proceso con mayor inicio
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
        gotoxy(81, procesos.at(procesos.size()-1).getColT() + 2); cout<< m;
    }
    else
    {
        gotoxy(81, procesos.at(procesos.size()-1).getColT() + 2); printf("%.1f", mitad);
    }
    gotoxy(116, procesos.at(procesos.size()-1).getColT() + 2); cout<<""<<tme;
}

