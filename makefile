output: Cargo.o Cell.o Character.o Dining.o Game.o inBounds.o integerValidation.o Locomotive.o main.o Security.o Space.o Stable.o
	g++ -std=c++11 Cargo.o Cell.o Character.o Dining.o Game.o inBounds.o integerValidation.o Locomotive.o main.o Security.o Space.o Stable.o -o output

Cargo.o: Cargo.cpp Cargo.hpp
	g++ -std=c++11 -c Cargo.cpp

Cell.o: Cell.cpp Cell.hpp
	g++ -std=c++11 -c Cell.cpp

Character.o: Character.cpp Character.hpp
	g++ -std=c++11 -c Character.cpp

Dining.o: Dining.cpp Dining.hpp
	g++ -std=c++11 -c Dining.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

inBounds.o: inBounds.cpp inBounds.hpp
	g++ -std=c++11 -c inBounds.cpp

integerValidation.o: integerValidation.cpp integerValidation.hpp
	g++ -std=c++11 -c integerValidation.cpp

Locomotive.o: Locomotive.cpp Locomotive.hpp
	g++ -std=c++11 -c Locomotive.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Security.o: Security.cpp Security.hpp
	g++ -std=c++11 -c Security.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++11 -c Space.cpp

Stable.o: Stable.cpp Stable.hpp
	g++ -std=c++11 -c Stable.cpp

clean:
	rm *.o output

zip:
	zip -D Final_Lin_Justin.zip *.cpp *.hpp *.pdf makefile
