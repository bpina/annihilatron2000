#include "application.h"
#include "texture_loader.h"

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

  glClearColor(1,1,1,0);
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
      if (event->key.keysym.sym == SDLK_DOWN)
        player_info_.y += 4;
      if (event->key.keysym.sym == SDLK_UP)
        player_info_.y -= 4;
      if (event->key.keysym.sym == SDLK_RIGHT)
        player_info_.x += 4;
      if (event->key.keysym.sym == SDLK_LEFT)
        player_info_.x -= 4;

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
  
  GLuint texture;
  TextureLoader texture_loader;
  TextureInfo texture_info =
    texture_loader.GetTexture("resources/character.bmp");

  glBindTexture(GL_TEXTURE_2D, texture_info.texture);
  
  glBegin( GL_QUADS );
	  //Bottom-left vertex (corner)
	  glTexCoord2i( 0, 0 );
	  glVertex2i(player_info_.x,player_info_.y);
   
	  //Bottom-right vertex (corner)
	  glTexCoord2i( 1, 0 );
	  glVertex2i( player_info_.x + texture_info.width, player_info_.y );
   
	  //Top-right vertex (corner)
	  glTexCoord2i( 1, 1 );
	  glVertex2i( player_info_.x + texture_info.width,
          player_info_.y + texture_info.height );
   
	  //Top-left vertex (corner)
	  glTexCoord2i( 0, 1 );
	  glVertex2i( player_info_.x, player_info_.y + texture_info.height);
  glEnd();

  SDL_GL_SwapBuffers();

  glDeleteTextures( 1, &texture );
}

void Application::CleanUp() {
    SDL_Quit();
}
