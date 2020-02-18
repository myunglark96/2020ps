#include <iostream>
using namespace std;

long long n, p, q;
int arr[1000010];

long long infi(long long i) {
	if (i==0) return 1;
	else if (i==1) return 2;
	else if (i<1000000&&arr[i]!=0) return arr[i];
	else {
		if (i<1000000&&arr[i]==0) {
			arr[i]=infi(i/p)+infi(i/q);
			return arr[i];
		}
		else {
			return infi(i/p)+infi(i/q);
		}
		
	}
}

int main(){
	//scanf_s("%d%d%d", &n, &p, &q);
	cin>>n>>p>>q;
	cout<<infi(n)<<endl;
	return 0;
}