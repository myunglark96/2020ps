#include <iostream>
using namespace std;

int t, x,n, m;

bool kill(int h, int nn, int mm) {
	if (h<=0) return true;
	if (nn==0&&mm==0) return false;
	if (mm==0&&h>0) return false;

	if (nn>0&&h>=21) {
		return kill(h/2+10, nn-1, mm);
	}
	else if(mm>0){
		return kill(h-10, nn, mm-1);
	}
}

int main() {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d%d%d", &x, &n, &m);
		bool ans=kill(x, n, m);
		if (ans) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}