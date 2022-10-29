all: compile link

compile:
	g++ -c *.cpp -I"D:\\Projects\\DLLS\\SFML-2.5.1\\include" -DSFML_STATIC

link:
	g++ *.o -o sfml-app -L"D:\\Projects\\DLLS\\SFML-2.5.1\\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

clean:
	rm -f main *.o