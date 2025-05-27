#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "../Headers/menu.h"
#include "../Headers/preparation.h"
#include "../Headers/deplacements.h"

int main(int argc, char const *argv[])
{
	/* définition des variables */
	choix* choix_joueur = malloc(sizeof(choix));
	info_image* img = malloc(sizeof(info_image));
	KeySym touche;
	int fin,
		coups,
		v,
		retour_fonction,
		attente,
		clique,
		deplacement,
		partie[100],
		but[100];

	while (1)
	{
		/* initialisation des valeurs vérifiant la progression du programme */
		fin = 0;
		coups = 0;
		v = 1;

		InitialiserGraphique();

		retour_fonction = menu_accueil();

		if (retour_fonction == 1)
		{
			FermerGraphique();
			free(choix_joueur);
			free(img);

			return EXIT_SUCCESS;
		}

		menu_image(choix_joueur);
		FermerGraphique();
		initialiser_tableau(partie, choix_joueur);
		initialiser_tableau(but, choix_joueur);

		InitialiserGraphique();

		preparer_partie(choix_joueur, img, partie);

		compteur_coups(coups, choix_joueur);

		/* déroulement de la partie */
		while (fin != 1)
		{
			attente = ToucheEnAttente();
			clique = SourisCliquee();
			if (attente == 1 || clique == 1)
			{
				if (attente == 1)
				{
					touche = Touche();
					deplacement = touche_deplacement(touche);
				}
				if (clique == 1)
				{
					deplacement = clique_deplacement(partie, choix_joueur, img);
				}
				retour_fonction = menu_jeu(v, partie, choix_joueur, img, touche);
				touche = 0;
				/* reboucle le programme sur le menu d'accueil */
				if (retour_fonction == 1)
				{
					fin = 1;
				}
				/* termine le programme */
				if (retour_fonction==2)
				{
					FermerGraphique();
					free(choix_joueur);
					free(img);

					return EXIT_SUCCESS;
				}

				retour_fonction = deplacer_case(deplacement, partie, choix_joueur, img);

				if (retour_fonction != 1 && deplacement != -1)
				{
					coups++;
					retour_fonction = 1;
				}

				compteur_coups(coups, choix_joueur);

				v = victoire(but,partie, choix_joueur);
				if (v == 0)
				{
					fin = 1;
				}
			}
		}
		/* en cas de victoire */
		if (v == 0)
		{
			affichage_victoire(choix_joueur);
		}

		while (v == 0)
		{
			attente = ToucheEnAttente();
			clique = SourisCliquee();
			if (clique == 1 || attente == 1)
			{
				if (attente == 1)
				{
					touche = Touche();
				}
				retour_fonction = menu_jeu(v, partie, choix_joueur, img, touche);
				touche = 0;
				/* reboucle le programme sur le menu d'accueil */
				if (retour_fonction == 1)
				{
					v = 1;
				}
				/* termine le programme */
				if (retour_fonction == 2)
				{
					FermerGraphique();
					free(choix_joueur);
					free(img);

					return EXIT_SUCCESS;
				}
			}
		}

		FermerGraphique();
	}

	/* le prog est censé se terminer a l'interieur de la boucle avec un bouton quitter,
	   on garde quand même une fin normal ici au cas où */
	free(choix_joueur);
	free(img);

	return EXIT_SUCCESS;
}