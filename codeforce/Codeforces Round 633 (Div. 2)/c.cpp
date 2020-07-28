#include <iostream>
#include <algorithm>
using namespace std;

double logB(double x, double base) { return log(x)/log(base); }
int t, n, arr[101010], bign, ans;

int main() {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d", &n);
		for (int i=0;i<n;i++) {
			scanf_s("%d", &arr[i]);
			if (i==0) bign=arr[i];
			else {
				if (arr[i]>bign) {
					bign=arr[i];
				}
				else {
					if(logB(bign-arr[i]+1, 2)==(int)logB(bign-arr[i]+1, 2)) ans=max(ans, (int)logB(bign-arr[i]+1, 2));
					else ans=max(ans, (int)logB(bign-arr[i]+1, 2)+1);
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}