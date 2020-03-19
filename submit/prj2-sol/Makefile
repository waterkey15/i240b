all: nums seq-test

seq-test: seq-test.o command.o
	g++ -o seq-test seq-test.o command.o

nums: 	nums.o command.o
	g++ -o nums nums.o command.o

seq-test.o: seq-test.cc seq.hh dlinkseq.hh
	g++ -c seq-test.cc

nums.o:	nums.cc seq.hh dlinkseq.hh
	g++ -c nums.cc

command.o: command.cc command.hh
	g++ -c command.cc

clean:	
	rm -f *~ *.o nums seq-test
