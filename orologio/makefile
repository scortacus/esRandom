LIBS := `root-config --libs`
INCS := `root-config --cflags`

main : main.cpp classi.o
	g++ -Wall main.cpp classi.o -o main ${LIBS} ${INCS} -g

%.o : %.cpp %.h
	g++ -Wall -c $< -o $@ -g

clean :
	rm -f *.o *.png main
