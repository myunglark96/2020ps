#include <iostream>
#include <map>
#include <vector>
using namespace std;

int depth[1000000], ind[1000000]; //item이 mp에 담길 index
bool visited[1000000]={ false, };

int main() {
	int n, parentnum, itemnum, cnt=0;
	map<int, int> mp;
	map<int, int>::iterator depthitr;
	mp.insert(make_pair(1, 0));
	scanf_s("%d", &n);
	for (int i=1; i<n; i++) {
		scanf_s("%d%d", &parentnum, &itemnum);
		mp.insert(make_pair(itemnum, parentnum));
	}

	for (auto itr=mp.begin(); itr!=mp.end(); itr++) {
		depth[itr->first]=depth[itr->second]+1;
	}

	for (int i=mp.size(); i>0; i--) {
		depthitr=mp.find(i);
		if (!visited[depthitr->first]) {
			if (depth[i]%2==0) {
				for (int j=depth[i]; j>0; j--) {
					if (j%2==1&&!visited[depthitr->first]) {
						visited[depthitr->first]=true;
						cnt++;
					}
					depthitr=mp.find(depthitr->second);
				}
			}
			else {
				for (int j=depth[i]; j>0; j--) {
					if (j%2==0&&!visited[depthitr->first]) {
						visited[depthitr->first]=true;
						cnt++;
					}
					depthitr=mp.find(depthitr->second);
				}
			}
		}
	}
	cout<<cnt<<endl;
}