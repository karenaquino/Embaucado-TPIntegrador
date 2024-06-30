#include <iostream>
#include <string>
#include "funciones.h"
#include<cstdlib>
#include<ctime>
#include <windows.h>
#include <locale.h>
using namespace std;

/*
    1-)menu
        EMBAUCADO
---------------------
1 - JUGAR
2 - ESTADÍSTICAS
3 - CRÉDITOS
---------------------
0 - SALIR
while


  2-) Repartir
  10, J, Q, K y A de las cuatro figuras Corazón, Diamantes, Picas y Tréboles.
  En total son 20 cartas.
  En cada ronda los jugadores reciben cinco cartas al azar que se denominan mano.

  2-)Además, se da vuelta sobre la mesa una carta de las figuras.
 Esta carta se denomina embaucadora y es la que da nombre al juego.
 ejemplo: Carta embaucadora: Corazón

  3-)Calcular Puntaje


     Naipe	Puntaje
        10	10
        J	11
        Q	12
        K	15
        A	20

   4-)a partir de la ronda 2 que permite a los jugadores sacrificar 20 puntos de los acumulados para poder
    cambiar la carta embaucadora
    . Luego de haber recibido las cartas y que se haya revelado cuál es la carta embaucadora de la ronda,
    cada jugador puede decidir sacrificar 20 puntos para que la carta embaucadora se vuelva a obtener.
    Si un jugador en una ronda utiliza este sacrificio de puntos entonces el otro jugador no puede utilizarlo.
    Sólo pueden hacerlo si disponen de al menos 20 puntos para restar.
    En la ronda 2, es el jugador 1 quien puede acceder a sacrificar puntos primero y si no lo hace, puede hacerlo el jugador 2.
    En la ronda 3, es el jugador 2 quien puede acceder a sacrificar puntos primero y si no lo hace, puede hacerlo el jugador 1.

*/

//El símbolo & de ampersand se utiliza en C++ como declarador de referencia además de ser el operador de dirección.
int main()
{
    const int TAM = 20;
    int numero;
    int ronda = 0;
    setlocale(LC_ALL, "SPANISH");

    const int cantCartas = 5;
    string cartaEmbaucadora;

    string mazoNaipe[TAM] = {};
    string mazoPalo[TAM] = {};

    string naipesJugador1[cantCartas] = {};
    string naipesJugador2[cantCartas] = {};

    string palosJugador1[cantCartas] = {};
    string palosJugador2[cantCartas] = {};

    int puntosJugador1[cantCartas] = {};
    int puntosJugador2[cantCartas] = {};

    char confirmaEmbaucadora;

    /* string vJugador1[cantCartas] = {};
     string vJugador2[cantCartas] = {};*/

    int totalPuntoRondaJugador1[3]={};
    int totalPuntoRondaJugador2[3]={};

    int acuJ1 = 0;
    int acuJ2 = 0;
    srand(time(0));//semilla para numero random

    string nombreJugador1, nombreJugador2;

    mostrarMenuPrincipal();
    cin >> numero;
    cout << endl;
    cout << endl;
    cout << endl;
    system("cls");

    if (numero == 1 && ronda == 0)
    {

        ronda++;

        /// carga de jugadores
        cout << endl;

        cargarJugadores(nombreJugador1, nombreJugador2);

        cout << endl;
        cout << endl;

        for (size_t i = 0; i <=2 ; i++)
        {
            //crear mazos
            crearMazos(mazoNaipe, mazoPalo);
            //cartas jugador 1
            cout << "---------------------------------------------------------------   " << endl;
            cout << "Ronda N:" << ronda << endl;
            cout << endl;

            repartirCartasJugador(mazoNaipe, mazoPalo, naipesJugador1, palosJugador1);

            repartirCartasJugador(mazoNaipe, mazoPalo, naipesJugador2, palosJugador2);

            mostrarNombresJugadores(nombreJugador1, nombreJugador2);

            //genera cartaEmbaucadora
            generarEmbaucadora(cartaEmbaucadora);

            puntosPorJugador(naipesJugador1, palosJugador1, puntosJugador1, cantCartas, cartaEmbaucadora);
            puntosPorJugador(naipesJugador2, palosJugador2, puntosJugador2, cantCartas, cartaEmbaucadora);

            mostrarCartasjugadores(naipesJugador1, palosJugador1, puntosJugador1,
                                   naipesJugador2, palosJugador2, puntosJugador2);
            //cartasjugadores(vJugador1, vJugador2, cantCartas, nombreJugador1, nombreJugador2);


            //muestra carta Embaucadora
            cout << "---------------------------------------------------------------   " << endl;
            cout << endl;
            cout << "Carta Embaucadora:" << cartaEmbaucadora << endl;
            cout << endl;
            cout << "---------------------------------------------------------------" << endl;
            //---------------------------------------------------------------------------//
           

           
            for (int j = 0; j < 5; j++)
            {
                totalPuntoRondaJugador1 [i] += puntosJugador1[j];
            }
             acuJ1 += totalPuntoRondaJugador1 [i];
            cout << "JUGADOR " << nombreJugador1 << endl;
            cout << "Puntos: " << totalPuntoRondaJugador1 [i] << endl;
            cout << "---------------- " << endl;

            cout << "JUGADOR " << nombreJugador2 << endl;
            for (int j = 0; j < 5; j++)
            {
                totalPuntoRondaJugador2 [i] += puntosJugador2[j];
            }
            acuJ2 += totalPuntoRondaJugador2 [i];
            cout <<" Puntos: " << totalPuntoRondaJugador2 [i] << endl;

            //RONDA 2
            //PREGUNTAMOS SI EL JUGADOR 1 TIENE UN PUNTAJE DE 20 O MAS
            if (i == 1 && acuJ1 >= 20)
            {   
                //RONDA 2, 
                // SE LE PREGUNTA PRIMERO AL JUGADOR 1 SI QUIERE CAMBIAR LA EMBAUCADORA
                cout << nombreJugador1 << ", ¿Deseas modificar la carta embaucadora actual? Se te descontarán 20 puntos (S/N): ";
                cin >> confirmaEmbaucadora;
                
                //PUEDE RESPONDER SI
                if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                {
                    mostrarCambioEmbaucadora(cartaEmbaucadora, acuJ1);
                }
               
                //PUEDE RESPONDER NO
                else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                {   
                    //SI EL JUGADOR 1, RESPONDE QUE NO, SE PROCEDE A PREGUNTARLE AL JUGADOR 2
                    //PARA ESO DEBE CUMPLIR CON LA CONDICIÓN PUNTAJE>=20
                    if (acuJ2 >= 20)
                    {
                        cout << nombreJugador2 << ", ¿Deseas modificar la carta embaucadora actual? Se te descontarán 20 puntos (S/N): ";
                        cin >> confirmaEmbaucadora;
                        
                        //JUGADOR 2, PUEDE RESPONDER QUE SI
                        if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                        {
                            mostrarCambioEmbaucadora(cartaEmbaucadora, acuJ2);
                        }
                        
                        //JUGADOR 2, PUEDE RESPONDER QUE NO
                        else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                        {
                            cout << "No se modificó la carta Embaucadora, a continuación se calcularán los puntos de la ronda..." << endl;
                            //CALCULAR PUNTAJES DE LA RONDA...
                        }

                    }

                    
                }

            }

            else if (i == 1 && acuJ2 >= 20)
            {
                cout << nombreJugador1 << ", no tenes los puntos necesarios para cambiar la carta Embaucadora." << endl;
                cout << nombreJugador2 << ", ¿Deseas modificar la carta embaucadora actual? Se te descontarán 20 puntos (S/N): ";
                cin >> confirmaEmbaucadora;
                if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                {
                    mostrarCambioEmbaucadora(cartaEmbaucadora, acuJ2);
                }
                else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                {
                    cout << "No se modificó la carta Embaucadora, a continuación se calcularán los puntos de la ronda..." << endl;
                }
            }

            else if (i == 1 && acuJ1 < 20 && acuJ2 < 20)
            {
                cout << nombreJugador1 << ", " << nombreJugador2 << ", no tienen los puntos necesarios para cambiar la carta Embaucadora." << endl;
                cout << "A continuación se calcularán los puntos de la ronda ..." << endl;
            }

            if (i == 2 && acuJ2 >= 20)
            {
                cout << nombreJugador2 << ", ¿Deseas modificar la carta embaucadora actual? Se te descontarán 20 puntos (S/N): ";
                cin >> confirmaEmbaucadora;
                if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                {
                    mostrarCambioEmbaucadora(cartaEmbaucadora, acuJ2);
                }
                else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                {
                    if (acuJ1 >= 20)
                    {
                        cout << nombreJugador1 << ", ¿Deseas modificar la carta embaucadora actual? Se te descontarán 20 puntos (S/N): ";
                        cin >> confirmaEmbaucadora;
                        if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                        {
                            mostrarCambioEmbaucadora(cartaEmbaucadora, acuJ1);
                        }
                        else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                        {
                            cout << "No se modificó la carta Embaucadora, a continuación se calcularán los puntos de la ronda..." << endl;
                        }

                    }
                    else
                    {
                        cout << nombreJugador1 << ", no tenes los puntos necesarios para cambiar la carta Embaucadora." << endl;
                        cout << "No se modificó la carta Embaucadora, a continuación se calcularán los puntos de la ronda..." << endl;
                        cout << endl;
                    }
                }

            }
            else if (i == 2 && acuJ1 >= 20)
            {
                cout << nombreJugador2 << ", no tenes los puntos necesarios para cambiar la carta Embaucadora." << endl << endl;
                cout << nombreJugador1 << ", ¿Deseas modificar la carta embaucadora actual? Se te descontarán 20 puntos (S/N): ";
                cin >> confirmaEmbaucadora;
                if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                {
                    mostrarCambioEmbaucadora(cartaEmbaucadora, acuJ1);
                }
                else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                {
                    cout << "No se modificó la carta Embaucadora, a continuación se calcularán los puntos de la ronda..." << endl;
                }
            }
            else if (i == 2 && acuJ2 < 20 && acuJ1 < 20)
            {
                cout << nombreJugador2 << ", " << nombreJugador1 << ", no tienen los puntos necesarios para cambiar la carta Embaucadora." << endl;
                cout << "A continuación se calcularán los puntos de la ronda ..." << endl;
            }

            system("pause");
            system("cls");


           
            ronda++;
        }

        resumenPartida(nombreJugador1,nombreJugador2,totalPuntoRondaJugador1,totalPuntoRondaJugador2);
        mostrarGanador(acuJ1,acuJ2,nombreJugador1,nombreJugador2,totalPuntoRondaJugador1,totalPuntoRondaJugador2);


    }

 //falta agregar la estadistica



 //Menu de creditos
    if (numero == 3)
    {

        creditos();
        system("pause");
        system("cls");
    }

}













