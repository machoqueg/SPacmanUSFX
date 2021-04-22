#pragma once
#include <SDL.h>


class Fruta
{
private:
	int color;
	int posicionX;
	int posicionY;
	SDL_Point posicion;
public:
	int getColor() { return color; }
	void setColor(int _color) { color = _color; }

	int getPosicionX() { return posicionX; }
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }

	int getPosicionY() { return posicionY; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	SDL_Point getPosicion() { return posicion; }
	void setPosicion(SDL_Point _posicion) { posicion = _posicion; }

	//Metodos accesores de la propiedad tipo
	int getTipo() { return tipo; }
	void setTipo(int _tipo) { tipo = _tipo; }
private:
	int tipo;
};
