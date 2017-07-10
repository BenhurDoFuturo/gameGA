#include "Municao.h"
#include "libUnicornio.h"



Municao::Municao()
{
}


Municao::~Municao()
{
}

void Municao::desenhar()
{
	if (vivo)
		sprite.desenhar(x, y);
}

void Municao::atualizar()
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
				x = 0;
				sprite.setInverterX(true);
				direcao = direita;
			}
			else if (rando == 1)
			{
				x = 1115;
				sprite.setInverterX(false);
				direcao = esquerda;
			}
		}
		else
		{
			if (direcao == esquerda)
			{
				x -= 1.7;
			}
			else
			{
				x += 1.7;
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
float Municao::getX()
{
	return x;
}

float Municao::getY()
{
	return y;
}

Sprite Municao::getSprite()
{
	return sprite;
}

void Municao::inicializar()
{

	if (!gRecursos.carregouSpriteSheet("municao"))
	{
		gRecursos.carregarSpriteSheet("municao", "imagens/municao.png", 1);
		sprite.setSpriteSheet("municao");
	}
	vida = 1;

	x = gJanela.getLargura();
	rando = rand() % 600 + 300;
	y = rando;
    direcao = esquerda;

}
