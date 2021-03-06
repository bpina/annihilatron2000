#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "SDL/SDL.h"
#include "GL/gl.h"

enum PlayerFacing { FACING_LEFT, FACING_RIGHT };

class PlayerInfo {
  private:
  int jump_start_time_;

  public:
  PlayerInfo();
  PlayerFacing player_facing;
  int x;
  int y;
};

class Application 
{
  private:
    bool _running;
    SDL_Surface* _display;
    PlayerInfo player_info_;
    
    int _height;
    int _width;

  public:
    Application();
    void SetSize(int width, int height);
    bool Initialize();
    int Run(PlayerInfo player_info);
    void HandleEvent(SDL_Event* event);
    void Loop();
    void Render();
    void CleanUp();

};

#endif
