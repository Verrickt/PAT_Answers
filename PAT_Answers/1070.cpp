#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
struct cake
{
	double stock;
	double price;
	double unit_price;
};
bool cmp(cake& a, cake& b) { return a.unit_price > b.unit_price; }
int main()
{
	int n, d;
	cin >> n >> d;
	vector<cake> cakes = vector<cake>(n);
	for (int i = 0; i < n; i++) cin >> cakes[i].stock;
	for (int i = 0; i < n; i++) cin >> cakes[i].price;
	for (int i = 0; i < n; i++) cakes[i].unit_price = cakes[i].price / cakes[i].stock;
	sort(cakes.begin(), cakes.end(), cmp);
	double v = 0;
	for (auto c : cakes)
	{
		if (d - c.stock >= 0) { d -= c.stock; v += c.price; }
		else { v += (c.unit_price) * d; break; }
	}
	printf("%.2lf\n", v);
	return 0;
}