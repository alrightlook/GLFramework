GLFrameworkDemo:main.o Game.o stb_image.o GameObj.o Mesh.o
	g++ main.o Game.o stb_image.o GameObj.o Mesh.o -o GLFrameworkDemo -lmingw32 -lSDL2main -lSDL2 -lopengl32 -lglu32 -lglew32 -g 
GameObj.o:GameObj.cpp
	g++ -c GameObj.cpp -g
main.o:main.cpp
	g++ -c main.cpp -g
Game.o:Game.cpp
	g++ -c Game.cpp -g
stb_image.o:stb_image.c
	gcc -c stb_image.c -g
Mesh.o:Mesh.cpp
	g++ -c Mesh.cpp -g

clean:
	rm -fr *.o *.exe *~
