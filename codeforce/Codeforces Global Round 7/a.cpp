#include <iostream>
#include <string>
using namespace std;

long long t, n, sum=3;

int main() {
	scanf("%lld", &t);
	string str="3";
	for (int i=0;i<t;i++) {
		scanf("%lld", &n);
		if (n==1) {
			cout<<-1<<"\n";
		}
		else {
			for (int j=1;j<n;j++) {
				if ((sum+2)%3!=0) {
					str.insert(0,"2");
					sum+=2;
				}
				else {
					str.insert(0, "3");
					sum+=3;
				}
			}
			cout<<str<<endl;
			sum=3;
			str="3";
		}
 	}
	return 0;
}