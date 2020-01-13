#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, map[100][100]={ 0, }, dx[4]={ 1, -1, 0, 0 }, dy[4]={0, 0, 1, -1}, area=1;
vector<int> areaV;
bool visited[100][100]={false, };

void markarea(int sx, int sy, int ex, int ey) {
	for (int i=sx; i<ex; i++) {
		for (int j=sy; j<ey; j++) {
			if (map[j][i]==0) {
				map[j][i]=1;
				visited[j][i]=true;
			}
		}
	}
}

void dfs(int x, int y) {
	int nx=x, ny=y;
	for (int i=0; i<4; i++) {
		int nextx=nx+dx[i], nexty=ny+dy[i];
		if (nextx>=0&&nextx<n&&nexty>=0&&nexty<m&&!visited[nexty][nextx]&&map[nexty][nextx]!=1) {
			area++;
			visited[nexty][nextx]=true;
			dfs(nextx, nexty);
		}
	}
}

int main() {
	int startx, starty, endx, endy, cnt=0;
	scanf_s("%d%d%d", &m, &n, &k);
	for (int i=0; i<k; i++) {
		scanf_s("%d%d%d%d", &startx, &starty, &endx, &endy);
		markarea(startx, starty, endx, endy);
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!visited[j][i]) {
				visited[j][i]=true;
				dfs(i, j);
				areaV.push_back(area);
				area=1;
				cnt++;
			}
		}
	}
	sort(areaV.begin(), areaV.end());
	printf("%d\n", cnt);
	for (int i=0; i<areaV.size(); i++) {
		printf("%d ", areaV[i]);
	}
	return 0;
}