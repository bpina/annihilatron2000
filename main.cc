#include "application.h"

int main(int argc, char** argV) {
  Application application;
  application.SetSize(1024,768);
  return application.Run();
}
