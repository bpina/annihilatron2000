#include "application.h"

int main(int argc, char** argV) {
  Application application;
  PlayerInfo player_info;
  player_info.x = 0;
  player_info.y = 0;

  application.SetSize(1024,768);
  return application.Run(player_info);
}
