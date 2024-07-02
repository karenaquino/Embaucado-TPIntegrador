#pragma once
#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
#include "colors.h"
using namespace std;

// FUNCION MENU
void mostrarMenuPrincipal();

//FUNCION CARGA DE JUGADORES
void cargarJugadores(string& nombre1, string& nombre2);

//FUNCION REPARTE CARTAS AMBOS JUGADORES
void repartirCartasJugador(string mazoNaipe[], string mazoPalo[], string naipesJugador[], string palosJugador[]);

//FUNCION MUETRA CARTA JUGADORES
void mostrarCartasjugadores(string naipesJugador1[], string palosJugador1[], int puntosJugador1[], string naipesJugador2[], string palosJugador2[], int puntosJugador2[]);

//FUNCION GENERA CARTA EMBAUCADORA
void generarEmbaucadora(string& cartaEmbaucadora);

//FUNCION GENERA NUEVA EMBAUCADORA Y SACRIFICA 20 PUNTOS
void mostrarCambioEmbaucadora(int& i, string& cartaEmbaucadora, int totalPuntoRondaJugador[], int& acuJ);

//FUNCIONES PARA CREAR MAZOS
void crearMazoNaipe(string mazoNaipe[]);
void crearMazoPalo(string mazoPalo[]);
void crearMazos(string mazoNaipe[], string mazoPalo[]);

//FUNCION MUESTAR LOS NOMBRES CON LOS PUNTOS ACUMULADOS
void mostrarNombresJugadores(string nombreJugador1, string nombreJugador2, int& acuJ1, int& acuJ2);

//FUNCION CALCULA LOS PUNTOS TENIENDO EN CUENTA LA CARTA EMBAUCADORA
void puntosPorJugador(string naipeJugador[], string paloJugador[], int puntosJugador[], int cantCartas, string& cartaEmbaucadora);

//FUNCION CALCULA LOS PUNTOS TOTALES DE LAS PARTIDAS
void calcularPuntos(int& i, int totalPuntoRondaJugador1[], int puntosJugador1[], int& acuJ1, string& nombreJugador1, int totalPuntoRondaJugador2[], int puntosJugador2[], int& acuJ2, string& nombreJugador2);

//FUNCION MUESTRA GANADOR DE LA PARTIDA
void mostrarGanador(int& acuJ1, int& acuJ2, string& nombreJugador1, string& nombreJugador2, int totalPuntoRondaJugador1[], int totalPuntoRondaJugador2[], string& nombreJugadorPuntajeMax, int& puntajeMax);

//FUNCION MUETRA RESUMAN DE PUNTOS POR PARTIDA Y EL TOTAL
void resumenPartida(string& nombreJugador1, string& nombreJugador2, int totalPuntoRondaJugador1[], int totalPuntoRondaJugador2[], int acuJ1, int acuJ2);

//FUNCION MUESTRA JUGADOR CON PUNTAJE MAXIMO Y LO ALMACENA
void estadisticas(string& nombreJugadorPuntajeMax, int& puntajeMax, int partidas);

//FUNCION MUESTRA CREDITOS
void creditos();
