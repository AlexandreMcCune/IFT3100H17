// IFT3100H17_Origin/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"

class Renderer
{
public:

  ofNode * node;

  float xCenter;
  float yCenter;

  int framebufferWidth;
  int framebufferHeight;

  bool isVerbose;

  Renderer();

  void setup();

  void draw();

  void reset();

  void drawScene();

  void drawLocator(float scale);

  ~Renderer();
};
