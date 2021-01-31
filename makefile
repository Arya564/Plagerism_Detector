final: main helper
	g++ -o plagiarismCatcher main.o helper.o
main:
	g++ -std=c++11 -O0 -g -Wall -Werror -o main.o -c main.cpp
helper:
	g++ -std=c++11 -O0 -g -Wall -Werror -o helper.o -c helper.cpp
