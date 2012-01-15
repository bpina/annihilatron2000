#ifndef TEXTURE_LOADER_H
#define TEXTURE_LOADER_H

#include <SDL/SDL.h>
#include <GL/gl.h>

struct TextureInfo {
  GLuint texture;
  GLint colors;
  int width;
  int height;
};

class TextureLoader {
  public:
  TextureLoader();
  TextureInfo GetTexture(const char *file_name);
};



#endif
