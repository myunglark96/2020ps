#include <iostream>
using namespace std;

long long num, t, n, k,ans;

int main() {
	scanf_s("%lld", &t);
	while (t--){
		scanf_s("%lld", &n);
		for (int i=2;i<40;i++) {
			num=pow(2, i);
			if (n%(num-1)==0) {
				ans=n/(num-1);
				cout<<ans<<endl;
				break;
			}
		}
		ans=0;
	}
	return 0;
}