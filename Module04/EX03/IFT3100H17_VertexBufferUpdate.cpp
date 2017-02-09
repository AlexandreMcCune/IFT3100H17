// IFT3100H17_VertexBufferUpdate.cpp
// Exemple d'une section de code pour faire la mise à jour des valeurs des attributs d'un intervalle continu de sommets d'un buffer de géométrie.

// précondition
// - identifiant unique d'un buffer de géométrie
GLuint vbo;
// - données de sommets à mettre à jour
int count;
int offset;
VertexStruct * vertexArray

// postcondition
// - mise à jour des valeurs des attributs d'un intervalle continu de sommets du buffer de géométrie

// sélectionner le buffer de géométrie à mettre à jour
glBindBuffer(GL_ARRAY_BUFFER, vbo);

// téléverser un intervalle continu de sommets de la mémoire RAM vers le buffer de géométrie en mémoire GPU
glBufferSubData(GL_ARRAY_BUFFER, offset * sizeof(VertexStruct), count * sizeof(VertexStruct), vertexArray);
