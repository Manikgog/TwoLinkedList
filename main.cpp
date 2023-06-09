#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>


struct Node
{
public:
	Node() : _data(0), _next(nullptr), _prev(nullptr) {}
	Node(int data) : _data(data), _next(nullptr), _prev(nullptr) {}
	Node* _next;
	Node* _prev;
	int GetData()
	{
		return _data;
	}
	~Node()
	{
		std::cout << "Node deleted with data " << _data << std::endl;
	}
private:
	int _data;
};


class List
{
private:
	Node* _head;
	Node* _tail;
	size_t _size;
	bool AddMain(Node* node)
	{
		if (_head == nullptr)
		{
			_head = node;
			_tail = node;
			return true;
		}
		return false;
	}
	

public:
	List() : _head(nullptr), _tail(nullptr), _size(0)
	{}

	size_t GetSize()
	{
		return _size;
	}

	void AddTail(int data)
	{
		Node* newNode = new Node(data);
		if(AddMain(newNode))
			return;
		newNode->_next = _tail;
		_tail->_prev = newNode;
		_tail = newNode;
		_size++;
		return;
	}

	void AddHead(int data)
	{
		Node* newHead = new Node(data);
		if (AddMain(newHead))
			return;
		_head->_next = newHead;
		newHead->_prev = _head;
		_head = newHead;
		_size++;
		return;
	}

	void ShowListFromHead()
	{
		for (auto cur = _head; cur != nullptr; cur = cur->_prev)
		{
			std::cout << cur->GetData() << " ";
		}
		std::cout << std::endl;
	}

	void ShowListFromTail()
	{
		for (auto cur = _tail; cur != nullptr; cur = cur->_next)
		{
			std::cout << cur->GetData() << " ";
		}
		std::cout << std::endl;
	}

	void Clear()
	{
		if (_size == 0)
			return;
		auto cur = _head;
		while (cur != nullptr)
		{
			cur = cur->_prev;
			delete _head;
			_head = cur;
			_size--;
		}
	}

	Node* Find(int index)
	{
		if (index < 0 || index >= _size)
		{
			std::cout << "Индекс за пределами списка " << std::endl;
			return _head;
		}
			
		auto cur = _head;
		while (index != 0)
		{
			cur = cur->_prev;
			index--;
		}
		return cur;
	}

	void DeleteData(int index)
	{
		if (index < 0 || index > _size)
		{
			std::cout << "Индекс за пределами списка " << std::endl;
			return;
		}

		if (index == _size - 1)
		{
			Node* temp = _tail;
			_tail = _tail->_next;
			delete temp;
			_size--;
			return;
		}
		else if (index == 0)
		{
			Node* temp = _head;
			_head = _head->_prev;
			delete temp;
			_size--;
			return;
		}

		Node* nextNode = Find(index+1);
		Node* prevNode = Find(index-1);
		Node* deleteNode = Find(index);
		prevNode->_prev = nextNode;
		nextNode->_next = prevNode;
		delete(deleteNode);
		_size--;
		return;
	}


	~List()
	{
		Clear();
	}

};


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); // установка кодовой страницы на ввод текста
	
	List list;
	for (int i = 0; i < 10; ++i)
		list.AddHead(i + 2);
	list.ShowListFromHead();
	list.ShowListFromTail();
	list.DeleteData(2);
	list.ShowListFromHead();

	return 0;
}
