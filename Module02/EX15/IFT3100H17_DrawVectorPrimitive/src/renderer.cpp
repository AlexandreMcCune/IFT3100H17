// IFT3100H17_DrawVectorPrimitives/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer(){}

void Renderer::setup()
{
  ofSetFrameRate(60);

  ofSetWindowShape(512, 512);

  // nombre maximale de primitives vectorielles dans le tableau
  count = 100;

  // calculer la taille de la structure générique commune à toutes les primitives vectorielles
  stride = sizeof(StructVectorPrimitive);

  // calculer le nombre d'octets à allouer pour un tableau contenant toutes les primitives vectorielles
  size = count * stride;

  // allouer un espace mémoire de taille suffisante pour contenir les données de l'ensemble des primitives vectorielles
  shape = (StructVectorPrimitive *) calloc(size, stride);

  // mode de dessin par défaut
  drawMode = VectorPrimitive::RECTANGLE;

  // position de la prochaine primitive
  head = 0;

  // largeur de la ligne de contour
  strokeWidthDefault = 2;

  // couleur de la ligne de contour
  randomColorStroke();

  // couleur de la zone de remplissage
  randomColorFill();

  xMousePress = yMousePress = 0;
  xMouseCurrent = yMouseCurrent = 0;

  isMouseButtonPressed = false;
}

void Renderer::draw()
{
  ofClear(191);

  for(index = 0; index < count; ++index)
  {
    switch(shape[index].type)
    {
      case VectorPrimitive::PIXEL:

        ofFill();
        ofSetLineWidth(0);
        ofSetColor(
          shape[index].strokeColor[0],
          shape[index].strokeColor[1],
          shape[index].strokeColor[2]);
        drawPixel(
          shape[index].position2[0],
          shape[index].position2[1]);
        break;

      case VectorPrimitive::POINT:

        ofFill();
        ofSetLineWidth(0);
        ofSetColor(
          shape[index].strokeColor[0],
          shape[index].strokeColor[1],
          shape[index].strokeColor[2]);
        drawPoint(
          shape[index].position2[0],
          shape[index].position2[1],
          shape[index].strokeWidth);
        break;

      case VectorPrimitive::LINE:

        ofNoFill();
        ofSetLineWidth(shape[index].strokeWidth);
        ofSetColor(
          shape[index].strokeColor[0],
          shape[index].strokeColor[1],
          shape[index].strokeColor[2]);
        drawLine(
          shape[index].position1[0],
          shape[index].position1[1],
          shape[index].position2[0],
          shape[index].position2[1]);
        break;

      case VectorPrimitive::RECTANGLE:

        ofFill();
        ofSetLineWidth(0);
        ofSetColor(
          shape[index].fillColor[0],
          shape[index].fillColor[1],
          shape[index].fillColor[2]);
        drawRectangle(
          shape[index].position1[0],
          shape[index].position1[1],
          shape[index].position2[0],
          shape[index].position2[1]);
        ofNoFill();
        ofSetLineWidth(shape[index].strokeWidth);
        ofSetColor(
          shape[index].strokeColor[0],
          shape[index].strokeColor[1],
          shape[index].strokeColor[2]);
        drawRectangle(
          shape[index].position1[0],
          shape[index].position1[1],
          shape[index].position2[0],
          shape[index].position2[1]);
        break;

      case VectorPrimitive::ELLIPSE:

        ofFill();
        ofSetLineWidth(0);
        ofSetCircleResolution(48);
        ofSetColor(
          shape[index].fillColor[0],
          shape[index].fillColor[1],
          shape[index].fillColor[2]);
        drawEllipse(
          shape[index].position1[0],
          shape[index].position1[1],
          shape[index].position2[0],
          shape[index].position2[1]);
        ofNoFill();
        ofSetLineWidth(shape[index].strokeWidth);
        ofSetColor(
          shape[index].strokeColor[0],
          shape[index].strokeColor[1],
          shape[index].strokeColor[2]);
        drawEllipse(
          shape[index].position1[0],
          shape[index].position1[1],
          shape[index].position2[0],
          shape[index].position2[1]);
        break;

      default:
        break;
    }
  }

  // afficher la zone de sélection
  if(isMouseButtonPressed)
  {
    ofSetColor(255);
    ofSetLineWidth(3);
    ofNoFill();

    drawZone(
      xMousePress,
      yMousePress,
      xMouseCurrent,
      yMouseCurrent);
  }

  // afficher le curseur
  ofSetLineWidth(2);
  ofSetColor(32);

  drawCursor(xMouseCurrent, yMouseCurrent);
}

// fonction qui vide le tableau de primitives vectorielles
void Renderer::reset()
{
  for(index = 0; index < count; ++index)
    shape[index].type = VectorPrimitive::NONE;

  head = 0;

  ofLog() << "<reset>";
}

// fonction qui ajoute une primitive vectorielle au tableau
void Renderer::addVectorShape(VectorPrimitive type)
{
  shape[head].type = type;

  shape[head].position1[0] = xMousePress;
  shape[head].position1[1] = yMousePress;

  shape[head].position2[0] = xMouseCurrent;
  shape[head].position2[1] = yMouseCurrent;

  shape[head].strokeColor[0] = strokeColorR;
  shape[head].strokeColor[1] = strokeColorG;
  shape[head].strokeColor[2] = strokeColorB;
  shape[head].strokeColor[3] = strokeColorA;

  shape[head].fillColor[0] = fillColorR;
  shape[head].fillColor[1] = fillColorG;
  shape[head].fillColor[2] = fillColorB;
  shape[head].fillColor[3] = fillColorA;

  switch(shape[head].type)
  {
    case VectorPrimitive::POINT:
      shape[head].strokeWidth = ofRandom(1,64);
      break;

    case VectorPrimitive::LINE:
      shape[head].strokeWidth = ofRandom(1,16);
      break;

    case VectorPrimitive::RECTANGLE:
      shape[head].strokeWidth = strokeWidthDefault;
      break;

    case VectorPrimitive::ELLIPSE:
      shape[head].strokeWidth = strokeWidthDefault;
      break;

    default:
      shape[head].strokeWidth = strokeWidthDefault;
      break;
  }

  head = ++head >= count ? 0: head; // boucler sur le tableau si plein

  ofLog() << "<add a vector primitive to collection at index: " << head << ">";
}

// fonction qui dessine un pixel
void Renderer::drawPixel(float x, float y) const
{
  int xPixel = floorf(x);
  int yPixel = floorf(y);

  ofDrawRectangle(xPixel, yPixel, 1, 1);
}

// fonction qui dessine un point
void Renderer::drawPoint(float x, float y, float radius) const
{
  ofDrawEllipse(x, y, radius, radius);
}

// fonction qui dessine une ligne
void Renderer::drawLine(float x1, float y1, float x2, float y2) const
{
  ofDrawLine(x1, y1, x2, y2);
}

// fonction qui dessine un rectangle
void Renderer::drawRectangle(float x1, float y1, float x2, float y2) const
{
  ofDrawRectangle(x1, y1, x2 - x1, y2 - y1);
}

// fonction qui dessine une ellipse
void Renderer::drawEllipse(float x1, float y1, float x2, float y2) const
{
  float xDiameter = x2 - x1;
  float yDiameter = y2 - y1;

  ofDrawEllipse(x1 + xDiameter/2.0f, y1 + yDiameter/2.0f, xDiameter, yDiameter);
}

// fonction qui détermine une couleur aléatoire pour les lignes de contour
void Renderer::randomColorStroke()
{
  strokeColorR = (int) ofRandom(0, 256);
  strokeColorG = (int) ofRandom(0, 256);
  strokeColorB = (int) ofRandom(0, 256);
  strokeColorA = 255;

  ofLog() << "<random color stroke>";
}

// fonction qui détermine une couleur aléatoire pour les zones de remplissage
void Renderer::randomColorFill()
{
  fillColorR = (int) ofRandom(0, 256);
  fillColorG = (int) ofRandom(0, 256);
  fillColorB = (int) ofRandom(0, 256);
  fillColorA = 255;

  ofLog() << "<random color fill>";
}

void Renderer::drawZone(float x1, float y1, float x2, float y2) const
{
  float x2Clamp = min(max(0.0f, x2), (float) ofGetWidth());
  float y2Clamp = min(max(0.0f, y2), (float) ofGetHeight());

  ofDrawRectangle(x1, y1, x2Clamp - x1, y2Clamp - y1);
}

void Renderer::drawCursor(float x, float y) const
{
  float length = 10.0f;
  float offset = 5.0f;

  ofDrawLine(x + offset, y, x + offset + length, y);
  ofDrawLine(x - offset, y, x - offset - length, y);
  ofDrawLine(x, y + offset, x, y + offset + length);
  ofDrawLine(x, y - offset, x, y - offset - length);
}

Renderer::~Renderer()
{
  free(shape);
}
