// IFT3100H17_DrawCursor/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"

class Renderer
{
public:

  int xMousePress;
  int yMousePress;

  int xMouseCurrent;
  int yMouseCurrent;

  bool isMouseButtonPressed;

  Renderer();

  void setup();
  void draw();

  void drawCursor(float x, float y) const;

  ~Renderer();
};
