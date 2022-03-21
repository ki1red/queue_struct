#include <iostream>

using namespace std;

struct QueueL
{
	int value;
	QueueL* next;
	QueueL* back;
	QueueL(QueueL* b = NULL,int val = NULL, QueueL* n = NULL)
	{
		value = val;
		next = n;
		back = b;
	}
};

class Queue
{
private:
	QueueL* first;
	QueueL* last;
	bool empty;

	bool g;
	//QueueL* dl;
public:
	Queue()
	{
		first = new QueueL();
		last = first;

		empty = true;


		g = false;
	}

	void Push(int value)
	{
		if (empty)//Только для первого объекта
		{
			QueueL* a = new QueueL(first, value, last);

			first = a;
			last = a;

			empty = false;
			g = true;
		}
		else if (g)//ТОЛЬКО ДЛЯ ВТОРОГО ОБЪЕКТА
		{
			g = false;

			QueueL* a = new QueueL(first, value, last);

			QueueL* tmp = first;

			tmp->next = a;
			tmp->back = a;

			last = a;

		}
		else//Для всех объектов
		{
			QueueL* a = new QueueL(first, value, last);
			last->back = a;
			first->next = a;

			last = a;
		}
	}

	bool Pop()
	{
		if (empty)
			return false;
		else
		{
			if (first->back == first)
			{
				empty = true;

				first = NULL;
				last = NULL;
				
				return true;
			}
			first = first->back;

			//--//
			if (last == first) 
			{
				g = true;
			}
			//--//

			first->next = last;



			last->back = first;



			return true;
		}
	}

	int Front()
	{
		if (empty)
			throw std::runtime_error("Queue is empty");
		else
		{
			return (first->value);
		}
	}

	int Back()
	{
		if (empty)
			throw std::runtime_error("Queue is empty");
		else
		{
			return (last->value);
		}
	}

	void Print()
	{
		if (empty)
			throw std::runtime_error("Queue is empty");
		else
		{
			cout << "--Print Queue--" << endl;
			QueueL* print = first;
			while (print != last)
			{
				cout << "\t" << print->value << endl;
				print = print->back;
			}
			cout << "\t" << print->value << endl;
			cout << "---------------" << endl;
		}
	}
};

int main()
{
	Queue a;
	a.Push(10);
	a.Push(11);
	a.Push(12);
	a.Pop();
	a.Push(13);
	a.Pop();
	a.Pop();
	a.Push(14);
	a.Push(15);
	a.Pop();
	a.Pop();
	a.Pop();
	a.Push(16);
	cout<< a.Front()<< endl;
	cout << a.Back()<<endl;
	a.Print();
}
