#ifndef MENU_H
#define MENU_H

typedef struct {
	int image,
		nb_lignes,
		nb_colonnes;
}choix;

typedef struct {
	int taille_image_x,
		taille_image_y,
		coupe_x,
		coupe_y;
}info_image;

int menu_accueil();
/* affiche le menu avec les boutons "jouer" et "quitter". */

void menu_image(choix* choix_joueur);
/* affiche le menu avec les images, le nombre de lignes et le nombre de colonnes à
   choisir */

int menu_jeu(int v, int partie[], choix* choix_joueur, info_image* img, KeySym touche);
/* détecte si un bouton présent en jeu est utilisé, par rapport à l'image sélectionnée */

void charger_image(choix* choix_joueur);
/* charge la sélection de l'image et des lignes et colonnes */

void placer_curseur(int selection);
/* place le curseur sur la bonne position */

void affichage_victoire(choix* choix_joueur);
/* provoque un changement visible lors de la victoire du joueur */

#endif /* MENU_H */