all:
	c++ montecarlo/simplemontecarlo.cpp -std=c++17 -Wall -Werror -o bin/simplemontecarlo
	c++ montecarlo/generalmontecarlo.cpp -std=c++17 -Wall -Werror -o bin/generalmontecarlo

clean:
	rm -rf bin/*
