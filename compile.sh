mkdir -p out
g++ -c utilities/commandutils.cpp -o out/commandutils.o
g++ -c main.cpp -o out/main.o
g++ out/commandutils.o out/main.o -o out/run.o
