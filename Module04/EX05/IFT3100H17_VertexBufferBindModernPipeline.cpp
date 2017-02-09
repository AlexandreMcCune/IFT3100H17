// IFT3100H17_VertexBufferBindModernPipeline.cpp
// Exemple d'une section de code pour assigner les pointeurs vers chaque attribut de la structure de sommets du buffer de géométrie (pipeline moderne).

// précondition
// - identifiant unique d'un buffer de géométrie préinitialisé
GLuint vbo;

// postcondition
// - un buffer de géométrie prêt à l'utilisation où chaque attribut est adéquatement configuré

// définir l'ordre des indices des attributs de sommet
const GLuint VERTEX_ATTRIBUTE_POSITION = 0;
const GLuint VERTEX_ATTRIBUTE_NORMAL   = 1;
const GLuint VERTEX_ATTRIBUTE_TEXCOORD = 2;
const GLuint VERTEX_ATTRIBUTE_COLOR    = 3;

// sélectionner le buffer de géométrie
glBindBuffer(GL_ARRAY_BUFFER, vbo);

// assigner les pointeurs vers chaque attribut de la structure de sommets du buffer de géométrie
glVertexAttribPointer(VERTEX_ATTRIBUTE_POSITION, 2, GL_FLOAT,         GL_FALSE, sizeof(VertexStruct), (void*) offsetof(VertexStruct, position));
glVertexAttribPointer(VERTEX_ATTRIBUTE_NORMAL,   2, GL_FLOAT,         GL_FALSE, sizeof(VertexStruct), (void*) offsetof(VertexStruct, normal));
glVertexAttribPointer(VERTEX_ATTRIBUTE_TEXCOORD, 2, GL_FLOAT,         GL_FALSE, sizeof(VertexStruct), (void*) offsetof(VertexStruct, texcoord));
glVertexAttribPointer(VERTEX_ATTRIBUTE_COLOR,    4, GL_UNSIGNED_BYTE, GL_TRUE,  sizeof(VertexStruct), (void*) offsetof(VertexStruct, color));

// activer les pointeurs d'attributs
glEnableVertexAttribArray(VERTEX_ATTRIBUTE_POSITION);
glEnableVertexAttribArray(VERTEX_ATTRIBUTE_NORMAL);
glEnableVertexAttribArray(VERTEX_ATTRIBUTE_TEXCOORD);
glEnableVertexAttribArray(VERTEX_ATTRIBUTE_COLOR);
