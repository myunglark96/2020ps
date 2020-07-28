#include <iostream>
using namespace std;

long long n, k, t;

int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld", &n, &k);
		if (n<k) {
			cout<<"NO\n";
		}
		else if (n%2==1) {
			if (k%2==1&&pow(k,2)<=n) {
				cout<<"YES\n";
			}
			else if (k%2==1&&pow(k, 2)>n) {
				cout<<"NO\n";
			}
			else {
				cout<<"NO\n";
			}
		}
		else if(n%2==0){
			if (k%2==0&&pow(k, 2)<=n) {
				cout<<"YES\n";
			}
			else if (k%2==0&&pow(k, 2)>n) {
				cout<<"NO\n";
			}
			else {
				cout<<"NO\n";
			}
		}
	}
	return 0;
}