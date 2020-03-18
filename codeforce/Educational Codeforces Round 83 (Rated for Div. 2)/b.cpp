#include <iostream>
#include <algorithm>
using namespace std;

int t, n, arr[111];

int main() {
	scanf("%d", &t);
	for (int i=0;i<t;i++) {
		scanf("%d", &n);
		for (int j=0;j<n;j++) {
			scanf("%d", &arr[j]);
		}
		if (n==1) cout<<arr[0]<<endl;
		else {
			sort(arr, arr+n, greater<int>());
			for (int j=0;j<n;j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
		}
	}
	return 0;
}