// IFT3100H17_TriangleSoup/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

// structure d'un triangle
struct TriangleStruct
{
  int           state;         // 1 * 4 = 4  octets
  float         position1 [3]; // 3 * 4 = 12 octets
  float         position2 [3]; // 3 * 4 = 12 octets
  float         position3 [3]; // 3 * 4 = 12 octets
  unsigned char color     [4]; // 4 * 1 = 4  octets
};                             //       = 44 octets

class Renderer
{

public:

  TriangleStruct * soup;

  ofVec3f * vectorOrigin;

  ofVec3f * vectorPosition1;
  ofVec3f * vectorPosition2;
  ofVec3f * vectorPosition3;

  ofColor * vectorColor;

  ofLight light;

  ofNode * node;

  float xCenter;
  float yCenter;

  float speed;

  float xOffset;
  float yOffset;
  float zOffset;

  float xDelta;
  float yDelta;
  float zDelta;

  float soupRadius;

  float triangleRadius;

  int triangleCount;

  int triangleBufferSize;
  int triangleBufferHead;

  int index;

  int framebufferWidth;
  int framebufferHeight;

  bool isVerbose;

  Renderer();

  void setup();
  void draw();

  void reset();

  void dispatchRandomTriangle(int count, float range);

  void drawScene();

  void drawLocator(float scale);

  void drawSoup();
  void drawTriangle(int indexInSoup);

  void imageExport(const string name, const string extension) const;

  ~Renderer();
};
