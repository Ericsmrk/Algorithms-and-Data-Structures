void MyArrayExample00() {
	int n = 10;
	int* a = new int[n];
	// initialization
	for (int i = 0; i < n; i++)
		a[i] = rand() % 200;

	int x = 100;
	// find if there exists a value > x
	int argx;

	bool find = false;
	argx = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] > x) {
			find = true;
			argx = i;
			break;
		}
	}
	if (find)
		cout << "Found " << a[argx] << endl;
	else
		cout << "Not found" << endl;


	find = false;
	int i=0;
	while ((!find) && (i < n)) {
		if (a[i] > x) {
			find = true;
			argx = i;
		}
		i++;
	}
	if (find)
		cout << "Found " << a[argx] << endl;
	else
		cout << "Not found" << endl;

	find = false;
	i = 0;
	do {
		if (a[i] > x) {
			find = true;
			argx = i;
		}
		i++;
	} while ((!find) && (i < n));

	if (find)
		cout << "Found " << a[argx] << endl;
	else
		cout << "Not found" << endl;
}

// a and n are just as input!
void f1(int* a,int n) {
	a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = i;
}

// a is input/output and n as input
// we modify the link to *a which is **a
void f2(int** a, int n) {
	*a = new int[n];
	for (int i = 0; i < n; i++)
		(*a)[i] = i;
}

int* f3(int n) {
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		a[i] = i;
	return a;
}


void DisplayArray(int* a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << ",";
	cout << endl;
}

void MyArrayExample01() {
	int n = 10;
	int* a = NULL;
	cout << "Evaluate f1" << endl;
	f1(a,n);
	//DisplayArray(a,n); // not working because a has nothing !
	cout << "Evaluate f2" << endl;
	f2(&a,n);
	DisplayArray(a, n);
	cout << "Evaluate f3" << endl;
	a = NULL;
	a=f3(n);
	DisplayArray(a, n);
}
