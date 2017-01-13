// IFT3100H17_HelloTriangle.pde
// Dessiner un triangle par seconde à des positions aléatoires dans la fenêtre d'affichage.

float vertex1X;
float vertex1Y;
float vertex2X;
float vertex2Y;
float vertex3X;
float vertex3Y;

float colorR;
float colorG;
float colorB;

float pointRadius;

// fonction invoquée à l'initialisation de l'application
void setup()
{
  size(512, 512);
  frameRate(1);
  noStroke();

  pointRadius = 8;
}

// fonction invoquée lors d'une mise à jour de la logique de l'application
void update()
{
  vertex1X = random(0, width);
  vertex1Y = random(0, height);
  vertex2X = random(0, width);
  vertex2Y = random(0, height);
  vertex3X = random(0, width);
  vertex3Y = random(0, height);

  colorR = random(0, 255);
  colorG = random(0, 255);
  colorB = random(0, 255);
}

// fonction invoquée lors d'une mise à jour du rendu de la fenêtre de l'application
void draw()
{
  update();

  background(191);

  fill(colorR, colorG, colorB);

  triangle(
    vertex1X, vertex1Y,
    vertex2X, vertex2Y,
    vertex3X, vertex3Y);

  fill(0);

  ellipse(vertex1X, vertex1Y, pointRadius, pointRadius);
  ellipse(vertex2X, vertex2Y, pointRadius, pointRadius);
  ellipse(vertex3X, vertex3Y, pointRadius, pointRadius);
}
