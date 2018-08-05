all: EventLoop.o Socket.o SocketOps.o Mutex.o Condition.o CountDownLatch.o Thread.o ThreadPool.o

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
Thread.o: Thread.cc
	g++ -c Thread.cc
ThreadPool.o: ThreadPool.cc
	g++ -c ThreadPool.cc
clean:
	rm -rf EventLoop.o Socket.o SocketOps.o Mutex.o Condition.o CountDownLatch.o Thread.o ThreadPool.o
