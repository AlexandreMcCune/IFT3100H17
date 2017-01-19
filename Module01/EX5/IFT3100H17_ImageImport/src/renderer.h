// IFT3100H17_ImageImport/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"

class Renderer
{
public:

  ofImage image;

  Renderer();

  void setup();
  void draw();

  ~Renderer();
};
