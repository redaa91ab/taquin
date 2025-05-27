# Jeu de Taquin – SAÉ 1.1 (BUT Informatique UPEC)

Projet réalisé en première année de BUT Informatique à l’IUT de Fontainebleau (UPEC), dans le cadre de la SAÉ 1.1 (Développement).  
Ce jeu de taquin codé en C permet de reconstituer une image mélangée en déplaçant des tuiles, avec le clavier ou la souris.

## Fonctionnalités

- Choix de l’image et de la taille de la grille (3x3 à 8x8)
- Mélange aléatoire des tuiles (une case vide)
- Déplacements valides via clavier ou souris
- Affichage du nombre de coups
- Détection de fin de partie et relance possible

## Structure du projet

- `main.c` : point d’entrée du programme
- `menu.c` : configuration initiale
- `preparation.c` : création et affichage de la grille
- `deplacements.c` : logique de déplacement et mélange

## Compilation

```bash
gcc main.c menu.c preparation.c deplacements.c -o taquin -lSDL
./taquin
