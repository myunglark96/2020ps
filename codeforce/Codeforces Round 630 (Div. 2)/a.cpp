#include <iostream>
using namespace std;

int t, a, b, c, d, x, y, lx, mx, ly, my;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		scanf("%d%d", &x, &y);
		scanf("%d%d", &lx, &ly);
		scanf("%d%d", &mx, &my);
		if (x-a+b<lx||x+b-a>mx||y-c+d<ly||y+d-c>my) cout<<"NO\n";
		else if((a!=0||b!=0)&&lx==mx) cout<<"NO\n";
		else if ((c!=0||d!=0)&&ly==my) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}