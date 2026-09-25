LIBS := `root-config --libs`
INCS := `root-config --cflags`

myLIBS = funzioni.o 


main : main.cpp funzioni.o
	g++ main.cpp funzioni.o -Wall -o main ${LIBS} ${INCS} -g

%.o : %.cpp %.h
	g++ -Wall -c $< -o $@

clean :
	rm -f *.o *.png main