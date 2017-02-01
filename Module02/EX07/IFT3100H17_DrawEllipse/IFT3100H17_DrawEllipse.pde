// IFT3100H17_DrawEllipse.pde
// Dessine une séquence d'ellipses de taille décroissante.

size(512, 512);

background(0);
strokeWeight(2);
rectMode(CENTER);

float radius = 512.0f;

int colorStroke = int(random(255.0f));
int colorFill = int(random(255.0f));

while(radius > 10)
{
  stroke(colorStroke);
  fill(colorFill);

  // dessiner une ellipse en fonction de la position x et y de son centre, d'une largeur et d'une hauteur
  ellipse(
    width / 2.0f,
    height / 2.0f,
    radius,
    radius);

  radius *= 0.95f;

  colorStroke += 8;
  colorStroke = colorStroke <= 255 ? colorStroke : 255;

  colorFill -= 8;
  colorFill = colorFill > 0 ? colorFill : 0;
}

saveFrame("render.png");