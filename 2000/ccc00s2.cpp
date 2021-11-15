#include <bits/stdc++.h>

using namespace std;

#define range(x) for (int i=0; i < x; i++)
#define in_range(a, b, c) for (int j=a; j < b; j+=c)
#define all(x) x.begin(), x.end()

//debuging 
#define DEBUG(a) cout << #a "=[" << a << "]" << endl

int main() {
	int n; cin >> n;
	vector<long double> v(n);
	range(n)
		cin >> v[i];
  
	while (1) {
		int temp;
		cin >> temp;
		if (temp == 99) {
			//split
			int stream; double percentage;
			cin >> stream >> percentage;
			int l= v[stream-1];
			v[stream-1]=(int)(v[stream-1]*percentage/100);
			v.insert(v.begin()+stream, (int)(l-v[stream-1]));
		}
		else if (temp == 88) {
			//rejoin
			int num;
			cin >> num;
			v[num-1] += v[num];
			v.erase(v.begin()+num);
		}
		else if (temp == 77) {
			break;
		}
	}
	for (auto &n : v)
		cout << n << " " ;
	cout << endl;
	return 0;
}
