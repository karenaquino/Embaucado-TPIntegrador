#include <iostream>
#include <string>
#include "funciones.h"
#include<cstdlib>
#include<ctime>
#include <windows.h>
#include <locale.h>

using namespace std;

int main()
{
    const int TAM = 20; //TAMA�O DEL VECTOR DE NAIPES ,PALOS
    int numero;

    setlocale(LC_ALL, "SPANISH");

    const int cantCartas = 5;// CANTIDAD DE CARTAS POR JUGADORES
    string cartaEmbaucadora; //ALMACENA CARTA EMBAUCADORA

    string mazoNaipe[TAM] = {};//ALMACENA NAIPES CREADOS EN LA FUNCION CREAR MAZO
    string mazoPalo[TAM] = {};//ALMACENA PALO CREADOS EN LA FUNCION CREAR MAZO

    string naipesJugador1[cantCartas] = {};//ALMACENA LOS NAIPES DEL JUGADOR 1
    string naipesJugador2[cantCartas] = {};//ALMACENA LOS NAIPES DEL JUGADOR 2

    string palosJugador1[cantCartas] = {};//ALMACENA LOS PALOS DE LOS NAIPES DEL JUGADOR 1
    string palosJugador2[cantCartas] = {};//ALMACENA LOS PALOS DE LOS NAIPES DEL JUGADOR 2

    int puntosJugador1[cantCartas] = {};//ALMACENA LOS VALORES DE LAS CARTAS DEL JUGADOR 1
    int puntosJugador2[cantCartas] = {};//ALMACENA LOS VALORES DE LAS CARTAS DEL JUGADOR 2

    char confirmaEmbaucadora;//ALMACENA LA OPCION DE SI CAMBIA O NO LA CARTA EMBAUCADORA




    //VARIABLES PARA ALMACENAR EL MEJOR PUNTAJE PARA LA PARTE DE ESTAD�STICAS
    int puntajeMax=0;
    string nombreJugadorPuntajeMax;
    int partidas = 0;

    srand(time(0));//SEMILLA PARA EL NUMERO RAMDOM

    string nombreJugador1, nombreJugador2;//ALMACENA LOS NOMBRES DE LOS JUGADORES

    while (true) { //WHILE PARA QUE NO SALGA A MENOS QUE SE INGRESE 0
        int acuJ1 = 0;//ACUMULADORES DE LA SUMA DE LOS NAIPES DE CADA JUGADOR
        int acuJ2 = 0;

        int totalPuntoRondaJugador1[3] = {}; //VECTORES QUE GUARDAN LOS PUNTOS OBTENIDOS EN CADA RONDA PARA CADA JUGADOR
        int totalPuntoRondaJugador2[3] = {};

        mostrarMenuPrincipal();
        cin >> numero;//ALMACENA OPCION DEL MENU
        cout << endl;
        cout << endl;

        system("cls");

        switch (numero) {
        case 1:

            cout << endl;
            //SE LLAMA A FUNCION CARGA JUGADORES
            cargarJugadores(nombreJugador1, nombreJugador2);

            cout << endl;
            partidas++; //CONTADOR DE PARTIDAS
            for (int i = 0; i < 3; i++)
            {
                //SE LLAMA A FUNCION CREAR MAZO
                crearMazos(mazoNaipe, mazoPalo);
                //cartas jugador 1



                cout << "     #### ##  ##  #####    ####  #    #  ####   ####  ####    ####    " << endl;
                cout << "     #    # ## #  #    #  #    # #    # #      #    # #    # #    #  " << endl;
                cout << "     #### #    #  #####   # ## # #    # #      # ## # #    # #    #  " << endl;
                cout << "     #    #    #  #    #  #    # #    # #      #    # #    # #    #  " << endl;
                cout << "     #### #    #  #####   #    #  ####   ####  #    # ####    ####   " << endl;


                cout << "=========================================================================" << endl;
                cout << "Ronda N:" << i + 1 << endl;

                //REPARTE CARTAS AMBOS JUGADORES
                repartirCartasJugador(mazoNaipe, mazoPalo, naipesJugador1, palosJugador1);
                repartirCartasJugador(mazoNaipe, mazoPalo, naipesJugador2, palosJugador2);

                //MUESTRA NOMBRES JUGADORS
                mostrarNombresJugadores(nombreJugador1, nombreJugador2, acuJ1, acuJ2);

                //CARTA EMBAUCADORA
                generarEmbaucadora(cartaEmbaucadora);

                //CALCULA PUNTOS POR JUGADOR
                puntosPorJugador(naipesJugador1, palosJugador1, puntosJugador1, cantCartas, cartaEmbaucadora);
                puntosPorJugador(naipesJugador2, palosJugador2, puntosJugador2, cantCartas, cartaEmbaucadora);

                //MUESTRA CARTA DE LOS JUGADORARES
                mostrarCartasjugadores(naipesJugador1, palosJugador1, puntosJugador1, naipesJugador2, palosJugador2, puntosJugador2);

                //MUESTRA CARTA EMBAUCADORA
                cout << endl;
                cout << "-------------------------------------------------------------------------" << endl;
                cout << "Carta Embaucadora: " << cartaEmbaucadora << endl;
                cout << "-------------------------------------------------------------------------" << endl;
                //---------------------------------------------------------------------------//


                if (i == 0)
                {   //CALCULA PUNTOS AMBOS JUGADORES
                    calcularPuntos(i, totalPuntoRondaJugador1, puntosJugador1, acuJ1, nombreJugador1, totalPuntoRondaJugador2, puntosJugador2, acuJ2, nombreJugador2);
                }

                //RONDA 2
                //PREGUNTAMOS SI EL JUGADOR 1 TIENE UN PUNTAJE DE 20 O MAS
                if (i == 1 && acuJ1 >= 20)
                {
                    //RONDA 2,
                    // SE LE PREGUNTA PRIMERO AL JUGADOR 1 SI QUIERE CAMBIAR LA EMBAUCADORA
                    cout << nombreJugador1 << ", �Deseas modificar la carta embaucadora actual?" << endl;
                    cout << "Se te descontar�n 20 puntos (S/N): ";
                    cin >> confirmaEmbaucadora;

                    //PUEDE RESPONDER SI
                    if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                    {
                        mostrarCambioEmbaucadora(i, cartaEmbaucadora, totalPuntoRondaJugador1, acuJ1);
                        puntosPorJugador(naipesJugador1, palosJugador1, puntosJugador1, cantCartas, cartaEmbaucadora);
                        puntosPorJugador(naipesJugador2, palosJugador2, puntosJugador2, cantCartas, cartaEmbaucadora);
                        mostrarCartasjugadores(naipesJugador1, palosJugador1, puntosJugador1, naipesJugador2, palosJugador2, puntosJugador2);
                    }

                    //PUEDE RESPONDER NO
                    else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                    {
                        //SI EL JUGADOR 1, RESPONDE QUE NO, SE PROCEDE A PREGUNTARLE AL JUGADOR 2
                        //PARA ESO DEBE CUMPLIR CON LA CONDICI�N PUNTAJE>=20
                        if (acuJ2 >= 20)
                        {
                            cout << nombreJugador2 << ", �Deseas modificar la carta embaucadora actual?" << endl;
                            cout << "Se te descontar�n 20 puntos (S/N): ";
                            cin >> confirmaEmbaucadora;

                            //JUGADOR 2, PUEDE RESPONDER QUE SI
                            if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                            {
                                mostrarCambioEmbaucadora(i, cartaEmbaucadora, totalPuntoRondaJugador2, acuJ2);
                                puntosPorJugador(naipesJugador1, palosJugador1, puntosJugador1, cantCartas, cartaEmbaucadora);
                                puntosPorJugador(naipesJugador2, palosJugador2, puntosJugador2, cantCartas, cartaEmbaucadora);
                                mostrarCartasjugadores(naipesJugador1, palosJugador1, puntosJugador1, naipesJugador2, palosJugador2, puntosJugador2);
                            }

                            //JUGADOR 2, PUEDE RESPONDER QUE NO
                            else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                            {
                                cout << "No se modific� la carta Embaucadora, a continuaci�n se calcular�n los puntos de la ronda..." << endl;
                            }
                        }
                        else
                        {
                            cout << nombreJugador2 << ", no tenes los puntos necesarios para cambiar la carta Embaucadora." << endl;
                            cout << "No se modificó la carta Embaucadora, a continuación se calcularán los puntos de la ronda..." << endl;
                            cout << endl;
                        }
                    }
                    calcularPuntos(i, totalPuntoRondaJugador1, puntosJugador1, acuJ1, nombreJugador1, totalPuntoRondaJugador2, puntosJugador2, acuJ2, nombreJugador2);
                }
                else if (i == 1 && acuJ2 >= 20)
                {   //JUGADOR 1 NO TINEN PUNTOS ,SE LE PREGUNTA AL JUGADOR 2
                    cout << nombreJugador1 << ", no tenes los puntos necesarios para cambiar la carta Embaucadora." << endl;
                    cout << nombreJugador2 << ", �Deseas modificar la carta embaucadora actual?" << endl;
                    cout << "Se te descontar�n 20 puntos (S/N): ";
                    cin >> confirmaEmbaucadora;
                    if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                    {
                        mostrarCambioEmbaucadora(i, cartaEmbaucadora, totalPuntoRondaJugador2, acuJ2);
                        puntosPorJugador(naipesJugador1, palosJugador1, puntosJugador1, cantCartas, cartaEmbaucadora);
                        puntosPorJugador(naipesJugador2, palosJugador2, puntosJugador2, cantCartas, cartaEmbaucadora);
                        mostrarCartasjugadores(naipesJugador1, palosJugador1, puntosJugador1, naipesJugador2, palosJugador2, puntosJugador2);
                    }
                    else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                    {
                        cout << "No se modific� la carta Embaucadora, a continuaci�n se calcular�n los puntos de la ronda..." << endl;
                    }
                    calcularPuntos(i, totalPuntoRondaJugador1, puntosJugador1, acuJ1, nombreJugador1, totalPuntoRondaJugador2, puntosJugador2, acuJ2, nombreJugador2);

                }
                else if (i == 1 && acuJ1 < 20 && acuJ2 < 20)
                {   //NINGUNO DE LOS JUGADORES TIENEN PUNTOS SUFICIENTES
                    cout << nombreJugador1 << ", " << nombreJugador2 << ", no tienen los puntos necesarios para cambiar la carta Embaucadora." << endl;
                    cout << "A continuaci�n se calcular�n los puntos de la ronda ..." << endl;

                    calcularPuntos(i, totalPuntoRondaJugador1, puntosJugador1, acuJ1, nombreJugador1, totalPuntoRondaJugador2, puntosJugador2, acuJ2, nombreJugador2);
                }
                if (i == 2 && acuJ2 >= 20)
                {   //RONDA 3 SE LE PREGUNTA AL JUGADOR 2
                    cout << nombreJugador2 << ", �Deseas modificar la carta embaucadora actual?" << endl;
                    cout << "Se te descontar�n 20 puntos (S/N): ";
                    cin >> confirmaEmbaucadora;
                    if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                    {
                        mostrarCambioEmbaucadora(i, cartaEmbaucadora, totalPuntoRondaJugador2, acuJ2);
                        puntosPorJugador(naipesJugador1, palosJugador1, puntosJugador1, cantCartas, cartaEmbaucadora);
                        puntosPorJugador(naipesJugador2, palosJugador2, puntosJugador2, cantCartas, cartaEmbaucadora);
                        mostrarCartasjugadores(naipesJugador1, palosJugador1, puntosJugador1, naipesJugador2, palosJugador2, puntosJugador2);
                    }
                    else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                    {
                        if (acuJ1 >= 20)
                        {   //SI EL JUGADOR 2 NO QUISO CAMBIAR SE LE PREGUNTA AL JUGADOR 1
                            cout << nombreJugador1 << ", �Deseas modificar la carta embaucadora actual?" << endl;
                            cout << "Se te descontar�n 20 puntos (S/N): ";
                            cin >> confirmaEmbaucadora;
                            if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                            {
                                mostrarCambioEmbaucadora(i, cartaEmbaucadora, totalPuntoRondaJugador1, acuJ1);
                                puntosPorJugador(naipesJugador1, palosJugador1, puntosJugador1, cantCartas, cartaEmbaucadora);
                                puntosPorJugador(naipesJugador2, palosJugador2, puntosJugador2, cantCartas, cartaEmbaucadora);
                                mostrarCartasjugadores(naipesJugador1, palosJugador1, puntosJugador1, naipesJugador2, palosJugador2, puntosJugador2);
                            }
                            else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                            {
                                cout << "No se modific� la carta Embaucadora, a continuaci�n se calcular�n los puntos de la ronda..." << endl;
                            }

                        }
                        else
                        {
                            cout << nombreJugador1 << ", no tenes los puntos necesarios para cambiar la carta Embaucadora." << endl;
                            cout << "No se modific� la carta Embaucadora, a continuaci�n se calcular�n los puntos de la ronda..." << endl;
                            cout << endl;
                        }
                    }


                    calcularPuntos(i, totalPuntoRondaJugador1, puntosJugador1, acuJ1, nombreJugador1, totalPuntoRondaJugador2, puntosJugador2, acuJ2, nombreJugador2);

                }
                else if (i == 2 && acuJ1 >= 20)
                {   //RONDA 2 JUGADOR 2 NO TIENEN PUNTOS SE LE PREGUNTA AL JUGADOR 1
                    cout << nombreJugador2 << ", no tenes los puntos necesarios para cambiar la carta Embaucadora." << endl << endl;
                    cout << nombreJugador1 << ", �Deseas modificar la carta embaucadora actual?" << endl;
                    cout << "Se te descontar�n 20 puntos (S/N): ";
                    cin >> confirmaEmbaucadora;
                    if (confirmaEmbaucadora == 's' || confirmaEmbaucadora == 'S')
                    {
                        mostrarCambioEmbaucadora(i, cartaEmbaucadora, totalPuntoRondaJugador1, acuJ1);
                        puntosPorJugador(naipesJugador1, palosJugador1, puntosJugador1, cantCartas, cartaEmbaucadora);
                        puntosPorJugador(naipesJugador2, palosJugador2, puntosJugador2, cantCartas, cartaEmbaucadora);
                        mostrarCartasjugadores(naipesJugador1, palosJugador1, puntosJugador1, naipesJugador2, palosJugador2, puntosJugador2);
                    }
                    else if (confirmaEmbaucadora == 'n' || confirmaEmbaucadora == 'N')
                    {
                        cout << "No se modific� la carta Embaucadora, a continuaci�n se calcular�n los puntos de la ronda..." << endl;
                    }

                    calcularPuntos(i, totalPuntoRondaJugador1, puntosJugador1, acuJ1, nombreJugador1, totalPuntoRondaJugador2, puntosJugador2, acuJ2, nombreJugador2);
                }

                else if (i == 2 && acuJ2 < 20 && acuJ1 < 20)
                {   //RONDA 2 NINGUNO DE LOS 2 JUGADORES TIENEN PUNTOS SUFICIENTES
                    cout << nombreJugador2 << ", " << nombreJugador1 << ", no tienen los puntos necesarios para cambiar la carta Embaucadora." << endl;
                    cout << "A continuaci�n se calcular�n los puntos de la ronda ..." << endl;

                    calcularPuntos(i, totalPuntoRondaJugador1, puntosJugador1, acuJ1, nombreJugador1, totalPuntoRondaJugador2, puntosJugador2, acuJ2, nombreJugador2);
                }

                system("pause");
                system("cls");

            }

            resumenPartida(nombreJugador1, nombreJugador2, totalPuntoRondaJugador1, totalPuntoRondaJugador2, acuJ1, acuJ2);

            mostrarGanador(acuJ1, acuJ2, nombreJugador1, nombreJugador2, totalPuntoRondaJugador1, totalPuntoRondaJugador2, nombreJugadorPuntajeMax, puntajeMax);

            system("pause");
            system("cls");
            break;

        case 2:
            estadisticas(nombreJugadorPuntajeMax, puntajeMax, partidas);
            system("pause");
            system("cls");
            break;

        case 3:
            creditos();
            system("pause");
            system("cls");
            break;

        case 0:
            return 0;
        }
    }
}
