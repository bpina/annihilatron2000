g++ -g -Wall -c texture_loader.cc application.cc  -lSDL -lGL
g++ -g -Wall -c -lSDL -lGL
g++ -g -Wall -c main.cc
g++ -g -Wall -o testapp texture_loader.o application.o player_manager.o main.o -lSDL -lGL
