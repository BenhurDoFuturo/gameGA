#pragma once
#include "libUnicornio.h"
#include "Tiro.h"



class Inimigo
{
public:
	Inimigo();
	~Inimigo();
	void desenhar();
	void atualizar();
	void inicializar();
	float getX();
	float getY();
	Sprite getSprite();

	float getXTiro() { return tiro.getX(); };
	float getYTiro() { return tiro.getY(); };
	Sprite getSpriteTiro() { return tiro.getSprite(); };
	void matarTiro() { tiro.morrer(); };
	void atirar();
	bool getVivo() { return vivo; };
	void morrer() { vivo = false; };
	bool getTiroVivo() { return tiro.getVivo(); };
	void resetarPosicao();
	int setVel(float novoVel) { return vel = novoVel; };
	void destruir();
	void resetarVel();

	void setX(float novoX) { x = novoX; };
	void setY(float novoY) { y = novoY; };

	float getVida() { return vida; };

private:
	Sprite sprite, spritetiro;
	float x, y;
	float randpos;
	Tiro tiro;
	float vida, pontuacao;
	bool atirando;
	float rando;
	float vel;
	bool vivo;
	Direcao direcao;
	int chantiro;

};


