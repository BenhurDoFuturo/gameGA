#include "libUnicornio.h"
#include "Navio.h"
#include "Tiro.h"



Navio::Navio()
{
}


Navio::~Navio()
{
}

void Navio::desenhar()
{
	if (atirando)
		spritetiro.desenhar(x, y);
	else
		sprite.desenhar(x, y);

	tiro.desenhar();

}

void Navio::atualizar()
{
	tiro.atualizar();
	
	if (gTeclado.segurando[TECLA_CIMA] && y > sprite.getAltura() + 90)
	{
		y-=vel;
		
	}

	if (gTeclado.segurando[TECLA_BAIXO] && y < gJanela.getAltura() - sprite.getAltura() - 25)
	{
		y+=vel;
	}
	if (gTeclado.segurando[TECLA_DIR] && x < gJanela.getLargura() - sprite.getLargura() / 2)
	{
		x += vel * 2;
		sprite.setInverterX(false);
		spritetiro.setInverterX(false);
		if (atirando)
			spritetiro.setInverterX(false);
		    direcao = direita; 
	}
	if (gTeclado.segurando[TECLA_ESQ] && x > sprite.getLargura() / 3)
	{
		x -= vel * 2;
		
		sprite.setInverterX(true);
		spritetiro.setInverterX(true);
		if (atirando)
		spritetiro.setInverterX(true);
		direcao = esquerda;
	}
	if (gTeclado.pressionou[TECLA_ESPACO] && !tiro.getVivo())
	{
		
		atirar();
		som.tocar();
		atirando = true;
	}
	sprite.avancarAnimacao();
	tiro.atualizar();
	if (atirando)
	{
		spritetiro.avancarAnimacao();
		spritetiro.setVelocidadeAnimacao(12);
		if (spritetiro.terminouAnimacao())
		{
			atirando = false;
		}
	}
}
float Navio::getX()
{ 
	return x;
}

float Navio::getY()
{
	return y;
}

Sprite Navio::getSprite()
{
	return sprite;
}

void Navio::resetarVel()
{ 
	vel = 1.60;
}

void Navio::inicializar()
{
	tiro.inicializar("tiro", "imagens/tiroamer.png");

	if (!gRecursos.carregouSpriteSheet("atirando"))
	{
		gRecursos.carregarSpriteSheet("atirando", "imagens/subamericanotiro1.png", 1, 8);
	}
	spritetiro.setSpriteSheet("atirando");
	atirando = false;

	if (!gRecursos.carregouSpriteSheet("submarino"))
	{
		gRecursos.carregarSpriteSheet("submarino", "imagens/subamericano1.png", 1, 2);
	}
	sprite.setSpriteSheet("submarino");
	direcao = direita;
	vida = 10;
	pontuacao = 0;
	ammo = 0;

	x = 400;
	y = 300;
	vel = 1.60;

	
}

void Navio::atirar()
{
	tiro.atirar(x, y, direcao);
	
}

bool Navio::getTiro()
{
	return tiro.getVivo();
}

void Navio::perderVida()
{

	vida -= 1;
	

}

void Navio::pegarMunicao()
{

	ammo += 1;

}

void Navio::aumentarPontos()
{
	pontuacao += 50;
}

void Navio::resetarPontos()
{
	pontuacao = 0;
	vida = 10;
}

void Navio::resetarPosicao()
{
	x = 400;
	y = 300;
}

void Navio::tocarExplosao()
{
	explosao.tocar();
}

void Navio::pegarAmmo()
{
	pegarammo.tocar();
}

void Navio::entregarAmmo()
{
	entregarammo.tocar();
}

void Navio::setAudio(string nome)
{
	som.setAudio(nome);

	som.setVolume(50);
}

void Navio::setAudio2(string nome)
{
	explosao.setAudio(nome);

	explosao.setVolume(50);
}

void Navio::setAudio3(string nome)
{
	pegarammo.setAudio(nome);

	pegarammo.setVolume(80);
}

void Navio::setAudio4(string nome)
{
	entregarammo.setAudio(nome);

	entregarammo.setVolume(80);
}

bool Navio::perdeuVida()
{
	
	if (vida -=1)
	{
		return true;
	}
	else
	{
		return false;
	}
}



