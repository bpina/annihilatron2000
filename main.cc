#include "application.h"

int main(int argc, char** argV) {
  PlayerInfo player_info;
  Application application;
  player_info.x = 0;
  player_info.y = 0;

  application.SetSize(1660,900);
  return application.Run(player_info);
}
