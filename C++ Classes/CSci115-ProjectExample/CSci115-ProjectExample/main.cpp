#include <iostream>

using namespace std;


void Display(int** M,int n,int m,char x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c=' ';
			switch (M[i][j])
			{
			case 1: c = '#'; break;
			case 0: c = x; break;
			}
			cout << c;
		}
		cout << endl;
	}
}


// Example to display a matrix in the console and refresh what is displayed
int main()
{

	cout << "CSci 115 - Project" << endl;


	int n = 120;
	int m = 120;

	// Allocate memory
	int** M = new int*[n];
	for (int i = 0; i < n; i++)
		M[i] = new int[m];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			M[i][j] = 1;

	for (int i = 0; i < n; i++)
		M[i][i] = 0;

	Display(M,n,m,'x');

	bool finish = false;
	while (!finish)
	{
		char input;
		cin >> input;
		system("cls"); // clear the commandline (to refresh the screen)
		switch (input)
		{
		case 'q': finish = true; break;
		case 'a': Display(M, n, m, 'a'); break;
		case 'b': Display(M, n, m, 'b'); break;
		}
	}

	// Free memory
	for (int i = 0; i < n; i++)
		delete[] M[i];
	delete[] M;
}