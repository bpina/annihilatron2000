#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "SDL/SDL.h"
#include "GL/gl.h"

class Application 
{
  private:
    bool _running;
    SDL_Surface* _display;
    
    int _height;
    int _width;

  public:
    Application();
    void SetSize(int width, int height);
    bool Initialize();
    int Run();
    void HandleEvent(SDL_Event* event);
    void Loop();
    void Render();
    void CleanUp();

};


struct PlayerInfo {
  int x;
  int y;
};
#endif
