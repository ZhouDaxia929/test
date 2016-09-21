
//test
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
struct cmp_key{
	bool operator()(const int &k1, const int &k2)const{
		return k1 - k2 > 0;
	}
};
int main() {
	typedef map<int, double, cmp_key> M;
	M m;
	int aa, ab, first, size;
	double second;
	cin >> ab >> first >> second;
	m.insert(make_pair(first, second));
	for (int i = 1;i < ab;i++) {
		cin >> first >> second;
		map<int, double>::iterator pos = m.find(first);
		if (pos == m.end() && first+second != 0)
			m.insert(make_pair(first, second));
		else if(m.size() != 0)
			pos->second += second;
	}
	cin >> aa;
	for (int i = 0; i < aa; i++) {
		cin >> first >> second;
		map<int, double>::iterator pos = m.find(first);
		if (pos == m.end() && first + second != 0)
			m.insert(make_pair(first, second));
		else if (m.size() != 0)
			pos->second += second;
	}
	map<int, double>::iterator pos1 = m.begin();
	if (aa == 0 && ab == 0 || pos1->first+pos1->second==0) {
		printf("0");
		return 0;
	}
	else {
		size = m.size();
		printf("%d ", size);
		map<int, double>::iterator pos;
		for (pos = m.begin();pos != m.end();++pos) {
			if (pos != --m.end())
				printf("%d %.1f ", pos->first, pos->second);
			else
				printf("%d %.1f", pos->first, pos->second);
		}
		return 0;
	}
}











//
//float a[1001], b[1001], c[1001];
//for (int i = 0; i < 1001; i++)
//	c[i] = 0.0;
//int mm, n;
//cin >> mm;
//for (int i = 0; i < mm; i++) {
//	int t;
//	cin >> t;
//	cin >> a[t];
//	c[t] += a[t];
//}
//cin >> n;
//for (int i = 0; i < n; i++) {
//	int t;
//	cin >> t;
//	cin >> b[t];
//	c[t] += b[t];
//}
//int count = 0;
//for (int i = 0; i < 1001; i++) {
//	if (c[i] != 0)
//		count++;
//}
//cout << count;
//if (count != 0)
//cout << " ";
//int temp = 1001;
//for (int i = 1000; i >= 0; i--) {
//	if (c[i] != 0.0 && count > 1) {
//		cout << i << " ";
//		printf("%.1f ", c[i]);
//		count--;
//		temp = i;
//	}
//}
//for (int i = temp - 1; i >= 0; i--) {
//	if (c[i] != 0.0) {
//		cout << i << " ";
//		printf("%.1f", c[i]);
//	}
//}
//return 0;