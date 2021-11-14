#include<iostream>
#include<vector>

using namespace std;

class Sieve {
private:
	//NˆÈ‰º‚Ì‘f”‚ğ‹‚ß‚é
	int N;

	//‘f”‚©‚Ç‚¤‚©
	vector<bool> list;

	//‘S‚Ä‚Ì‘f”
	vector<int> prime;

	//‘f”‚Ì”‚Ì—İÏ˜a
	vector<int> add_sum;

	//‘f”‚Ì‡Œv
	int sum;
private:
	void range_error(int n);
	void calc();//‘f”‚ğ‹‚ß‚é

public:
	//”ÍˆÍ‚ğw’è‚µ‚Ä‘f”‚ğ‹‚ß‚é
	Sieve(int n);

	//”ÍˆÍ‚ğ•Ï‚¦‚é
	void reset(int n);

	//w’è‚µ‚½”‚ª‘f”‚©‚Ç‚¤‚©”»’è‚·‚é
	bool check(int n);

	//‘f”‚Ì”‚ğ•Ô‚·
	int get_sum();

	//”ÍˆÍ“à‚Ì‘f”‚Ì”‚ğ•Ô‚·
	int range_sum(int left, int right);

	//n”Ô–Ú‚Ì‘f”‚ğ•Ô‚·
	int get_num(int n);
};

void Sieve::range_error(int n) {
	if (n < 0 || n > N) {
		cout << "‘f””»’è:" << n << "‚Í”ÍˆÍŠO‚Å‚·" << endl;
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


//‘fˆö”•ª‰ğ
void divide(int N, vector<pair<long long, long long> >& res) {
	for (long long a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;
		long long ex = 0; // w”

		// Š„‚ê‚éŒÀ‚èŠ„‚è‘±‚¯‚é
		while (N % a == 0) {
			++ex;
			N /= a;
		}

		// ‚»‚ÌŒ‹‰Ê‚ğ push
		res.push_back({ a, ex });
	}
	// ÅŒã‚Éc‚Á‚½”‚É‚Â‚¢‚Ä
	if (N != 1) res.push_back({ N, 1 });
}