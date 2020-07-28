#include <iostream>
using namespace std;

int q,n,t[202020], k[202020];
int same;

int main() {
	scanf_s("%d", &q);
	while (q--) {
		scanf_s("%d", &n);
		for (int i=0;i<n;i++) {
			scanf_s("%d", &t[i]);
			if (i==0) {
				same=t[i];
				k[i]=1;
			}
			else if (i==n-1) {
				if (same==t[i]&&same==t[0]) {
					if (k[i-1]==1) {
						k[i]=1;
					}
					else if (k[i-1]==2) {
						k[i]=2;
					}
				}
				else if(same==t[i]&&same!=t[0]){
					if (k[i-1]==1) {
						k[i]=1;
					}
					else if (k[i-1]==2) {
						k[i]=2;
					}
				}
				else if (same!=t[i]&&same==t[0]) {

				}
				else if (same!=t[i]&&same!=t[0]) {

				}
			}
			else if (same!=t[i]) {
				same=t[i];
				if (k[i-1]==1) {
					k[i]=2;
				}
				else if (k[i-1]==2) {
					k[i]=1;
				}
			}
			else if(same==t[i]){
				if (k[i-1]==1) {
					k[i]=1;
				}
				else if (k[i-1]==2) {
					k[i]=2;
				}
			}
		}
	}
	return 0;
}