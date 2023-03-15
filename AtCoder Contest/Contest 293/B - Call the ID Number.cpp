#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, cnt;

	cin >> N;
	vector<int> call(cnt = N);

	for (auto& e : call) cin >> e;

	for (int i = 0; i < N; i++) {
		if (call[i] >= 0 && call[call[i] - 1] > 0) {
			call[call[i] - 1] = -1;
			cnt--;
		}
	}

	cout << cnt << '\n';
	for (int i = 0; i < N; i++)
		if (call[i]>0) cout << i + 1 << ' ';

	return 0;
}