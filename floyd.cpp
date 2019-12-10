#include<iostream>
#include<vector>

using namespace std;

const int N = 500;
int d[N][N];
int p[N][N];

vector<int> path;

void rec(int x, int y)
{
	if(p[x][y] == x)
		path.push_back(x);
	else
	{
		int k = p[x][y];
		rec(x, k);
		rec(k, y);
	}
}

void restore(int x, int y)
{
	path.clear();
	rec(x, y);
	path.push_back(y);
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			d[i][j] = int(1e9);
	for(int i = 0; i < n; i++)
		d[i][i] = 0;
	for(int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		--x;
		--y;
		// обработка кратных ребер
		d[x][y] = min(d[x][y], w);
		p[x][y] = x;
	}
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				if(d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = k;
				}
			}
}