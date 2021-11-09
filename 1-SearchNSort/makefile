all:	sns perf

sns:	TestSNS.cpp
	g++ -std=c++11 -Wall TestSNS.cpp -o sns
	
perf:	perf.cpp
	g++ -std=c++11 -Wall -O4 perf.cpp -o perf

clean:
	rm sns perf
