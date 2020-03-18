#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;
int ids=-1, ide=-1,start=0;
vector<int> v;

int main() {
	cin>>s;
	int end=s.size();
	while (true){
		for (int i=start;i<end;i++) {
			if (s[i]=='('&&ids==-1) {
				ids=i;
			}
			if (s[i]==')'&&i>ids&&ids!=-1) ide=i;
		}
		if (ide==-1||ids==-1) {
			if (v.size()==0) {
				printf("%d\n", 0);
				return 0;
			}
			else printf("%d\n", 1);
			printf("%d\n", v.size());
			sort(v.begin(), v.end());
			for (int i=0;i<v.size();i++) {
				printf("%d ", v[i]+1);
			}
			return 0;
		}
		v.push_back(ids);
		v.push_back(ide);
		start=ids+1;
		end=ide;
		ids=-1;
		ide=-1;
	}

	return 0;
}