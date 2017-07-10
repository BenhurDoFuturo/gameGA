#include "Jogo.h"
#include "Navio.h"
#include "Inimigo.h"
#include "Ship.h"
#include "Missil.h"
#include "ForcaCoreana.h"
#include "Kim.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1215, 1115, true);

	status = sTelaInicial;

	gRecursos.carregarMusica("musicafim", "sons/musicafim.mp3");
	gRecursos.carregarMusica("musicachefao", "sons/musicachefao.mp3");
	gRecursos.carregarMusica("musicaganhou", "sons/musicaganhou.mp3");
	
	if (!gRecursos.carregouMusica("musicajogo"))
	{
		gRecursos.carregarMusica("musicajogo", "sons/musicajogo.wav");
	}
	if (!gRecursos.carregouMusica("musicamenu"))
	{
		gRecursos.carregarMusica("musicamenu", "sons/musicamenu.mp3");
	}

	if (!gRecursos.carregouFonte("BRAINSTORM"))
	{
		gRecursos.carregarFonte("BRAINSTORM", "fontes/Brainstorm.OTF", 48);
	}
	texto.setFonte("BRAINSTORM");
	texto.setAncora(0, 0.5);

	if (!gRecursos.carregouSpriteSheet("fundo"))
	{
		gRecursos.carregarSpriteSheet("fundo", "imagens/fundo.png");
	}
	sprite.setSpriteSheet("fundo");

	if (!gRecursos.carregouSpriteSheet("fundomenu"))
	{
		gRecursos.carregarSpriteSheet("fundomenu", "imagens/fundomenu.png");
	}
	sprite2.setSpriteSheet("fundomenu");


	


	submarino.inicializar();
	municao.inicializar();
	
	missil[0].inicializar();
	missil[1].inicializar();
	
	inimigo[0].inicializar();
	inimigo[1].inicializar();

	ship.inicializar();

	kim.inicializar();

	forcacoreana.inicializar();

	musicatocando = true;
}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while (!gTeclado.pressionou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();


		switch (status)
		{
		case sTelaInicial: telaInicial();
			break;
		case sTelaJogo: telaJogo();
			break;
		case sTelaCreditos: telacreditos();
			break;
		case sTelaInstrucoes: telaInstrucoes();
			break;
		case sTelaFimJogo: telaFimJogo();
			break;
		case sTelaVenceu: telaVenceu();
			break;
		default:
			break;
		}


		uniTerminarFrame();
	}

}

void Jogo::telaJogo()
{   

	if (!gRecursos.carregouAudio("tiro"))
	{
		gRecursos.carregarAudio("tiro", "sons/tiro.mp3");
	}
	submarino.setAudio("tiro");

	if (!gRecursos.carregouAudio("explosao"))
	{
		gRecursos.carregarAudio("explosao", "sons/Explosao.wav");
	}
	submarino.setAudio2("explosao");

	if (!gRecursos.carregouAudio("pegarammo"))
	{
		gRecursos.carregarAudio("pegarammo", "sons/pegarmun.wav");
	}
	submarino.setAudio3("pegarammo");

	if (!gRecursos.carregouAudio("entregarammo"))
	{
		gRecursos.carregarAudio("entregarammo", "sons/entregar.mp3");
	}
	submarino.setAudio4("entregarammo");
	
	if (musicatocando == true && gMusica.getNomeMusica() != "musicajogo")
		gMusica.tocar("musicajogo", true);
	sprite.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	
	ship.atualizar();
	ship.desenhar();

	texto.setString("Vidas: " + to_string(submarino.getVida()));
	texto.desenhar(100,100);

	texto.setString("Pontuação: " + to_string(submarino.getPontuacao()));
	texto.desenhar(500, 100);

	texto.setString("Municao: " + to_string(submarino.getAmmo()));
	texto.desenhar(900, 100);

	texto.setString("Força Coreana:");
	texto.desenhar(60, 1070);

	municao.atualizar();
	municao.desenhar();

	missil[0].atualizar();
	missil[0].desenhar();

	missil[1].atualizar();
	missil[1].desenhar();

	submarino.atualizar();
	submarino.desenhar();

	forcacoreana.atualizar();
	forcacoreana.desenhar();
	forcacoreana.iniciarContador();
	


	for (int in = 0; in < 2; in++)
	{

		inimigo[in].atualizar();
		inimigo[in].desenhar();

		if (submarino.getPontuacao() >= 500)
		{
			inimigo[in].setVel(2.3);
		}

		if (submarino.getPontuacao() >= 1000)
		{
			inimigo[in].setVel(2.8);
			submarino.setVel(1.85);
		}

		if (submarino.getPontuacao() >= 1500)
		{
			inimigo[in].setVel(3.6);
			submarino.setVel(1.98);
		}

		if (submarino.getPontuacao() >= 2000)
		{
			musicatocando = false;
			inimigo[in].destruir();
			submarino.setVel(2);
			kim.viver();
			kim.atualizar();
			kim.desenhar();
			forcacoreana.setPausarForca(-10000);

			if (gMusica.getNomeMusica() != "musicachefao")
				gMusica.tocar("musicachefao", true);

	        


			
		}

		if (uniTestarColisaoSpriteComSprite(kim.getSprite(), kim.getX(), kim.getY(), 0,
			submarino.getSpriteTiro(), submarino.getXTiro(), submarino.getYTiro(), 0) && submarino.getTiro() && kim.getVivo() && kim.getVida() > 1)
		{

			kim.perderVida();

			submarino.matarTiro();

			submarino.aumentarPontos();

			submarino.tocarExplosao();


		}

		if (uniTestarColisaoSpriteComSprite(kim.getSprite(), kim.getX(), kim.getY(), 0,
			submarino.getSpriteTiro(), submarino.getXTiro(), submarino.getYTiro(), 0) && submarino.getTiro() && kim.getVivo() && kim.getVida() == 1)
		{

			kim.destruir();
			
			submarino.matarTiro();

			submarino.aumentarPontos();

			submarino.tocarExplosao();

		}
		if (uniTestarColisaoSpriteComSprite(kim.getSpriteTiro(), kim.getXTiro(), kim.getYTiro(), 0,
			submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && kim.getVivo() && kim.getTiroVivo())
		{

			kim.matarTiro();

			submarino.perderVida();

			submarino.tocarExplosao();

			if (submarino.getVida() == 0)
			{
				status = sTelaFimJogo;
			}
		}

		if (uniTestarColisaoSpriteComSprite(kim.getSprite(), kim.getX(), kim.getY(), 0,
			submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && kim.getVivo())
		{

			submarino.perderVida();

			submarino.tocarExplosao();

			if (submarino.getVida() == 0)
			{
				status = sTelaFimJogo;
			}
		}


		if (uniTestarColisaoSpriteComSprite(inimigo[in].getSprite(), inimigo[in].getX(), inimigo[in].getY(), 0,
			submarino.getSpriteTiro(), submarino.getXTiro(), submarino.getYTiro(), 0) && submarino.getTiro() && inimigo[in].getVivo())
		{

			//COLOQUE OS SONS CORRESPONDENTES EM CADA COLISÃO, A MAIORIA É CTRL-C CTRL-V
			inimigo[in].morrer();
			
			submarino.tocarExplosao();

			submarino.matarTiro();

			submarino.aumentarPontos();

		}


		if (uniTestarColisaoSpriteComSprite(inimigo[in].getSpriteTiro(), inimigo[in].getXTiro(), inimigo[in].getYTiro(), 0,
			submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && inimigo[in].getTiroVivo())
		{

			inimigo[in].matarTiro();

			submarino.tocarExplosao();

			submarino.perderVida();

			if (submarino.getVida() == 0)
			{
				status = sTelaFimJogo;
			}
		}
		if (uniTestarColisaoSpriteComSprite(inimigo[in].getSprite(), inimigo[in].getX(), inimigo[in].getY(), 0,
			submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && inimigo[in].getVivo())
		{

			inimigo[in].morrer();

			submarino.perderVida();

			submarino.tocarExplosao();

			if (submarino.getVida() == 0)
			{
				status = sTelaFimJogo;
			}
		}


	}

	for (int mis = 0; mis < 2; mis++)
	{
		if (submarino.getPontuacao() >= 500)
		{
			missil[mis].setVel(3.4);
		}

		if (submarino.getPontuacao() >= 1000)
		{
			missil[mis].setVel(3.6);
		}

		if (submarino.getPontuacao() >= 1500)
		{
			missil[mis].setVel(3.7);
		}


		if (uniTestarColisaoSpriteComSprite(missil[mis].getSprite(), missil[mis].getX(), missil[mis].getY(), 0,
			submarino.getSpriteTiro(), submarino.getXTiro(), submarino.getYTiro(), 0) && submarino.getTiro() && missil[mis].getVivo())
		{

			submarino.tocarExplosao();

			missil[mis].morrer();

			submarino.matarTiro();

			submarino.aumentarPontos();

		}

		if (uniTestarColisaoSpriteComSprite(missil[mis].getSprite(), missil[mis].getX(), missil[mis].getY(), 0,
			submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && missil[mis].getVivo())
		{

			submarino.tocarExplosao();

			missil[mis].morrer();

			submarino.perderVida();

			if (submarino.getVida() == 0)
			{
				status = sTelaFimJogo;
			}
		}
	}

	if (uniTestarColisaoSpriteComSprite(municao.getSprite(), municao.getX(), municao.getY(), 0,
		submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && municao.getVivo() && submarino.getAmmo() < 5)
	{
		submarino.pegarAmmo();

		municao.morrer();

		submarino.pegarMunicao();
	}

	if (uniTestarColisaoSpriteComSprite(ship.getSprite(), ship.getX(), ship.getY(), 0,
		submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && submarino.getAmmo() == 1 && forcacoreana.getForca() == 1)
	{
		submarino.setAmmo();
		forcacoreana.resetarForca();
		submarino.aumentarPontos();
		submarino.entregarAmmo();
	}

	if (uniTestarColisaoSpriteComSprite(ship.getSprite(), ship.getX(), ship.getY(), 0,
		submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && submarino.getAmmo() == 1 && forcacoreana.getForca() > 1)
	{
		submarino.setAmmo();
		forcacoreana.setForca(1);
		submarino.aumentarPontos();
		submarino.entregarAmmo();
	}

	if (uniTestarColisaoSpriteComSprite(ship.getSprite(), ship.getX(), ship.getY(), 0,
		submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && submarino.getAmmo() == 2 && forcacoreana.getForca() >= 2)
	{
		submarino.setAmmo();
		forcacoreana.setForca(2);
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.entregarAmmo();
	}

	if (uniTestarColisaoSpriteComSprite(ship.getSprite(), ship.getX(), ship.getY(), 0,
		submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && submarino.getAmmo() == 2 && forcacoreana.getForca() < 2)
	{
		submarino.setAmmo();
		forcacoreana.forcaZero();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.entregarAmmo();
	}

	if (uniTestarColisaoSpriteComSprite(ship.getSprite(), ship.getX(), ship.getY(), 0,
		submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && submarino.getAmmo() == 3 && forcacoreana.getForca() >= 3)
	{
		submarino.setAmmo();
		forcacoreana.setForca(3);
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.entregarAmmo();
	}

	if (uniTestarColisaoSpriteComSprite(ship.getSprite(), ship.getX(), ship.getY(), 0,
		submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && submarino.getAmmo() == 3 && forcacoreana.getForca() < 3)
	{
		submarino.setAmmo();
		forcacoreana.forcaZero();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.entregarAmmo();
	}

	if (uniTestarColisaoSpriteComSprite(ship.getSprite(), ship.getX(), ship.getY(), 0,
		submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && submarino.getAmmo() == 4 && forcacoreana.getForca() >= 4)
	{
		submarino.setAmmo();
		forcacoreana.setForca(4);
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.entregarAmmo();
	}

	if (uniTestarColisaoSpriteComSprite(ship.getSprite(), ship.getX(), ship.getY(), 0,
		submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && submarino.getAmmo() == 4 && forcacoreana.getForca() < 4)
	{
		submarino.setAmmo();
		forcacoreana.forcaZero();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.entregarAmmo();
	}

	if (uniTestarColisaoSpriteComSprite(ship.getSprite(), ship.getX(), ship.getY(), 0,
		submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && submarino.getAmmo() == 5 && forcacoreana.getForca() >= 5)
	{
		submarino.setAmmo();
		forcacoreana.setForca(5);
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.entregarAmmo();
	}

	if (uniTestarColisaoSpriteComSprite(ship.getSprite(), ship.getX(), ship.getY(), 0,
		submarino.getSprite(), submarino.getX(), submarino.getY(), 0) && submarino.getAmmo() == 5 && forcacoreana.getForca() < 5)
	{
		submarino.setAmmo();
		forcacoreana.forcaZero();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.aumentarPontos();
		submarino.entregarAmmo();
	}

		

	if (forcacoreana.getForca() == 6)
	{
		status = sTelaFimJogo;
	}
	if (kim.getVenceuJogo() == true)
	{
		status = sTelaVenceu;
	} 
}
void Jogo::telaInicial()
{

	sprite2.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	if (gMusica.getNomeMusica() != "musicamenu")
		gMusica.tocar("musicamenu", true);
	
	texto.setString("(J) - Jogar");
	texto.desenhar(20, 500);
	texto.setString("(I) - Instruções");
	texto.desenhar(20, 550);
	texto.setString("(C) - Créditos");
	texto.desenhar(20, 600);
	



	if (gTeclado.pressionou[TECLA_J])
	{
		status = sTelaJogo;
	}
	if (gTeclado.pressionou[TECLA_I])
	{
		status = sTelaInstrucoes;
	}
	if (gTeclado.pressionou[TECLA_C])
	{
		status = sTelaCreditos;
	}
	if (gTeclado.pressionou[TECLA_S])
	{
		status = sSair;
	}

}


void Jogo::telaInstrucoes()
{
	if (gMusica.getNomeMusica() != "musicamenu")
		gMusica.tocar("musicamenu", true);
	texto.setString("Mova-se com as teclas de setas.");
	texto.desenhar(50, 307);
	texto.setString("Atire com espaço.");
	texto.desenhar(50, 407);
	texto.setString("Pegue as munições e entregue-as no cargueiro");
	texto.desenhar(50, 507);
	texto.setString("antes que as forças coreanas atinjam seu poder máximo");
	texto.desenhar(50, 550);
	texto.setString("Aperte 'V' para voltar ao menu");
	texto.desenhar(300, 900);
	if (gTeclado.pressionou[TECLA_V])
	{
		status = sTelaInicial;
	}

}

void Jogo::telacreditos()
{
	if (gMusica.getNomeMusica() != "musicamenu")
		gMusica.tocar("musicamenu", true);
	texto.setString("Sprites e Programação: Andrei Souza");
	texto.desenhar(100, 400);
	texto.setString("Programação: Benhur Farias");
	texto.desenhar(100, 500);
	texto.setString("Feito com libUnicornio 1.1");
	texto.desenhar(100, 600);
	texto.setString("Aperte 'V' para voltar ao menu");
	texto.desenhar(300, 900);
	if (gTeclado.pressionou[TECLA_V])
	{
		status = sTelaInicial;
	}

}

void Jogo::telaFimJogo()
{

	texto.setString("GAME OVER");
	texto.desenhar(450, 507);

	texto.setString("Aperte 'V' para voltar ao menu");
	texto.desenhar(300, 707);

	if (gMusica.getNomeMusica() != "musicafim")
		gMusica.tocar("musicafim", true);

	if (gTeclado.pressionou[TECLA_V])
	{
		submarino.resetarPontos();
		submarino.resetarPosicao();
		submarino.setAmmo();
		inimigo[0].resetarPosicao();
		inimigo[1].resetarPosicao();
		inimigo[2].resetarPosicao();
		missil[0].resetarPosicao();
		missil[1].resetarPosicao();
		missil[2].resetarPosicao();
		inimigo[0].matarTiro();
		inimigo[1].matarTiro();
		inimigo[2].matarTiro();
		forcacoreana.resetarForca();
		kim.resetarPosicao();
		submarino.resetarVel();
		inimigo[0].resetarVel();
		inimigo[1].resetarVel();
		inimigo[2].resetarVel();
		missil[0].resetarVel();
		missil[1].resetarVel();
		missil[2].resetarVel();
		musicatocando = true;
		status = sTelaInicial;
	}
}

void Jogo::telaVenceu()
{
	if (gMusica.getNomeMusica() != "musicaganhou")
		gMusica.tocar("musicaganhou", true);

	texto.setString("Parabéns! Você venceu Kim Jong Un!");
	texto.desenhar(300, 300);
	texto.setString("Obrigado por jogar!");
	texto.desenhar(300, 500);
	texto.setString("Aperte 'V' para voltar ao menu");
	texto.desenhar(300, 900);


	if (gTeclado.pressionou[TECLA_V])
	{
		submarino.resetarPontos();
		submarino.resetarPosicao();
		submarino.setAmmo();
		inimigo[0].resetarPosicao();
		inimigo[1].resetarPosicao();
		inimigo[2].resetarPosicao();
		missil[0].resetarPosicao();
		missil[1].resetarPosicao();
		missil[2].resetarPosicao();
		inimigo[0].matarTiro();
		inimigo[1].matarTiro();
		inimigo[2].matarTiro();
		forcacoreana.resetarForca();
		kim.resetarPosicao();
		submarino.resetarVel();
		inimigo[0].resetarVel();
		inimigo[1].resetarVel();
		inimigo[2].resetarVel();
		missil[0].resetarVel();
		missil[1].resetarVel();
		missil[2].resetarVel();
		musicatocando = true;

		status = sTelaInicial;
	}
	
}
