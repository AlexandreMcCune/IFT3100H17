// IFT3100H17_VectorFunction.glsl
// Exemples de fonctions applicables aux variables de type vecteur en GLSL.

// paramètres
vec3 normal; // normale du sommet transformée dans l'espace de la vue
vec3 light; // vecteur normalisé en direction d'une lumière
vec3 view; // vecteur normalisé en direction d'une caméra

float p; // facteur de puissance spéculaire

// exemple 1 : normaliser un vecteur
vec3 v = normalize(vec3(1.0, 2.0, 3.0));

// exemple 2 : calculer le produit croisé entre deux axes
vec3 zaxis = cross(vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0));

// exemple 3 : calculer la réflexion diffuse d'un matériau
float ndotl = dot(normal, light);

// exemple 4 : calculer la direction de la réflexion d'une lumière
vec3 r = reflect(-light, normal);

// exemple 5 : calculer la réflexion spéculaire d'un matériau
float rdotv = pow(dot(r, view) p);

// exemple 6 : calculer une combinaison des deux types de réflexion de matériau
float color = mix(ndotl, rdotv, 0.5);
