// IFT3100H17_Locator/Application.h
// Classe principale de l'application.

#pragma once

#include "ofMain.h"

#include "renderer.h"

class Application : public ofBaseApp
{
public:

  Renderer * renderer;

  float timeCurrent;
  float timeLast;
  float timeElapsed;

  bool isKeyPressUp;
  bool isKeyPressDown;
  bool isKeyPressLeft;
  bool isKeyPressRight;

  Application();

  void setup();

  void update();

  void draw();

  void keyPressed(int key);

  void keyReleased(int key);

  void mouseReleased(int x, int y, int button);

  void exit();

  ~Application();
};
