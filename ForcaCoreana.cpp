#include "ForcaCoreana.h"



ForcaCoreana::ForcaCoreana()
{
}


ForcaCoreana::~ForcaCoreana()
{
}

void ForcaCoreana::desenhar()
{
}

void ForcaCoreana::atualizar()
{

	if (forca >= 2)
	{
		sprite2.desenhar(x[1], y[1]);

	}

	if (forca >= 3)
	{
		sprite3.desenhar(x[2], y[2]);

	}

	if (forca >= 4)
	{
		sprite4.desenhar(x[3], y[3]);
	}

	if (forca >= 5)
	{
		sprite5.desenhar(x[4], y[4]);
	}

	if (forca >= 6)
	{
		sprite6.desenhar(x[5], y[5]);
		
	}

}

void ForcaCoreana::morrer()
{

}

void ForcaCoreana::inicializar()
{
	forca = 1;
	contador = 0;
	if (!gRecursos.carregouSpriteSheet("forcacoreana"))
	{
		gRecursos.carregarSpriteSheet("forcacoreana", "imagens/forcacoreana.png", 1);
		sprite.setSpriteSheet("forcacoreana");
	}

	if (!gRecursos.carregouSpriteSheet("forcacoreana2"))
	{
		gRecursos.carregarSpriteSheet("forcacoreana2", "imagens/forcacoreana.png", 1);
		sprite2.setSpriteSheet("forcacoreana2");
	}

	if (!gRecursos.carregouSpriteSheet("forcacoreana3"))
	{
		gRecursos.carregarSpriteSheet("forcacoreana3", "imagens/forcacoreana.png", 1);
		sprite3.setSpriteSheet("forcacoreana3");
	}

	if (!gRecursos.carregouSpriteSheet("forcacoreana4"))
	{
		gRecursos.carregarSpriteSheet("forcacoreana4", "imagens/forcacoreana.png", 1);
		sprite4.setSpriteSheet("forcacoreana4");
	}

	if (!gRecursos.carregouSpriteSheet("forcacoreana5"))
	{
		gRecursos.carregarSpriteSheet("forcacoreana5", "imagens/forcacoreana.png", 1);
		sprite5.setSpriteSheet("forcacoreana5");
	}

	if (!gRecursos.carregouSpriteSheet("forcacoreana6"))
	{
		gRecursos.carregarSpriteSheet("forcacoreana6", "imagens/forcacoreana.png", 1);
		sprite6.setSpriteSheet("forcacoreana6");
	}

	if (!gRecursos.carregouSpriteSheet("trump"))
	{
		gRecursos.carregarSpriteSheet("trump", "imagens/trump.png", 1, 6 );
		sprite7.setSpriteSheet("trump");
	}

	x[1] = 400;
	y[1] = 1080;

	x[2] = 500;
	y[2] = 1080;

	x[3] = 600;
	y[3] = 1080;

	x[4] = 700;
	y[4] = 1080;

	x[5] = 800;
	y[5] = 1080;

	x[0] = 100;
	y[0] = 100;

	x[6] = -500;
	y[6] = -500;


}

void ForcaCoreana::iniciarContador()
{
	contador2++;
	contador++;
	if (contador == 680)
	   {
		forca += 1;
		contador = 0;
		contador2 = 0;
	   }

}

float ForcaCoreana::getX()
{
	return x[0], x[1], x[2], x[3], x[4];
}

float ForcaCoreana::getY()
{
	return y[0], y[1], y[2], y[3], y[4];
}

Sprite ForcaCoreana::getSprite()
{
	return Sprite();
}

void ForcaCoreana::resetarForca()
{

	forca = 0;
	contador = 0;

}

void ForcaCoreana::forcaZero()
{

	forca = 0;

}
