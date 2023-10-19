#include <iostream>
#include <fstream>

#define MAX	50
#define INF 999

using namespace std;

int Distance[MAX], parent[MAX];
bool visited[MAX] = { 0 };

struct Graph
{
	int V;
	int Matrix[MAX][MAX];
};

bool NhapMatrix_File(Graph& A)
{
	ifstream f;

	f.open("Graph.txt", ios::in);
	if (!f.is_open()) return false;
	f >> A.V;
	if (f.eof()) return false;

	for (int i = 0; i < A.V; i++)
		for (int j = 0; j < A.V; j++)
			f >> A.Matrix[i][j];

	f.close();
	return true;
}


void NhapMatrix(Graph& A)
{
	cout << "Nhap so dinh: "; cin >> A.V;
	cout << "Nhap Matrix" << endl;

	for (int i = 0; i < A.V; i++)
		for (int j = 0; j < A.V; j++)
		{
			cout << "Matrix[" << i << "][" << j << "] = ";
			cin >> A.Matrix[i][j];
		}
}

void XuatMatrix(Graph A)
{
	cout << "Matrix:" << endl;
	for (int i = 0; i < A.V; i++) {
		for (int j = 0; j < A.V; j++)
			cout << A.Matrix[i][j] << " ";
		cout << endl;
	}
}

void init(Graph A, int X)
{
	for (int i = 0; i < A.V; i++)
	{
		Distance[i] = INF;
		parent[i] = -1;
	}
	Distance[X] = 0;
}

//Hàm reset lại tất cả các biến toàn cục
void reset()
{
	memset(Distance, 0, sizeof(Distance));
	memset(parent, 0, sizeof(parent));
	memset(visited, 0, sizeof(visited));
}

int Nearest(Graph A)
{
	int min = INF, u = -1;
	for (int i = 0; i < A.V; i++)
	{
		if (visited[i] == false && Distance[i] < min)
		{
			u = i;
			min = Distance[i];
		}
	}

	return u;
}

void Dijkstra(Graph A)
{
	int number_V_visited = 0;
	int u;
	while (number_V_visited <= A.V)
	{
		u = Nearest(A);
		if (u == -1) break;
		visited[u] = true;

		for (int j = 0; j < A.V; j++)
		{
			if (visited[j] == false &&
				A.Matrix[u][j] != 0 &&
				Distance[u] + A.Matrix[u][j] < Distance[j])
			{
				Distance[j] = Distance[u] + A.Matrix[u][j];
				parent[j] = u;
			}
		}
		number_V_visited++;
	}
}

void Display_ALL(Graph A, int X)
{
	cout << "DUONG DI TU DINH " << X << " DEN CAC DINH CON LAI : " << endl;

	int k;
	for (int i = 0; i < A.V; i++)
	{
		if (Distance[i] > 0 && Distance[i] < INF)
		{
			cout << "(" << X << "," << i << ") = " << Distance[i] << " DUONG DI: " << i;
			k = i;
			while (k != X)
			{
				cout << " <- " << parent[k];
				k = parent[k];
			}
		}
		cout << endl;
	}
}

void Display_ONE(Graph A, int X, int Y)
{
	cout << "DUONG DI TU DINH " << X << " DEN DINH " << Y << ": " << endl;

	int k;
	if (Distance[Y] > 0 && Distance[Y] < INF)
	{
		cout << "(" << X << "," << Y << ") = " << Distance[Y] << " DUONG DI: " << Y;
		k = Y;
		while (k != X)
		{
			cout << " <- " << parent[k];
			k = parent[k];
		}
	}
	cout << endl;
}

void MENU()
{
	cout << "\n---------------MENU---------------" << endl;
	cout << "1. Xem MENU" << endl;
	cout << "2. Nhap Matrix" << endl;
	cout << "3. Nhap Matrix tu file txt co san" << endl;
	cout << "4. Xuat Matrix" << endl;
	cout << "5. Khoang cach tu dinh X den cac dinh con lai" << endl;
	cout << "6. Khoang cach tu dinh bat ki den dinh bat ki" << endl;
	cout << "0. Thoat" << endl;
}

int main()
{
	Graph A;
	int choice;
	MENU();
	while (true)
	{
		cout << "Nhap lua chon: "; cin >> choice;

		switch (choice)
		{
		case 1:
			MENU();
			break;
		case 2:
			NhapMatrix(A);
			break;
		case 3:
			if (NhapMatrix_File(A))
				cout << "Nhap file thanh cong" << endl;
			else
				cout << "Nhap file khong thanh cong!" << endl;
			break;
		case 4:
			XuatMatrix(A);
			break;
		case 5:
			int X;
			cout << "Nhap dinh dau: ";
			cin >> X;

			reset();
			init(A, X);
			Dijkstra(A);
			Display_ALL(A, X);
			break;
		case 6:
			int U, V;
			cout << "Nhap X va Y: ";
			cin >> U >> V;

			reset();
			init(A, U);
			Dijkstra(A);
			Display_ONE(A, U, V);
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "Khong co thao tac " << choice << endl;
			cout << "Vui long nhap lai" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}