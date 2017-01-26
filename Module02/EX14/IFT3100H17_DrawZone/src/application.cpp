// IFT3100H16_DrawZone/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  renderer = nullptr;
}

void Application::setup()
{
  ofSetWindowTitle("zone de sélection");

  ofLog() << "<app::setup>";

  renderer = new Renderer();
  renderer->setup();

  isVerbose = false;
}

void Application::draw()
{
  renderer->draw();
}

void Application::mouseMoved(int x, int y)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  if(isVerbose)
    ofLog() << "<app::mouse moved    at: (" << x << ", " << y << ")>";
}

void Application::mouseDragged(int x, int y, int button)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  if(isVerbose)
    ofLog() << "<app::mouse dragged  at: (" << x << ", " << y << ") button:" << button <<">";
}

void Application::mousePressed(int x, int y, int button)
{
  renderer->isMouseButtonPressed = true;

  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  renderer->xMousePress = x;
  renderer->yMousePress = y;

  ofLog() << "<app::mouse pressed  at: (" << x << ", " << y << ")>";
}

void Application::mouseReleased(int x, int y, int button)
{
  renderer->isMouseButtonPressed = false;

  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  ofLog() << "<app::mouse released at: (" << x << ", " << y << ")>";
}

void Application::mouseEntered(int x, int y)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  ofLog() << "<app::mouse entered  at: (" << x << ", " << y << ")>";
}

void Application::mouseExited(int x, int y)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  ofLog() << "<app::mouse exited   at: (" << x << ", " << y << ")>";
}

void Application::keyReleased(int key)
{
  switch(key)
  {
    case 118: // key v
      isVerbose = !isVerbose;
      ofLog() << "<verbose mode:" << isVerbose << ">";
      break;

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
