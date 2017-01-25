// IFT3100H17_DrawPolygon.pde
// Dessine une séquence de polygones réguliers avec un nombre de côtés croissant.

size(1280, 128);

strokeWeight(3);

// paramètres
int sideMin = 3;
int countPolygon = 12;

// variables
int side = sideMin;

int indexPolygon;
int indexVertex;

float angle  = 0.0f;
float offset = 0.0f;

float xPosition = 0.0f;
float yPosition = 0.0f;

float xPolygon = 0.0f;
float yPolygon = 0.0f;

float diameter = width  / countPolygon;
float radius   = height / 3.0f;

// une itération de la boucle pour chaque polygone 
for(indexPolygon = 0; indexPolygon < countPolygon; ++indexPolygon)
{
  // calculer l'angle qui sépare chaque sommet du polygone
  offset = radians(360.0f / side);

  // calculer la position du centre du polygone 
  xPolygon = radius + indexPolygon * diameter;
  yPolygon = height / 2.0f;

  // débuter une nouvelle forme vectorielle
  beginShape();

  // une itération pour chaque sommet du polygone
  for(indexVertex = 0; indexVertex < side; ++indexVertex)
  {
    // calculer la position du sommet 
    xPosition = xPolygon + cos(angle) * radius;
    yPosition = yPolygon + sin(angle) * radius;

    // ajouter un sommet à la forme vectorielle 
    vertex(xPosition, yPosition);

    // incrémenter l'angle pour le prochain sommet
    angle += offset;
  }

  // terminer et rendre la forme vectorielle
  endShape(CLOSE);

  // incrémenter l'index de l'itérateur
  ++side;
}

saveFrame("render.png");