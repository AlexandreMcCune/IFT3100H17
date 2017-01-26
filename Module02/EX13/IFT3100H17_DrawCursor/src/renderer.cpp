// IFT3100H17_DrawCursor/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer(){}

void Renderer::setup()
{
  ofSetFrameRate(60);

  ofSetWindowShape(512, 512);

  xMousePress = yMousePress = 0;
  xMouseCurrent = yMouseCurrent = 0;

  isMouseButtonPressed = false;
}

void Renderer::draw()
{
  ofClear(191);

  ofSetLineWidth(2);
  ofSetColor(32);

  // afficher le curseur
  drawCursor(xMouseCurrent, yMouseCurrent);
}

// fonction qui dessine un curseur
void Renderer::drawCursor(float x, float y) const
{
  float length = 10.0f;
  float offset = 5.0f;

  ofDrawLine(x + offset, y, x + offset + length, y);
  ofDrawLine(x - offset, y, x - offset - length, y);
  ofDrawLine(x, y + offset, x, y + offset + length);
  ofDrawLine(x, y - offset, x, y - offset - length);
}

Renderer::~Renderer(){}
