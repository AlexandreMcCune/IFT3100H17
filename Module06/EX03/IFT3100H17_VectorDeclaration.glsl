// IFT3100H17_VectorDeclaration.glsl
// Exemples de déclaration de variables de type vecteur en GLSL.

// exemple 1 : déclaration d'un vecteur avec trois dimensions (nombres entiers)
ivec3 ivector3D = ivec3(1, 2, 3);

// exemple 2 : déclaration d'un vecteur avec deux dimensions (nombres réels)
vec2 vector2D = vec2(1.0, 2.0);

// exemple 3 : déclaration d'un vecteur avec trois dimensions (nombres réels)
vec3 vector3D = vec3(1.0, 2.0, 3.0);

// exemple 4 : déclaration d'un vecteur avec quatre dimensions (nombres réels)
vec4 vector4D = vec4(1.0, 2.0, 3.0, 4.0);

// exemple 5 : déclaration d'un vecteur avec trois dimensions qui ont la même valeur initiale
vec3 vectorOf1 = vec3(1.0); // équivalent à vec3(1.0, 1.0, 1.0)

// exemple 6 : déclaration d'un vecteur avec les quatre composantes d'une position homogène
vec4 position = vec4(vec3(0.0, 0.0, 1.0), 1.0);

// exemple 7 : déclaration d'un vecteur avec les trois composantes de la couleur blanche dans l'espace RGB
vec3 colorWhiteRGB = vec3(1.0);

// exemple 8 : déclaration d'un vecteur avec les quatre composantes de la couleur blanche dans l'espace RGBA
vec4 colorWhiteRGBA = vec4(1.0);
