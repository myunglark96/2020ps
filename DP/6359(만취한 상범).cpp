#include <iostream>
#include <cstring>
using namespace std;

int t,n,ans;
bool room[101];

int main() {
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (j%i==0) room[j]=!room[j];
			}
		}
		for (int i=1;i<=n;i++) {
			if (room[i]) ans++;
		}
		cout<<ans<<endl;
		ans=0;
		memset(room, false, sizeof(room));
	}
	return 0;
}