#include <iostream>
#include <algorithm>
using namespace std;

int t, n,k,arr[202020],minnum=999999,cnt=999999,same[101010];
bool check[404040];
int main() {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d%d", &n,&k);
		for (int i=0;i<n;i++) {
			scanf_s("%d", &arr[i]);
			if (arr[i]<minnum) minnum=arr[i];
		}
		for (int i=0;i<n/2;i++) {
			same[i]=arr[i]+arr[n-i-1];
		}
		for (int i=0;i<n/2;i++) {
			if (!check[same[i]]) {
				check[same[i]]=true;
				int tmp=0;
				for (int j=0;j<n/2;j++) {
					if (arr[j]+arr[j-1-i]<same[i]) {
						if (max(arr[j], arr[j-1-i])+k<same[i]) tmp=tmp+2;
						else tmp++;
					}
					else if (arr[j]+arr[j-1-i]>same[i]) {
						if (min(arr[j], arr[j-1-i])+1>same[i]) tmp=tmp+2;
						else tmp++;
					}
				}
				cnt=min(cnt, tmp);
			}
		}
		int tmp=0;
		for (int i=0;i<n/2;i++) {
			if (arr[i]+arr[n-i-1]!=minnum+k) tmp++;
		}
		cnt=min(cnt, tmp);
		cout<<cnt<<endl;
		minnum=999999;
		cnt=999999;
	}
	return 0;
}