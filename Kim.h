#pragma once
#include "libUnicornio.h"
#include "Tiro.h"



class Kim
{
public:
	Kim();
	~Kim();
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
	void resetarPosicao();
	
	bool getVivo() { return vivo; };
	void morrer() { vivo = false; };
	bool getTiroVivo() { return tiro.getVivo(); };
	int setVel(float novoVel) { return vel = novoVel; };
	void destruir();
	bool viver() { return vivo = true; };
	float perderVida() { return vida -= 1; };
	bool getVenceuJogo() { return venceujogo; };
	bool setVencerJogo() { return venceujogo = true; };

	void setX(float novoX) { x = novoX; };
	void setY(float novoY) { y = novoY; };

	float getVida() { return vida; };


private:
	Sprite sprite, spritetiro, spritexplode;
	float x, y;
	float randpos;
	Tiro tiro;
	float vida, pontuacao;
	bool atirando;
	float rando;
	bool explode;
	float vel;
	bool vivo;
	bool venceujogo;
	Direcao direcao;
	int chantiro;

};


