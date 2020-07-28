#include <iostream>
using namespace std;

int n, t;

int main() {
	scanf_s("%d", &t);
	while (t--)
	{
		scanf_s("%d", &n);
		if ((n/2)%2==1) cout<<"NO";
		else {
			cout<<"YES\n";
			for (int i=1;i<=n/2;i++) {
				cout<<2*i<<" ";
			}
			for (int i=0;i<n/2+1;i++) {
				if (i!=(n/2+1)/2) cout<<i*2+1<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}