#include "Ship.h"
#include "Tiro.h"
#include "libUnicornio.h"


Ship::Ship()
{
}

Ship::~Ship()
{
}

void Ship::desenhar()
{
	sprite.desenhar(x, y);
}


void Ship::atualizar()
{
	if (vivo)
	{
		if (x < -sprite.getLargura() / 2 && direcao == esquerda
			|| x > gJanela.getLargura() + sprite.getLargura() / 2 && direcao == direita)
		{
			y = 50;
			rando = 0;
			if (rando == 0)
			{
				x = -100;
				sprite.setInverterX(false);
				direcao = direita;
			}
			else if (rando == 1)
			{
				x = 1115;
				sprite.setInverterX(true);
				direcao = esquerda;
			}
		}
		else
		{
			if (direcao == esquerda)
			{
				x -= 0.5;
			}
			else
			{
				x += 0.5;
			}
		}

	}

	vivo = true;
}

void Ship::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("ship"))
	{
		gRecursos.carregarSpriteSheet("ship", "imagens/navioamericano.png", 1);
	}
	sprite.setSpriteSheet("ship");


	x = 0;
	y = 50;
	direcao = direita;
}

float Ship::getX()
{
	return x;
}

float Ship::getY()
{
	return y;
}

Sprite Ship::getSprite()
{
	return sprite;
}