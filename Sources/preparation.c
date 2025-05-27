#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#include "../Headers/menu.h"
#include "../Headers/preparation.h"
#include "../Headers/deplacements.h"

void preparer_partie(choix* choix_joueur, info_image* img, int partie[])
{
	couleur fond = CouleurParComposante(60, 60, 60);
	char image[20];
	int i,
		j;

	if (choix_joueur->image == 1)
	{
		CreerFenetre(100, 100, 500 + 260, 500 + 50);
		img->taille_image_x = 500;
		img->taille_image_y = 500;

	} else if (choix_joueur->image == 2)
	{
		CreerFenetre(100, 100, 960 + 400, 540 + 50);
		img->taille_image_x = 960;
		img->taille_image_y = 540;

	} else if (choix_joueur->image == 3)
	{
		CreerFenetre(100, 100, 408 + 300, 638 + 50);
		img->taille_image_x = 408;
		img->taille_image_y = 638;
	}

	ChoisirCurseur(1);
	ChoisirTitreFenetre("TAQUIN");

	EffacerEcran(fond);

	img->coupe_x = img->taille_image_x / choix_joueur->nb_colonnes;
	img->coupe_y = img->taille_image_y / choix_joueur->nb_lignes;

	if (choix_joueur->image == 1)
	{
		sprintf(image, "./Images/Taquin.png");
	}else if (choix_joueur->image == 2)
	{
		sprintf(image, "./Images/Taquin2.png");
	}else if (choix_joueur->image == 3)
	{
		sprintf(image, "./Images/Taquin3.png");
	}

	for (i = 0; i < choix_joueur->nb_colonnes; ++i)
	{
		if (i == 0)
		{
			j = 1;
		} else
		{
			j = 0;
		}
		for (; j < choix_joueur->nb_lignes; ++j)
		{
			ChargerImage(image, 10 + i * (img->coupe_x + 5), 10 + j * (img->coupe_y + 5), img->coupe_x * i, img->coupe_y * j, img->coupe_x, img->coupe_y);
		}
	}

	melanger(partie, choix_joueur, img);
	
	return;
}

void initialiser_tableau(int partie[], choix* choix_joueur)
{
	for (int i = 0; i < (choix_joueur->nb_colonnes + 2); ++i)
	{
		for (int j = 0 ; j < (choix_joueur->nb_lignes + 2); ++j)
		{
			if (i == 0 || j == 0 || i == (choix_joueur->nb_colonnes + 1) || j == (choix_joueur->nb_lignes + 1))
			{
				partie[i * 10 + j] = -1;
			} else
			{
				partie[i * 10 + j] = j + i * 10;
			}
			if (i == 1 && j == 1)
			{
				partie[i * 10 + j] = 0;
			}
		}
	}

	return;
}

void melanger(int partie[], choix* choix_joueur, info_image* img)
{
	int deplacement;

	srand((unsigned int) time(NULL));

	for (int i = 0; i < 10000; ++i)
	{
		deplacement = rand()%4;
		deplacer_case(deplacement, partie, choix_joueur, img);
	}

	return;
}