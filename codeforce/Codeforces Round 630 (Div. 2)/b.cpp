#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n, arr[1010], ans[1010],m[1010];

int gcd(int a, int b) {
	// Everything divides 0  
	if (a==0)
		return b;
	if (b==0)
		return a;

	// base case 
	if (a==b)
		return a;

	// a is greater 
	if (a>b)
		return gcd(a-b, b);
	return gcd(a, b-a);
}

int main() {
	int cnt=0;
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d", &n);
		for (int i=0;i<n;i++) {
			scanf_s("%d", &arr[i]);
		}
		for (int i=0;i<n-1;i++) {
			for (int j=i+1;j<n;j++) {
				int tmp=gcd(arr[j], arr[i]);
				if (!m[tmp]&&tmp!=1) {
					m[tmp]=++cnt;
					if (ans[j]==0&&ans[i]==0) {
						ans[j]=m[tmp];
						ans[i]=m[tmp];
					}
					else if (ans[j]==0) {
						ans[j]=m[tmp];
					}
					else if (ans[i]==0) {
						ans[i]=m[tmp];
					}
				}
				else if (m[tmp]) {
					if (ans[j]==0&&ans[i]==0) {
						ans[j]=m[tmp];
						ans[i]=m[tmp];
					}
					else if (ans[j]==0) {
						ans[j]=m[tmp];
					}
					else if (ans[i]==0) {
						ans[i]=m[tmp];
					}
				}
			}
		}
		for (int i=0;i<n;i++) {
			if (ans[i]==0) {
				ans[i]=++cnt;
			}
		}
		cout<<cnt<<endl;
		for (int i=0;i<n;i++) {
			printf("%d ", ans[i]);
		}
		cout<<endl;
		cnt=0;
		s.clear();
		memset(ans, 0, sizeof(ans));
		memset(m, 0, sizeof(m));
	}
	return 0;
}