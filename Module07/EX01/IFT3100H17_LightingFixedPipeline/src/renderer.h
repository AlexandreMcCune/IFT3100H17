// IFT3100H17_LightingFixedPipeline/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

// fonction utilitaire d'oscillation
inline float oscillate(float time, float amplitude, float period, float shift, float offset)
{
  return amplitude * sin((time - shift) * 2 * PI / period) + offset;
}

class Renderer
{
public:

  ofColor * lightAmbient;

  ofLight * lightDirectional;
  ofLight * lightPoint;
  ofLight * lightSpot;

  ofMaterial * materialCube;
  ofMaterial * materialSphere;
  ofMaterial * materialTeapot;

  ofxAssimpModelLoader * teapot;

  ofQuaternion * orientationDirectional;
  ofQuaternion * orientationSpot;

  ofVec3f * positionCube;
  ofVec3f * positionSphere;
  ofVec3f * positionTeapot;

  float cameraOffset;

  float oscillation;

  float scaleCube;
  float scaleSphere;
  float scaleTeapot;

  float xCenter;
  float yCenter;

  float speedMotion;
  float speedOscillation;

  float xOffset;
  float zOffset;

  float xDelta;
  float zDelta;

  float xInitial;
  float yInitial;

  int framebufferWidth;
  int framebufferHeight;

  bool isActiveLightAmbient;
  bool isActiveLightDirectional;
  bool isActiveLightPoint;
  bool isActiveLightSpot;

  bool useSmoothLighting;

  bool isFlipAxisY;

  Renderer();

  void setup();
  void update();
  void draw();

  void reset();

  void lightingOn();
  void lightingOff();

  ~Renderer();
};
