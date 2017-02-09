// IFT3100H17_Teapot/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

// stucture d'un localisateur de transformation
struct LocatorStruct
{
  int   state;         // 1 * 4 = 4  octets
  float position  [3]; // 3 * 4 = 12 octets
  float rotation  [3]; // 3 * 4 = 12 octets
  float dimension [3]; // 3 * 4 = 12 octets
};                     //       = 40 octets

class Renderer
{
public:

  LocatorStruct * locators;

  ofNode * node;

  ofVec3f * vectorPosition;
  ofVec3f * vectorRotation;
  ofVec3f * vectorDimension;

  ofxAssimpModelLoader * teapot;

  ofLight * light;

  float xCenter;
  float yCenter;

  float speed;
  float xOffset;
  float zOffset;

  float xDelta;
  float zDelta;

  int locatorCount;

  int locatorBufferSize;
  int locatorBufferHead;

  int index;

  int framebufferWidth;
  int framebufferHeight;

  bool isFlipAxisY;

  bool isActiveTranslation;
  bool isActiveRotation;
  bool isActiveDimension;

  bool isVerbose;

  Renderer();

  void setup();
  void draw();

  void reset();

  void dispatchRandomLocator(int count, float range);

  void drawScene();

  void drawLocator(float scale);

  ~Renderer();
};
