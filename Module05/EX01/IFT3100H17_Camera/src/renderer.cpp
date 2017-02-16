// IFT3100H17_Camera/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer(){}

void Renderer::setup()
{
  ofSetFrameRate(60);
  ofEnableDepthTest();

  // paramètres
  cameraFov = 60.0f;
  cameraNear = 50.0f;
  cameraFar = 1750.0f;

  cameraTarget = {0.0f, 0.0f, 0.0f};

  fovDelta = 16.0f;

  speedDelta = 250.0f;

  cubeCount = 7;
  cubeOffset = 64.0f;

  isVisibleAxes = false;
  isVisibleGrid = false;
  isVisibleCamera = false;
  isVisibleBox = true;
  isVisibleLocator = false;
  isVisibleText = false;

  isCameraMoveLeft = false;
  isCameraMoveRight = false;
  isCameraMoveUp = false;
  isCameraMoveDown = false;
  isCameraMoveForward = false;
  isCameraMoveBackward = false;

  isCameraTiltUp = false;
  isCameraTiltDown = false;
  isCameraPanLeft = false;
  isCameraPanRight = false;
  isCameraRollLeft = false;
  isCameraRollRight = false;

  isCameraFovNarrow = false;
  isCameraFovWide = false;

  isCameraPerspective = true;

  useColorFill = true;

  drawAsCheckerboard = false;

  reset();

  setupCamera();
}

void Renderer::reset()
{
  // initialisation des variables
  cubeSize = cubeOffset / 2.0f;
  sceneOffset = cubeCount * cubeOffset / 2.0f * -1.0f + cubeSize;
  colorOffset = 255.0f / cubeCount;
  cameraOffset = sceneOffset * 3.5f * -1.0f;

  // position initiale de chaque caméra
  cameraFront.setPosition(0, 0, -cameraOffset);
  cameraBack.setPosition(0, 0, cameraOffset);
  cameraLeft.setPosition(-cameraOffset, 0, 0);
  cameraRight.setPosition(cameraOffset, 0, 0);
  cameraTop.setPosition(0, cameraOffset, 0);
  cameraDown.setPosition(0, -cameraOffset, 0);

  // orientation de chaque caméra
  cameraFront.lookAt(cameraTarget);
  cameraBack.lookAt(cameraTarget);
  cameraLeft.lookAt(cameraTarget);
  cameraRight.lookAt(cameraTarget);
  cameraTop.lookAt(cameraTarget, ofVec3f(1, 0, 0));
  cameraDown.lookAt(cameraTarget, ofVec3f(1, 0, 0));

  // caméra par défault
  cameraActive = Camera::FRONT;

  ofLog() << "<reset>";
}

void Renderer::update()
{
  timeCurrent = ofGetElapsedTimef();
  timeElapsed = timeCurrent - timeLast;
  timeLast = timeCurrent;

  speedTranslation = speedDelta * timeElapsed;
  speedRotation = speedTranslation / 8.0f;

  if(isCameraMoveLeft)
    camera->truck(-speedTranslation);
  if(isCameraMoveRight)
    camera->truck(speedTranslation);

  if(isCameraMoveUp)
    camera->boom(speedTranslation);
  if(isCameraMoveDown)
    camera->boom(-speedTranslation);

  if(isCameraMoveForward)
    camera->dolly(-speedTranslation);
  if(isCameraMoveBackward)
    camera->dolly(speedTranslation);

  if(isCameraTiltUp)
    camera->tilt(-speedRotation);
  if(isCameraTiltDown)
    camera->tilt(speedRotation);

  if(isCameraPanLeft)
    camera->pan(speedRotation);
  if(isCameraPanRight)
    camera->pan(-speedRotation);

  if(isCameraRollLeft)
    camera->roll(-speedRotation);
  if(isCameraRollRight)
    camera->roll(speedRotation);

  if(isCameraPerspective)
  {
    if(isCameraFovNarrow)
    {
      cameraFov = std::max(cameraFov -= fovDelta * timeElapsed, 0.0f);
      camera->setFov(cameraFov);
    }

    if(isCameraFovWide)
    {
      cameraFov = std::min(cameraFov += fovDelta * timeElapsed, 180.0f);
      camera->setFov(cameraFov);
    }
  }
}

void Renderer::draw()
{
  ofBackground(31);

  camera->begin();

  if(isVisibleGrid)
    ofDrawGrid(64);

  if(isVisibleAxes)
    ofDrawRotationAxes(64);

  if(isVisibleCamera)
  {
    if(cameraActive != Camera::FRONT)
      cameraFront.draw();
    if(cameraActive != Camera::BACK)
      cameraBack.draw();
    if(cameraActive != Camera::LEFT)
      cameraLeft.draw();
    if(cameraActive != Camera::RIGHT)
      cameraRight.draw();
    if(cameraActive != Camera::TOP)
      cameraTop.draw();
    if(cameraActive != Camera::DOWN)
      cameraDown.draw();
  }

  if(isVisibleText)
  {
    if(cameraActive != Camera::FRONT)
      ofDrawBitmapString(" camera front", cameraFront.getPosition());
    if(cameraActive != Camera::BACK)
      ofDrawBitmapString(" camera back", cameraBack.getPosition());
    if(cameraActive != Camera::LEFT)
      ofDrawBitmapString(" camera left", cameraLeft.getPosition());
    if(cameraActive != Camera::RIGHT)
      ofDrawBitmapString(" camera right", cameraRight.getPosition());
    if(cameraActive != Camera::TOP)
      ofDrawBitmapString(" camera top", cameraTop.getPosition());
    if(cameraActive != Camera::DOWN)
      ofDrawBitmapString(" camera down", cameraDown.getPosition());
  }

  if(isVisibleBox)
  {
    for(xIndex = 0; xIndex < cubeCount; ++xIndex)
    {
      for(yIndex = 0; yIndex < cubeCount; ++yIndex)
      {
        for(zIndex = 0; zIndex < cubeCount; ++zIndex)
        {
          if(xIndex % 2 == yIndex % 2 == zIndex % 2 || !drawAsCheckerboard)
          {
            ofSetColor(
              xIndex * colorOffset,
              yIndex * colorOffset,
              zIndex * colorOffset);

            ofDrawBox(
              sceneOffset + xIndex * cubeOffset,
              sceneOffset + yIndex * cubeOffset,
              sceneOffset + zIndex * cubeOffset,
              cubeSize);
          }
        }
      }
    }
  }

  camera->end();
}

// fonction de configuration de la caméra active
void Renderer::setupCamera()
{
  switch(cameraActive)
  {
    case Camera::FRONT:
      camera = &cameraFront;
      cameraName = "front";
      break;

    case Camera::BACK:
      camera = &cameraBack;
      cameraName = "back";
      break;

    case Camera::LEFT:
      camera = &cameraLeft;
      cameraName = "left";
      break;

    case Camera::RIGHT:
      camera = &cameraRight;
      cameraName = "right";
      break;

    case Camera::TOP:
      camera = &cameraTop;
      cameraName = "top";
      break;

    case Camera::DOWN:
      camera = &cameraDown;
      cameraName = "down";
      break;

    default:
      break;
  }

  cameraPosition = camera->getPosition();

  cameraOrientation = camera->getOrientationQuat();

  if(isCameraPerspective)
  {
    camera->disableOrtho();
    camera->setupPerspective(false, cameraFov, cameraNear, cameraFar, ofVec2f(0, 0));
  }
  else
  {
    camera->enableOrtho();
  }

  camera->setPosition(cameraPosition);
  camera->setOrientation(cameraOrientation);

  ofLog() << "<setup camera: " << cameraName << ">";
}

void Renderer::imageExport(const string name, const string extension) const
{
  ofImage imageTemp;
  string timestamp = ofGetTimestampString("-%y%m%d-%H%M%S-%i");
  string fileName = name + timestamp + "." + extension;
  imageTemp.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
  imageTemp.save(fileName);
  ofLog() << "<export image: " << fileName << ">";
}

Renderer::~Renderer(){}
