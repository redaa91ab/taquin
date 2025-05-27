#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "../Headers/menu.h"
#include "../Headers/preparation.h"

int menu_accueil()
{
	/* définition des variables */
	KeySym touche;
	int sortie,
		clique,
		attente;

	CreerFenetre(100, 100, 720, 525);
	ChoisirCurseur(1);
	ChoisirTitreFenetre("TAQUIN");
	ChargerImageFond("./Images/Menu.png");
	ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));
	/* par défaut, la flèche est placée sur "jouer" */
	ChargerImage("./Images/Fleche.png", 170, 210, 0, 0, 88, 43);
	sortie = 0;

	while (1)
	{
		clique = SourisCliquee();
		if (touche == XK_Up)
		{
			ChargerImageFond("./Images/Menu.png");
			ChargerImage("./Images/Fleche.png", 170, 210, 0, 0, 88, 43);
			sortie = 0;
			touche == XK_space;
		}
		if (touche == XK_Down)
		{
			ChargerImageFond("./Images/Menu.png");
			ChargerImage("./Images/Fleche.png", 170, 345, 0, 0, 88, 43);
			sortie = 1;
			touche == XK_space;
		}
		/* bouton "jouer" */
		if (clique == 1 && _X > 255 && _X < 510 && _Y > 190 && _Y < 265)
		{
			return 0;
		}
		/* bouton "quitter" */
		if (clique == 1 && _X > 255 && _X < 510 && _Y > 325 && _Y < 395)
		{
			return 1;
		}
		attente= ToucheEnAttente();
		if (attente == 1)
		{
			touche = Touche();
			if (touche == XK_Return)
			{
				return sortie;
			}
		}
	}
}

void charger_image(choix* choix_joueur)
{
	ChargerImageFond("./Images/Fond.png");

	/* image */
	if (choix_joueur->image == 2)
	{
		DessinerRectangle(19, 87, 250, 139);
	}
	if (choix_joueur->image == 1)
	{
		DessinerRectangle(295, 66, 200, 200);
	}
	if (choix_joueur->image == 3)
	{
		DessinerRectangle(520, 28, 175, 274);
	}

	/* lignes */
	for (int ligne = 0; ligne < 6; ligne++)
	{
		if (choix_joueur->nb_lignes == (ligne + 3))
		{
			ChargerImage("./Images/check.png",(ligne * 57 + 168), 360, 0, 0, 40, 40);
		}
	}

	/* colonnes */
	for (int colonne = 0; colonne < 6; ++colonne)
	{
		if (choix_joueur->nb_colonnes == (colonne + 3))
		{
			ChargerImage("./Images/check.png",(colonne * 57 + 168), 426, 0, 0, 40, 40);
		}
	}

	return;
}

void placer_cuseur(int selection)
{
	/* image n°1 */
	if (selection == 1)
	{
		RemplirArc(19, 72, 15, 15, 0, 360);
	}
	/* image n°2 */
	if (selection == 2)
	{
		RemplirArc(295, 51, 15, 15, 0, 360);
	}
	/* image n°3*/
	if (selection == 3)
	{
		RemplirArc(520, 13, 15, 15, 0, 360);
	}
	for (int ligne = 0; ligne < 6; ++ligne)
	{
		if (selection == 4 + ligne)
		{
			RemplirArc((ligne * 57 + 168), 340, 15, 15, 0, 360);
		}
	}
	for (int colonne = 0; colonne < 6; ++colonne)
	{
		if (selection == 10 + colonne)
		{
			RemplirArc((colonne * 57 + 168), 411, 15, 15, 0, 360);
		}
	}
	/* bouton "jouer" */
	if (selection == 16)
	{
		RemplirArc(525, 340, 15, 15, 0, 360);
	}

	return;
}

void menu_image(choix* choix_joueur)
{
	KeySym touche;
	int i,
		clique,
		attente,
		selection;

	ChoisirCouleurDessin(CouleurParComposante(255, 255, 255));

	charger_image(choix_joueur);
	/* par défaut, le premier objet est séléctionné */
	selection = 1;
	placer_cuseur(selection);

	while (1)
	{
		clique = SourisCliquee();
		attente = ToucheEnAttente();
		if (attente == 1)
		{
			touche = Touche();
		}
		/* choix de l'image */
		if ((clique == 1 && _X > 19 && _X < 269 && _Y > 87 &&_Y < 226) || (selection == 1 && touche == XK_Return))
		{
			choix_joueur->image = 2;
			charger_image(choix_joueur);
			selection = 1;
			placer_cuseur(selection);
			touche = 0;
		} else if ((clique == 1 && _X > 295 && _X < 495 && _Y > 66 &&_Y < 266) || (selection == 2 && touche == XK_Return))
		{
			choix_joueur->image = 1;
			charger_image(choix_joueur);
			selection = 2;
			placer_cuseur(selection);
			touche = 0;
		} else if ((clique == 1 && _X > 520 && _X < 695 && _Y > 28 &&_Y < 302) || (selection == 3 && touche == XK_Return))
		{
			choix_joueur->image = 3;
			charger_image(choix_joueur);
			selection = 3;
			placer_cuseur(selection);
			touche = 0;
		}

		/* choix du nombre de colonnes */
		for(i = 0; i < 6; ++i)
		{
			if ((clique == 1 && _X > (i * 57 + 168) && _X < (i * 57 + 212) && _Y > 355 &&_Y < 400) || (selection == 4 + i && touche == XK_Return))
			{
				choix_joueur->nb_lignes = (i + 3);
				charger_image(choix_joueur);
				selection = 4 + i;
				placer_cuseur(selection);
				touche = 0;
			}
		}

		/* choix du nombre de lignes */
		for(i = 0; i < 6; ++i)
		{
			if ((clique == 1 && _X > (i * 57 + 168) && _X < (i * 57 + 212) && _Y > 422 &&_Y < 466) || (selection == 10 + i && touche == XK_Return))
			{
				choix_joueur->nb_colonnes = i + 3;
				charger_image(choix_joueur);
				selection = 10 + i;
				placer_cuseur(selection);
				touche = 0;
			}
		}

		/* deplacement de la sélecton vers la droite */
		if (touche == XK_Right && selection != 16)
		{
			/* passer du bouton 8 lignes au bouton "jouer" en appuyant sur droite */
			if (selection != 9)
			{
				selection++;
			} else
			{
				(selection = 16);
			}
			charger_image(choix_joueur);
			placer_cuseur(selection);
			touche = 0;
		}

		/* deplacement de la sélection vers la gauche */
		if (touche == XK_Left && selection != 1)
		{
			selection--;
			charger_image(choix_joueur);
			placer_cuseur(selection);
			touche = 0;
		}

		/* déplacement de la sélection vers le haut*/
		if (touche == XK_Down && (selection < 4 || (selection > 3 && selection < 10)))
		{
			if (selection < 4)
			{
				selection = 4;
			} else if (selection > 3 && selection < 10)
			{
				selection += 6;
			}
			charger_image(choix_joueur);
			placer_cuseur(selection);
			touche = 0;
		}

		/* déplacement de la sélection vers le bas */
		if (touche == XK_Up && ((selection > 3 && selection < 10) || selection > 9))
		{
			if (selection > 3 && selection < 10)
			{
				selection = 1;
			} else if (selection > 9)
			{
				selection -= 6;
			}
			charger_image(choix_joueur);
			placer_cuseur(selection);
			touche = 0;
		}

		/* bouton "jouer" */
		if ((clique == 1 && _X > 525 && _X < 705 && _Y > 355 &&_Y < 480) || (selection == 16 && touche == XK_Return))
		{
			/* empèche les problèmes causés par la positions de la souris */
			_X = 0;
			_Y = 0;

			return;
		}
	}
}

int menu_jeu(int v, int partie[], choix* choix_joueur, info_image* img, KeySym touche)
{
	int sortie;

	if (choix_joueur->image == 1 && _X > 500 + 5 + 10 * choix_joueur->nb_lignes && _X < 500 + 191 + 10 * choix_joueur->nb_lignes && _Y > 289 + 10 && _Y < 328 + 10 && v != 0) /* bouton "re-mélanger" de l'image n°1 */
	{
		melanger(partie, choix_joueur, img);
		sortie = 0;
	} else if (choix_joueur->image == 2 && _X > 960 + 52 + 10 * choix_joueur->nb_lignes && _X < 960 + 238 + 10 * choix_joueur->nb_lignes && _Y > 288 + 10 && _Y < 328 + 10 && v != 0) /* bouton "re-mélanger" de l'image n°2 */
	{
		melanger(partie, choix_joueur, img);
		sortie = 0;
	} else if (choix_joueur->image == 3 && _X > 408 + 6 + 10 * choix_joueur->nb_lignes && _X < 408 + 192 + 10 * choix_joueur->nb_lignes && _Y > 393 + 10 && _Y < 432 + 10 && v != 0) /* bouton "re-mélanger" de l'image n°3 */
	{
		melanger(partie, choix_joueur, img);
		sortie = 0;
	} else if ((touche == XK_r || touche == XK_R) && v !=0) /* bouton "re-mélanger" par clavier */
	{
		melanger(partie, choix_joueur, img);
		sortie = 0;
	} else if (choix_joueur->image == 1 && _X > 500 + 7 + 10 * choix_joueur->nb_lignes && _X < 500 + 191 + 10 * choix_joueur->nb_lignes && _Y > 351 + 10 && _Y < 387 + 10) /* bouton "retour menu" de l'image n°1 */
	{
		sortie = 1;
	} else if (choix_joueur->image == 2 && _X > 960 + 54 + 10 * choix_joueur->nb_lignes && _X < 960 + 238 + 10 * choix_joueur -> nb_lignes && _Y > 350 + 10 && _Y < 386 + 10) /* bouton "retour menu" de l'image n°2 */
	{
		sortie = 1;
	} else if (choix_joueur->image == 3 && _X > 408 + 8 + 10 * choix_joueur->nb_lignes && _X < 408 + 192 + 10 * choix_joueur->nb_lignes && _Y > 455 + 10 && _Y < 491 + 10) /* bouton "retour menu" de l'image n°3 */
	{
		sortie = 1;
	} else if (touche == XK_BackSpace) /* bouton "retour menu" par clavier */
	{
		sortie = 1;
	} else if (choix_joueur->image == 1 && _X > 500 + 6 + 10 * choix_joueur->nb_lignes && _X < 500 + 190 + 10 * choix_joueur->nb_lignes && _Y > 412 + 10 && _Y < 446 + 10) /* bouton "quitter" de l'image n°1 */
	{
		sortie = 2;
	} else if (choix_joueur->image == 2 && _X > 960 + 53 + 10 * choix_joueur->nb_lignes && _X < 960 + 237 + 10 * choix_joueur->nb_lignes && _Y > 410 + 10 && _Y < 445 + 10) /* bouton "quitter" de l'image n°2 */
	{
		sortie = 2;
	} else if (choix_joueur->image == 3 && _X > 408 + 7 + 10 * choix_joueur->nb_lignes && _X < 408 + 191 + 10 * choix_joueur->nb_lignes && _Y > 516 + 10 && _Y < 550 + 10) /* bouton "quitter" de l'image n°3 */
	{
		sortie = 2;
	} else if (touche == XK_Escape) /* bouton "quitter" par clavier */
	{
		sortie = 2;
	}
	/* empeche d'activer les mauvais boutons en repassant dans cette fonction par l'appuie sur une touche du clavier */
	_X = 0;
	_Y = 0;

	return sortie;
}

void affichage_victoire(choix * choix_joueur)
{
	ChoisirCouleurDessin(CouleurParComposante(60, 60, 60));
	if (choix_joueur->image == 1)
	{	/* masque l'image */
		RemplirRectangle(10, 10, 500 + 4 * ((choix_joueur->nb_colonnes + 1)), 600);
		/* masque le mini taquin */
		RemplirRectangle(500 + 6 * choix_joueur->nb_colonnes, 10, 220, 220);
		/* masque le bouton "re-melanger */
		RemplirRectangle(500 + 6 * choix_joueur->nb_colonnes, 289, 210, 50);

		ChargerImage("./Images/Taquin.png", 10, 10, 0, 0, 500, 500);
		ChargerImage("./Images/Victory.png", 500 + 6 * choix_joueur->nb_colonnes, 10, 0, 0, 182, 204);
	}
	if (choix_joueur->image == 2)
	{
		/* masque l'image */
		RemplirRectangle(0, 0, 1000 + 4 * (choix_joueur -> nb_colonnes + 1), 600);
		/* masque le mini taquin */
		RemplirRectangle(960 + 10 * choix_joueur->nb_colonnes, 10, 288, 180);
		/* cache le bouton "re-melanger */
		RemplirRectangle(960 + 10 * choix_joueur->nb_colonnes, 290, 288, 50);

		ChargerImage("./Images/Taquin2.png", 10, 10, 0, 0, 960, 540);
		ChargerImage("./Images/Victory.png", 1000 + 10 * choix_joueur->nb_colonnes, 10, 0, 0, 182, 204);
	}
	if (choix_joueur->image==3)
	{
		/* masque l'image */
		RemplirRectangle(0, 0, 420 + 4 * (choix_joueur->nb_colonnes + 1), 700);
		/* masque le mini taquin */
		RemplirRectangle(408 + 10 * choix_joueur->nb_colonnes, 10, 197, 300);
		/* cache le bouton "re-melanger */
		RemplirRectangle(408 + 10 * choix_joueur->nb_colonnes, 393, 197, 50);

		ChargerImage("./Images/Taquin3.png", 10, 10, 0, 0, 408, 638);
		ChargerImage("./Images/Victory.png", 408 + 10 * choix_joueur->nb_colonnes, 10, 0, 0, 182, 204);
	}

	return;
}