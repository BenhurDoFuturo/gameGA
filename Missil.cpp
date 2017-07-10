#include "Missil.h"
#include "libUnicornio.h"



Missil::Missil()
{
}


Missil::~Missil()
{
}

void Missil::desenhar()
{
	if (vivo)
	sprite.desenhar(x, y);
}

void Missil::atualizar()
{

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
				direcao = direita;
			}
			else if (rando == 1)
			{
				x = 1415;
				sprite.setInverterX(false);
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
			direcao = direita;
		}
		else if (rando == 1)
		{
			x = 1415;
			sprite.setInverterX(false);
			direcao = esquerda;
		}

	}
}
float Missil::getX()
{
	return x;
}

float Missil::getY()
{
	return y;
}

Sprite Missil::getSprite()
{
	return sprite;
}

void Missil::resetarPosicao()
{
	x = gJanela.getLargura();
	rando = rand() % 600 + 300;
	y = rando;
	direcao = esquerda;
	sprite.setInverterX(false);

}

void Missil::resetarVel()
{
	vel = 2.7;
}

void Missil::inicializar()
{

	if (!gRecursos.carregouSpriteSheet("missil"))
	{
		gRecursos.carregarSpriteSheet("missil", "imagens/missilcoreano.png", 1);
	}
	sprite.setSpriteSheet("missil");

	vida = 1;
	vel = 2.7;

	x = gJanela.getLargura();
	rando = rand() % 600 + 300;
	y = rando;
	sprite.setInverterX(false);
	direcao = esquerda;


}
