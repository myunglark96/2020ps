#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int map[11][11], dp[11][1<<11], n, m, dx[4]={-1, 1, -1, 1 }, dy[4]={0,0,1,1 };
/*
int dx[2]={0, 0}, dy[2]={-1,1}, n, m, ans=0;
bool visited[11][11]={false,};

void bfs(int startx, int starty) {
	int cnt=0;
	queue<pair<int, int>> que;
	que.push(make_pair(startx, starty));
	visited[starty][startx]=true;
	cnt++;
	while (!que.empty()) {
		int nx=que.front().first, ny=que.front().second;
		que.pop();
		for (int i=0; i<2; i++) {
			int nextx=nx+dx[i], nexty=ny+dy[i];
			if (nextx>=0&&nextx<m&&nexty>=0&&nexty<n&&!visited[nexty][nextx]&&map[nexty][nextx]==0) {
				cnt++;
				visited[nexty][nextx]=true;
				que.push(make_pair(nextx, nexty));
			}
		}
	}
}
*/

void bitmapdp() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (i==0) {
				if (map[i][j]!=1) {

				}
			}
			else {

			}
		}
	}
}

int main() {
	int t, ans=0;
	string s;
	scanf_s("%d", &t);
	for (int i=0; i<t; i++) {
		scanf_s("%d%d", &n, &m);
		for (int j=0; j<n; j++) {
			cin>>s;
			for (int len=0; len<s.size(); len++) {
				if (s[len]=='.') {
					map[j][len]=0;
				}
				else if (s[len]=='x') {
					map[j][len]=1;
				}
			}
		}
		/*printf("\n");
		for (int j=0; j<n; j++) {
			for (int k=0; k<m; k++) {
				printf("%d ", map[j][k]);
			}
			printf("\n");
		}
		printf("\n");*/
	}
	return 0;
}