#pragma once
#include "libUnicornio.h"
#include "Tiro.h"

class Ship
{
public:
	Ship();
	~Ship();
	void desenhar();
	void atualizar();
	void inicializar();
	float getX();
	float getY();
	Sprite getSprite();

	bool getVivo() { return vivo; };
	void morrer() { vivo = true; };

	void setX(float novoX) { x = novoX; };
	void setY(float novoY) { y = novoY; };
private:
	Sprite sprite, spritetiro;
	float x, y;
	float rando;
	bool vivo;
	Direcao direcao;
};