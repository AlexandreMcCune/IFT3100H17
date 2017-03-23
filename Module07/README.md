# IFT3100H17

## Module 7 : Illumination

### Exemple #7.1

Démonstration de différents types de lumières et de matériaux du pipeline fixe de OpenGL (version 2.1). La scène contient trois modèles : un cube, une sphère et un teapot. Chaque modèle possède son propre matériau. L'éclairage de la scène est une lumière ambiante, directionnelle, pontuelle et projecteur.


### Exemple #7.2

Démonstration de différents types de lumières et de matériaux du pipeline moderne de OpenGL (version 4.0). La scène contient trois modèles : un cube, une sphère et un teapot. Chaque modèle possède son propre matériau. L'éclairage de la scène est une lumière ambiante, directionnelle, pontuelle et projecteur.

### Exemple #7.3

Exemple de projet qui supporte une version moderne (3.3) et une version de base (2.1) du pipeline programmable de OpenGL, avec shaders en version 330 et 120 respectivement.

Dans chaque cas, quatre shaders sont disponibles (touches 1-4), soit :
- un shader de couleur de remplissage uniforme,
- un shader avec modèle d'illumination de Lambert,
- un shader avec modèle d'illumination de Gouraud,
- un shader avec modèle d'illumination de Phong et
- un shader avec modèle d'illumination de Blinn-Phong.

Certains attributs sont animés (facteur de brillance spéculaire) ou interactifs (position de la source de lumière).
