#include <iostream>
using namespace std;

int t, n, m, arr[101][101];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				if (i==0&&j==0) cout<<"W";
				else cout<<"B";
			}
			cout<<endl;
		}

	}
	return 0;
}