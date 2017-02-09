// IFT3100H17_TriangleSoup/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  isKeyPressUp    = false;
  isKeyPressDown  = false;
  isKeyPressLeft  = false;
  isKeyPressRight = false;
  isKeyPressZ     = false;
  isKeyPressX     = false;

  renderer = nullptr;
}

void Application::setup()
{
  ofLog() << "<app::setup>";

  ofSetWindowTitle("soupe au triangles (↑ ↓ ← → z x)");

  renderer = new Renderer();
  renderer->setup();

  isVerbose = false;
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

  // rotation en Y en fonction de l'état des touches Z et X
  if(isKeyPressZ)
    renderer->yOffset += renderer->yDelta * timeElapsed;
  if(isKeyPressX)
    renderer->yOffset -= renderer->yDelta * timeElapsed;
}

void Application::draw()
{
  renderer->draw();
}

void Application::mouseReleased(int x, int y, int button)
{
  // réinitialiser la scène
  renderer->reset();

  if(isVerbose)
    ofLog() << "<app::mouse release at: (" << x << ", " << y << ")>";
}

void Application::keyPressed(int key)
{
  switch(key)
  {
    case 120: // X
      isKeyPressX = true;
      break;
    case 122: // Z
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
  switch(key)
  {
    case 120: // key x
      isKeyPressX = false;
      break;

    case 122: // key z
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
