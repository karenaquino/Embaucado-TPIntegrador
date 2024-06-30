#pragma once
#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
using namespace std;

//declaraciones de funciones
void mostrarMenuPrincipal();
//carga nombre jugadores
void cargarJugadores(string& nombre1, string& nombre2);

//reparte cartas del jugador 1
void repartirCartasJugador1(string vJugador1[], int cantCartas, string vMazo[], int TAM);



//reparte cartas del jugador 1
void repartirCartasJugador2(string vJugador2[], int cantCartas, string vMazo[], int TAM);

//void repartirCartas_Jugador2(string vJugador2[]);


//mostrar cartas ambos jugadores
void cartasjugadores(string vJugador1[], string vJugador2[], int cantCartas, string& nombre1, string& nombre2);

//carta embaucadora
void generarEmbaucadora(string& cartaEmbaucadora);
void mostrarCambioEmbaucadora(string cartaEmbaucadora, int& totalPuntoRondaJugador);

//funciones para crear mazos
void crearMazoNaipe(string mazoNaipe[]);
void crearMazoPalo(string mazoPalo[]);
void crearMazos(string mazoNaipe[], string mazoPalo[]);


void repartirCartasJugador(string mazoNaipe[], string mazoPalo[], string naipesJugador[], string palosJugador[]);

void mostrarNombresJugadores(string nombreJugador1, string nombreJugador2);

void mostrarCartasjugadores(string naipesJugador1[], string palosJugador1[], int puntosJugador1[],
                            string naipesJugador2[], string palosJugador2[], int puntosJugador2[]);

void puntosPorJugador(string naipeJugador[], string paloJugador[], int puntosJugador[], int cantCartas, string& cartaEmbaucadora);

void mostrarGanador(int &acuJ1, int &acuJ2, string &nombreJugador1, string &nombreJugador2, int totalPuntoRondaJugador1[], int totalPuntoRondaJugador2[]);

void resumenPartida(string &nombreJugador1, string &nombreJugador2, int totalPuntoRondaJugador1[], int totalPuntoRondaJugador2[]);

//Funcion para creditos
void creditos();
