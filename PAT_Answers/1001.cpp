#include "cstdio"
#include "string"
#include "stack"
using namespace std;
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int result = a + b;
	if (result < 0) printf("-");
	string str = to_string(abs(result));
	stack<char> s;
	int i = 0;
	for (auto it = str.rbegin(); it != str.rend(); *it++)
	{
		s.push(*it);
		if ((i + 1) % 3 == 0&&(i+1)<str.length())
		{
			s.push(',');
		}
		i++;
	}
	while (!s.empty())
	{
		printf("%c", s.top());
		s.pop();
	}
	return 0;
}