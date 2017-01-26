// IFT3100H17_ClearScreen/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  renderer = nullptr;
}

void Application::setup()
{
  ofSetWindowTitle("couleur d'arrière-plan (1-5 ou hasard)");

  ofLog() << "<app::setup>";

  renderer = new Renderer();
  renderer->setup();
}

void Application::draw()
{
  renderer->draw();
}

// fonction invoquée quand une touche du clavier est relâchée
void Application::keyReleased(int key)
{
  switch(key)
  {
    case 49: // key 1
      renderer->clearMode = ClearMode::DEFAULT;
      ofLog() << "<clear mode: DEFAULT>";
      break;

    case 50: // key 2
      renderer->clearMode = ClearMode::BLACK;
      ofLog() << "<clear mode: BLACK>";
      break;

    case 51: // key 3
      renderer->clearMode = ClearMode::WHITE;
      ofLog() << "<clear mode: WHITE>";
      break;

    case 52: // key 4
      renderer->clearMode = ClearMode::GRAY;
      ofLog() << "<clear mode: GRAY>";
      break;

    case 53: // key 5
      renderer->clearMode = ClearMode::COLOR;
      ofLog() << "<clear mode: COLOR>";
      break;

    case 54: // key 6
      renderer->clearMode = ClearMode::RANDOM;
      ofLog() << "<clear mode: RANDOM>";
      break;

    default:
      renderer->clearMode = ClearMode::RANDOM;
      break;
  }

  renderer->hasChanged = true;
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
