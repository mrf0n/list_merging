#include <iostream>
using namespace std;
struct TNode
{
	int Data;
	TNode* next;
};
typedef TNode* PNode;
PNode t;
bool check_norm(PNode h)
{
	while (h->next != nullptr)
	{
		if (h->Data > h->next->Data)
			return false;
		h = h->next;
	}
	return true;
}
void add(PNode& head)
{
	if (head == NULL)
	{
		head = new TNode;
		cin >> head->Data;
		head->next = NULL;
		t = head;
	}
	else
	{
		PNode elem = new TNode;
		cin >> elem->Data;
		head->next = elem;
		elem->next = NULL;
		head = elem;
	}
}

void sliv1(PNode h1, PNode h2)
{
	PNode temp, t = 0;
	while (h1 != nullptr && h2 != nullptr)
	{
		if (h1->Data <= h2->Data)
		{
			while (h1 != nullptr)
			{
				if (h1->Data <= h2->Data)
				{
					t = h1;
					h1 = h1->next;
				}
				else break;
			}
			h1 = t;
			temp = h1;
			h1 = h1->next;
			temp->next = h2;
		}
		else if (h1->Data > h2->Data)
		{
			while (h2 != nullptr)
			{
				if (h1->Data > h2->Data)
				{
					t = h2;
					h2 = h2->next;
				}
				else break;
			}
			h2 = t;
			temp = h2;
			h2 = h2->next;
			temp->next = h1;
		}
	}
}



void print(PNode h)
{
	while (h->next != nullptr)
	{
		cout << h->Data << " - ";
		h = h->next;
	}
	cout << h->Data << " ->> NULL" << endl;
}


int main()
{
	setlocale(LC_ALL, "ru");
	int n1, n2;
	PNode h1 = 0, h2 = 0, m, d;
	cout << "Введите кол-во эл-тов в первом списке: ";
	cin >> n1;
	for (int i = 0; i < n1; i++)
		add(h1);
	m = t; // голова 1 списка
	cout << "Введите кол-во эл-тов во втором списке: ";
	cin >> n2;
	for (int i = 0; i < n2; i++)
		add(h2);
	d = t; // голова второго списка
	cout << "Первый введённый список: " << endl;
	print(m);
	cout << "Второй введённый список: " << endl;
	print(d);
	if (check_norm(m) && check_norm(d))
	{
		sliv1(d, m);
		cout << "Список после слияния: " << endl;
		if (d->Data <= m->Data)
			print(d);
		else print(m);
	}
	else cout << "Введённые списки должны быть упорядочены!" << endl;
		system("pause");
}