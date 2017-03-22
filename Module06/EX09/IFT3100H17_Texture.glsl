// IFT3100H17_Texture.glsl
// Exemples de manipulation de texture en GLSL.

// exemple 1 : coordonnées de mapping en attribut d'entrée
in vec2 texcoord;

// exemple 2 : définition d'un échantillonneur de texture
uniform sampler2D texture1;
uniform sampler2D texture2;

// exemple 3 : échantillonner une texture
vec4 sample1 = texture(texture1, texcoord);
vec4 sample2 = texture(texture2, texcoord);

// exemple 4 : mixer 2 échantillons de texture avec une équation
vec4 color1 = (1.0 - sample2.a) * sample1 + sample2.a * sample2;

// exemple 5 : mixer 2 échantillons de texture avec la fonction mix
vec4 color2 = mix(sample1, sample2, sample2.a);

// note: les 2 précédents exemples sont équivalents à la fonction de composition avec transparence de OpenGL : glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

