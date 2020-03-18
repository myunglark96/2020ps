#include <iostream>
#include <algorithm>
using namespace std;

int s, n, m,v[101],ans=-1;
bool visited[101][1010];

void gitar(int sing, int nowv) {
	if (nowv<0||nowv>m) return;
	if (visited[sing][nowv]) return;
	if (sing==n) {
		ans=max(ans, nowv);
		return;
	}
	visited[sing][nowv]=true;

	gitar(sing+1, nowv-v[sing]);
	gitar(sing+1, nowv+v[sing]);

	return;
}

int main() {
	scanf_s("%d%d%d", &n, &s, &m);
	for (int i=0;i<n;i++) {
		scanf_s("%d", &v[i]);
	}
	gitar(0, s);
	if (ans==-1) cout<<-1;
	else cout<<ans;

	return 0;
}