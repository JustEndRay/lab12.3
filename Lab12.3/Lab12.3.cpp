#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};
void Process(Elem* L, Info req_item);
void Enqueue(Elem*& first, Elem*& last, Info value);
void Print(Elem* L);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;

    bool result;

    Info value, N, info;

    do
    {
        cout << "������ ������� �������� ������: "; cin >> N;
    } while (N < 0);

    for (int i = 0; i < N; i++)
    {
        cout << "������ ���: "; cin >> value;
        Enqueue(first, last, value);
    }

    cout << "�������� �����: "; Print(first); cout << endl;
    cout << "������ ���� ������� ������� ������������: "; cin >> info;
    Process(first, info);
    cout << "\n���������: ";
    Print(first);
    return 0;
}
void Enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}
void Print(Elem* L)
{
    while (L != NULL)
    {
        cout << L->info << " ";
        L = L->next;
    }
}
void Process(Elem* L, Info req_item)
{
    while (L != NULL)
    {
        if (L->info == req_item)
        {
            Elem* tmp = new Elem;   //1 - ��������� ������ ����������� ��������
            tmp->info = req_item;   //2 - ��������� �������� ����� info
            tmp->next = L->next;    //3 - �� � �������� ������� ������������
            L->next = tmp;          //4 - ���������� ����������� �������� � ������ 

            L = L->next;            //5 - ��������� ���������� �� ������
        }
        L = L->next;                //6 - ��������� ���������� �� ������
    }
}