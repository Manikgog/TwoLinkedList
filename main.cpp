#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>


class TwoLinkedList
{
private:
	struct Node
	{
		Node() : data(0), next(nullptr), prev(nullptr) {}
		int data;
		Node* next;
		Node* prev;
	};

	Node* _head;
	Node* _tail;
	size_t _size;

public:
	



};















int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	srand(time(NULL));



	return 0;
}
