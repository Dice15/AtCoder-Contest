#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	for (int i = 1; i < (int)s.size(); i += 2) swap(s[i], s[i - 1]);
	cout << s << '\n';

	return 0;
}