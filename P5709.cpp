#include <iostream>
using namespace std;

int main() {
	int m, t, s;

	cin >> m >> t >> s;
	if (!t)
		cout << 0 << endl;
	else
		cout << m - min((int)m, (int)(s + t -1)/t)<<endl;
	return 0;
}

