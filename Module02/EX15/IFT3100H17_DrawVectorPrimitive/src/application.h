// IFT3100H17_DrawVectorPrimitives/application.h
// Classe principale de l'application.

#pragma once

#include "ofMain.h"

#include "renderer.h"

class Application : public ofBaseApp
{
public:

  Renderer * renderer;

  bool isVerbose;

  Application();

  void setup();
  void draw();

  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);

  void keyReleased(int key);

  void exit();

  ~Application();
};
