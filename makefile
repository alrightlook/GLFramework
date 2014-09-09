GLFrameworkDemo:main.o Game.o stb_image.o
	g++ main.o Game.o stb_image.o -o GLFrameworkDemo -lSDL2main -lmingw32 -lSDL2 -lopengl32 -lglu32 -g
main.o:main.cpp
	g++ -c main.cpp -g
Game.o:Game.cpp
	g++ -c Game.cpp -g
stb_image:stb_image.c
	gcc -c stb_image.o -g

clean:
	rm -fr *.o *.exe *~