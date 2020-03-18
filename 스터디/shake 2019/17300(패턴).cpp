#include <iostream>
#include <queue>
using namespace std;

int l, arr[11], map[4][4], 
	dx[]={1,1,0,-1,-1,-1,0,1,2,2,1,1,-2,-2,-1,-1}, 
	dy[]={0,-1,-1,-1,0,1,1,1,-1,1,2,-2,1,-1,2,-2},
	cdx[]={2,-2,2,-2,2,-2,0,0},
	cdy[]={0,0,2,-2,-2,2,2,-2};
bool used[11], ans=true;
queue<pair<int, int>> qu;

int main() {
	int cnt=1,nx=0,ny=0;
	for (int i=1;i<=3;i++) {
		for (int j=1;j<=3;j++) {
			map[i][j]=cnt++;
		}
	}
	scanf_s("%d", &l);
	for (int k=0;k<l;k++) {
		scanf_s("%d", &arr[k]);
		if (k==0) {
			for (int i=1;i<=3;i++) {
				for (int j=1;j<=3;j++) {
					if (nx&&ny) break;
					if (map[i][j]==arr[k]) {
						nx=j;
						ny=i;
						used[map[ny][nx]]=true;
						qu.push({ ny,nx });
					}
				}
				if (nx&&ny) break;
			}
		}
		else {
			if (used[arr[k]]) {
				cout<<"NO\n";
				return 0;
			}
			for (int d=0;d<16;d++) {
				int nextx=nx+dx[d], nexty=ny+dy[d];
				if (nextx>0&&nexty>0&&nextx<=3&&nexty<=3&&arr[k]==map[nexty][nextx]) {
					nx=nextx,ny=nexty;
					used[map[nexty][nextx]]=true;
					break;
				}
			}
			for (int cd=0;cd<8;cd++) {
				int nextx=nx+cdx[cd], nexty=ny+cdy[cd];
				if (nextx>0&&nexty>0&&nextx<=3&&nexty<=3&&arr[k]==map[nexty][nextx]) {
					switch (cd)
					{
					case 0:
						if (!used[map[ny][nx+1]]) {
							cout<<"NO\n";
							return 0;
						}
						else {
							nx=nextx;
							ny=nexty;
							used[map[nexty][nextx]]=true;
						}
						break;
					case 1:
						if (!used[map[ny][nx-1]]) {
							cout<<"NO\n";
							return 0;
						}
						else {
							nx=nextx;
							ny=nexty;
							used[map[nexty][nextx]]=true;
						}
						break;
					case 2:
						if (!used[map[ny+1][nx+1]]) {
							cout<<"NO\n";
							return 0;
						}
						else {
							nx=nextx;
							ny=nexty;
							used[map[nexty][nextx]]=true;
						}
						break;
					case 3:
						if (!used[map[ny-1][nx-1]]) {
							cout<<"NO\n";
							return 0;
						}
						else {
							nx=nextx;
							ny=nexty;
							used[map[nexty][nextx]]=true;
						}
						break;
					case 4:
						if (!used[map[ny-1][nx+1]]) {
							cout<<"NO\n";
							return 0;
						}
						else {
							nx=nextx;
							ny=nexty;
							used[map[nexty][nextx]]=true;
						}
						break;
					case 5:
						if (!used[map[ny+1][nx-1]]) {
							cout<<"NO\n";
							return 0;
						}
						else {
							nx=nextx;
							ny=nexty;
							used[map[nexty][nextx]]=true;
						}
						break;
					case 6:
						if (!used[map[ny+1][nx]]) {
							cout<<"NO\n";
							return 0;
						}
						else {
							nx=nextx;
							ny=nexty;
							used[map[nexty][nextx]]=true;
						}
						break;
					case 7:
						if (!used[map[ny-1][nx]]) {
							cout<<"NO\n";
							return 0;
						}
						else {
							nx=nextx;
							ny=nexty;
							used[map[nexty][nextx]]=true;
						}
						break;
					default:
						break;
					}
				}
			}
		}
	}
	
	if (ans) cout<<"YES\n";
	return 0;
}