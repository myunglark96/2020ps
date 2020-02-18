#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int w, h, map[1000][1000], locx, locy, dx[4]={ 1,-1,0,0 }, dy[4]={ 0,0,1,-1 }, burnmap[1000][1000];
bool visited[1000][1000]={ false, };
queue<pair<pair<int, int>, int>> que;
queue<pair<int, int>>fque;

int bfs() {
	int nx, ny, nt=0;
	que.push(make_pair(make_pair(locx, locy), nt));
	while (!que.empty()) {
		nx=que.front().first.first;
		ny=que.front().first.second;
		nt=que.front().second;
		que.pop();
		for (int i=0; i<4; i++) {
			int nextx=nx+dx[i], nexty=ny+dy[i];
			if (map[nexty][nextx]==4) {
				return nt+1;
			}
			if (nextx>=0&&nextx<w&&nexty>=0&&nexty<h&&!visited[nexty][nextx]&&map[nexty][nextx]==0&&burnmap[nexty][nextx]>nt+1) {
				que.push(make_pair(make_pair(nextx, nexty), nt+1));
				visited[nexty][nextx]=true;
			}
		}
	}
	return -1;
}

void burn() {
	int nx, ny, t=0;
	while (!fque.empty()) {
		nx=fque.front().first, ny=fque.front().second;
		fque.pop();
		for (int i=0; i<4; i++) {
			int nextx=nx+dx[i], nexty=ny+dy[i];
			if (nextx>=0&&nextx<w&&nexty>=0&&nexty<h&&(map[nexty][nextx]==0||map[nexty][nextx]==3)&&burnmap[nexty][nextx]>burnmap[ny][nx]+1) {
				fque.push(make_pair(nextx, nexty));
				burnmap[nexty][nextx]=burnmap[ny][nx]+1;
			}
		}
	}
	/*printf("\n");
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			printf("%6d ", burnmap[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
}

int main() {
	int n;
	char state;
	scanf_s("%d%d", &h, &w);
	scanf_s("%c", &state);
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			scanf_s("%c", &state);
			burnmap[i][j]=999999;
			if (state=='.') {
				map[i][j]=0;
			}
			else if (state=='X') {
				map[i][j]=1;
			}
			else if (state=='*') {
				map[i][j]=2;
				burnmap[i][j]=0;
				fque.push(make_pair(j, i));
			}
			else if (state=='S') {
				map[i][j]=3;
				locx=j;
				locy=i;
			}
			else if (state=='D') {
				map[i][j]=4;
			}
		}
		scanf_s("%c", &state);
	}
	burn();
	int ans=bfs();
	if (ans!=-1) cout<<ans<<endl;
	else cout<<"KAKTUS"<<endl;	

	return 0;
}