#include "main_head.h"
//Пример для задачи "Переместить отрицательные элементы в хвост стека"
int main()
{
    srand(time(0));
    string type;
    double amount, curr, next;

    print_sheet();
    take_info(type, amount);
    Stack tmp(type, amount);
    Stack tmp_positive;
    Stack tmp_negative;

    cout << "Начало" << endl;
    cout << "Стэк до:" << endl;
    tmp.print();

    for (int i = 0; i < amount; i++) {

        {
            curr = tmp.pop_front();
            if (curr >= 0) {
                tmp_positive.push_front(curr);
            }
            else
            {
                tmp_negative.push_front(curr);
            }
        }


    }

    int tmpp = tmp_positive.size();
    int tmpd = tmp_negative.size();
    for (int i = 0; i < tmpd; i++)
        tmp.push_front(tmp_negative.pop_front());
    for (int i = 0; i < tmpp; i++)
        tmp.push_front(tmp_positive.pop_front());


    cout << "Стэк после:" << endl;
    tmp.print();

    cin.get();
}
