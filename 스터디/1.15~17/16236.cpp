#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int map[21][21], sharksize=2, growup=0, n, sharkx, sharky, time=0, dx[4]={ 0,-1,1,0 }, dy[4]={ -1,0,0,1 }, lengthmap[21][21]={ 0, };
bool caneat[21][21]={ false, }, visited[21][21]={ false, };

int bfs() {
	int nx, ny, minlength=999999, eatx=-1, eaty=-1;
	queue<pair<int, int>> que;
	que.push(make_pair(sharkx, sharky));
	visited[sharky][sharkx]=true;
	lengthmap[sharky][sharkx]=0;
	map[sharky][sharkx]=0;
	while (!que.empty()) {
		nx=que.front().first;
		ny=que.front().second;
		que.pop();
		for (int i=0; i<4; i++) {
			int nextx=nx+dx[i], nexty=ny+dy[i];
			if (nextx>=0&&nextx<n&&nexty>=0&&nexty<n&&map[nexty][nextx]<sharksize&&!visited[nexty][nextx]&&map[nexty][nextx]!=0) {
				visited[nexty][nextx]=true;
				que.push(make_pair(nextx, nexty));
				lengthmap[nexty][nextx]=min(lengthmap[nexty][nextx], lengthmap[ny][nx]+1);
				caneat[nexty][nextx]=true;
			}
			else if (nextx>=0&&nextx<n&&nexty>=0&&nexty<n&&(map[nexty][nextx]==sharksize||map[nexty][nextx]==0)&&!visited[nexty][nextx]) {
				visited[nexty][nextx]=true;
				que.push(make_pair(nextx, nexty));
				lengthmap[nexty][nextx]=min(lengthmap[nexty][nextx], lengthmap[ny][nx]+1);
			}
		}
	}/*
	printf("\n");
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			printf("%6d ", lengthmap[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (caneat[i][j]&&lengthmap[i][j]<minlength) {
				eatx=j;
				eaty=i;
				minlength=lengthmap[i][j];
			}
			visited[i][j]=false;
			caneat[i][j]=false;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			lengthmap[i][j]=999999;
		}
	}
	if (eatx!=-1) {
		sharkx=eatx;
		sharky=eaty;
		map[eaty][eatx]=0;
		growup++;
		if (sharksize==growup) {
			sharksize++;
			growup=0;
		}
		time=time+minlength;
		return 1;
	}
	else {
		return -1;
	}
}

int main() {
	scanf_s("%d", &n);

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			scanf_s("%d", &map[i][j]);
			if (map[i][j]==9) {
				sharkx=j;
				sharky=i;
			}
			lengthmap[i][j]=999999;
		}
	}

	for (int i=0; i<n*n; i++) {
		if (bfs()==-1) break;
	}

	cout<<time<<endl;

	return 0;
}