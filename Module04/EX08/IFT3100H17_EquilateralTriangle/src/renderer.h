// IFT3100H17_EquilateralTriangle/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"

class Renderer
{
public:

  float xViewportCenter;
  float yViewportCenter;

  float xTriangleOrigin;
  float yTriangleOrigin;

  float xTriangleCenter;
  float yTriangleCenter;

  float xVertex1;
  float yVertex1;

  float xVertex2;
  float yVertex2;

  float xVertex3;
  float yVertex3;

  float edgeDiameter;
  float edgeDiameterHalf;

  float radiusInnercircle;
  float radiusCircumcircle;

  float trianglePerimeter;
  float triangleArea;
  float triangleAltitude;

  float pointDiameter;

  Renderer();

  void setup();

  void update();

  void draw();

  void reset();

  ~Renderer();
};
