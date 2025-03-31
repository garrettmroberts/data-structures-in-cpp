all:
	clang++ -std=c++17 -c LinkedList.cpp -o LinkedList.o
	clang++ -std=c++17 -c DoublyLinkedList.cpp -o DoublyLinkedList.o
	clang++ -std=c++17 -c main.cpp -o main.o
	clang++ -std=c++17 main.o LinkedList.o DoublyLinkedList.o -o output
run: all
	./output
clean:
	rm -f *.o output
