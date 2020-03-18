#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, a, b, k, map[501][501], startx, starty, endx, endy, visited[501][501], dx[]={ 1,0,-1,0 }, dy[]={0,-1,0,1};
queue<pair<int, int>> qu;

bool isok(int ny, int nx) {
	if (!visited[ny][nx]&&ny>0&&nx>0&&ny+a-1<=n&&nx+b-1<=m&&map[ny][nx]==0) {
		visited[ny][nx]=1;
		for (int j=0;j<a;j++) {
			for (int ka=0;ka<b;ka++) {
				if (map[ny+j][nx+ka]==1) return false;
			}
		}
		return true;
	}
	else return false;
}

int main() {
	scanf_s("%d%d%d%d%d", &n,&m,&a,&b,&k);
	int u, v, nextx, nexty,move=0;
	for (int i=0;i<k;i++) {
		scanf_s("%d%d", &u, &v);
		map[u][v]=1;
	}
	scanf_s("%d%d%d%d",&starty,&startx,&endy,&endx);
	qu.push({ starty,startx });
	visited[starty][startx]=1;
	map[endy][endx]=3;
	while (!qu.empty()){
		int qsize=qu.size();
		for (int qs=0;qs<qsize;qs++) {
			int nowy=qu.front().first;
			int nowx=qu.front().second;
			qu.pop();
			for (int i=0;i<4;i++) {
				int nexty=nowy+dy[i], nextx=nowx+dx[i];
				if (map[nexty][nextx]==3) {
					cout<<move+1;
					return 0;
				}
				if (isok(nexty, nextx)) {
					qu.push({ nexty,nextx });
				}
			}
		}
		move++;
	}

	cout<<-1;
	return 0;
}