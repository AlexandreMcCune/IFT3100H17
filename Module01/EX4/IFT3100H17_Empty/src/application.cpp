// IFT3100H17_Empty/application.cpp
// Classe principale de l'application.

#include "application.h"

// constructeur de la classe
Application::Application()
{
  renderer = nullptr;
}

// fonction invoquée à l'initialisation de l'application
void Application::setup()
{
  ofSetWindowTitle("projet vide");

  renderer = new Renderer();
  renderer->setup();

  ofLog() << "<app::setup>";
}

// fonction invoquée lors d'une mise à jour de la logique de l'application
void Application::update()
{
  renderer->update();
}

// fonction invoquée lors d'une mise à jour du rendu de la fenêtre de l'application
void Application::draw()
{
  renderer->draw();
}

// fonction invoquée quand l'application quitte
void Application::exit()
{
  ofLog() << "<app::exit>";
}

// destructeur de la classe
Application::~Application()
{
  if(nullptr != renderer)
    delete renderer;
}
