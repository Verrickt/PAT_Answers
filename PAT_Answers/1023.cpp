#include "iostream"
#include "string"
#include "vector"
using namespace std;
bool digits1[10];
bool digits2[10];
string double_str(string str)
{
	int carry=0;
	string result;
	for (auto it = str.rbegin(); it != str.rend(); it++)
	{
		int c = *it - '0';
		c = 2*c + carry;
		result.insert(result.begin(), c % 10 + '0');
		carry =c/10;
	}
	if(carry!=0)
		result.insert(result.begin(), carry%10 + '0');
	return result;
}
int main()
{
	bool flag = true;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) digits1[str[i] - '0'] = true;
	string str2 = double_str(str);
	for (int i = 0; i < str2.size(); i++) digits2[str2[i] - '0'] = true;
	for (int i = 0; i < 10; i++)
	{
		flag = (digits1[i]==digits2[i]) & flag;
	}
	cout << (flag ? "Yes" : "No") << endl;
	cout << str2;
	return 0;
}