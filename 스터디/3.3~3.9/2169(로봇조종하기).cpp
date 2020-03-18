#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, map[1010][1010], newmap[1010][1010], dp[1010][1010][3];
bool visited[1010][1010];

int dfs(int y, int x, int dir) {
	if (y==n&&x==m) return map[y][x];
	if (dp[y][x][dir]!=-987654321) return dp[y][x][dir];
	visited[y][x]=true;
	if (!visited[y][x+1]&&x+1<=m&&x+1>0&&y>0&&y<=n) dp[y][x][dir]=max(dp[y][x][dir], dfs(y, x+1, 0)+map[y][x]);
	if (!visited[y][x-1]&&x-1<=m&&x-1>0&&y>0&&y<=n) dp[y][x][dir]=max(dp[y][x][dir], dfs(y, x-1, 1)+map[y][x]);
	if (!visited[y+1][x]&&y+1<=n&&x>0&&x<=m) dp[y][x][dir]=max(dp[y][x][dir], dfs(y+1, x, 2)+map[y][x]);
	visited[y][x]=false;	
	return newmap[y][x]=dp[y][x][dir];
}

int main() {
	scanf_s("%d%d", &n, &m);
	for (int i=1;i<=n+1;i++) {
		for (int j=1;j<=m+1;j++) {
			if(i<=n&&j<=m) scanf_s("%d", &map[i][j]);
			newmap[i][j]=-987654321;
			for (int k=0;k<3;k++) {
				dp[i][j][k]=-987654321;
			}
		}
	}
	cout<<dfs(1, 1, 0);
	/*
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			cout<<newmap[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	return 0;
}