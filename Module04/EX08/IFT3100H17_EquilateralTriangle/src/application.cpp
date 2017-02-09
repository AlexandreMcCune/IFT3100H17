// IFT3100H17_EquilateralTriangle/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  renderer = nullptr;
}

void Application::setup()
{
  ofSetWindowTitle("triangle équilatéral");

  ofLog() << "<app::setup>";

  renderer = new Renderer();
  renderer->setup();
}

void Application::update()
{
  renderer->update();
}

void Application::draw()
{
  renderer->draw();
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
