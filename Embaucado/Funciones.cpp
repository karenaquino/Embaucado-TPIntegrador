#include <iostream>
#include <string>
#include "funciones.h"
#include<cstdlib>
#include <stdlib.h>
#include<ctime>
#include <windows.h>


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);





using namespace std;

//FUNCION MENU
void mostrarMenuPrincipal()
{
    SetConsoleTextAttribute(hConsole, 15);
    cout << endl;
    cout << endl;
    cout << " #######  ##   ##  #####      ###    ##   ##   #####     ###    #####     #####  " << endl;
    cout << " ##       ### ###  ##   ##   ## ##   ##   ##  ##   ##   ## ##   ##  ##   ##   ## " << endl;
    cout << " ##       #######  ##   ##  ##   ##  ##   ##  ##       ##   ##  ##   ##  ##   ## " << endl;
    cout << " #####    ## # ##  ######   ##   ##  ##   ##  ##       ##   ##  ##   ##  ##   ## " << endl;
    cout << " ##       ##   ##  ##   ##  #######  ##   ##  ##       #######  ##   ##  ##   ## " << endl;
    cout << " ##       ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  ##  ##   ##   ## " << endl;
    cout << " #######  ##   ##  #####    ##   ##   #####    #####   ##   ##  #####     #####  " << endl;
    cout << endl;

    cout << "             \t ======================================" << endl;
    cout << "             \t=|                                    |=" << endl;
    cout << "    *  " << "  \t=|        ---------------------       |=" << "      *   *    " << endl;
    cout << "   *** " << "  \t=|             1 - JUGAR              |=" << "     *** ***   " << endl;
    cout << "  *****" << "  \t=|             2 - ESTAD�STICAS       |=" << "     *******    " << endl;
    cout << "   *** " << "  \t=|             3 - CR�DITOS           |=" << "      *****    " << endl;
    cout << "    *  " << "  \t=|        ---------------------       |= " << "       *    " << endl;
    cout << "             \t=|             0 - SALIR              |=" << endl;
    cout << "             \t=|                                    |=" << endl;
    cout << "             \t ======================================" << endl;
    cout << endl;
    cout << "\t\t    Jugadores Ingresen una Opcion: ";
}



//FUNCION CARGA DE JUGADORES
void cargarJugadores(string& nombre1, string& nombre2)
{
    char opcion;
    int cambioNombre;

    cout << endl;
    cout << endl;
    cout << " #######  ##   ##  #####      ###    ##   ##   #####     ###    #####     #####  " << endl;
    cout << " ##       ### ###  ##   ##   ## ##   ##   ##  ##   ##   ## ##   ##  ##   ##   ## " << endl;
    cout << " ##       #######  ##   ##  ##   ##  ##   ##  ##       ##   ##  ##   ##  ##   ## " << endl;
    cout << " #####    ## # ##  ######   ##   ##  ##   ##  ##       ##   ##  ##   ##  ##   ## " << endl;
    cout << " ##       ##   ##  ##   ##  #######  ##   ##  ##       #######  ##   ##  ##   ## " << endl;
    cout << " ##       ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  ##  ##   ##   ## " << endl;
    cout << " #######  ##   ##  #####    ##   ##   #####    #####   ##   ##  #####     #####  " << endl;
    cout << endl;
    cout << "================================================================================" << endl;
    cout << endl;
    cout << "\t  Antes de comenzar deben registrar sus nombres:  " << endl;
    cout << "\t                                                  " << endl;
    cout << "\t  Nombre del Jugador 1: ";
    cin >> nombre1;
    cout << "\t  Nombre del Jugador 2: ";
    cin >> nombre2;
    cout << endl;

    do
    {
        cout << "\t  Confirmar nombres (S/N): ";
        cin >> opcion;
        cout << endl;
        //SI INGRESA QUE NO PREGUNTA CUAL CAMBIAR A FINDE NO CARGAR NUEVAMENTE LOS 2
        if (opcion == 'N' || opcion == 'n')
        {
            cout << "\tIngrese el numero de Jugador que desea cambiar: ";

            cin >> cambioNombre;
            cout << endl;
            if (cambioNombre == 1)
            {
                cout << "\tNombre del Jugador 1: ";
                cin >> nombre1;
            }
            else if (cambioNombre == 2)
            {
                cout << "================================================================================" << endl;

                cout << "\t\tNombre del Jugador 2: ";
                cin >> nombre2;
            }
            cout << endl;
            cout << "================================================================================" << endl;
            cout << "\tConfirmar nombres (S/N): ";
            cin >> opcion;
        }
        else
        {
            //SI INGRESA CUALQUIER OTRO CARACTER DISTINTO DE (S/N) REPITE EL MENSAJE
            cout << endl;
            cout << "\t ----------------------------------------------   " << endl;
            cout << "\t -------INGRESE UNA OPCION VALIDA (S/N):-------   " << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }
    } while (opcion != 'S' && opcion != 's');
    system("cls");
}



//FUNCIONES PARA CREAR MAZOS
void crearMazos(string mazoNaipe[], string mazoPalo[])
{
    crearMazoNaipe(mazoNaipe);
    crearMazoPalo(mazoPalo);
}

void crearMazoNaipe(string mazoNaipe[])
{
    int cont = 0;

    string vNaipes[] = { "10","J","Q","K","A" };

    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            mazoNaipe[cont] = vNaipes[i];

            cont++;
        }
    }
}

void crearMazoPalo(string mazoPalo[])
{
    int cont = 0;

    string vPalo[] = { "Corazon","Diamante","Pica","Trebol" };

    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            mazoPalo[cont] = vPalo[j];
            cont++;
        }
    }
}


//FUNCION REPARTE CARTAS AMBOS JUGADORES
void repartirCartasJugador(string mazoNaipe[], string mazoPalo[], string naipesJugador[], string palosJugador[])
{
    int contadorCartas = 0;

    int num1, num2 = 1;

    while (contadorCartas < 5)
    {
        num1 = 1 + (rand() % (20 - contadorCartas));
        //genera un numero random del 1 al 20 lo almacena en num1 y le resto contadorCartas que se van poniendo en cero

        if (num1 != num2 && (mazoNaipe[num1] != "Cero"))
        {
            //pregunto si son distintos num1 y num2 Y si lo que hay guardado en mazoNaipe[num1] es distinto de "Cero".
            // si es verdadero almacena el palo y el naipe en su respectivo vector, si es falso no hace nada y genera numero nuevo.
            // num2 lo inicialize en 1
            num2 = num1;
            naipesJugador[contadorCartas] = mazoNaipe[num1];
            palosJugador[contadorCartas] = mazoPalo[num1];
            contadorCartas++; //incrementa contador para las 5 cartas
        }
        mazoNaipe[num1] = "Cero";
        //En el indice num1 del vector mazoNaipe guardamos el string "Cero", porque esa es una carta que ya se entrego, para que no se repita le ponemos el valor "Cero"
    }

}


//FUNCION MUETRA CARTA JUGADORES
void mostrarNombresJugadores(string nombreJugador1, string nombreJugador2, int& acuJ1, int& acuJ2)
{


    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Jugador 1:" << nombreJugador1 << " (" << acuJ1 << " puntos) \t\t  " << "Jugador 2:" << nombreJugador2 << " (" << acuJ2 << " puntos)" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;

}



//FUNCION GENERA CARTA EMBAUCADORA
void generarEmbaucadora(string& cartaEmbaucadora)
{
    string vPalo[] = { "Corazon","Diamante","Pica","Trebol" };

    cartaEmbaucadora = vPalo[(rand() % 4)];
}



//FUNCION MUETRA CARTA JUGADORES
void mostrarCartasjugadores(string naipesJugador1[], string palosJugador1[], int puntosJugador1[], string naipesJugador2[], string palosJugador2[], int puntosJugador2[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << " " << puntosJugador1[i] << "\t " << naipesJugador1[i] << " de " << palosJugador1[i] << "\t\t\t" << " " << puntosJugador2[i] << "\t" << naipesJugador2[i] << " de " << palosJugador2[i] << endl;
    }
}


//FUNCION CALCULA LOS PUNTOS TENIENDO EN CUENTA LA CARTA EMBAUCADORA
void puntosPorJugador(string naipeJugador[], string paloJugador[], int puntosJugador[], int cantCartas, string& cartaEmbaucadora)
{
    int x;

    for (x = 0; x < 5; x++)
    {
        if (paloJugador[x] == cartaEmbaucadora)
        {
            puntosJugador[x] = 0;
        }
        else if (naipeJugador[x] == "10")
        {
            puntosJugador[x] = 10;
        }
        else if (naipeJugador[x] == "J")
        {
            puntosJugador[x] = 11;
        }
        else if (naipeJugador[x] == "Q")
        {
            puntosJugador[x] = 12;
        }
        else if (naipeJugador[x] == "K")
        {
            puntosJugador[x] = 15;
        }
        else if (naipeJugador[x] == "A")
        {
            puntosJugador[x] = 20;
        }
    }
}


//FUNCION MUESTRA CREDITOS
void creditos()
{
    cout << " ## ##   ### ##   ##  ###  ### ##    ## ##            ## ##    ###### " << endl;
    cout << "##   ##   ##  ##  ##   ##   ##  ##  ##   ##           ##  ##   ##     " << endl;
    cout << "##        ##  ##  ##   ##   ##  ##  ##   ##               ##   ## ##  " << endl;
    cout << "##  ###   ## ##   ##   ##   ##  ##  ##   ##              ##        ## " << endl;
    cout << "##   ##   ## ##   ##   ##   ## ##   ##   ##             ##     ##  ## " << endl;
    cout << "##   ##   ##  ##  ##   ##   ##      ##   ##            #   ##  ##  ## " << endl;
    cout << " ## ##   #### ##   ## ##   ####      ## ##            ######     ###  " << endl;
    cout << endl;
    cout << "+:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::+" << endl;
    cout << "\t\t\t     INTEGRANTES:" << endl;
    cout << "+:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::+" << endl;
    cout << endl;
    cout << "Legajo     Apellido y Nombre:" << endl;
    cout << endl;
    cout << "29680      Aquino, Karen " << endl;
    cout << "30901      Benitez, Jorge Ezequiel" << endl;
    cout << "29822      Martin, Matias" << endl;
    cout << "30482      Morales, Juan Pablo" << endl;
    cout << endl;
}

//FUNCION GENERA NUEVA EMBAUCADORA Y SACRIFICA 20 PUNTOS
void mostrarCambioEmbaucadora(int& i, string& cartaEmbaucadora, int totalPuntoRondaJugador[], int& acuJ)
{
    SetConsoleTextAttribute(hConsole, 4);
    generarEmbaucadora(cartaEmbaucadora);
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Nueva Carta Embaucadora: " << cartaEmbaucadora << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Puntos Acumulados: " << (totalPuntoRondaJugador[i - 1] - 20) << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;

    totalPuntoRondaJugador[i - 1] = (totalPuntoRondaJugador[i - 1] - 20);
    acuJ -= 20;

    SetConsoleTextAttribute(hConsole, 15);

}


//FUNCION CALCULA LOS PUNTOS TOTALES DE LAS PARTIDAS
void calcularPuntos(int& i, int totalPuntoRondaJugador1[], int puntosJugador1[], int& acuJ1, string& nombreJugador1, int totalPuntoRondaJugador2[], int puntosJugador2[], int& acuJ2, string& nombreJugador2)
{
    for (int j = 0; j < 5; j++)
    {
        totalPuntoRondaJugador1[i] += puntosJugador1[j];
        totalPuntoRondaJugador2[i] += puntosJugador2[j];
    }
    acuJ1 += totalPuntoRondaJugador1[i];
    acuJ2 += totalPuntoRondaJugador2[i];

    cout << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "JUGADOR 1 " << nombreJugador1 << "                           " << "JUGADOR 2" << nombreJugador2 << endl;
    cout << "Puntos: " << totalPuntoRondaJugador1[i] << "                                " << "Puntos: " << totalPuntoRondaJugador2[i] << endl;
    cout << endl;
    cout << "=========================================================================" << endl;
    cout << endl;
    cout << endl;
}


//FUNCION MUETRA RESUMAN DE PUNTOS POR PARTIDA Y EL TOTAL
void resumenPartida(string& nombreJugador1, string& nombreJugador2, int totalPuntoRondaJugador1[], int totalPuntoRondaJugador2[], int acuJ1, int acuJ2)
{
    SetConsoleTextAttribute(hConsole, 9);
    cout << " #######  ##   ##  #####      ###    ##   ##   #####     ###    #####     #####  " << endl;
    cout << " ##       ### ###  ##   ##   ## ##   ##   ##  ##   ##   ## ##   ##  ##   ##   ## " << endl;
    cout << " ##       #######  ##   ##  ##   ##  ##   ##  ##       ##   ##  ##   ##  ##   ## " << endl;
    cout << " #####    ## # ##  ######   ##   ##  ##   ##  ##       ##   ##  ##   ##  ##   ## " << endl;
    cout << " ##       ##   ##  ##   ##  #######  ##   ##  ##       #######  ##   ##  ##   ## " << endl;
    cout << " ##       ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  ##  ##   ##   ## " << endl;
    cout << " #######  ##   ##  #####    ##   ##   #####    #####   ##   ##  #####     #####  " << endl;
    cout << endl;
    cout << "\t\t\t RESUMEN DE PARTIDA: " << endl;
    cout << "+::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::+" << endl;
    cout << endl;
    cout << " \t\t\t" << nombreJugador1 << " VS " << nombreJugador2 << endl;
    cout << endl;
    cout << "RONDA 1: \t\t " << totalPuntoRondaJugador1[0] << " \t " << totalPuntoRondaJugador2[0] << endl;

    cout << "RONDA 2: \t\t " << totalPuntoRondaJugador1[1] << " \t " << totalPuntoRondaJugador2[1] << endl;

    cout << "RONDA 3: \t\t " << totalPuntoRondaJugador1[2] << " \t " << totalPuntoRondaJugador2[2] << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "TOTAL:   \t\t " << acuJ1 << " \t " << acuJ2 << endl;

    cout << "+::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::+" << endl;
}


//FUNCION MUESTRA GANADOR DE LA PARTIDA
void mostrarGanador(int& acuJ1, int& acuJ2, string& nombreJugador1, string& nombreJugador2, int totalPuntoRondaJugador1[], int totalPuntoRondaJugador2[], string& nombreJugadorPuntajeMax, int& puntajeMax)
{
    int rondaMaximaJ1;
    int rondaMaximaJ2;

    if (acuJ1 > acuJ2)
    {
        cout << "+------------------------------------------------------------------------------+" << endl;
        cout << "\t\t�GANADOR: " << nombreJugador1 << " CON " << acuJ1 << " PUNTOS!" << endl;
        cout << "+------------------------------------------------------------------------------+" << endl;

        if (acuJ1 > puntajeMax)
        {
            nombreJugadorPuntajeMax = nombreJugador1;
            puntajeMax = acuJ1;
        }
    }
    else if (acuJ2 > acuJ1)
    {
        cout << "+-------------------------------------------------------------------------------+" << endl;
        cout << "\t\t�GANADOR: " << nombreJugador2 << " CON " << acuJ2 << " PUNTOS!" << endl;
        cout << "+-------------------------------------------------------------------------------+" << endl;

        if (acuJ2 > puntajeMax)
        {
            nombreJugadorPuntajeMax = nombreJugador2;
            puntajeMax = acuJ2;
        }
    }

    else if (acuJ1 == acuJ2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                rondaMaximaJ1 = totalPuntoRondaJugador1[i];
                rondaMaximaJ2 = totalPuntoRondaJugador2[i];
            }
            if (rondaMaximaJ1 > totalPuntoRondaJugador1[i])
            {
                rondaMaximaJ1 = totalPuntoRondaJugador1[i];
            }
            if (rondaMaximaJ2 > totalPuntoRondaJugador2[i])
            {
                rondaMaximaJ2 = totalPuntoRondaJugador2[i];
            }
        }

        if (rondaMaximaJ1 > rondaMaximaJ2)
        {
            cout << "+-------------------------------------------------------------------------------+" << endl;
            cout << "\t\t�GANADOR: " << nombreJugador1 << " OBTUVISTE EL MAYOR PUNTAJE EN UNA RONDA!" << endl;
            cout << "+-------------------------------------------------------------------------------+" << endl;

            if (acuJ1 > puntajeMax)
            {
                nombreJugadorPuntajeMax = nombreJugador1;
                puntajeMax = acuJ1;
            }
        }
        else if (rondaMaximaJ2 > rondaMaximaJ1)
        {
            cout << "+-------------------------------------------------------------------------------+" << endl;
            cout << "\t\t�GANADOR: " << nombreJugador2 << " OBTUVISTE EL MAYOR PUNTAJE EN UNA RONDA!" << endl;
            cout << "+-------------------------------------------------------------------------------+" << endl;

            if (acuJ2 > puntajeMax)
            {
                nombreJugadorPuntajeMax = nombreJugador2;
                puntajeMax = acuJ2;
            }
        }
        else
        {
            cout << "+-------------------------------------------------------------------------------+" << endl;
            cout << "\t\t�EMPATE: " << nombreJugador1 << " Y " << nombreJugador2 << endl;
            cout << "\t\tOBTUVIERON EL MISMO PUNTAJE TOTAL Y MISMO PUNTAJE M�XIMO EN RONDAS." << endl;
            cout << "+-------------------------------------------------------------------------------+" << endl;
        }

    }
    SetConsoleTextAttribute(hConsole, 15);
}


//FUNCION MUESTRA JUGADOR CON PUNTAJE MAXIMO Y LO ALMACENA
void estadisticas(string& nombreJugadorPuntajeMax, int& puntajeMax, int partidas)
{
    cout << endl;
    cout << " #######  ##   ##  #####      ###    ##   ##   #####     ###    #####     #####  " << endl;
    cout << " ##       ### ###  ##   ##   ## ##   ##   ##  ##   ##   ## ##   ##  ##   ##   ## " << endl;
    cout << " ##       #######  ##   ##  ##   ##  ##   ##  ##       ##   ##  ##   ##  ##   ## " << endl;
    cout << " #####    ## # ##  ######   ##   ##  ##   ##  ##       ##   ##  ##   ##  ##   ## " << endl;
    cout << " ##       ##   ##  ##   ##  #######  ##   ##  ##       #######  ##   ##  ##   ## " << endl;
    cout << " ##       ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  ##   ##  ##  ##   ##   ## " << endl;
    cout << " #######  ##   ##  #####    ##   ##   #####    #####   ##   ##  #####     #####  " << endl;
    cout << endl;
    cout << "+:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::+" << endl;
    cout << "\t\t\t\t MEJOR PUNTAJE \t\t\t" << endl;
    cout << "+:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::+" << endl;
    cout << endl;

    if (partidas == 0)
    {
        cout << "JUEGUE AL MENOS UNA PARTIDA PARA ACTUALIZAR LAS ESTAD�STICAS ... " << endl;
    }
    else
    {
        cout << "\t\t\t JUGADOR: " << nombreJugadorPuntajeMax << " CON " << puntajeMax << " PUNTOS!" << endl;
    }
    cout << endl;
}
