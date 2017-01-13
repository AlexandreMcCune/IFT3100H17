// IFT3100H17_HelloTriangle/application.h
// Classe principale de l'application.

#pragma once

#include "ofMain.h"

class Application : public ofBaseApp
{
public:

  float vertex1X;
  float vertex1Y;
  float vertex2X;
  float vertex2Y;
  float vertex3X;
  float vertex3Y;

  float colorR;
  float colorG;
  float colorB;

  float pointRadius;

  void setup();
  void update();
  void draw();
};
