#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int t,n,k, marry, ans1,ans2;
bool prince[100001], married[100001];
vector<int> dau[100001];

int main() {
	int cnt=0;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i=1;i<=n;i++) {
			scanf("%d", &k);
			dau[i].clear();
			for (int j=1;j<=k;j++) {
				int tmp;
				scanf("%d", &tmp);
				dau[i].push_back(tmp);
			}
			sort(dau[i].begin(), dau[i].end());
			for (int l=0;l<dau[i].size();l++) {
				if (!prince[dau[i][l]]) {
					prince[dau[i][l]]=true;
					married[i]=true;
					cnt++;
					break;
				}
			}
		}

		if (cnt==n) cout<<"OPTIMAL\n";
		else {
			for (int i=1;i<=n;i++) {
				if (!married[i]) {
					ans1=i;
					break;
				}
			}
			for (int i=1;i<=n;i++) {
				if (!prince[i]) {
					ans2=i;
					break;
				}
			}
			cout<<"IMPROVE\n";
			cout<<ans1<<" "<<ans2<<"\n";
		}
		cnt=0;
		memset(prince, 0, sizeof(prince));
		memset(married, 0, sizeof(married));
	}
	return 0;
}