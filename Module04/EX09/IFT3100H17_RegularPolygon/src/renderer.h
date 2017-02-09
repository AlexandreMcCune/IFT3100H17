// IFT3100H17_RegularPolygon/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"

class Renderer
{
public:

  float xPolygonCenter;
  float yPolygonCenter;

  float xPositionVertex;
  float yPositionVertex;

  float angle;
  float offset;
  float radius;

  float pointDiameter;

  int side;

  int index;

  Renderer();

  void setup();

  void update();

  void draw();

  void reset();

  ~Renderer();
};
