// IFT3100H17_Teapot/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  isKeyPressUp    = false;
  isKeyPressDown  = false;
  isKeyPressLeft  = false;
  isKeyPressRight = false;

  renderer = nullptr;
}

void Application::setup()
{
  ofLog() << "<app::setup>";

  ofSetWindowTitle("teapot (↑ ↓ ← → w e r f)");

  renderer = new Renderer();
  renderer->setup();
}

void Application::update()
{
  timeCurrent = ofGetElapsedTimef();
  timeElapsed = timeCurrent - timeLast;
  timeLast = timeCurrent;

  // déplacement sur le plan XZ en fonction de l'état des flèches du clavier
  if(isKeyPressUp)
    renderer->zOffset += renderer->zDelta * timeElapsed;
  if(isKeyPressDown)
    renderer->zOffset -= renderer->zDelta * timeElapsed;
  if(isKeyPressLeft)
    renderer->xOffset += renderer->xDelta * timeElapsed;
  if(isKeyPressRight)
    renderer->xOffset -= renderer->xDelta * timeElapsed;
}

void Application::draw()
{
  renderer->draw();
}

void Application::mouseReleased(int x, int y, int button)
{
  renderer->reset();
}

void Application::keyPressed(int key)
{
  switch(key)
  {
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
  switch(key)
  {
    case 114: // key r
      renderer->isActiveDimension = !renderer->isActiveDimension;
      ofLog() << "<dimension is active: " << renderer->isActiveDimension << ">";
      break;

    case 101: // key e
      renderer->isActiveRotation = !renderer->isActiveRotation;
      ofLog() << "<rotation is active: " << renderer->isActiveRotation << ">";
      break;

    case 102: // key f
      renderer->isFlipAxisY = !renderer->isFlipAxisY;
      ofLog() << "<axis Y is flipped: " << renderer->isFlipAxisY << ">";
      break;

    case 119: // key w
      renderer->isActiveTranslation = !renderer->isActiveTranslation;
      ofLog() << "<translation is active: " << renderer->isActiveTranslation << ">";
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

    default:
      renderer->reset();
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
