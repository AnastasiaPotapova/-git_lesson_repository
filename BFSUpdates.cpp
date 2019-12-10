#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 300043;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef pair<int, int> pt;

vector<pt> g[N];
int n, m, s;
long long d[N];

int main()
{
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		--x;
		--y;
		g[x].pb(mp(y, w));
	}
	
	queue<int> q;
	q.push(s);
	for(int i = 0; i < n; i++)
		d[i] = (long long)(1e18);
	d[s] = 0;
	vector<int> inq(n);
	inq[s] = 1;
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		inq[k] = 0;
		for(int i = 0; i < g[k].size(); i++)
		{
			int to = g[k][i].x;
			int w = g[k][i].y;
			if(d[to] > w + d[k])
			{
				d[to] = w + d[k];
				if(inq[to] == 0)
				{
					q.push(to);
					inq[to] = 1;
				}
			}
		}
	}
}