#ifndef PREPARATION_H
#define PREPARATION_H

void preparer_partie(choix* choix_joueur, info_image* img, int partie[]);
/* ouvre la fenêtre et remplis des variables requises pour d'autres fonctions, affiche
   l'image découpée et la mélange */

void initialiser_tableau(int partie[], choix* choix_joueur);
/* initialise un tableau qui représenterant l'image avant le mélange */

void melanger(int partie[], choix* choix_joueur, info_image* img);
/* effectue de nombreuses fois les déplacements autorisés */

#endif /* PREPARATION_H */