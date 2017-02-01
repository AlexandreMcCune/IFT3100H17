// IFT3100H17_ImageExport/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  renderer = nullptr;
}

void Application::setup()
{
  ofSetWindowTitle("exportation d'une image");

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
  ofLog() << "<app::keyReleased: " << key << ">";

  // valider si la clé relâchée est la barre d'espacement (space)
  if(key == ' ')
    renderer->imageExport("render","png");
}

void Application::windowResized(int w, int h)
{
  ofLog() << "<app::windowResized to: (" << w << ", " << h << ")>";
}

void Application::dragEvent(ofDragInfo dragInfo)
{
  ofLog() << "<app::ofDragInfo file[0]: " << dragInfo.files.at(0)
  << " at : " << dragInfo.position << ">";

  renderer->image.load(dragInfo.files.at(0));

  if(renderer->image.getWidth() > 0 && renderer->image.getHeight() > 0)
    ofSetWindowShape(renderer->image.getWidth(), renderer->image.getHeight());
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
