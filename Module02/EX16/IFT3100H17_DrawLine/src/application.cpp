// IFT3100H17_DrawLine/application.cpp
// Classe principale de l'application.

#include "application.h"

Application::Application()
{
  renderer = nullptr;
}

void Application::setup()
{
  ofLog() << "<app::setup>";

  renderer = new Renderer();
  renderer->setup();

  switch(renderer->lineRasterMode)
  {
    case LINE_RASTERIZER_DDA:
      ofSetWindowTitle("rastérisation de lignes (DDA)");
      break;
    case LINE_RASTERIZER_BRESENHAM:
      ofSetWindowTitle("rastérisation de lignes (Bresenham)");
      break;
    default:
      ofSetWindowTitle("rastérisation de lignes");
      break;
  }

  isVerbose = false;
}

void Application::draw()
{
  renderer->draw();
}

void Application::mouseMoved(int x, int y)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;
}

void Application::mouseDragged(int x, int y, int button)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;
}

void Application::mousePressed(int x, int y, int button)
{
  renderer->isMouseButtonPressed = true;

  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  renderer->xMousePress = x;
  renderer->yMousePress = y;

  if(renderer->isInside(x, y, 0, 0, renderer->framebufferWidth, renderer->framebufferHeight))
  {
    int fatPixelIndex = renderer->findIndexOfFatPixelByPosition(x, y);

    renderer->fatPixelStateChange(fatPixelIndex, FAT_PIXEL_STATE_ON);
  }

  if(isVerbose)
    ofLog() << "<app::mouse press at: (" << x << ", " << y << ")>";
}

void Application::mouseReleased(int x, int y, int button)
{
  renderer->isMouseButtonPressed = false;

  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;

  if(renderer->isInside(x, y, 0, 0, renderer->framebufferWidth, renderer->framebufferHeight))
  {
    int fatPixelIndex1 = renderer->findIndexOfFatPixelByPosition(renderer->xMousePress,   renderer->yMousePress);
    int fatPixelIndex2 = renderer->findIndexOfFatPixelByPosition(renderer->xMouseCurrent, renderer->yMouseCurrent);

    int x1 = fatPixelIndex1 % renderer->fatPixelGridHeight;
    int y1 = fatPixelIndex1 / renderer->fatPixelGridWidth;
    int x2 = fatPixelIndex2 % renderer->fatPixelGridHeight;
    int y2 = fatPixelIndex2 / renderer->fatPixelGridWidth;

    switch(renderer->lineRasterMode)
    {
      case LINE_RASTERIZER_DDA:
        renderer->rasterLineDDA(x1, y1, x2, y2);
        break;

      case LINE_RASTERIZER_BRESENHAM:
        renderer->rasterLineBresenham(x1, y1, x2, y2);
        break;

      default:
        break;
    }

    renderer->fatPixelStateChange(fatPixelIndex1, FAT_PIXEL_STATE_START);
    renderer->fatPixelStateChange(fatPixelIndex2, FAT_PIXEL_STATE_END);
  }

  if(isVerbose)
    ofLog() << "<app::mouse release at: (" << x << ", " << y << ")>";
}

void Application::mouseEntered(int x, int y)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;
}

void Application::mouseExited(int x, int y)
{
  renderer->xMouseCurrent = x;
  renderer->yMouseCurrent = y;
}

void Application::keyReleased(int key)
{
  switch(key)
  {
    case 49:  // key 1
      renderer->lineRasterMode = LINE_RASTERIZER_DDA;
      ofSetWindowTitle("rastérisation de lignes (DDA)");
      ofLog() << "<draw mode: DDA>";
      break;
    case 50:  // key 2
      renderer->lineRasterMode = LINE_RASTERIZER_BRESENHAM;
      ofSetWindowTitle("rastérisation de lignes (Bresenham)");
      ofLog() << "<draw mode: BRESENHAM>";
      break;
    case 114: // key r
      renderer->reset();
      break;
    case 118: // key v
      isVerbose = !isVerbose;
      renderer->isVerbose = this->isVerbose;
      ofLog() << "<verbose mode:" << isVerbose << ">";
      break;

    default:
      break;
  }

  if(isVerbose)
    ofLog() << "<app::keyReleased: " << key << ">";
}

void Application::exit()
{
  ofLog() << "<app::exit>";
}

Application::~Application()
{
  if(nullptr != renderer)
    delete renderer;
}
