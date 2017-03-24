// IFT3100H17_ShaderClassic/application.cpp
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

  renderer = new Renderer();

  if(ofIsGLProgrammableRenderer())
  {
    renderer->glVersionMajor = 3;
    renderer->glVersionMinor = 3;
  }
  else
  {
    renderer->glVersionMajor = 2;
    renderer->glVersionMinor = 1;
  }

  renderer->setup();
}

void Application::update()
{
  ofSetWindowTitle("illumination classique " + renderer->shaderName + " (" + renderer->shaderVersion + ") (1-5 ↑↓←→ f)");

  timeCurrent = ofGetElapsedTimef();
  timeElapsed = timeCurrent - timeLast;
  timeLast = timeCurrent;

  if(isKeyPressUp)
    renderer->zOffset += renderer->zDelta * timeElapsed;
  if(isKeyPressDown)
    renderer->zOffset -= renderer->zDelta * timeElapsed;
  if(isKeyPressLeft)
    renderer->xOffset += renderer->xDelta * timeElapsed;
  if(isKeyPressRight)
    renderer->xOffset -= renderer->xDelta * timeElapsed;

  renderer->update();
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
    case 49:  // key 1
      renderer->activeShader = Shading::COLOR_FILL;
      ofLog() << "<shader: Color Fill>";
      break;

    case 50:  // key 2
      renderer->activeShader = Shading::LAMBERT;
      ofLog() << "<shader: Lambert>";
      break;

    case 51:  // key 3
      renderer->activeShader = Shading::GOURAUD;
      ofLog() << "<shader: Gouraud>";
      break;

    case 52:  // key 4
      renderer->activeShader = Shading::PHONG;
      ofLog() << "<shader: Phong>";
      break;

    case 53:  // key 5
      renderer->activeShader = Shading::BLINN_PHONG;
      ofLog() << "<shader: Blinn-Phong>";
      break;

    case 102: // key f
      renderer->isFlipAxisY = !renderer->isFlipAxisY;
      ofLog() << "<axis Y is flipped: " << renderer->isFlipAxisY << ">";
      break;

    case 114: // key r
      renderer->reset();
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
      break;
  }
}

void Application::windowResized(int w, int h)
{
  renderer->reset();

  ofLog() << "<app::windowResized: (" << w << ", " << h << ")>";
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
