#include "Inimigo.h"
#include "libUnicornio.h"



Inimigo::Inimigo()
{
}


Inimigo::~Inimigo()
{
}

void Inimigo::desenhar()
{
	if (vivo)
	{
		if (atirando)
			spritetiro.desenhar(x, y);
		else
			sprite.desenhar(x, y);

		tiro.desenhar();
	}
}

void Inimigo::atualizar()
{
	tiro.atualizar();
	chantiro = rand() % 4000;

	if (chantiro <= 20 && !tiro.getVivo())
	{
		atirar();
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
	if (vivo)
	{

		if (x < -sprite.getLargura() / 2 && direcao == esquerda
			|| x > gJanela.getLargura() + sprite.getLargura() / 2 && direcao == direita)
		{
			y = rand() % 600 + 300;
			rando = rand() % 2;
			if (rando == 0)
			{
				x = -250;
				sprite.setInverterX(true);
				spritetiro.setInverterX(true);
				if (atirando)
					spritetiro.setInverterX(true);
				direcao = direita;
			}
			else if (rando == 1)
			{
				x = 1415;
				sprite.setInverterX(false);
				spritetiro.setInverterX(false);
				if (atirando)
					spritetiro.setInverterX(false);

				direcao = esquerda;
			}
		}
		else
		{
			if (direcao == esquerda)
			{
				x -= vel;
			}
			else
			{
				x += vel;
			}
		}

		//vivo = false;
	}

	//vivo = true;
	if (!vivo)
	{
		vivo = true;
		y = rand() % 600 + 300;
		x = rando;
		rando = rand() % 2;
		if (rando == 0)
		{
			x = -250;
			sprite.setInverterX(true);
			spritetiro.setInverterX(true);
			if (atirando)
				spritetiro.setInverterX(true);
			direcao = direita;
		}
		else if (rando == 1)
		{
			x = 1415;
			sprite.setInverterX(false);
			spritetiro.setInverterX(false);
			if (atirando)
				spritetiro.setInverterX(false);

			direcao = esquerda;
		}

	}
}
float Inimigo::getX()
{
	return x;
}

float Inimigo::getY()
{
	return y;
}

Sprite Inimigo::getSprite()
{
	return sprite;
}

void Inimigo::inicializar()
{

	tiro.inicializar("tiroinimigo", "imagens/tirocor.png");
	if (!gRecursos.carregouSpriteSheet("inimatirando"))
	{
		gRecursos.carregarSpriteSheet("inimatirando", "imagens/subcoreanotiro.png", 1, 8);
	}
	spritetiro.setSpriteSheet("inimatirando");
	atirando = false;

	if (!gRecursos.carregouSpriteSheet("inimigo"))
	{
		gRecursos.carregarSpriteSheet("inimigo", "imagens/subcoreano.png", 1, 2);

	}
	sprite.setSpriteSheet("inimigo");

	vida = 3;
	vel = 1.4;

	x = gJanela.getLargura();
	rando = rand() % 600 + 300;
	y = rando;
	direcao = esquerda;


}

void Inimigo::atirar()
{
	tiro.atirar(x, y, direcao);
}

void Inimigo::resetarPosicao()
{
	x = gJanela.getLargura();
	rando = rand() % 600 + 300;
	y = rando;
	direcao = esquerda;
	sprite.setInverterX(false);
	spritetiro.setInverterX(false);
}

void Inimigo::destruir()
{

	x = -10000;
	y = -10000;

}

void Inimigo::resetarVel()
{ 
	vel = 1.6;
}

