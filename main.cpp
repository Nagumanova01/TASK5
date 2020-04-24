#include <iostream>

using namespace std;

struct list
{
    int st;
    int zn;
    list *next;
};

list *tmp = NULL;
list *tmp2 = NULL;

//Добавить элемент в начало списка
void push(list* &ptr, int x, int y)
    {
        list *tmp = new list;
        tmp->st = x;
        tmp->zn = y;
        tmp->next=ptr;
        ptr = tmp;
    }

//Распечатать список
void print_list(list *ptr)
{
    while(ptr)
    {
        cout << ptr->st << "  " << ptr->zn << "    " ;
        ptr = ptr->next;
    }
    cout << "\n";
}


int main()
{
    int t1, t2;
    int s, z;
    int i;

    cin >> t1;
    for (i=0; i<t1; i++)   //Создаем первый список
    {
        cin >> s >> z;
        push(tmp, s, z);
    }

    list *er = new list;
    er = tmp;

    cin >>t2;
    for (i=0; i<t2; i++)   //Создаем второй список
    {
        cin >> s >> z;
        push(tmp2, s, z);
    }
    list *er2 = new list;
    er2 = tmp2;

    //Добавляем в первый список из второго списка элементы, степень которых есть в первом списке
    while (er)
    {
        while(er2)
        {
            if (er2->st==er->st)
            {
                er->zn = (er->zn) + (er2->zn);
            }
            er2 = er2->next;
        }
        er2 = tmp2;
        er = er->next;
    }

    list *xo = new list;
    xo = tmp;
    list *xo2 = new list;
    xo2 = tmp2;
    int q = 0;

    //Добавляем в первый список элементы из второго,степеней которых нет в первом
    while(xo2)
    {
        while (xo)
        {
            if (xo->st == xo2->st)
            {
                q = 1;
                break;
            }
            xo = xo->next;
        }
        xo = tmp;
        if (q == 0)
        {
            push(tmp, xo2->st, xo2->zn);
        }
        xo2 = xo2->next;
        q = 0;
    }

    cout << "\n";
    print_list(tmp);

    return 0;
}
