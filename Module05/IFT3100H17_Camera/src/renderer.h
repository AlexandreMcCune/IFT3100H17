// IFT3100H17_Camera/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"

enum class Camera {FRONT, BACK, LEFT, RIGHT, TOP, DOWN, FREE, ORBIT};

class Renderer
{
public:

  Camera cameraActive;

  ofCamera cameraFront;
  ofCamera cameraBack;
  ofCamera cameraLeft;
  ofCamera cameraRight;
  ofCamera cameraTop;
  ofCamera cameraDown;

  ofCamera * camera;

  ofQuaternion cameraOrientation;

  ofVec3f cameraPosition;
  ofVec3f cameraTarget;

  string cameraName;

  float cameraFov;
  float cameraNear;
  float cameraFar;

  float fovDelta;

  float timeCurrent;
  float timeLast;
  float timeElapsed;

  float speedDelta;
  float speedTranslation;
  float speedRotation;

  float sceneOffset;

  float cubeOffset;
  float cubeSize;

  float colorOffset;

  float cameraOffset;

  int cubeCount;

  int xIndex;
  int yIndex;
  int zIndex;

  bool isVisibleAxes;
  bool isVisibleGrid;
  bool isVisibleCamera;
  bool isVisibleBox;
  bool isVisibleLocator;
  bool isVisibleText;

  bool isCameraMoveLeft;
  bool isCameraMoveRight;
  bool isCameraMoveUp;
  bool isCameraMoveDown;
  bool isCameraMoveForward;
  bool isCameraMoveBackward;

  bool isCameraTiltUp;
  bool isCameraTiltDown;
  bool isCameraPanLeft;
  bool isCameraPanRight;
  bool isCameraRollLeft;
  bool isCameraRollRight;

  bool isCameraFovNarrow;
  bool isCameraFovWide;

  bool isCameraPerspective;

  bool useColorFill;

  bool drawAsCheckerboard;

  Renderer();

  void setup();
  void reset();
  void update();
  void draw();

  void setupCamera();

  void imageExport(const string name, const string extension) const;

  ~Renderer();
};
