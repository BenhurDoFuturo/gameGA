#include "Tiro.h"

Tiro::Tiro()
{
}


Tiro::~Tiro()
{
}

void Tiro::desenhar()
{
	if (vivo)
	{
		sprite.desenhar(x, y);
	}
}

void Tiro::atualizar()
{
	if (vivo)
	{
		sprite.avancarAnimacao();
		if (direcao == esquerda)
		{
			sprite.setInverterX(true);
			sprite.setInverterX(true);
			x-=2;

		}
		else
		{
			sprite.setInverterX(false);
			sprite.setInverterX(false);
			x+=2;
		}
		if (x < -sprite.getLargura() / 2 || x > gJanela.getLargura() + sprite.getLargura() / 2)
		{
			vivo = false;
		}
	}
}

void Tiro::inicializar(string nome, string path)
{
	if (!gRecursos.carregouSpriteSheet(nome))
	{
		gRecursos.carregarSpriteSheet(nome, path);
	}
	sprite.setSpriteSheet(nome);
	vivo = false;
}

void Tiro::atirar(float novoX, float novoY, Direcao novaDirecao)
{
	vivo = true;
	
	vivo = true;
	direcao = novaDirecao;
	if (direcao == esquerda)
	{
		x = novoX - 78;
		y = novoY  + 12;
		sprite.setInverterX(false);

	}
	else
	{
		x = novoX + 78;
		y = novoY + 12;
		sprite.setInverterX(true);
	}

	
}

float Tiro::getX()
{
	return x;
}

float Tiro::getY()
{
	return y;
}

Sprite Tiro::getSprite()
{
	return Sprite();
}
