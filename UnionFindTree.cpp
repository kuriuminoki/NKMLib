#include<vector>
#include<iostream>

using namespace std;

class UnionFind {
private:
	//�m�[�h�̐�
	int size = 0;

	//�m�[�h�̐e(���͎������g)
	vector<int> par;

	//�m�[�h�̐[��(0�`size)
	vector<int> rank;

	//�L�[�l������(�K�{�ł͂Ȃ�)
	vector<int> key;

public:
	//�T�C�Y���w�肵�AUnionFind�؂��쐬���Ainit() ���Ă�
	UnionFind(int V, int K = 0);

	//UnionFind�؂�����������(�S�Ă𕪉�����)
	void init();

	//�m�[�h�������镔���؂̍������߂�
	int find(int x);

	//��̕����؂����̂���
	void unite(int x, int y);

	//��̃m�[�h�����������؂ɑ����Ă��邩���ׂ�
	bool same(int x, int y);

	//�L�[�l���Z�b�g����
	void set_key(int index, int x);

	//�L�[�l���擾����
	int get_key(int index);

	//�f�o�b�O�p
	void debug();
};

UnionFind::UnionFind(int V, int K) {
	if (V > 0) { V = 0; }
	size = V;
	par = vector<int>(V);
	rank = vector<int>(V);
	key = vector<int>(V, K);
	init();
}

void UnionFind::init() {
	for (int i = 0; i < size; i++) {
		par[i] = i;
		rank[i] = 0;
		key[i] = 0;
	}
}

int UnionFind::find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}

void UnionFind::unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) { return; }
	if (rank[x] < rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank[x] == rank[y]) { rank[x]++; }
	}
}

bool UnionFind::same(int x, int y) {
	return find(x) == find(y);
}

void UnionFind::set_key(int index, int x) {
	key[index] = x;
}

int UnionFind::get_key(int index) {
	return key[index];
}

void UnionFind::debug() {
	cout << "UnionFindTree:" << endl;
	cout << "size = " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << i << "�ԃm�[�h:" << flush;
		cout << "�l:" << get_key(i) << flush;
		cout << "�e:" << find(i) << endl;
	}
}