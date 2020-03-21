#include <iostream>
#include <algorithm>
using namespace std;

int n, c, arr[250001], diff[250001], idx=1;
long long secondsum=0,firstsum=0,num=0,ans;
pair<int, int> road[250001];

int main() {
	scanf_s("%d%d", &n, &c);
	for (int i=0;i<n;i++) {
		scanf_s("%d", &arr[i]);
	}
	for (int i=0;i<n-1;i++) {
		road[i].first=arr[i+1]-arr[i];
		road[i].second=arr[i]-arr[i+1];
		if(road[i].first<0){
			road[i].first=c-arr[i]+arr[i+1];
			num+=road[i].first;
		}
		else {
			num+=road[i].first;
		}
		if (road[i].second<0) {
			road[i].second=c-arr[i+1]+arr[i];
		}
	}
	ans=num;
	for (int i=0;i<n-1;i++) {
		firstsum+=road[i].first;
		secondsum+=road[i].second;
		if (max(num-firstsum,secondsum)<ans) {
			ans=max(num-firstsum, secondsum);
			idx=i+2;
		}
	}

	cout<<idx<<endl<<ans;
	return 0;
}