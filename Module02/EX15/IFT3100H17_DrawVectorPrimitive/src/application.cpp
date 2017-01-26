// IFT3100H17_DrawVectorPrimitives/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  renderer = nullptr;
}

void Application::setup()
{
  ofSetWindowTitle("dessin vectoriel (1-5, s, f, r, v)");

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
    ofLog() << "<app::mouse move at: (" << x << ", " << y << ")>";
}

void Application::mouseDragged(int x, int y, int button)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  if(isVerbose)
    ofLog() << "<app::mouse drag at: (" << x << ", " << y << ") button:" << button <<">";
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

  renderer->addVectorShape(renderer->drawMode);

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
    case 49:  // key 1
      renderer->drawMode = VectorPrimitive::PIXEL;
      ofLog() << "<draw mode: PIXEL>";
      break;

    case 50:  // key 2
      renderer->drawMode = VectorPrimitive::POINT;
      ofLog() << "<draw mode: POINT>";
      break;

    case 51:  // key 3
      renderer->drawMode = VectorPrimitive::LINE;
      ofLog() << "<draw mode: LINE>";
      break;

    case 52:  // key 4
      renderer->drawMode = VectorPrimitive::RECTANGLE;
      ofLog() << "<draw mode: RECTANGLE>";
      break;

    case 53:  // key 5
      renderer->drawMode = VectorPrimitive::ELLIPSE;
      ofLog() << "<draw mode: ELLIPSE>";
      break;

    case 102: // key f
      renderer->randomColorFill();
      break;

    case 114: // key r
      renderer->reset();
      break;

    case 115: // key s
      renderer->randomColorStroke();
      break;

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
