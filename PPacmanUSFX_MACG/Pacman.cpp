#include <stdio.h>
#include "Pacman.h"


Pacman::Pacman(SDL_Renderer* _renderer, SDL_Texture* _pacmanTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron):
GameObject(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	// Inicializa propiedade de de pacman;

	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	renderer = _renderer;
	pacmanTexture = _pacmanTexture;
}

void Pacman::handleEvent(SDL_Event& e)
{
	//Si se a presionado una tecla
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Se ajusta la velocidad
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velocidadY -= velocidadPatron; break;
		case SDLK_DOWN: velocidadY += velocidadPatron; break;
		case SDLK_LEFT: velocidadX -= velocidadPatron; break;
		case SDLK_RIGHT: velocidadX += velocidadPatron; break;
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

void Pacman::move()
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

void Pacman::render()
{

	//Color key image
	//SDL_SetColorKey(screenSurface, SDL_TRUE, SDL_MapRGB(pacmanSurface->format, 0, 0xFF, 0xFF));

	//SDL_Texture* newTexture = nullptr;

	//newTexture = SDL_CreateTextureFromSurface(renderer, pacmanSurface);
	//if (newTexture == NULL)
	//{
	//	cout << "No se puede crear la textura a partir de la superficie, SDL Error: " << SDL_GetError() << endl;
	//}
	//else
	//{
		//Obtener dimensiones de la imagen
	//	ancho = pacmanSurface->w;
	//	alto = pacmanSurface->h;
	//}
	//SDL_Rect* clip = NULL;
	//double angle = 0.0;
	//SDL_Point* center = NULL;
	//SDL_RendererFlip flip = SDL_FLIP_NONE;

	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };

	//Set clip rendering dimensions
	/*if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
*/
	//Renderizar pantalla
	SDL_RenderCopyEx(renderer, pacmanTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}

