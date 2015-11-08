/*!
 * \file harryPotter.h
 * \brief Contiene la definición de la clase "harryPotter"
 * \author Airam Manuel Navas Simón <alu0100618426@ull.edu.es>
 * \date 9 de Octubre
 */

#ifndef harryPotter_H
#define harryPotter_H

#include <common.h>
#include <mapa_t.h>
#include <QStack>
#include <cmath>

class harryPotter
{
	/*!
	  * \brief Clase del muñeco de Harry Potter
	  *
	  * \author Rafael Herrero Álvarez <alu0100812275@ull.edu.es>
	  */

private:
	QPoint posicion_harry;
	unsigned vidas;
	unsigned mana;
	mapa_t& laberinto;
	tabla_t marcar;
	harryPotter();  //Lo ponemos aqui porque Dani lo quiso así
    QPoint get_next_dir();
    QStack<QPoint> stack;
	QPoint aux;
	bool primera_vez;
	bool encontrada_copa;

public:

	harryPotter(mapa_t& lab);
	QPoint get_posicion_harry();
	void set_posicion_harry(QPoint ranas_de_chocolate);
	void set_posicion_harry_nuevo (QPoint nueva_posicion);
	void set_mana(unsigned mana_encontrado);
	void set_vidas(unsigned vida_gastada);
	bool puedo_continuar_DFS();
    bool estoy_en_la_copa();
	QPoint movimiento_DFS();
	bool puedo_continuar_escalada();
	QPoint movimiento_escalada();
	bool puedo_continuar_estrella();
	QPoint movimiento_estrella();
	unsigned get_mana();
	unsigned get_vidas();

	unsigned funcion_heuristica_prox(QPoint);
	QPoint get_next_dir_escalada();
};

#endif // harryPotter_H
