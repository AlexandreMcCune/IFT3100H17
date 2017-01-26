// IFT3100H16_DrawZone/renderer.cpp
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

// fonction qui dessine une zone rectangulaire
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

Renderer::~Renderer(){}
