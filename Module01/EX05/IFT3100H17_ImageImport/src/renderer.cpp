// IFT3100H17_ImageImport/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer(){}

void Renderer::setup()
{
  ofSetFrameRate(60);

  // importer une image située dans ./bin/data
  image.load("field.jpg");

  // redimensionner la fenêtre aux dimensions de l'image
  ofSetWindowShape(image.getWidth(), image.getHeight());
}

void Renderer::draw()
{
  // couleur de l'arrière-plan
  ofClear(0);

  // tinte de l'image (blanc pour les couleurs d'origine)
  ofSetColor(255);

  // afficher l'image sur toute la surface de la fenêtre
  image.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
}

Renderer::~Renderer(){}
