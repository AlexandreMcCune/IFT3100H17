// IFT3100H17_Discography/ofApp.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  renderer = nullptr;
}

void Application::setup()
{
  ofSetWindowTitle("discographie");

  ofLog() << "<app::setup>";

  renderer = new Renderer();
  renderer->setup();
}

void Application::draw()
{
  renderer->draw();
}

void Application::keyReleased(int key)
{
  ofLog() << "<app::key release: " << key << ">";
}

void Application::windowResized(int w, int h)
{
  ofLog() << "<app::resize (" << w << ", " << h << ")>";
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
