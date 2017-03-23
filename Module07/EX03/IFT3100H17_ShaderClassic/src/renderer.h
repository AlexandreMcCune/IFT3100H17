// IFT3100H17_ShaderClassic/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

// énumération des types de shader
enum class Shading {COLOR_FILL, LAMBERT, GOURAUD, PHONG, BLINN_PHONG};

// fonction utilitaire d'oscillation
inline float oscillate(float time, float amplitude, float period, float shift, float offset)
{
  return amplitude * sin((time - shift) * 2 * PI / period) + offset;
}

class Renderer
{
public:

  Shading activeShader;

  ofShader * shader;

  ofShader * shaderColorFill;
  ofShader * shaderLambert;
  ofShader * shaderGouraud;
  ofShader * shaderPhong;
  ofShader * shaderBlinnPhong;

  ofLight * lightPoint;

  ofxAssimpModelLoader * teapot;

  ofVec3f * positionCube;
  ofVec3f * positionSphere;
  ofVec3f * positionTeapot;

  string shaderVersion;
  string shaderName;

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

  int glVersionMajor;
  int glVersionMinor;

  bool isFlipAxisY;

  Renderer();

  void setup();
  void update();
  void draw();

  void reset();

  ~Renderer();
};
