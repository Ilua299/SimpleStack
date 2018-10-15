#ifndef MT
#define MT

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;


#endif // !MT

struct Item
{
	double number;
	Item *next;
};

class List
{
protected:
	double amount;
	Item *start;
public:
	List();
	List(string, double);
	virtual ~List();

	//void push_back(double);
	void erase(int);
	void insert(int, double);
	double size() { return amount; }
	double operator[](int);
	void clear_l();
	void print();
	double at(int);
};


class Stack : public List
{
public:
	Stack();
	Stack(string &, double &);
	virtual ~Stack();

	double pop_front();
	void push_front(double);
private:

};


void print_sheet();
void clear();
void take_info(string &, double &);
