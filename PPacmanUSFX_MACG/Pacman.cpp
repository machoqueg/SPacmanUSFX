#include <stdio.h>
#include "Pacman.h"

Pacman::Pacman(Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) :
	GameObject(_texturaPacman, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	// Inicializa propiedade de de pacman
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	posicionXEnTextura = 0;
	posicionYEnTextura = 0;
}


void Pacman::handleEvent(SDL_Event& e)
{
	//Si se a presionado una tecla
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Se ajusta la velocidad
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			velocidadY -= velocidadPatron;
			posicionXEnTextura = 50;
			posicionYEnTextura = 25;
			break;
		case SDLK_DOWN:
			velocidadY += velocidadPatron;
			posicionXEnTextura = 50;
			posicionYEnTextura = 0;
			break;
		case SDLK_LEFT:
			velocidadX -= velocidadPatron;
			posicionXEnTextura = 0;
			posicionYEnTextura = 0;
			break;
		case SDLK_RIGHT:
			velocidadX += velocidadPatron;
			posicionXEnTextura = 0;
			posicionYEnTextura = 25;
			break;
		}
	}
	//Si se a soltado una tecla
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		//Se ajusta la velocidad
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velocidadY += velocidadPatron; break;
		case SDLK_DOWN: velocidadY -= velocidadPatron; break;
		case SDLK_LEFT: velocidadX += velocidadPatron; break;
		case SDLK_RIGHT: velocidadX -= velocidadPatron; break;
		}
	}
	//move();
}

void Pacman::update()
{
	// Mueve pacman a la izquierda o a la derecha
	posicionX += velocidadX;

	// Se verifica que no se sobrepasen los bordes horizontales de los margenes establecidos para la pantalla
	if ((posicionX < 0) || (posicionX + ancho > anchoPantalla)) 
	{
		// mover atras
		posicionX -= velocidadX;
	}

	// Mover pacman arriba o abajo
	posicionY += velocidadY;

	// Se verifica que no se sobrepasen los bordes verticales de los margenes establecidos para la pantalla
	if ((posicionY < 0) || (posicionY + alto > altoPantalla))
	{
		// mover atra
		posicionY -= velocidadY;
	}
}
