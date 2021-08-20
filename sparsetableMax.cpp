template<typename int_t>
struct sparsemx {
	const int LG = 20;
	vector<vector<int_t>> st;
	vector<int> sp2;
	
	void init(int n, int_t* a) {
		st = vector<vector<int_t>>(LG, vector<int_t>(n));
		sp2 = vector<int>(n + 1);
		
		for (int i = 0; i < n; i++) st[0][i] = a[i];
		
		int r = 0;
		for (int i = 1; i <= n; i++) {
			while (2 * (1 << r) <= i) ++r;
			sp2[i] = r;
		}
		
		for (int j = 1; j < LG; j++) {
			for (int i = 0; i < n; i++) {
				if (i + (1 << j) - 1 >= n) break;
				
				st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]); // combine
			}
		}
	}
	
	int_t query(int l, int r) {
		int x = sp2[r - l + 1];
		
		return max(st[x][l], st[x][r - (1 << x) + 1]);
	}
};
 