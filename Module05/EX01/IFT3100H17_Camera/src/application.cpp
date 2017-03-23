// IFT3100H17_Camera/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  isKeyPressUp = false;
  isKeyPressDown = false;
  isKeyPressLeft = false;
  isKeyPressRight = false;

  isKeyPressA = false;
  isKeyPressD = false;
  isKeyPressE = false;
  isKeyPressH = false;
  isKeyPressI = false;
  isKeyPressJ = false;
  isKeyPressK = false;
  isKeyPressQ = false;
  isKeyPressS = false;
  isKeyPressU = false;
  isKeyPressW = false;
  isKeyPressX = false;
  isKeyPressY = false;
  isKeyPressZ = false;

  renderer = nullptr;
}

void Application::setup()
{
  ofLog() << "<app::setup>";

  renderer = new Renderer();

  renderer->setup();
}

void Application::update()
{
  if(renderer->isCameraPerspective)
    ofSetWindowTitle("camera " + renderer->cameraName + " perspective (1-6 ↑↓←→ wasdqe uhjkyi zx fgcvb)");
  else
    ofSetWindowTitle("camera " + renderer->cameraName + " orthographic");

  renderer->isCameraMoveForward = isKeyPressUp || isKeyPressW;
  renderer->isCameraMoveBackward = isKeyPressDown || isKeyPressS;

  renderer->isCameraMoveLeft = isKeyPressLeft || isKeyPressA;
  renderer->isCameraMoveRight = isKeyPressRight || isKeyPressD;

  renderer->isCameraMoveUp = isKeyPressQ;
  renderer->isCameraMoveDown = isKeyPressE;

  renderer->isCameraTiltUp = isKeyPressJ;
  renderer->isCameraTiltDown = isKeyPressU;

  renderer->isCameraPanLeft = isKeyPressH;
  renderer->isCameraPanRight = isKeyPressK;

  renderer->isCameraRollLeft = isKeyPressY;
  renderer->isCameraRollRight = isKeyPressI;

  renderer->isCameraFovNarrow = isKeyPressZ;
  renderer->isCameraFovWide = isKeyPressX;

  renderer->update();
}

void Application::draw()
{
  renderer->draw();
}

void Application::keyPressed(int key)
{
  switch(key)
  {
    case 97:  // key A
      isKeyPressA = true;
      break;

    case 100: // key D
      isKeyPressD = true;
      break;

    case 101: // key E
      isKeyPressE = true;
      break;

    case 104: // key H
      isKeyPressH = true;
      break;

    case 105: // key I
      isKeyPressI = true;
      break;

    case 106: // key J
      isKeyPressJ = true;
      break;

    case 107: // key K
      isKeyPressK = true;
      break;

    case 113: // key Q
      isKeyPressQ = true;
      break;

    case 115: // key S
      isKeyPressS = true;
      break;

    case 117: // key U
      isKeyPressU = true;
      break;

    case 119: // key W
      isKeyPressW = true;
      break;

    case 120: // key X
      isKeyPressX = true;
      break;

    case 121: // key Y
      isKeyPressY = true;
      break;

    case 122: // key Z
      isKeyPressZ = true;
      break;

    case 356: // key ←
      isKeyPressLeft = true;
      break;

    case 357: // key ↑
      isKeyPressUp = true;
      break;

    case 358: // key →
      isKeyPressRight = true;
      break;

    case 359: // key ↓
      isKeyPressDown = true;
      break;

    default:
      break;
  }
}

void Application::keyReleased(int key)
{
  //TODO ofLog() << "<key " << key << ">";

  switch(key)
  {
    case 49:  // key 1
      renderer->cameraActive = Camera::FRONT;
      renderer->setupCamera();
      break;

    case 50:  // key 2
      renderer->cameraActive = Camera::BACK;
      renderer->setupCamera();
      break;

    case 51:  // key 3
      renderer->cameraActive = Camera::LEFT;
      renderer->setupCamera();
      break;

    case 52:  // key 4
      renderer->cameraActive = Camera::RIGHT;
      renderer->setupCamera();
      break;

    case 53:  // key 5
      renderer->cameraActive = Camera::TOP;
      renderer->setupCamera();
      break;

    case 54:  // key 6
      renderer->cameraActive = Camera::DOWN;
      renderer->setupCamera();
      break;

    case 97:  // key A
      isKeyPressA = false;
      break;

    case 98:  // key B
      renderer->isVisibleBox = !renderer->isVisibleBox;
      ofLog() << "<toggle box:" << renderer->isVisibleBox << ">";
      break;

    case 99:  // key C
      renderer->drawAsCheckerboard = !renderer->drawAsCheckerboard;
      ofLog() << "<toggle checkerboard:" << renderer->drawAsCheckerboard << ">";
      break;

    case 100: // key D
      isKeyPressD = false;
      break;

    case 101: // key E
      isKeyPressE = false;
      break;

    case 102: // key F
      renderer->useColorFill = !renderer->useColorFill;
      renderer->useColorFill ? ofFill() : ofNoFill();
      ofLog() << "<color fill:" <<  renderer->useColorFill << ">";
      break;

    case 103: // key G
      renderer->isVisibleGrid = !renderer->isVisibleGrid;
      ofLog() << "<toggle grid:" << renderer->isVisibleGrid << ">";
      break;

    case 104: // key H
      isKeyPressH = false;
      break;

    case 105: // key I
      isKeyPressI = false;
      break;

    case 106: // key J
      isKeyPressJ = false;
      break;

    case 107: // key K
      isKeyPressK = false;
      break;

    case 111: // key O
      renderer->isCameraPerspective = false;
      renderer->setupCamera();
      ofLog() << "<orthographic projection>";
      break;

    case 112: // key P
      renderer->isCameraPerspective = true;
      renderer->setupCamera();
      ofLog() << "<perpective projection>";
      break;

    case 113: // key Q
      isKeyPressQ = false;
      break;

    case 114: // key R
      renderer->reset();
      break;

    case 115: // key S
      isKeyPressS = false;
      break;

    case 116: // key T
      renderer->isVisibleText = !renderer->isVisibleText;
      ofLog() << "<toggle text:" << renderer->isVisibleText << ">";
      break;

    case 117: // key U
      isKeyPressU = false;
      break;

    case 118: // key V
      renderer->isVisibleAxes = !renderer->isVisibleAxes;
      ofLog() << "<toggle axes:" << renderer->isVisibleAxes << ">";
      break;

    case 119: // key W
      isKeyPressW = false;
      break;

    case 120: // key X
      isKeyPressX = false;
      ofLog() << "<fov:" << renderer->cameraFov << ">";
      break;

    case 121: // key Y
      isKeyPressY = false;
      break;

    case 122: // key Z
      ofLog() << "<fov:" << renderer->cameraFov << ">";
      isKeyPressZ = false;
      break;

    case 356: // key ←
      isKeyPressLeft = false;
      break;

    case 357: // key ↑
      isKeyPressUp = false;
      break;

    case 358: // key →
      isKeyPressRight = false;
      break;

    case 359: // key ↓
      isKeyPressDown = false;
      break;

    case ' ':
        renderer->imageExport("render","png");

    default:
      break;
  }
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}

Application::~Application()
{
  if(nullptr != renderer)
    delete renderer;
}
