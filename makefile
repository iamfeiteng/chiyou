all: EventLoop.o Socket.o SocketOps.o

EventLoop.o: EventLoop.cc
	g++ -c EventLoop.cc
Socket.o: Socket.cc
	g++ -c Socket.cc
SocketOps.o: SocketOps.cc
	g++ -c SocketOps.cc
InetAddress.o: InetAddress.cc
	g++ -c InetAddress.cc
clean:
	rm -rf EventLoop.o Socket.o SocketOps.o InetAddress.o
