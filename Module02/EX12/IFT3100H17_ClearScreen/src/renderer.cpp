// IFT3100H17_ClearScreen/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer(){}

void Renderer::setup()
{
  ofSetFrameRate(60);

  // mode initial
  clearMode = ClearMode::NONE;

  // couleur initiale
  clearColorRed   = 127;
  clearColorGreen = 63;
  clearColorBlue  = 31;

  // flag de mise à jour
  hasChanged = true;
}

void Renderer::draw()
{
  switch(clearMode)
  {
    case ClearMode::NONE:
      clear();
      break;

    case ClearMode::DEFAULT:
      clear();
      break;

    case ClearMode::BLACK:
      clearToBlack();
      break;

    case ClearMode::WHITE:
      clearToWhite();
      break;

    case ClearMode::GRAY:
      clearToGray(223);
      break;

    case ClearMode::COLOR:
      clearToColor(127,0,63);
      break;

    case ClearMode::RANDOM:
      clearToRandom();
      break;

    default:
      clearToColor(255, 0, 0);
      break;
  }
}

// fonction qui efface le contenu du framebuffer actif et le remplace par une couleur par défaut (gris)
void Renderer::clear() const
{
  ofClear(clearColorRed, clearColorGreen, clearColorBlue);
}

// fonction qui efface le contenu du framebuffer actif et le remplace par la couleur noire
void Renderer::clearToBlack() const
{
  ofClear(0);
}

// fonction qui efface le contenu du framebuffer actif et le remplace par la couleur blanche
void Renderer::clearToWhite() const
{
  ofClear(255);
}

// fonction qui efface le contenu du framebuffer actif et le remplace par un ton de gris passé en paramètre
void Renderer::clearToGray(int g)
{
  if(hasChanged)
  {
    hasChanged = false;
    clearColorGray = g;
  }

  ofClear(clearColorGray);
}

// fonction qui efface le contenu du framebuffer actif et le remplace par une couleur RGB passée en paramètre
void Renderer::clearToColor(int r, int g, int b)
{
  if(hasChanged)
  {
    hasChanged = false;

    clearColorRed   = r;
    clearColorGreen = g;
    clearColorBlue  = b;
  }

  clear();
}

// fonction qui efface le contenu du framebuffer actif et le remplace par une couleur RGB aléatoire
void Renderer::clearToRandom()
{
  if(hasChanged)
  {
    hasChanged = false;

    clearColorRed   = (int) ofRandom(0, 256);
    clearColorGreen = (int) ofRandom(0, 256);
    clearColorBlue  = (int) ofRandom(0, 256);
  }

  clear();
}

Renderer::~Renderer(){}
