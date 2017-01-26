// IFT3100H17_DrawVectorPrimitives/main.cpp
// Dessiner des primitives vectorielles dans la zone de dessin (pixel, point, ligne, rectangle et ellipse)
// avec des couleurs aléatoires pour les lignes de contour et les zones de remplissage.

#include "ofMain.h"
#include "application.h"

int main( )
{
  ofSetupOpenGL(512, 512, OF_WINDOW);

  ofRunApp(new Application());
}
