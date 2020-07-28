#include <iostream>
#include <algorithm>
using namespace std;

int n, t, arr[202020], now,maxlen,maxplus,maxminus;
long long maxsum;

int main() {
	scanf_s("%d", &t);
	while (t--)
	{
		scanf_s("%d", &n);
		for (int i=0;i<n;i++) {
			scanf_s("%d", &arr[i]);
			if (n==1) maxsum=arr[i];
			if (i==0) {
				if (arr[i]>0) {
					now=1;
					maxplus=arr[i];
				}
				else {
					now=-1;
					maxminus=arr[i];
				}
				
			}
			else {
				if (now==1&&now*arr[i]<0) {
					now=-1;
					maxminus=arr[i];
					maxsum=maxsum+maxplus;
					maxplus=0;
					if (i==n-1) maxsum=maxsum+maxminus, maxplus=0;
				}
				else if(now==-1&&now*arr[i]<0){
					now=1;
					maxplus=arr[i];
					maxsum=maxsum+maxminus;
					maxminus=0;
					if (i==n-1) maxsum=maxsum+maxplus, maxplus=0;
				}
				else if (now==1&&now*arr[i]>0) {
					maxplus=max(maxplus, arr[i]);
					if (i==n-1) maxsum=maxsum+maxplus, maxplus=0;
				}
				else if (now==-1&&now*arr[i]>0) {
					maxminus=max(maxminus, arr[i]);
					if (i==n-1) maxsum=maxsum+maxminus, maxminus=0;
				}
			}
		}
		cout<<maxsum<<endl;
		maxsum=0;
	}
	return 0;
}