// IFT3100H17_VertexBufferDraw.cpp
// Exemple de différentes approches pour rendre un buffer de géométrie avec une commande de rendu :
// 1. dessiner un ensemble de points (point sprite)
// 2. dessiner un quad à partir de deux triangles connexes
// 3. dessiner une série de triangles connexes
// 4. dessiner un maillage triangulaire indexé à partir d'un buffer d'indices

// précondition
// - identifiant unique d'un buffer de géométrie préinitialisé
GLuint vbo;
// - index du premier sommet à rendre
int start;
// - nombre de sommets à rendre
int count;
// - tableau d'indices de sommet
int * indices;

// postcondition
// - rendu graphique du contenu du buffer de géométrie dans un framebuffer

// sélectionner le buffer de géométrie
glBindBuffer(GL_ARRAY_BUFFER, vbo);

// exemples de commande de rendu :

// 1. dessiner un ensemble de points (point sprite)
glDrawArrays(GL_POINTS, start, count);

// 2. dessiner un quad à partir de deux triangles connexes
glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

// 3. dessiner une série de triangles connexes
glDrawArrays(GL_TRIANGLE_STRIP, start, count);

// 4. dessiner un élément à partir d'un buffer d'indices
glDrawElements(GL_TRIANGLE_STRIP, count, GL_UNSIGNED_SHORT, indices);
