#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int n, m, t, map[101][101]={ 0, }, dx[4]={ 1, -1, 0, 0 }, dy[4]={ 0, 0, 1, -1 }, lengthmap[101][101], gx, gy;
bool visited[101][101]={ false, };

void bfs() {
	queue<pair<int, int>> que;
	que.push(make_pair(0, 0));
	lengthmap[0][0]=0;
	visited[0][0]=true;
	while (!que.empty()) {
		int nx, ny;
		nx=que.front().first;
		ny=que.front().second;
		que.pop();
		for (int i=0; i<4; i++) {
			int nextx=nx+dx[i], nexty=ny+dy[i];
			if (nextx>=0&&nextx<m&&nexty>=0&&nexty<n&&!visited[nexty][nextx]&&map[nexty][nextx]!=1) {
				if (map[nexty][nextx]==2) {
					gx=nextx;
					gy=nexty;
				}
				que.push(make_pair(nextx, nexty));
				lengthmap[nexty][nextx]=min(lengthmap[nexty][nextx], lengthmap[ny][nx]+1);
				visited[nexty][nextx]=true;
			}
		}
		
	}
	return;
}

int main() {
	scanf_s("%d%d%d", &n, &m, &t);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf_s("%d", &map[i][j]);
			if (map[i][j]==2) {
				gx=j;
				gy=i;
			}
		}
	}
	for (int i=0; i<101; i++) {
		for (int j=0; j<101; j++) {
			lengthmap[i][j]=999999;
		}
	}
	bfs();
	if (min(lengthmap[gy][gx]+abs(n-1-gy)+abs(m-1-gx), lengthmap[n-1][m-1])<=t) cout<<min(lengthmap[gy][gx]+abs(n-1-gy)+abs(m-1-gx), lengthmap[n-1][m-1])<<endl;
	else cout<<"Fail"<<endl;
	return 0;
}