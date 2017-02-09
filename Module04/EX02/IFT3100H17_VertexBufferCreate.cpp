// IFT3100H17_VertexBufferCreate.cpp
// Exemple d'une section de code pour créer d'un buffer de géométrie (vbo).

// précondition
// - une structure de sommet avec une taille fixe pour chaque attribut
struct VertexStruct{/*...*/}
// - nombre de sommets à stocker dans le buffer de géométrie
int count;
// - données pour initialiser les sommets du buffer de géométrie

// postcondition
// - un buffer de géométrie mis en cache en mémoire GPU et prêt à l'utilisation

// calculer la taille de la structure commune à tous les sommets en nombre d'octets
int vertexBufferStride = sizeof(VertexStruct);

// calculer la taille du buffer à partir du nombre de sommets et de la taille de la structure de sommet
int vertexBufferSize = count * vertexBufferStride;

// déclarer un pointeur sur un espace mémoire du même type que la structure de sommet
VertexStruct * vertexArray;

// allouer un espace mémoire de taille suffisante pour contenir les données des attributs de tous les sommets
vertexArray = (VertexStruct *) calloc(vertexBufferSize, vertexBufferStride);

// assigner les données de chaque attribut pour chaque sommet
for(int index = 0; index < count; ++index)
{
  vertexArray[index].position[0] = // ...
  vertexArray[index].position[1] = // ...
  vertexArray[index].position[2] = // ...
  vertexArray[index].normal  [0] = // ...
  vertexArray[index].normal  [1] = // ...
  vertexArray[index].normal  [2] = // ...
  vertexArray[index].texcoord[0] = // ...
  vertexArray[index].texcoord[1] = // ...
  vertexArray[index].color   [0] = // ...
  vertexArray[index].color   [1] = // ...
  vertexArray[index].color   [2] = // ...
  vertexArray[index].color   [3] = // ...
}

// déclarer un identifiant pour référencer un nouveau buffer de géométrie
GLuint vertexBufferID;

// création d'un nouveau buffer de géométrie dont l'identifiant unique sera retourné par OpenGL
glGenBuffers(1, &vertexBufferID);

// sélectionner le nouveau buffer de géométrie
glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

// transférer les données de la mémoire RAM vers buffer de géométrie en mémoire du GPU
glBufferData(GL_ARRAY_BUFFER, vertexBufferSize, vertexArray, GL_STATIC_DRAW);

// déselectionner le buffer
glBindBuffer(GL_ARRAY_BUFFER, 0);

// les données en mémoire RAM peuvent être supprimées si le buffer de géométrie est statique
free(vertexArray);
