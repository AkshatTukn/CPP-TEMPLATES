 int pb1[1700];
int pb2[1700];
struct hsh
{
	int n;
	vector<int> v1;
	vector<int> v2;
	hsh(string &s){
		n = s.size();
		v1.resize(n + 1);
		v2.resize(n + 1);
		loop(i,1,n+1){
			v1[i] = (v1[i - 1] + s[i - 1] * 1ll * pb1[i - 1]) % mod;
			v2[i] = (v2[i - 1] + s[i - 1] * 1ll * pb2[i - 1]) % mod1;
		}
	}
	PII sub(int l,int r){
		int h1 = (v1[r + 1] + mod - v1[l]) * 1ll * pb1[n - r] % mod;
		int h2 = (v2[r + 1] + mod1 - v2[l]) * 1ll * pb2[n - r] % mod1;
		return {h1,h2};
	}
};

