#include "Kim.h"
#include "libUnicornio.h"



Kim::Kim()
{
}


Kim::~Kim()
{
}

void Kim::desenhar()
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

void Kim::atualizar()
{
	tiro.atualizar();
	chantiro = rand() % 4000;

	if (explode)
	{
		sprite.setSpriteSheet("explode");
		sprite.avancarAnimacao();
		sprite.setVelocidadeAnimacao(2);
		if (sprite.terminouAnimacao())
		{
			vivo = false;
			venceujogo = true;
		}
	}

	else
	{

		if (chantiro <= 20 && !tiro.getVivo() && !explode)
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
		if (vivo && !explode)
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
		if (!vivo && !explode)
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
}
float Kim::getX()
{
	return x;
}

float Kim::getY()
{
	return y;
}

Sprite Kim::getSprite()
{
	return sprite;
}

void Kim::inicializar()
{

	tiro.inicializar("tirokim", "imagens/tirocor.png");

	if (!gRecursos.carregouSpriteSheet("kimatira"))
	{
		gRecursos.carregarSpriteSheet("kimatira", "imagens/subkimtiro.png", 1, 7);
	}
	spritetiro.setSpriteSheet("kimatira");
	atirando = false;

	if (!gRecursos.carregouSpriteSheet("kim"))
	{
		gRecursos.carregarSpriteSheet("kim", "imagens/subkim.png", 1, 2);

	}
	sprite.setSpriteSheet("kim");

	if (!gRecursos.carregouSpriteSheet("explode"))
	{
		gRecursos.carregarSpriteSheet("explode", "imagens/destruicao.png", 1, 10);

	}
	spritexplode.setSpriteSheet("explode");

	vida = 8;
	vel = 1.4;
	venceujogo = false;
	vivo = false;
	explode = false;

	x = gJanela.getLargura();
	rando = rand() % 600 + 300;
	y = rando;
	direcao = esquerda;


}

void Kim::atirar()
{
	tiro.atirar(x, y, direcao);
}

void Kim::resetarPosicao()
{
	sprite.setSpriteSheet("kim");
	vida = 8;
	vel = 1.4;
	venceujogo = false;
	vivo = false;
	explode = false;

	x = gJanela.getLargura();
	rando = rand() % 600 + 300;
	y = rando;
	if (direcao = esquerda)
	{
		sprite.setInverterX(false);
		spritetiro.setInverterX(false);
		direcao = esquerda;

	}
	else
	{
		sprite.setInverterX(true);
		spritetiro.setInverterX(true);
		direcao = direita;
	}
}



void Kim::destruir()
{
	explode = true;
	
	
}




