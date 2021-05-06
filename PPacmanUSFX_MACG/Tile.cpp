#include "Tile.h"


Tile::Tile() {
	posicion.x = 0;
	posicion.y = 0;

	pacman = nullptr;
	fantasma = nullptr;
	fruta = nullptr;
	moneda = nullptr;
	pared = nullptr;
}

Tile::Tile(int _x, int _y) {
	posicion.x = _x;
	posicion.y = _y;

	pacman = nullptr;
	fantasma = nullptr;
	fruta = nullptr;
	moneda = nullptr;
	pared = nullptr;
}

void Tile::setPosicion(int _x, int _y) {
	posicion.x = _x;
	posicion.y = _y;
}