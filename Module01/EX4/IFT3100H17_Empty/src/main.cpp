// IFT3100H17_Empty/main.cpp
// Exemple d'un projet relativement vide, mais avec une bonne structure de base
// et une simple animation de la couleur d'arrière-plan en fonction des frames et du temps écoulés.
// Un bon point de départ pour commencer un nouveau projet avec une scène vide.

#include "ofMain.h"
#include "application.h"

// point d'entrée de l'application
int main( )
{
  // création du contexte de rendu (OpenGL 2.1 par défaut)
  ofSetupOpenGL(512, 512, OF_WINDOW);

  // instancier et lancer le framework (OpenFrameworks 0.9.0)
  ofRunApp(new Application());
}
