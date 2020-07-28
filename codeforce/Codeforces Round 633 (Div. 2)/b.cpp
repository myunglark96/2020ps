#include <iostream>
#include <algorithm>
#include <vector>
#include<functional>
using namespace std;

int t, n, arr[101010];
vector<int> v;
int main() {
	scanf_s("%d", &t);
	while (t--) {
		v.clear();
		scanf_s("%d", &n);
		int sf=0, ef=n-1, putn=0;
		for (int i=0;i<n;i++) {
			scanf_s("%d", &arr[i]);
		}
		sort(arr, arr+n, greater<int>());
		for (int i=0;i<n;i++) {
			if (putn) {
				v.push_back(arr[sf]);
				putn=0;
				sf++;
			}
			else {
				v.push_back(arr[ef]);
				putn=1;
				ef--;
			}
		}
		for (int i=n-1;i>=0;i--) {
			printf("%d ", v[i]);
		}
		cout<<endl;
	}
	return 0;
}