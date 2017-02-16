// IFT3100H17_Empty/application.h
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
  void exit();

  ~Application();
};
