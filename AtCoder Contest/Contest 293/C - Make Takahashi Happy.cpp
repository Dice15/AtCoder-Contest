#include <bits/stdc++.h>
using namespace std;

int H, W, mvx[2] = { 1, 0 }, mvy[2] = { 0, 1 };
vector<vector<int>> tab;
set<int> s;

int dfs(int x, int y) {
	if (x == H && y == W) return 1;

	int res = 0;
	for (int i = 0; i < 2; i++) {
		int nx = x + mvx[i], ny = y + mvy[i];
		if ((nx > H || ny > W) || s.find(tab[nx][ny]) != s.end()) continue;
		s.insert(tab[nx][ny]);
		res += dfs(nx, ny);
		s.erase(tab[nx][ny]);
	}
	return  res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> H >> W;
	tab.assign(H, vector<int>(W, 0));

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) cin >> tab[i][j];

	H--; W--;
	s.insert(tab[0][0]);
	cout << dfs(0, 0) << '\n';

	return 0;
}