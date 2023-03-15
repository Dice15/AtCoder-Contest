#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
	int mSetSize;            // 집합들의 크기
	vector<int> mSetTable;   // 속한 집합의 루트를 저장하는 테이블. -1이면 자신이 루트라는 것을 의미

public:
	DisjointSet(int size = 0) { Assign(size); }
	void Assign(int size) { mSetSize = size; mSetTable.assign(size, -1); }

public:
	// val이 속한 집합의 번호를 반환한다
	int Find(int u) {
		if (mSetTable[u] < 0) return u;
		return mSetTable[u] = Find(mSetTable[u]);
	}

	// val1이 속한 집합과 val2가 속한 집합을 합친다. 합치는 것을 성공했다면 true를 아니면 false를 반환한다.
	bool Merge(int u, int v) {
		u = Find(u);
		v = Find(v);
		if (u == v) return false;
		mSetTable[u] += mSetTable[v];   // 두 집합의 크기를 합치는 연산
		mSetTable[v] = u;  // val2의 루트를 val1으로 설정함으로써 두 집합을 합침
		return true;
	}
};


int N, M, n1, n2, res1 = 0, res2 = 0;
char c1, c2;
DisjointSet ds1(200000);
vector<int> group[200000], cnt(200000);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	while (M--) {
		cin >> n1 >> c1 >> n2 >> c2;
		ds1.Merge(--n1, --n2);
		cnt[n1]++; cnt[n2]++;
	}

	for (int i = 0; i < N; i++) group[ds1.Find(i)].push_back(i);

	for (int i = 0; i < N; i++) {
		if (group[i].empty()) continue;

		bool res = true;
		for (auto& e : group[i]) {
			if (cnt[e] < 2) { res = false; break; }
		}
		res ? ++res1 : ++res2;
	}

	cout << res1 << ' ' << res2 << '\n';

	return 0;
}
