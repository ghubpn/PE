OBJ = main.o

test:	$(OBJ)
	g++ -o ProjectEuler $(OBJ)

Main.o:	main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o 