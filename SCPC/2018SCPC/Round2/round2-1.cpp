#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class SegmentTree {
public:

	vector <int> tree_min, tree_max;

	int s;

	SegmentTree(int n) {
		for (s = 1; s < n; s *= 2) {}
		tree_min.resize(s * 2);
		tree_max.resize(s * 2);
		for (int i = 1; i < s * 2; i++) tree_min[i] = numeric_limits<int>::max();
		for (int i = 1; i < s * 2; i++) tree_max[i] = numeric_limits<int>::min();
	}

	void insert_min(vector <int> &d) {
		for (int i = s; i < s + d.size(); i++)
			tree_min[i] = d[i - s];
		for (int i = s - 1; i >= 1; i--)
			tree_min[i] = min(tree_min[i * 2], tree_min[i * 2 + 1]);
	}

	void insert_max(vector <int> &d) {
		for (int i = s; i < s + d.size(); i++)
			tree_max[i] = d[i - s];
		for (int i = s - 1; i >= 1; i--)
			tree_max[i] = max(tree_max[i * 2], tree_max[i * 2 + 1]);
	}

	int getMin(int Left, int Right) {
		int l = Left + s - 1, r = Right + s - 1;
		int rval = numeric_limits<int>::max();
		while (l <= r) {
			if (l % 2 == 0) l /= 2;
			else {
				rval = min(rval, tree_min[l]);
				l = (l / 2) + 1;
			}
			if (r % 2 == 1) r /= 2;
			else {
				rval = min(rval, tree_min[r]);
				r = (r / 2) - 1;
			}
		}
		return rval;
	}

	int getMax(int Left, int Right) {
		int l = Left + s - 1, r = Right + s - 1;
		int rval = numeric_limits<int>::min();
		while (l <= r) {
			if (l % 2 == 0) l /= 2;
			else {
				rval = max(rval, tree_max[l]);
				l = (l / 2) + 1;
			}
			if (r % 2 == 1) r /= 2;
			else {
				rval = max(rval, tree_max[r]);
				r = (r / 2) - 1;
			}
		}
		return rval;
	}
};

int T, N;
int nCount = 0;

int main()
{
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		nCount = 0;
		scanf("%d", &N);
		SegmentTree t(N);

		vector <int> v(N);
		for (int i = 0; i < N; i++) scanf("%d", &v[i]);
		t.insert_min(v);
		t.insert_max(v);

		int nMin = 0, nMax = 0;
		for (int i = 1; i <= N; i++) {
			if (i == 1) {
				nMin = t.getMin(2, N);
				if (v[i-1] < nMin) nCount++;
			} else if (i == N) {
				nMax = t.getMax(1, N-1);
				if (v[i-1] > nMax) nCount++;
			} else {
				nMax = t.getMax(1, i-1);
				nMin = t.getMin(i+1, N);
				if (v[i-1] < nMin and v[i-1] > nMax) nCount++;
			}
		}

		printf("Case #%d\n", test_case);
		printf("%d\n", nCount);
	}
	return 0;
}
