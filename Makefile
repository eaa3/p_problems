


all: tribonacci_triangle.cpp
	g++ -o tribonacci_triangle tribonacci_triangle.cpp

run: tribonacci_triangle
	echo "..running test for ./tribonacci_triangle 10.."
	./tribonacci_triangle 10
