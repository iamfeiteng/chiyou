all: EventLoop.o Socket.o SocketOps.o Mutex.o Condition.o CountDownLatch.o

Mutex.o: Mutex.cc
	g++ -c Mutex.cc 
Condition.o: Condition.cc
	g++ -c Condition.cc
EventLoop.o: EventLoop.cc
	g++ -c EventLoop.cc
Socket.o: Socket.cc
	g++ -c Socket.cc
SocketOps.o: SocketOps.cc
	g++ -c SocketOps.cc
CountDownLatch.o: CountDownLatch.cc
	g++ -c CountDownLatch.cc
clean:
	rm -rf EventLoop.o Socket.o SocketOps.o Mutex.o Condition.o CountDownLatch.o
