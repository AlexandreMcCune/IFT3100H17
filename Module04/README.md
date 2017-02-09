# IFT3100H17

## Module 4 : Géométrie

### Exemple #1

Exemple d'une classe minimaliste pour stocker les données des sommets d'un maillage triangulaire.

### Exemple #2
Exemple d'une section de code pour créer d'un buffer de géométrie (vbo).

### Exemple #3

Exemple d'une section de code pour faire la mise à jour des valeurs des attributs d'un intervalle continu de sommets d'un buffer de géométrie.

### Exemple #4

Exemple d'une section de code pour assigner les pointeurs vers chaque attribut de la structure de sommets du buffer de géométrie (pipeline fixe).

### Exemple #5

Exemple d'une section de code pour assigner les pointeurs vers chaque attribut de la structure de sommets du buffer de géométrie (pipeline moderne).

### Exemple #6

Exemple de différentes approches pour rendre un buffer de géométrie avec une commande de rendu :
1. dessiner un ensemble de points (point sprite)
2. dessiner un quad à partir de deux triangles connexes
3. dessiner une série de triangles connexes
4. dessiner un maillage triangulaire indexé à partir d'un buffer d'indices

### Exemple #7

Alterner deux buffers de géométrie indépendants mais avec une structure identique pour la mise à jour et l'affichage afin d'éviter de bloquer le pipeline de rendu par une lecture et une écriture dans le même buffer pendant le même frame.

### Exemple #8

Exemple de dessin d'un triangle équilatéral et calcul de certaines de ses propriétés.

### Exemple #9

Exemple de dessin des polygones réguliers du triangle au dodécagone (3-12 arêtes).

### Exemple #10

Exemple de génération aléatoire et rendu d'une soupe au triangles.

### Exemple #11

Exemple de chargement et de rendu de plusieurs instances d'un teapot importé à partir d'un fichier de géométrie externe (format .obj).
