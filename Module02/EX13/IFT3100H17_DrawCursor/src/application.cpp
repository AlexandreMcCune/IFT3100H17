// IFT3100H17_DrawCursor/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  renderer = nullptr;
}

void Application::setup()
{
  ofSetWindowTitle("curseur");

  ofLog() << "<app::setup>";

  renderer = new Renderer();
  renderer->setup();

  isVerbose = false;
}

void Application::draw()
{
  // afficher le tableau de primitives vectorielles
  renderer->draw();
}

// fonction invoquée quand la position du curseur change
void Application::mouseMoved(int x, int y)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  if(isVerbose)
    ofLog() << "<app::mouse moved    at: (" << x << ", " << y << ")>";
}

// fonction invoquée quand la position du curseur change pendant qu'un bouton de la souris est appuyé
void Application::mouseDragged(int x, int y, int button)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  if(isVerbose)
    ofLog() << "<app::mouse dragged  at: (" << x << ", " << y << ") button:" << button <<">";
}

// fonction invoquée quand un bouton de la souris est appuyé
void Application::mousePressed(int x, int y, int button)
{
  renderer->isMouseButtonPressed = true;

  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  renderer->xMousePress = x;
  renderer->yMousePress = y;

  ofLog() << "<app::mouse pressed  at: (" << x << ", " << y << ")>";
}

// fonction invoquée quand un bouton de la souris est relaché
void Application::mouseReleased(int x, int y, int button)
{
  renderer->isMouseButtonPressed = false;

  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  ofLog() << "<app::mouse released at: (" << x << ", " << y << ")>";
}

// fonction invoquée quand le curseur entre dans la fenêtre
void Application::mouseEntered(int x, int y)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  ofLog() << "<app::mouse entered  at: (" << x << ", " << y << ")>";
}

// fonction invoquée quand le curseur sort dans la fenêtre
void Application::mouseExited(int x, int y)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  ofLog() << "<app::mouse exited   at: (" << x << ", " << y << ")>";
}

// fonction invoquée quand une touche du clavier est relâchée
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
