#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, arr[1010][1010], dp[1010][1010], dx[]={ 1,0 }, dy[]={0,1};
queue<pair<int,int>> qu;

int main() {
	scanf("%d%d", &n, &m);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0]=arr[0][0];
	qu.push({0,0});
	while (!qu.empty()){
		int ny=qu.front().first;
		int nx=qu.front().second;
		qu.pop();
		for (int i=0;i<2;i++) {
			int nexty=ny+dy[i], nextx=nx+dx[i];
			if (nexty>=0&&nexty<n&&nextx>=0&&nextx<m&&dp[nexty][nextx]<dp[ny][nx]+arr[nexty][nextx]) {
				qu.push({nexty,nextx});
				dp[nexty][nextx]=dp[ny][nx]+arr[nexty][nextx];
			}
		}
	}
	cout<<dp[n-1][m-1];
	return 0;
}