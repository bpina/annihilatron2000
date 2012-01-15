#include "texture_loader.h"

TextureLoader::TextureLoader() {
}

TextureInfo TextureLoader::GetTexture(const char *file_name) {
  TextureInfo texture_info;
  GLuint texture;
  SDL_Surface *surface;
  GLint num_colors;
  int width;
  int height;

  if((surface = SDL_LoadBMP(file_name))) { 
    num_colors = surface->format->BytesPerPixel;
    GLenum texture_format;
    if (num_colors == 4) {
      if (surface->format->Rmask == 0x000000ff)
        texture_format = GL_RGBA;
      else
        texture_format = GL_BGRA;
    } else if (num_colors == 3) {
      if (surface->format->Rmask == 0x000000ff)
        texture_format = GL_RGB;
      else
        texture_format = GL_BGR;
    } else {
      exit(0);
    }

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, num_colors, surface->w, surface->h, 0,
      texture_format, GL_UNSIGNED_BYTE, surface->pixels);
    
  }
  
  texture_info.texture = texture;
  texture_info.colors = num_colors;
  texture_info.width = surface->w;
  texture_info.height = surface->h;

  return texture_info;
}
