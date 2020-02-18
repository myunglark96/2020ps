#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int map[100][8][8], dx[8]={ 1,-1,0,0,1,1,-1,-1 }, dy[8]={0,0,1,-1,1,-1,1,-1};
bool ans=false, die=false, visited[8][8]={false,};
queue<pair<int, int>> wallque;

void movewall() {
	int nx, ny;
	for (int i=0; i<99; i++) {
		for (int j=0; j<8; j++) {
			for (int k=0; k<8; k++) {
				map[i+1][j][k]=map[i][j][k];
			}
		}
		int sizeq=wallque.size();
		//cout<<sizeq<<endl;
		while (sizeq--) {
			nx=wallque.front().first, ny=wallque.front().second;
			wallque.pop();
			if (ny+1!=8&&!visited[ny][nx]) {
				visited[ny+1][nx]=true;
				map[i+1][ny][nx]=0;
				map[i+1][ny+1][nx]=1;
				wallque.push(make_pair(nx, ny+1));
			}
			else if (ny+1!=8&&visited[ny][nx]) {
				visited[ny+1][nx]=true;
				map[i+1][ny+1][nx]=1;
				wallque.push(make_pair(nx, ny+1));
			}
			else if (ny==7&&!visited[ny][nx]) {
				map[i+1][ny][nx]=0;
			}
		}
		/*printf("\n");
		for (int k=0; k<8; k++) {
			for (int j=0; j<8; j++) {
				printf("%d", map[i][k][j]);
			}
			printf("\n");
		}
		printf("\n");*/
		for (int k=0; k<8; k++) {
			for (int j=0; j<8; j++) {
				visited[k][j]=false;
			}
		}
	}
	return;
}

void bfs() {
	queue<pair<pair<int, int>, int>> que;
	int nx, ny, depth;
	que.push(make_pair(make_pair(0, 7),0));
	while (!que.empty()) {
		nx=que.front().first.first;
		ny=que.front().first.second;
		depth=que.front().second;
		que.pop();
		for (int i=0; i<8; i++) {
			int nextx=nx+dx[i], nexty=ny+dy[i];
			if (nextx==7&&nexty==7) {
				ans=true;
				return ;
			}
			if (nextx>=0&&nextx<8&&nexty>=0&&nexty<8&&map[depth][nexty][nextx]==0&&map[depth+1][nexty][nextx]==0&&depth<100) {
				que.push(make_pair(make_pair(nextx, nexty), depth+1));
			}
		}
		if(ny-1>=0&&map[depth][ny-1][nx]!=1) que.push(make_pair(make_pair(nx, ny), depth+1));
	}
	return ;
}

int main() {
	char state;
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			scanf_s("%c", &state);
			if (state=='.') {
				map[0][i][j]=0;
			}
			else if (state=='#') {
				map[0][i][j]=1;
				wallque.push(make_pair(j, i));
			}
		}
		scanf_s("%c", &state);
	}

	movewall();
	bfs();

	if (ans) cout<<1<<endl;
	else cout<<0<<endl;
	/*printf("\n");
	for (int i=0; i<8; i++) {
		for (int j=0; j<8; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}*/


	return 0;
}