// IFT3100H17_Origin/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  renderer = nullptr;
}

void Application::setup()
{
  ofLog() << "<app::setup>";

  ofSetWindowTitle("origine");

  renderer = new Renderer();
  renderer->setup();
}

void Application::draw()
{
  renderer->draw();
}

void Application::mouseReleased(int x, int y, int button)
{
  renderer->reset();
}

void Application::keyReleased(int key)
{
  renderer->reset();
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
