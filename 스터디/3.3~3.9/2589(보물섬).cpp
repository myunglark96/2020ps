#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int map[51][51], w, h, ans, dx[]={ 1,0,-1,0 }, dy[]={ 0,-1,0,1 };
bool visited[51][51];
queue<pair<int, int>> qu;

int bfs(int starty, int startx) {
	while (!qu.empty()){
		qu.pop();
	}
	memset(visited, 0, sizeof(visited));
	int res=0;
	visited[starty][startx]=true;
	qu.push({ starty,startx });
	while (!qu.empty()){
		int qs=qu.size();
		for (int k=0;k<qs;k++) {
			int nowy=qu.front().first, nowx=qu.front().second;
			qu.pop();
			for (int i=0;i<4;i++) {
				int nexty=nowy+dy[i], nextx=nowx+dx[i];
				if (nexty>=0&&nextx>=0&&nexty<h&&nextx<w&&map[nexty][nextx]==1&&!visited[nexty][nextx]) {
					visited[nexty][nextx]=true;
					qu.push({ nexty, nextx });
				}
			}
		}
		res++;
	}
	return res-1;
}

int main() {
	scanf_s("%d%d", &h, &w);
	for (int i=0;i<h;i++) {
		string s;
		cin>>s;
		for (int j=0;j<w;j++) {
			if (s[j]=='L') {
				map[i][j]=1;
			}
			else {
				map[i][j]=0;
			}
		}
	}

	for (int i=0;i<h;i++) {
		for (int j=0;j<w;j++) {
			if (map[i][j]==1) {
				ans=max(ans, bfs(i, j));
			}
		}
	}
	cout<<ans;
	return 0;
}