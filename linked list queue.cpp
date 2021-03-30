#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Node{
	int data;
	Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int n)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = n;
	temp->next = NULL;
	if(front==NULL)
	{
		front = rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}

int Front()
{
	return front->data;
}

void deque()
{
	if(front==NULL)
	{
		puts("Queue kosong");
		return;
	}
	
	Node* temp = front;
	front = front->next;
	free(temp);
}

void Print()
{
	Node* temp = front;
	
	if(front==NULL)
	{
		puts("Queue kosong");
		return;
	}
	
	puts("Queue : ");
	while(temp != NULL)
	{
		printf("%d	", temp->data);
		temp = temp->next;
	}
	puts("");
}

int total()
{
	int total = 0;
	Node* temp = front;
	if(temp==NULL) return 0;
	while(temp!=NULL)
	{
		total += temp->data;
		temp = temp->next;
	}
	return total;
}

float rerata()
{
	int tot = total();
	int count = 0;
	float rerata = 0;
	Node* temp = front;
	if(temp==NULL) return 0;
	while(temp!=NULL)
	{
		count++;
		temp = temp->next;
	}
	rerata = (float) tot/count;
	return rerata;
}

int terbesar()
{
	Node* temp = front;
	if(temp==NULL) return 0;
	int terbesar = temp->data;
	Node* temp2 = temp->next;
	int temp3;
	while(temp2!=NULL)
	{
		if(temp2->data > temp->data )
		{
			temp3 = temp2->data;
		}
		if(temp3>terbesar) terbesar=temp3;
		temp = temp2;
		temp2 = temp2->next;
	}
	return terbesar;
}

int terkecil()
{
	Node* temp = front;
	if(temp==NULL) return 0;
	int terkecil = temp->data;
	Node* temp2 = temp->next;
	int temp3;
	while(temp2!=NULL)
	{
		if(temp2->data < temp->data )
		{
			temp3 = temp2->data;
		}
		if(temp3<terkecil) terkecil=temp3;
		temp = temp->next;
		temp2 = temp2->next;
	}
	return terkecil;
}

void RandomInsert(int n)
{
	srand(time(0));
	for(int i=0; i<n;i++)
	{
		int x = rand()%1001;
		enqueue(x);
	}
}

int main()
{
	int menu, n;
	mulai :
	fflush(stdin);
	printf("1.Enque\n2.Deque\n3.Print\n4.Random Enqueue\n5.Keluar\n"); scanf("%d", &menu);
	system("cls");
	
	switch (menu)
	{
		case 1 :
			printf("Masukan data : "); scanf("%d", &n);
			system("cls");
			enqueue(n);
			goto mulai;
		case 2 :
			deque();
			Print();
			system("pause");
			system("cls");
			goto mulai;
		case 3 :
			Print();
			printf("\nTotal : %d\n", total());
			printf("Rata-rata : %.2f\n", rerata());
			printf("Terbesar : %d\n", terbesar());
			printf("Terkecil : %d\n", terkecil());
			system("pause");
			system("cls");
			goto mulai;
		case 4 :
			printf("Ingin membuat berapa data ?  ") ;scanf("%d", &n);
			RandomInsert(n);
			Print();
			system("pause");
			system("cls");
			goto mulai;
		case 5 :
			break;
	}
}
