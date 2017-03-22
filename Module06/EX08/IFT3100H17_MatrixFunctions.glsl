// IFT3100H17_MatrixFunction.glsl
// Exemples de fonctions applicables aux variables de type matrice en GLSL.

// paramètre
mat4 m = mat4(/*...*/);

// variable locale
mat4 result;

// exemple 1 : transposition d'une matrice
result = transpose(m);

// exemple 2 : inversion d'une matrice
result = inverse(m);

// exemple 3 : déterminant d'une matrice
float d = determinant(m);
