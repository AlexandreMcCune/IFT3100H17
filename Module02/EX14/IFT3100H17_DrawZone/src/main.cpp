// IFT3100H16_DrawZone/main.cpp
// Dessiner une zone de dessin en fonction de la position où un des boutons de la souris a été appuyé
// et de la position courante du curseur du périphérique de pointage, tout en restant dans les limites du canevas.

#include "ofMain.h"
#include "application.h"

int main( )
{
  ofSetupOpenGL(512, 512, OF_WINDOW);
  ofRunApp(new Application());
}
