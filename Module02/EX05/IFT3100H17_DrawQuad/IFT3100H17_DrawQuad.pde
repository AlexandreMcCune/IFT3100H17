// IFT3100H17_DrawQuad.pde
// Dessine une séquence de quadrilatères dont les quatre sommets ont des positions aléatoires.

size(512, 512);

background(int(random(0.0f, 1.0f) * 255.0f));

int counter = 0;

while(counter <= 16)
{
  strokeWeight(1.5f);

  stroke(int(random(0.0f, 1.0f) * 255.0f));
  fill(int(random(0.0f, 1.0f) * 255.0f));

  quad(
    random(0.0f, 1.0f) * width,
    random(0.0f, 1.0f) * height,
    random(0.0f, 1.0f) * width,
    random(0.0f, 1.0f) * height,
    random(0.0f, 1.0f) * width,
    random(0.0f, 1.0f) * height,
    random(0.0f, 1.0f) * width,
    random(0.0f, 1.0f) * height);

  ++counter;
}

saveFrame("render.png");