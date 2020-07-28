#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int t, n, k, arr[202020],p,minl[202020], maxp,ansp,ansl;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		for (int i=0;i<n;i++) {
			scanf("%d", &arr[i]);
		}
		for (int i=1;i<n-k+2;i++) {
			for (int z=i;z<i+k-2;z++) {
				if (arr[z-1]<arr[z]&&arr[z+1]<arr[z]) {
					p++;
				}
				minl[i]=i;
			}
			if (maxp<p+1) {
				maxp=p+1;
				ansl=i;
			}
			if (k%2==1) {
				if (p==k/2) break;
			}
			else {
				if (p==k/2-1) break;
			}
			p=0;
		}
		printf("%d %d\n", maxp, ansl);
		maxp=0;
		ansl=0;
		p=0;
	}
	return 0;
}