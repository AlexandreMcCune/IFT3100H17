// IFT3100H17_Mesh.cpp
// Exemple d'une classe minimaliste pour stocker les données des sommets d'un maillage triangulaire.

// précondition
// - structure de sommet
// - structure de triangle
// - données initiales du maillage triangulaire

// postcondition
// - classe qui contient des triangles indexés par leurs sommets

// déclarer la structure de sommet
struct VertexStruct
{
  GLfloat position[3]; // 3 * 4 = 12 octets
  GLfloat normal  [3]; // 3 * 4 = 12 octets
  GLfloat texcoord[2]; // 2 * 4 = 8  octets
  GLubyte color   [4]; // 4 * 1 = 4  octets
};                     //       = 36 octets

// structure d'un sommet
struct Vertex
{
  // structure interne d'un sommet
  VertexStruct vs;
};

// structure d'un triangle
struct Triangle
{
  // indices des 3 sommets
  int vertexIndex[3];
};

// classe d'un maillage géométrique
class Mesh
{
  // nombre de sommets
  int countVertex;

  // séquence des sommets
  Vertex * arrayVertex;

  // nombre des triangles
  int countTriangle;

  // séquence des triangles
  Triangle * arrayTriangle;

  mesh()
  {
    // allocation d'une séquence de sommets
    arrayVertex = (Vertex *) calloc(countVertex, sizeof(Vertex));

    // allocation du tableau de triangles
    arrayTriangle = (Triangle *) calloc(countTriangle, sizeof(Triangle));

    // initialisation
    // ...
  }
};
