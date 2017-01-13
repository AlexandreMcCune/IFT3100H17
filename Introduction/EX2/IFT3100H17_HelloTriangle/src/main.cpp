// IFT3100H17_HelloTriangle/main.cpp
// Dessiner un triangle par seconde à des positions aléatoires dans la fenêtre d'affichage.

#include "ofMain.h"
#include "application.h"

// point d'entrée de l'application
int main( )
{
  // création du contexte de rendu
  ofSetupOpenGL(512, 512, OF_WINDOW);

  // instancier et lancer l'application
  ofRunApp(new Application());
}
