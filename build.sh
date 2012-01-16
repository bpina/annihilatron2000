g++ -g -Wall -c texture_loader.cc application.cc  -lSDL -lGL
g++ -g -Wall -c -lSDL -lGL
g++ -g -Wall -c main.cc
g++ -g -Wall -o annihilatron.bin texture_loader.o application.o main.o -lSDL -lGL
mv annihilatron.bin build/
