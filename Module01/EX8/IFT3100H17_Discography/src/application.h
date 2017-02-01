// IFT3100H17_Discography/ofApp.cpp
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

  void windowResized(int w, int h);

  void exit();

  ~Application();
};
