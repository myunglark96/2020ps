#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int t=1, u, v;
set<int> mp;

int main() {
	int cnt=0;
	while (true) {
		scanf_s("%d%d", &u, &v);
		while (true){
			if ((u==-1&&v==-1)||(u==0&&v==0)) break;
			else {
				mp.insert(u);
				mp.insert(v);
				cnt++;
			}
			scanf_s("%d%d", &u, &v);
		}
		if (u==-1&&v==-1) break;
		if (cnt==0||mp.size()==cnt+1) printf("Case %d is a tree.\n", t);
		else printf("Case %d is not a tree.\n", t);
		t++;
		cnt=0;
		mp.clear();
	}
	return 0;
}