// IFT3100H17_RegularPolygon/application.h
// Classe principale de l'application.

#pragma once

#include "ofMain.h"

#include "renderer.h"

class Application : public ofBaseApp
{
public:

  Renderer * renderer;

  Application();

  void setup();

  void update();

  void draw();

  void keyReleased(int key);

  void exit();

  ~Application();
};
