#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
	int mSetSize;            // ���յ��� ũ��
	vector<int> mSetTable;   // ���� ������ ��Ʈ�� �����ϴ� ���̺�. -1�̸� �ڽ��� ��Ʈ��� ���� �ǹ�

public:
	DisjointSet(int size = 0) { Assign(size); }
	void Assign(int size) { mSetSize = size; mSetTable.assign(size, -1); }

public:
	// val�� ���� ������ ��ȣ�� ��ȯ�Ѵ�
	int Find(int u) {
		if (mSetTable[u] < 0) return u;
		return mSetTable[u] = Find(mSetTable[u]);
	}

	// val1�� ���� ���հ� val2�� ���� ������ ��ģ��. ��ġ�� ���� �����ߴٸ� true�� �ƴϸ� false�� ��ȯ�Ѵ�.
	bool Merge(int u, int v) {
		u = Find(u);
		v = Find(v);
		if (u == v) return false;
		mSetTable[u] += mSetTable[v];   // �� ������ ũ�⸦ ��ġ�� ����
		mSetTable[v] = u;  // val2�� ��Ʈ�� val1���� ���������ν� �� ������ ��ħ
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
