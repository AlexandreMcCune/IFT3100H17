// IFT3100H17_VectorComponent.glsl
// Exemples d’accès aux composantes d’un vecteur en GLSL.

// variables locales
vec3 v = vec3(1.0, 2.0, 3.0);
vec3 result;
float component;

// exemple 1 : lecture par index de composante
component = v[0];
component = v[1];
component = v[2];

// exemple 2 : écriture par index de composante
v[0] = 1.0;
v[1] = 2.0;
v[2] = 3.0;

// exemple 3 : lecture par étiquette de composante de transformation
component = v.x;
component = v.y;
component = v.z;

// exemple 4 : écriture par étiquette de composante de transformation
v.x = 1.0;
v.y = 2.0;
v.z = 3.0;

// exemple 5 : lecture par étiquette de composante de couleur
component = v.r;
component = v.g;
component = v.b;

// exemple 6 : écriture par étiquette de composante de couleur
v.r = 1.0;
v.g = 2.0;
v.b = 3.0;

// exemple 7 : lecture par étiquette de composante de texture
component = v.s;
component = v.t;
component = v.p;

// exemple 8 : écriture par étiquette de composante de texture
v.s = 1.0;
v.t = 2.0;
v.p = 3.0;

// exemple 9 : swizzle par étiquette de composante de transformation
result = v.xyz; // result = (1.0, 2.0, 3.0)
result = v.zyx; // result = (3.0, 2.0, 1.0)
result = v.xzy; // result = (1.0, 3.0, 2.0)
result = v.yxz; // result = (2.0, 1.0, 3.0)
result = v.xxx; // result = (1.0, 1.0, 1.0)

// exemple 10 : swizzle par étiquette de composante de couleur
result = v.rgb; // result = (1.0, 2.0, 3.0)
result = v.bgr; // result = (3.0, 2.0, 1.0)
result = v.rbg; // result = (1.0, 3.0, 2.0)
result = v.grb; // result = (2.0, 1.0, 3.0)
result = v.rrr; // result = (1.0, 1.0, 1.0)

// exemple 11 : swizzle par étiquette de composante de texture
result = v.stp;  // result = (1.0, 2.0, 3.0)
result = v.pts;  // result = (3.0, 2.0, 1.0)
result = v.spt;  // result = (1.0, 3.0, 2.0)
result = v.tsp;  // result = (2.0, 1.0, 3.0)
result = v.sss;  // result = (1.0, 1.0, 1.0)
