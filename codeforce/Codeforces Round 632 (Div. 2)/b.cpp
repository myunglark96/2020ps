#include <iostream>
using namespace std;

int t, n, a[101000], aplus,bplus,aminus,bminus,azero,bzero, b[101000];
bool ans=true, havep, havem;

int main() {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d", &n);
		for (int i=0;i<n;i++) {
			scanf_s("%d", &a[i]);
			if (a[i]>0) aplus++;
			else if (a[i]<0) aminus++;
		}
		for (int i=0;i<n;i++) {
			scanf_s("%d", &b[i]);
			if (b[i]>0) bplus++;
			else if (b[i]<0) bminus++;
			else bzero++;
		}
		for (int i=0;i<n;i++) {
			if (a[i]!=b[i]) {
				if ((b[i]>0&&!havep)||(b[i]<0&&!havem)||(b[i]==0&&a[i]<0&&!havep)||(b[i]==0&&a[i]>0&&!havem)) {
					ans=false;
					break;
				}
			}
			if (bzero==0&&bminus==0&&havep) {
				ans=true;
				break;
			}
			if (bzero==0&&bplus==0&&havem) {
				ans=true;
				break;
			}
			if (a[i]==1) havep=true;
			if (a[i]==-1) havem=true;
			if (havep&&havem) {
				ans=true;
				break;
			} 
		}
		if (ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		ans=true;
		havep=false;
		havem=false;
		bzero=0;
		bplus=0;
		bminus=0;
	}
	return 0;
}