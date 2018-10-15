#include "main_head.h"
//	List
List::List() : start(nullptr), amount(0)
{
	cout << "Список создан." << endl;
}

List::List(string type, double nums) : start(nullptr), amount(0)
{
	if (type == "HAND")
	{
		double tmp, count = 0.0;
		cout << "Введите список " << nums << " чисел:" << endl;

		for (auto i = 0; i < nums; i++)
		{
			cout << i + 1 << ". -> ";
			(cin >> tmp).get();
			if (!cin)
			{
				clear();
				//this->push_front(0);
				continue;
			}
			//this->push_front(tmp);
		}
	}
	else if (type == "RAND")
	{
		for (auto i = 0.0; i < nums; i++)
			;
			//this->push_front((rand() % 100) - 120);
	}
	else
	{
		cout << "Ошибка типа ввода." << endl;
		cin.get();
		exit(0);
	}
	cout << endl << "Список создан." << endl;
}

List::~List()
{
	if (start != nullptr)
	{
		while (start->next != nullptr)
		{
			Item *tmp = start;
			start = start->next;
			delete tmp;
			amount--;
		}
		amount--;
		delete start;
		start = nullptr;
	}
	cout << "Список уничтожен." << endl;
}


void List::erase(int num)
{
	if (num <= 0 || num > amount)
	{
		cout << "Error in erase." << endl;
		cin.get();
		exit(0);
	}

	if (num == 1 && num == this->size())
	{
		delete start;
		start = nullptr;
		amount--;
		return;
	}

	if (num == 1)
	{
		Item *tmp = start;
		start = start->next;
		delete tmp;
		amount--;
		return;
	}

	Item *cur, *pred;
	cur = pred = start;
	for (int i = 1; i <= num - 1; i++)
		cur = cur->next;
	for (int i = 1; i <= num - 2; i++)
		pred = pred->next;

	pred->next = cur->next;
	delete cur;
	amount--;
}

void List::insert(int before, double num)
{
	if (start == nullptr)
	{
		start = new Item;
		start->number = num;
		start->next = nullptr;
		amount++;
		return;
	}

	if (before > this->size())
	{
		cout << "Ошибка вставки" << endl;
		clear();
		cin.get();
		exit(0);
	}


	Item *tmp = start;
	for (int i = 1; i <= before - 1; i++)
		tmp = tmp->next;
	Item *neww = new Item;
	neww->number = num;
	neww->next = tmp;
	start = neww;
	
	amount++;
}

void List::print()
{
	if (amount != 0)
	{
		Item *tmp = start;
		for (int i = 1; i <= amount; i++, tmp = tmp->next)
			cout << tmp->number << "[" << &tmp->next <<"]" <<" | ";
		cout << endl;
	}
	else
		cout << "Список пуст." << endl;
}

double List::operator[](int num)
{
	Item *tmp = start;
	for (int i = 1; i < num; i++)
		tmp = tmp->next;
	return tmp->number;
}

void List::clear_l()
{
	if (start != nullptr)
	{
		while (start->next != nullptr)
		{
			Item *tmp = start;
			start = start->next;
			delete tmp;
			amount--;
		}
		amount--;
		delete start;
		start = nullptr;
	}
}

double List::at(int num)
{
	Item *tmp = start;
	if (num <= this->size())
	{
		for (int i = 1; i < num; i++)
			tmp = tmp->next;
		return tmp->number;
	}
	else
	{
		cout << "Ошибка доступа в at." << endl;
		cin.get();
		exit(0);
	}
}

// Stack
Stack::Stack() : List()
{
	cout << "Стек создан" << endl;
}

Stack::Stack(string &type, double &amount) : List()
{
	if (type == "HAND")
	{
		double tmp, count = 0.0;
		cout << "Введите список  " << amount << " чисел:" << endl;

		for (auto i = 0; i < amount; i++)
		{
            cout << i + 1 << ": ";
			(cin >> tmp).get();
			if (!cin)
			{
				clear();
				this->push_front(0);
				continue;
			}
			this->push_front(tmp);
		}
	}
	else if (type == "RAND")
	{
		for (auto i = 0.0; i < amount; i++)
			this->push_front((rand() % 100) - 60);
	}
	else
	{
		cout << "Ошибка типа ввода." << endl;
		cin.get();
		exit(0);
	}
	cout << "Стек создан." << endl;
}

Stack::~Stack()
{
	cout << "Стэк уничтожен." << endl;
}

double Stack::pop_front()
{
	if (this->size())
	{
		double tmp = this->at(1);
		this->erase(1);
		return tmp;
	}
	else
	{
		cout << "Error in POP_FRONT" << endl;
		cin.get();
		exit(0);
	}
}

void Stack::push_front(double num)
{
	this->insert(1, num);
}



// Others
void take_info(string &type, double &amount)
{
	string tmp;
	ifstream in{ "conf.txt" };
	if (!in)
	{
		clear();
        cout << "Ошибка файл не удалось открыть." << endl;
		cin.get();
		exit(0);
	}

	getline(in, tmp);
	if (tmp != "MYSIGN")
	{
		cout << "Ошибка сигнатуры файла" << endl;
		cin.get();
		exit(0);
	}

	in >> type;
	if (type != "HAND" && type != "RAND")
	{
		cout << "Ошибка тип ввода должын быть HAND или RAND." << endl;
		cin.get();
		exit(0);
	}

	in >> amount;
	if (!in)
	{
		clear();
		cout << "Ошибка чтения количетсва чисел" << endl
			<< "Проверьте конфигурационный файл" << endl;
		cin.get();
		exit(0);
	}
	else if (amount < 0 || amount > 50)
	{
		cout << "Ошибка кол-во должно быть > 0 до < 50." << endl;
		cin.get();
		exit(0);
	}

	cout << endl << "Тип ввода: " << type << endl
		<< "Количество элементов: " << amount << endl;
}

void clear()
{
	char ch;
	cin.clear();
	while ((ch = cin.get()) != '\n')
		;
}

void print_sheet()
{
    cout << "Print your name" << endl;
	cin.get();
}
