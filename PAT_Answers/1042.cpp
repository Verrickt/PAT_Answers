#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
using namespace std;
struct card
{
	string name;
	int index;
};
bool cmp(card a, card b) { return a.index < b.index; }
int main()
{
	int k;
	vector<int> v = vector<int>(54);
	vector<card> deck;
	string t[5] = { "S","H","C","D","J" };
	int n[5] = { 13,13,13,13,2 };
	int cnt = 1;
	for (int i = 0; i < 5; i++)
		for (int j = 1; j <= n[i]; j++)
			deck.push_back(card({ t[i] + to_string(j),cnt++ }));
	cin >> k;
	for (int i = 0; i < 54; i++) cin >> v[i];
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 54; j++)
			deck[j].index = v[j];
		sort(deck.begin(), deck.end(), cmp);
	}
	for (int i = 0; i < 54; i++)
	{
		cout << deck[i].name;
		if (i != 53) cout << " ";
	}
	return 0;
}