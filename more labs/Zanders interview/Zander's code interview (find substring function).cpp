#include <iostream>
using namespace std;

bool findSub(string, string);

int main() {

	string s1 = "CSCI";
	string s2 = "CSCI";

	if (findSub(s2, s1))
		cout << "checks" << endl;
}

bool findSub(string strToFind, string myString) {

	int length1 = strToFind.length() - 1;
	int length2 = myString.length() - 1;
	bool truth = true;

	for (int i = 0; i <= length2; i++) {

		truth = true;

		for (int j = 0; (j <= length1) && truth; j++) {

			if (i + j > length2 || (strToFind.at(j) != myString.at(i + j)))
				truth = false;

			if (truth && j == length1)
				return true;
		}
	}
	return false;
}
