#include "application.h"
#include "texture_loader.h"

PlayerInfo::PlayerInfo() {
}

Application::Application() {
  _display = NULL;
}

void Application::SetSize(int width, int height) {
  _width = width;
  _height = height;
}

bool Application::Initialize() {
  if(SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;
  _running = true;

  
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE,            8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,          8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,           8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,          8);

  _display = SDL_SetVideoMode(_width, _height, 32, SDL_OPENGL);
  if(_display == NULL) return false;

  glClearColor(0,0,0,0);
  glClearDepth(1.0f);
  glViewport(0, 0, _width, _height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  
  glOrtho(0, _width, _height, 0, 1, -1);

  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_TEXTURE_2D);
  glLoadIdentity();

  return true;
}

int Application::Run(PlayerInfo player_info) {
  if(!Initialize()) return -1;
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
  
  player_info_ = player_info;
  SDL_Event event;
  
  while(_running) {
    while(SDL_PollEvent(&event)) {
      HandleEvent(&event);
      Loop();
      Render();
    }
  }

  CleanUp();

  return 0;
}

void Application::HandleEvent(SDL_Event* event) {
  switch(event->type) {
    case SDL_KEYDOWN:
      if (event->key.keysym.sym == SDLK_ESCAPE)
        _running = false;
      //if (event->key.keysym.sym == SDLK_DOWN)
      // player_info_.y += 4;
      //if (event->key.keysym.sym == SDLK_UP)
      //  player_info_.y -= 4;
      if (event->key.keysym.sym == SDLK_RIGHT) {
        player_info_.player_facing = FACING_RIGHT;
        player_info_.x += 10;
      }
      if (event->key.keysym.sym == SDLK_LEFT) {
        player_info_.player_facing = FACING_LEFT;
        player_info_.x -= 10;
      }

      break;
    case SDL_QUIT:
      _running = false;
      break;
  }
}

void Application::Loop() {
}

void Application::Render() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  
  TextureLoader texture_loader;
  TextureInfo background_texture = texture_loader.GetTexture("resources/level.bmp");
  glBindTexture(GL_TEXTURE_2D, background_texture.texture);

  glBegin( GL_QUADS );
	  //Bottom-left vertex (corner)
	  glTexCoord2i( 0, 0 );
	  glVertex2i(0, _height - background_texture.height);
   
	  //Bottom-right vertex (corner)
	  glTexCoord2i( 1, 0 );
	  glVertex2i(background_texture.width, _height - background_texture.height);
   
	  //Top-right vertex (corner)
	  glTexCoord2i( 1, 1 );
	  glVertex2i( background_texture.width, _height);
   
	  //Top-left vertex (corner)
	  glTexCoord2i( 0, 1 );
	  glVertex2i( 0, _height);
  glEnd();
  glDeleteTextures(1, &background_texture.texture);


  GLuint texture;
  TextureInfo texture_info =
    texture_loader.GetTexture("resources/character2.bmp"); 

  int playerCoords[4][2];
  playerCoords[0][0] = player_info_.x;
  playerCoords[0][1] = _height - texture_info.height - 40;

  playerCoords[1][0] = player_info_.x + texture_info.width;
  playerCoords[1][1] = _height - texture_info.height - 40;

  playerCoords[2][0] = player_info_.x + texture_info.width;
  playerCoords[2][1] = _height - 40;

  playerCoords[3][0] = player_info_.x;
  playerCoords[3][1] = _height - 40;


  glBindTexture(GL_TEXTURE_2D, texture_info.texture);
  
  glBegin( GL_QUADS );
	  //Bottom-left vertex (corner)
	  glTexCoord2i( 0, 0 );
	  glVertex2i(playerCoords[0][0],playerCoords[0][1]);
   
	  //Bottom-right vertex (corner)
	  glTexCoord2i( 1, 0 );
	  glVertex2i(playerCoords[1][0],playerCoords[1][1]);
   
	  //Top-right vertex (corner)
	  glTexCoord2i( 1, 1 );
	  glVertex2i( playerCoords[2][0],playerCoords[2][1] );
   
	  //Top-left vertex (corner)
	  glTexCoord2i( 0, 1 );
	  glVertex2i( playerCoords[3][0],playerCoords[3][1] );
  glEnd();
  glDeleteTextures(1, &texture_info.texture);

  SDL_GL_SwapBuffers();

  glDeleteTextures( 1, &texture );
}

void Application::CleanUp() {
    SDL_Quit();
}
