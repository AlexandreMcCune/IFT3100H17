// IFT3100H17_Origin/application.h
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

  void draw();

  void keyReleased(int key);

  void mouseReleased(int x, int y, int button);

  void exit();

  ~Application();
};
