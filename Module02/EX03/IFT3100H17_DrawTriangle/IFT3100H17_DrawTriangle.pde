// IFT3100H17_DrawTriangle.pde
// Dessine une séquence de triangles dont les trois sommets ont des positions aléatoires.

size(512, 512);

background(int(random(0.0f, 1.0f) * 255.0f));

int counter = 0;

while(counter <= 16)
{
  strokeWeight(2.0f);

  stroke(int(random(0.0f, 1.0f) * 255.0f));
  fill(int(random(0.0f, 1.0f) * 255.0f));

  // dessiner un triangle en fonction de la position x et y de ses trois sommets
  triangle(
    random(0.0f, 1.0f) * width,
    random(0.0f, 1.0f) * height,
    random(0.0f, 1.0f) * width,
    random(0.0f, 1.0f) * height,
    random(0.0f, 1.0f) * width,
    random(0.0f, 1.0f) * height);

  ++counter;
}

saveFrame("render.png");