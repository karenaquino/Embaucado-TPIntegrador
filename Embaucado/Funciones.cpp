#include <iostream>
#include <string>
#include "funciones.h"
#include<cstdlib>
#include<ctime>
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

void mostrarMenuPrincipal() {
    cout << endl;
    cout << endl;
    cout << "\t\t ======================================" << endl;
    cout << "\t\t=|             EMBAUCADO              |=" << endl;
    cout << "\t\t=|        ---------------------       |=" << endl;
    cout << "\t\t=|             1 - JUGAR              |=" << endl;
    cout << "\t\t=|             2 - ESTADÍSTICAS       |=" << endl;
    cout << "\t\t=|             3 - CRÉDITOS           |=" << endl;
    cout << "\t\t=|        ---------------------       |=" << endl;
    cout << "\t\t=|             0 - SALIR              |=" << endl;
    cout << "\t\t=|                                    |=" << endl;
    cout << "\t\t ======================================" << endl;
    cout << endl;
    cout << "\t\t    Jugadores Ingresen una Opcion: ";
}
void cargarJugadores(string& nombre1, string& nombre2) {

    char opcion;
    int cambioNombre;
    cout << "\t\t ----------------------------------------------   " << endl;
    cout << "\t\t  Antes de comenzar deben registrar sus nombres:  " << endl;
    cout << "\t\t                                                  " << endl;
    cout << "\t\t  Nombre del Jugador 1: ";cin >> nombre1;
    cout << "\t\t  Nombre del Jugador 2: ";cin >> nombre2;  cout << endl;




    do {
        cout << "\t\t  Confirmar nombres (S/N): ";
        cin >> opcion; cout << endl;


        if (opcion == 'N' || opcion == 'n') {
            cout << "\t\tIngrese el numero de Jugador que desea cambiar: ";

            cin >> cambioNombre;
            cout << endl;
            if (cambioNombre == 1) {

                cout << "\t\tNombre del Jugador 1:";
                cin >> nombre1;
            }
            else if (cambioNombre == 2) {
                cout << "\t\t ----------------------------------------------   " << endl;

                cout << "\t\tNombre del Jugador 2:";
                cin >> nombre2;
            }
            cout << endl;
            cout << "\t\t ----------------------------------------------   " << endl;
            cout << "\t\tConfirmar nombres (S/N):";
            cin >> opcion;
        }
        else {

            cout << endl;
            cout << "\t\t ----------------------------------------------   " << endl;
            cout << "\t\t -------INGRESE UNA OPCION VALIDA (S/N):-------   " << endl;
            cout << endl;
            cout << endl;
            cout << endl;
        }
    } while (opcion != 'S' && opcion != 's');
    system("cls");
}


void crearMazos(string mazoNaipe[], string mazoPalo[]) {
    crearMazoNaipe(mazoNaipe);
    crearMazoPalo(mazoPalo);
}
void crearMazoNaipe(string mazoNaipe[]) {

    int cont = 0;

    string vNaipes[] = { "10","J","Q","K","A" };

    for (int i = 0;i <= 4;i++) {
        for (int j = 0;j <= 3;j++) {
            mazoNaipe[cont] = vNaipes[i];

            cont++;
        }
    }
}
void crearMazoPalo(string mazoPalo[]) {
    int cont = 0;

    string vPalo[] = { "Corazon","Diamante","Pica","Trebol" };

    for (int i = 0;i <= 4;i++) {
        for (int j = 0;j <= 3;j++) {
            mazoPalo[cont] = vPalo[j];
            cont++;
        }
    }
}

void repartirCartasJugador(string mazoNaipe[],
                           string mazoPalo[],
                           string naipesJugador[],
                           string palosJugador[])
{
    int contadorCartas = 0;

    int num1, num2 = 1;

    while (contadorCartas < 5) {


        num1 = 1 + (rand() % (20 - contadorCartas));
        //genera un numero random del 1 al 20 lo almacena en num1 y le resto contadorCartas que se van poniendo en cero

        if (num1 != num2 && (mazoNaipe[num1] != "Cero")) {
            //pregunto si son distintos num1 y num2 Y si lo que hay guardado en mazoNaipe[num1] es distinto de "Cero".
            // si es verdadero almacena el palo y el naipe en su respectivo vector, si es falso no hace nada y genera numero nuevo.
            // num2 lo inicialize en 1
            num2 = num1;
            //  cout<<num2<<"----2--"<<endl;

            naipesJugador[contadorCartas] = mazoNaipe[num1];
            palosJugador[contadorCartas] = mazoPalo[num1];

            //vJugador1[k]=vMazo[num1];

            contadorCartas++; //incrementa contador para las 5 cartas
        }
        mazoNaipe[num1] = "Cero";
        //En el indice num1 del vector mazoNaipe guardamos el string "Cero", porque esa es una carta que ya se entrego, para que no se repita le ponemos el valor "Cero"
    }

}

//reparte cartas jugador 1

void repartirCartasJugador1(string vJugador1[], int cantCartas, string vMazo[], int TAM) {
    int k = 0;
    int num1, num2 = 1;
    while (k < 5) {


        num1 = 1 + (rand() % (20 - k));//genera un numero random del 1 al 20 lo almacena en num1 y
        // le resto k que se van poniendo en cero

        if (num1 != num2 && vMazo[num1] != "Cero") {//evaluo si son iguales num2 lo inicialize en 1 si son distintos almacena sino no hace nada y genera numero nuevo
            num2 = num1;
            //  cout<<num2<<"----2--"<<endl;
            vJugador1[k] = vMazo[num1];

            k++; //incrementa contador para las 5 cartas
        }
        vMazo[num1] = "Cero";//se reescribe el vector del mazo con las cartas entregadas al jugador 1 para que no le toquen las mismas al jugador2
    }
}

//reparte cartas jugador 2

void repartirCartasJugador2(string vJugador2[], int cantCartas, string vMazo[], int TAM) {
    int num3, num4 = 1;

    int l = 0;
    while (l < 5) {
        num3 = 1 + (rand() % 15);//genera un numero random del 1 al 15 ya que repartio 5 lo almacena en num3

        if (num3 != num4 && vMazo[num3] != "Cero") {//evaluo si son iguales num4 lo inicialize en 1
            //si son distintos almacena sino no hace nada y genera numero nuevo

            num4 = num3;

            vJugador2[l] = vMazo[num3];

            l++; //incrementa contador para las 5 cartas
        }
        vMazo[num3] = "Cero";//se reescribe el vector del mazo con las cartas entregadas al jugador 2 para que no le toquen las mismas
    }

}
//mostrar cartas jugador 1

//mostrar cartas jugador 2

//Genera carta Embaucadora
void generarEmbaucadora(string& cartaEmbaucadora) {

    string vPalo[] = { "Corazon","Diamante","Pica","Trebol" };

    cartaEmbaucadora = vPalo[(rand() % 4)];


}
void cartasjugadores(string vJugador1[], string vJugador2[], int cantCartas, string& nombreJugador1, string& nombreJugador2) {

    int z;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Jugador 1:" << nombreJugador1 << " \t\t  " << "Jugador 2:" << nombreJugador2 << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;

    for (z = 0;z < 5;z++) {

        cout << "\t" << vJugador1[z] << " \t\t\t " << vJugador2[z] << endl;
    }
}
void mostrarNombresJugadores(string nombreJugador1, string nombreJugador2, int &acuJ1, int &acuJ2) {

    cout << "---------------------------------------------------------------" << endl;
    cout << "Jugador 1:" << nombreJugador1 << " (" << acuJ1 << " puntos) \t\t  " << "Jugador 2:" << nombreJugador2 << " (" << acuJ2 << " puntos)" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;

}

void mostrarCartasjugadores(string naipesJugador1[], string palosJugador1[], int puntosJugador1[],
                             string naipesJugador2[], string palosJugador2[], int puntosJugador2[] ) {

    for (int i = 0;i < 5;i++) {

        cout << " " << puntosJugador1[i] << "\t " << naipesJugador1[i] << " de " << palosJugador1[i] << "\t\t" << " " << puntosJugador2[i] << "\t" << naipesJugador2[i] << " de " << palosJugador2[i] << endl;
    }
}
void puntosPorJugador(string naipeJugador[], string paloJugador[], int puntosJugador[], int cantCartas, string& cartaEmbaucadora) {

    int x;

    for (x = 0;x < 5;x++) {

        if (paloJugador[x] == cartaEmbaucadora) {

            puntosJugador[x] = 0;

        }
        else if (naipeJugador[x] == "10") {
            puntosJugador[x] = 10;
        }
        else if (naipeJugador[x] == "J") {
            puntosJugador[x] = 11;
        }
        else if (naipeJugador[x] == "Q") {
            puntosJugador[x] = 12;
        }
        else if (naipeJugador[x] == "K") {
            puntosJugador[x] = 15;
        }
        else if (naipeJugador[x] == "A") {
            puntosJugador[x] = 20;
        }


    }


}




//Opcion 3 creditos
void creditos()
{

    cout << "Grupo: 25" << endl << endl;
    cout << "Integrantes:" << endl;
    cout << "Legajo     Apellido y Nombre:" << endl;
    cout << "29680      Aquino, Karen " << endl;
    cout << "30901      Benitez, Jorge Ezequiel" << endl;
    cout << "29822      Martin, Matias" << endl;
    cout << "30489      Morales, Juan Pablo" << endl;
}

void mostrarCambioEmbaucadora(string cartaEmbaucadora, int &acuJ) {
   SetConsoleTextAttribute(hConsole, 4);
    generarEmbaucadora(cartaEmbaucadora);
    cout << "---------------------------------------------------------------   " << endl;
    cout << "Nueva Carta Embaucadora: " << cartaEmbaucadora << endl;
    cout << "---------------------------------------------------------------   " << endl;
   SetConsoleTextAttribute(hConsole, 15);
    acuJ -= 20;
}

void resumenPartida(string &nombreJugador1, string &nombreJugador2, int totalPuntoRondaJugador1[], int totalPuntoRondaJugador2[])
{
 SetConsoleTextAttribute(hConsole, 9);
 cout << "\t\t RESUMEN DE PARTIDA: " << endl;
 cout << "+:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
 cout << endl;
 cout << " \t\t" << nombreJugador1 << " VS " << nombreJugador2 << endl;
 cout << "RONDA 1: \t " << totalPuntoRondaJugador1 [0] << " \t " << totalPuntoRondaJugador2 [0] << endl;
 cout << "RONDA 2: \t " << totalPuntoRondaJugador1 [1] << " \t " << totalPuntoRondaJugador2 [1] << endl;
 cout << "RONDA 3: \t " << totalPuntoRondaJugador1 [2] << " \t " << totalPuntoRondaJugador2 [2] << endl;
 cout << endl;
 cout << "+:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
}

void mostrarGanador(int &acuJ1, int &acuJ2, string &nombreJugador1, string &nombreJugador2, int totalPuntoRondaJugador1[], int totalPuntoRondaJugador2[])
{
    int rondaMaximaJ1;
    int rondaMaximaJ2;

    if (acuJ1 > acuJ2)
    {
        cout << "+----------------------------------------------------------------------+" << endl;
        cout << "\t\t¡GANADOR: " << nombreJugador1 << " CON " << acuJ1 << " PUNTOS!" << endl;
        cout << "+----------------------------------------------------------------------+" << endl;
    }
    else if (acuJ2 > acuJ1)
    {
        cout << "+----------------------------------------------------------------------+" << endl;
        cout << "\t\t¡GANADOR: " << nombreJugador2 << " CON " << acuJ2 << " PUNTOS!" << endl;
        cout << "+----------------------------------------------------------------------+" << endl;
    }

    else if (acuJ1 == acuJ2)
    {
        for (int i=0; i<3; i++)
        {
            if (i==0)
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
            cout << "+----------------------------------------------------------------------+" << endl;
            cout << "\t\t¡GANADOR: " << nombreJugador1 << " OBTUVISTE EL MAYOR PUNTAJE EN UNA RONDA!" << endl;
            cout << "+----------------------------------------------------------------------+" << endl;
        }
        else if (rondaMaximaJ2 > rondaMaximaJ1)
        {
            cout << "+----------------------------------------------------------------------+" << endl;
            cout << "\t\t¡GANADOR: " << nombreJugador2 << " OBTUVISTE EL MAYOR PUNTAJE EN UNA RONDA!" << endl;
            cout << "+----------------------------------------------------------------------+" << endl;
        }
        else
        {
            cout << "+----------------------------------------------------------------------+" << endl;
            cout << "\t\t¡EMPATE: " << nombreJugador1 << " Y " << nombreJugador2 << endl;
            cout << "\t\tOBTUVIERON EL MISMO PUNTAJE TOTAL Y MISMO PUNTAJE MÁXIMO EN RONDAS." << endl;
            cout << "+----------------------------------------------------------------------+" << endl;
        }

    }
    SetConsoleTextAttribute(hConsole, 15);
}
