#pragma once
#include "libUnicornio.h"
#include "Tiro.h"

class Navio
{
public:
	Navio();
	~Navio();
	void desenhar();
	void atualizar();
	void inicializar();
	float getX();
	float getY();
	Sprite getSprite();
	void resetarVel();

	float getXTiro() { return tiro.getX(); };
	float getYTiro() { return tiro.getY(); };
	Sprite getSpriteTiro() { return tiro.getSprite(); };
	void matarTiro() { tiro.morrer(); };
	void atirar();
	bool getTiro();
	void perderVida();
	void pegarMunicao();
	void aumentarPontos();
	void resetarPontos();
	void resetarPosicao();
	float setVel(float novoVel) { return vel = novoVel; };

	void tocarExplosao();
	void pegarAmmo();
	void entregarAmmo();

	void setAudio(string nome);
	void setAudio2(string nome);
	void setAudio3(string nome);
	void setAudio4(string nome);

	void setX(float novoX) { x = novoX; };
	void setY(float novoY) { y = novoY; };

	int getVida() { return vida; };
	int getPontuacao() { return pontuacao; };	
	int getAmmo() { return ammo; };
	int setAmmo() { return ammo = 0; }
	bool perdeuVida();

private: 
	Sprite sprite, spritetiro;
	int x, y, vel;
	Tiro tiro;
	Direcao direcao;
	Som som, pegarammo, entregarammo, explosao;
	int vida, pontuacao;
	bool atirando;
	int ammo;
};
