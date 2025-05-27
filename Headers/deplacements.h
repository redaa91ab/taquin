#ifndef DEPLACEMENTS_H
#define DEPLACEMENTS_H

int deplacer_case(int deplacement, int partie[], choix* choix_joueur, info_image* img);
/* déplace la case si possible et effectue le changement sur l'image et dans le
   tableau représentant l'état actuel de l'image */

int touche_deplacement(KeySym touche);
/* traduit les touches en déplacements */

int clique_deplacement(int partie[], choix* choix_joueur, info_image* img);
/* traduit le clique de la souris en déplacement  */

int victoire(int but[], int partie[], choix* choix_joueur);
/* teste si le tableau représentant l'état de la partie est le même que celui représentant l'état attendu en cas de victoire */

void compteur_coups(int coups, choix* choix_joueur);
/* affiche la valeur de la variable coups */

#endif /* DEPLACEMENTS_H */