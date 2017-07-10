#pragma once
#include "libUnicornio.h"
#include "Tiro.h"



class Missil
{
public:
	Missil();
	~Missil();
	void desenhar();
	void atualizar();
	void inicializar();
	float getX();
	float getY();
	Sprite getSprite();
	void resetarPosicao();
	void resetarVel();
	int setVel(float novoVel) { return vel = novoVel; };

	bool getVivo() { return vivo; };
	void morrer() { vivo = false; };

	void setX(float novoX) { x = novoX; };
	void setY(float novoY) { y = novoY; };

private:
	Sprite sprite, spritetiro;
	float x, y;
	float vida, pontuacao;
	bool atirando;
	float rando;
	float vel;
	bool vivo;
	Direcao direcao;

};


