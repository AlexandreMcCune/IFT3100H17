// IFT3100H17_Camera/application.h
// Classe principale de l'application.

#pragma once

#include "ofMain.h"
#include "renderer.h"

class Application : public ofBaseApp
{
public:

  Renderer * renderer;

  bool isKeyPressUp;
  bool isKeyPressDown;
  bool isKeyPressLeft;
  bool isKeyPressRight;

  bool isKeyPressA;
  bool isKeyPressD;
  bool isKeyPressE;
  bool isKeyPressH;
  bool isKeyPressI;
  bool isKeyPressJ;
  bool isKeyPressK;
  bool isKeyPressQ;
  bool isKeyPressS;
  bool isKeyPressU;
  bool isKeyPressW;
  bool isKeyPressX;
  bool isKeyPressY;
  bool isKeyPressZ;

  Application();

  void setup();

  void update();

  void draw();

  void keyPressed(int key);

  void keyReleased(int key);

  void exit();

  ~Application();
};
