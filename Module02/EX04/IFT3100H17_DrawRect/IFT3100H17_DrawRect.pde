// IFT3100H17_DrawRect.pde
// Dessine une séquence de rectangles de taille décroissante.

size(512, 512);
background(0);
strokeWeight(2);
rectMode(CENTER);

float diameter = 512;

int colorStroke = int(random(255.0f));
int colorFill = int(random(255.0f));

while(diameter > 10)
{
  stroke(colorStroke);
  fill(colorFill);

  // dessiner un rectangle en fonction de la position x et y de son centre, d'une largeur et d'une hauteur
  rect(
    width / 2.0f,
    height / 2.0f,
    diameter,
    diameter);

  diameter *= 0.95f;

  colorStroke += 8;
  colorStroke = colorStroke <= 255 ? colorStroke : 255;

  colorFill -= 8;
  colorFill = colorFill > 0 ? colorFill : 0;
}

saveFrame("render.png");