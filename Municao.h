#pragma once
#include "libUnicornio.h"
#include "Tiro.h"



class Municao
{
public:
	Municao();
	~Municao();
	void desenhar();
	void atualizar();
	void inicializar();
	float getX();
	float getY();
	Sprite getSprite();

	bool getVivo() { return vivo; };
	void morrer() { vivo = false; };

	void setX(float novoX) { x = novoX; };
	void setY(float novoY) { y = novoY; };

private:
	Sprite sprite;
	float x, y;
	float vida, pontuacao;
	float rando;
	bool vivo;
	Direcao direcao;

};


