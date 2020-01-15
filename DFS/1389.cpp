#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, minr=99999, prestart=0, minvisit[101][101]={ 0, }, visited[101][101]={0,};
vector<int> relation[101];

void addToV(int a, int b) {
	if (find(relation[a].begin(), relation[a].end(), b)==relation[a].end()) {
		relation[a].push_back(b);
		relation[b].push_back(a);
		minvisit[a][b]=1;
		minvisit[b][a]=1;
	}
}

int dfs(int start, int end, int depth) {
	for (int i=0; i<relation[start].size(); i++) {
		if (minr>depth&&relation[start][i]!=prestart&&minvisit[relation[start][i]][end]==0&&minvisit[end][relation[start][i]]==0&&!visited[start][relation[start][i]]) {
			visited[start][relation[start][i]]=1;
			prestart=start;
			minr=min(minr, dfs(relation[start][i], end, depth+1));
		}
		else if(minvisit[relation[start][i]][end]!=0){
			minr=min(minr, depth+minvisit[relation[start][i]][end]);
		}
		else if (minvisit[end][relation[start][i]]!=0) {
			minr=min(minr, depth+minvisit[end][relation[start][i]]);
		}
	}
	return minr;
}

int main() {
	int r1, r2, kevin[101]={ 0, }, ans, mina=9999999;
	scanf_s("%d%d", &n, &m);
	for (int i=0; i<m; i++) {
		scanf_s("%d%d", &r1, &r2);
		addToV(r1, r2);
	}
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=m; j++) {
			minr=99999;
			for (int a=1; a<=n; a++) {
				for (int b=1; b<=n; b++) {
					visited[a][b]=0;
				}
			}
			if (i!=j&&minvisit[i][j]==0&&minvisit[j][i]==0) {
				minvisit[i][j]=dfs(i, j, 1);
				minvisit[j][i]=minvisit[i][j];
				kevin[i]=kevin[i]+minvisit[i][j];
			} 
			else if(minvisit[i][j]!=0) kevin[i]=kevin[i]+minvisit[i][j];
			else if(minvisit[j][i]!=0) kevin[i]=kevin[i]+minvisit[j][i];
			prestart=0;
		}
	}
	
	for (int i=1; i<=m; i++) {
		if (mina>kevin[i]) {
			mina=kevin[i];
			ans=i;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}