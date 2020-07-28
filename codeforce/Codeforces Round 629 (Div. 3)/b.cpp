#include <iostream>
#include <string>
using namespace std;

int n,t;
long long k;
string str="b";
bool findb;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &k);
		for (long long i=1;i<n;i++) {
			if ((i*(i+1))/2>=k&&!findb) {
				long long subs=k-i*(i-1)/2;
				str=str.substr(0,str.size()-subs+1)+"b"+str.substr(str.size()-subs+1,str.size());
				findb=true;
			}
			else if(findb){
				str="a"+str;
			}
			else {
				str=str+"a";
			}
		}
		cout<<str<<endl;
		str="b";
		findb=false;
	}
	return 0;
}