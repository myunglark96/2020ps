#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int v, e, k, mincost[20202];
vector<pair<int, int>> arr[20202];

int main() {
	int from, to, val;
	priority_queue<pair<int, int>> qu;
	scanf_s("%d%d%d", &v, &e, &k);
	for (int i=1; i<=v; i++) {
		if (i==k) {
			mincost[i]=0;
		}
		else mincost[i]=987654321;
	}
	for (int i=0; i<e; i++) {
		scanf_s("%d%d%d", &from, &to, &val);
		arr[from].push_back({ to, val });
	}
	qu.push({0, k});
	while (!qu.empty()) {
		int curcost=-qu.top().first;
		int curloc=qu.top().second;
		qu.pop();
		for (int i=0; i<arr[curloc].size(); i++) {
			if (mincost[arr[curloc][i].first]>curcost+arr[curloc][i].second) {
				mincost[arr[curloc][i].first]=curcost+arr[curloc][i].second;
				qu.push({ -mincost[arr[curloc][i].first], arr[curloc][i].first});
			}
		}
	}
	for (int i=1; i<=v; i++) {
		if (mincost[i]!=987654321) printf("%d\n", mincost[i]);
		else printf("INF\n");
	}
	return 0;
}