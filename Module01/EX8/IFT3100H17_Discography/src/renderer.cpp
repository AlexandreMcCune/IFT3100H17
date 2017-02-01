// IFT3100H17_Discography/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer(){}

void Renderer::setup()
{
  ofSetFrameRate(0);

  // définir la valeur des espacements verticals et horizontals
  offsetVertical   = 16;
  offsetHorizontal = 16;

  // définir les dimensions des pochettes au rendu
  imageWidth  = 256;
  imageHeight = 256;

  // ajuster la dimension de la fenêtre
  ofSetWindowShape(
    imageWidth  * 3 + offsetHorizontal * 4,
    imageHeight * 3 + offsetVertical   * 4);

  // importer les pochettes d'album
  imageTopLeft.load("[1976]-Sad-Wings-of-Destiny.jpg");
  imageTopCenter.load("[1977]-Sin-After-Sin.jpg");
  imageTopRight.load("[1978]-Hell-Bent-For-Leather.jpg");

  imageMiddleLeft.load("[1982]-Screaming-for-Vengeance.jpg");
  imageMiddleCenter.load("[1984]-Defenders-Of-The-Faith.jpg");
  imageMiddleRight.load("[1986]-Turbo.jpg");

  imageBottomLeft.load("[1988]-Ram-It-Down.jpg");
  imageBottomCenter.load("[1990]-Painkiller.jpg");
  imageBottomRight.load("[2005]-Angel-Of-Retribution.jpg");
}

void Renderer::draw()
{
  ofClear(31);

  // dessiner l'image du haut à gauche
  imageTopLeft.draw(
    offsetHorizontal,
    imageHeight * 0 + offsetVertical * 1,
    imageWidth,
    imageHeight);

  // dessiner l'image du haut au centre
  imageTopCenter.draw(
    imageWidth  * 1 + offsetHorizontal * 2,
    imageHeight * 0 + offsetVertical * 1,
    imageWidth,
    imageHeight);

  // dessiner l'image du haut à droite
  imageTopRight.draw(
    imageWidth * 2 + offsetHorizontal * 3,
    imageHeight * 0 + offsetVertical * 1,
    imageWidth,
    imageHeight);

  // dessiner l'image du milieu à gauche
  imageMiddleLeft.draw(
    offsetHorizontal,
    imageHeight * 1 + offsetVertical * 2,
    imageWidth,
    imageHeight);

  // dessiner l'image du milieu au centre
  imageMiddleCenter.draw(
    imageWidth  * 1 + offsetHorizontal * 2,
    imageHeight * 1 + offsetVertical * 2,
    imageWidth,
    imageHeight);

  // dessiner l'image du milieu à droite
  imageMiddleRight.draw(
    imageWidth  * 2 + offsetHorizontal * 3,
    imageHeight * 1 + offsetVertical * 2,
    imageWidth,
    imageHeight);

  // dessiner l'image du bas à gauche
  imageBottomLeft.draw(
    offsetHorizontal,
    imageHeight * 2 + offsetVertical * 3,
    imageWidth,
    imageHeight);

  // dessiner l'image du bas au centre
  imageBottomCenter.draw(
    imageWidth  * 1 + offsetHorizontal * 2,
    imageHeight * 2 + offsetVertical * 3,
    imageWidth,
    imageHeight);

  // dessiner l'image du bas à droite
  imageBottomRight.draw(
    imageWidth  * 2 + offsetHorizontal * 3,
    imageHeight * 2 + offsetVertical * 3,
    imageWidth,
    imageHeight);
}

Renderer::~Renderer(){}
