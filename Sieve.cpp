#include<iostream>
#include<vector>

using namespace std;

class Sieve {
private:
	//N以下の素数を求める
	int N;

	//素数かどうか
	vector<bool> list;

	//全ての素数
	vector<int> prime;

	//素数の数の累積和
	vector<int> add_sum;

	//素数の合計
	int sum;
private:
	void range_error(int n);
	void calc();//素数を求める

public:
	//範囲を指定して素数を求める
	Sieve(int n);

	//範囲を変える
	void reset(int n);

	//指定した数が素数かどうか判定する
	bool check(int n);

	//素数の数を返す
	int get_sum();

	//範囲内の素数の数を返す
	int range_sum(int left, int right);

	//n番目の素数を返す
	int get_num(int n);
};

void Sieve::range_error(int n) {
	if (n < 0 || n > N) {
		cout << "素数判定:" << n << "は範囲外です" << endl;
	}
}

Sieve::Sieve(int n) {
	N = n;
	list = vector<bool>(N + 1, true);
	add_sum = vector<int>(N + 1, 0);
	sum = 0;
	calc();
}

void Sieve::reset(int n) {
	N = n;
	list.resize(N);
	add_sum.resize(N);
	prime.resize(0);
	for (int i = 0; i < N; i++) {
		list[i] = true;
		add_sum[i] = 0;
	}
	sum = 0;
	calc();
}

void Sieve::calc() {
	list[0] = list[1] = false;
	for (int i = 2; i <= N; i++) {
		if (list[i]) {
			prime.push_back(i);
			sum++;
			add_sum[i] = sum;
			for (int j = i * 2; j <= N; j += i) { list[j] = false; }
		}
	}
}

bool Sieve::check(int n) {
	range_error(n);
	return list[n];
}


int Sieve::get_sum() {
	return sum;
}


int Sieve::range_sum(int left, int right) {
	range_error(left);
	range_error(right);
	if (left = 0) { return add_sum[right]; }
	return add_sum[right] - add_sum[left - 1];
}


int Sieve::get_num(int n) {
	return prime[n];
}


//素因数分解
void divide(int N, vector<pair<long long, long long> >& res) {
	for (long long a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;
		long long ex = 0; // 指数

		// 割れる限り割り続ける
		while (N % a == 0) {
			++ex;
			N /= a;
		}

		// その結果を push
		res.push_back({ a, ex });
	}
	// 最後に残った数について
	if (N != 1) res.push_back({ N, 1 });
}