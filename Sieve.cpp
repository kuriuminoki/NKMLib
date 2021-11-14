#include<iostream>
#include<vector>

using namespace std;

class Sieve {
private:
	//N�ȉ��̑f�������߂�
	int N;

	//�f�����ǂ���
	vector<bool> list;

	//�S�Ă̑f��
	vector<int> prime;

	//�f���̐��̗ݐϘa
	vector<int> add_sum;

	//�f���̍��v
	int sum;
private:
	void range_error(int n);
	void calc();//�f�������߂�

public:
	//�͈͂��w�肵�đf�������߂�
	Sieve(int n);

	//�͈͂�ς���
	void reset(int n);

	//�w�肵�������f�����ǂ������肷��
	bool check(int n);

	//�f���̐���Ԃ�
	int get_sum();

	//�͈͓��̑f���̐���Ԃ�
	int range_sum(int left, int right);

	//n�Ԗڂ̑f����Ԃ�
	int get_num(int n);
};

void Sieve::range_error(int n) {
	if (n < 0 || n > N) {
		cout << "�f������:" << n << "�͔͈͊O�ł�" << endl;
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


//�f��������
void divide(int N, vector<pair<long long, long long> >& res) {
	for (long long a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;
		long long ex = 0; // �w��

		// �������芄�葱����
		while (N % a == 0) {
			++ex;
			N /= a;
		}

		// ���̌��ʂ� push
		res.push_back({ a, ex });
	}
	// �Ō�Ɏc�������ɂ���
	if (N != 1) res.push_back({ N, 1 });
}