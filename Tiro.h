#pragma once
#include "libUnicornio.h"

enum Direcao { esquerda, direita };

class Tiro
{
public:
	Tiro();
	~Tiro();
	void desenhar();
	void atualizar();
	void inicializar(string nome, string path);
	void atirar(float novoX, float novoY, Direcao novaDirecao);
	float getX();
	float getY();
	Sprite getSprite();
	bool getVivo() { return vivo; };
	void morrer() { vivo = false; };

private:
	Sprite sprite;
	float x, y;
	Direcao direcao;
	bool vivo;
};

