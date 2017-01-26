// IFT3100H17_DrawVectorImage.pde
// Importer un fichier image vectoriel de type .svg et afficher la forme vectorielle qu'il contient en pleine fenêtre.

// paramètre
String file = "graph.svg";

// variable
PShape shape;

void setup()
{
  size(512, 512);
  noLoop();

  // mode où l'origine de l'image vectorielle est au centre
  shapeMode(CENTER);

  // chargement du fichier
  shape = loadShape(file);
}

void draw()
{
  background(255);

  // afficher l'image vectorielle au centre de la scène
  shape(shape, width/2.0f , height/2.0f, 512, 512);

  // exporter le contenu de la fenêtre d'affichage dans une image non-vectorielle
  saveFrame("render.png");
}