#include <iostream>
#include<vector>
using namespace std;

typedef long long int llint;

const int MOD = 1000000007;

vector<llint> fac, finv, inv;
void COMinit(llint N) {
	fac = vector<llint>(N);
	finv = vector<llint>(N);
	inv = vector<llint>(N);
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < N; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


///NoKmonoオリジナル///////////////////////////////////////////////////
//xのn乗を高速に求める
llint mod_pow(llint x, llint n, llint mod) {
	llint res = 1;
	while (n > 0) {
		if (n & 1) { res = res * x % mod; }
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

//start から end までをかける 階乗の計算とか用
llint mul(llint start, llint end, llint mod) {
	llint res = 1;
	for (llint i = start; i <= end; i++) {
		res *= i;
		res %= mod;
	}
	return res;
}

//フェルマーの小定理
//modの世界でup / down をしたいなら、up に down^(mod-2) をかけろ
//nCa を計算 フェルマーの小定理を利用
llint choose(llint n, llint a, llint mod) {
	llint up = mul(n - a + 1, n, mod);
	llint down = mul(1, a, mod);
	down = mod_pow(down, mod - 2, mod);
	return (up * down) % mod;
}
/////////////////////////////////////////////////////////

//使用例
int main() {
	// 前処理
	int N = 150000;
	COMinit(N);

	// 計算例
	cout << COM(6, 2) << endl;
}