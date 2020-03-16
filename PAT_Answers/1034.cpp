#include "string"
#include "map"
#include "vector"
#include "iostream"
#include "queue"
using namespace std;

map<string, int> mmap;
map<int, string> imap;
int mindex = 1;
int n, k;
int cnt=0;
int max_index=-1;
// 1000*2 = 2000. Why would I think it's 1000🙃
int times[2010][2010];
bool visited[2010];
int w[2010];
int s_to_i(string str)
{
	if (mmap.find(str) == mmap.end()) {
		mmap[str] = mindex;
		imap[mindex] = str;
		mindex += 1;
	}
	return mmap[str];
}

string i_to_s(int i)
{
	return imap[i];
}

int bfs(int s)
{
	if (visited[s]) return 0;
	int weight = 0;
	cnt = 0;
	max_index = 0;
	int max_w = -1;
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int i = q.front();
		cnt++;
		int acc = 0;
		for (int j = 1; j < mindex; j++)
		{
			if (times[i][j] != 0 )
			{
				weight += times[i][j];
				acc += times[i][j];
				if (!visited[j])
				{
					visited[j] = true;
					q.push(j);
				}
			}
		}
		if (acc > max_w) { max_w = acc; max_index = i; }
		q.pop();
	}
	return weight;
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		string s1, s2;
		int t;
		cin >> s1 >> s2 >> t;
		int i1 = s_to_i(s1), i2 = s_to_i(s2);
		times[i1][i2] += t;
		times[i2][i1] += t;
	}
	
	map<string, int> gangs;
	{
		for (int i = 1; i < mindex; i++)
		{
			if (!visited[i])
			{
				int t = bfs(i);
				if (t > k*2 && cnt > 2)
					gangs[i_to_s(max_index)] = cnt;
			}
		}
	}
	cout << gangs.size() << endl;
	for (auto it : gangs)
		cout<<it.first<<" "<<it.second<<endl;
	return 0;
}