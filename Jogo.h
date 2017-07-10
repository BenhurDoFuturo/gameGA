#pragma once
#include "Navio.h"
#include "Inimigo.h"
#include "Ship.h"
#include "Tiro.h"
#include "Missil.h"
#include "Municao.h"
#include "ForcaCoreana.h"
#include "Kim.h"


 

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
    bool pausarMusica() { return musicatocando = false; };

private:
	
	Sprite sprite, sprite2;
	Navio submarino;
	Inimigo inimigo[3];
	Ship ship;
	Kim kim;
	ForcaCoreana forcacoreana;
	Missil missil[3];
	Municao municao;
	void telaJogo();
	void telaInicial();
	void telaInstrucoes();
	void telacreditos();
	void telaFimJogo();
	void telaVenceu();
	bool musicatocando;
	

	Texto texto;
	StatusJogo status;		
	
};