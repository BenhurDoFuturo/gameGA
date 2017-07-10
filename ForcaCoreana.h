#pragma once
#include "libUnicornio.h"
#include "Municao.h"
#include "Navio.h"


class ForcaCoreana
{
public:
	ForcaCoreana();
	~ForcaCoreana();
	void desenhar();
	void atualizar();
	void morrer();
	void inicializar();
	void iniciarContador();
	float getX();
	float getY();
	Sprite getSprite();
	void resetarForca();
    void forcaZero();

	int setPausarForca(int forcaPausada) { return forca += forcaPausada; };

	int getForca() { return forca; };
	int setForca(int novaForca) { return forca -= novaForca; };
	
	int setForca1(int aumentForca) { return forca += aumentForca; };

	int getContador() { return contador; };
	int setContador(int novoContador) { return contador = novoContador; };

private:
	Sprite sprite, sprite2, sprite3, sprite4, sprite5, sprite6, sprite7;
	float x[7], y[7];
	bool vivo;
	int contador, forca, contador2, animacao;
};

