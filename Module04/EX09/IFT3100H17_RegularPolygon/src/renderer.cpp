// IFT3100H17_RegularPolygon/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer(){}

void Renderer::setup()
{
  ofSetFrameRate(10);
  ofSetCircleResolution(64);

  pointDiameter = 16;

  side = 3;
}

void Renderer::update()
{
  // déterminer la position du centre du polygone régulier
  xPolygonCenter = ofGetWidth() / 2.0f;
  yPolygonCenter = ofGetHeight() / 2.0f;

  // configurer l'angle de départ pour le premier sommet du polygone régulier
  angle = ofDegToRad(-90.0f);

  // calculer l'angle qui sépare chaque sommet du polygone
  offset = ofDegToRad(360.0f / side);

  // déterminer le rayon du polygone régulier
  radius = min(ofGetWidth(), ofGetHeight()) / 3.0f;
}

void Renderer::draw()
{
  // dégradé de couleurs en arrière-plan
  ofBackgroundGradient(ofColor(191), ofColor(127));

  // dessiner une grille sur le plan XY
  ofDrawGrid(max(ofGetWidth(), ofGetHeight())/8.0f, 8, false, false, false, true);

  // dessiner la zone de remplissage du polygone régulier
  ofFill();
  ofSetColor(255);

  // débuter un nouveau polygone régulier
  ofBeginShape();

  // une itération pour chaque sommet du polygone régulier
  for(index = 0; index < side; index++)
  {
    // calculer la position du sommet
    xPositionVertex = xPolygonCenter + cos(angle) * radius;
    yPositionVertex = yPolygonCenter + sin(angle) * radius;

    // ajouter un sommet au polygone régulier
    ofSetColor(255);
    ofVertex(xPositionVertex, yPositionVertex);

    // incrémenter l'angle pour le prochain sommet
    angle += offset;
  }

  // terminer et rendre le polygone régulier
  ofEndShape();

  // dessiner le centre du polygone régulier
  ofSetColor(63);
  ofDrawEllipse(xPolygonCenter, yPolygonCenter, pointDiameter, pointDiameter);
}

Renderer::~Renderer(){}
