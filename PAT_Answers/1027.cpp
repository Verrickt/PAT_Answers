#include "iostream"
using namespace std;
string mars[13] = { "0","1","2","3","4","5","6","7","8","9","A","B","C" };

int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	cout << "#" << mars[r / 13] + mars[r % 13] << mars[g / 13] + mars[g % 13]<<
		mars[b / 13] + mars[b % 13] << endl;
	return 0;
}