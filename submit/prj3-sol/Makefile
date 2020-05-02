all: multi-queues 

multi-queues: multi-queues.o command.o command-stream.o job.o
	g++ -o  multi-queues multi-queues.o command.o command-stream.o job.o 

command-test.o: command-test.cc command.hh job.hh command-stream.hh
	g++ -c command-test.cc

command.o: command.cc command.hh
	g++ -c command.cc

command-stream.o: command-stream.cc command-stream.hh
	g++ -c command-stream.cc

job.o: job.cc job.hh
	g++ -c job.cc

clean:
	rm -f *~ *.o command-test
	
