#include<vector>
#include<iostream>

using namespace std;

class UnionFind {
private:
	//ノードの数
	int size = 0;

	//ノードの親(根は自分自身)
	vector<int> par;

	//ノードの深さ(0～size)
	vector<int> rank;

	//キー値を入れる(必須ではない)
	vector<int> key;

public:
	//サイズを指定し、UnionFind木を作成し、init() を呼ぶ
	UnionFind(int V, int K = 0);

	//UnionFind木を初期化する(全てを分解する)
	void init();

	//ノードが属する部分木の根を求める
	int find(int x);

	//二つの部分木を合体する
	void unite(int x, int y);

	//二つのノードが同じ部分木に属しているか調べる
	bool same(int x, int y);

	//キー値をセットする
	void set_key(int index, int x);

	//キー値を取得する
	int get_key(int index);

	//デバッグ用
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
		cout << i << "番ノード:" << flush;
		cout << "値:" << get_key(i) << flush;
		cout << "親:" << find(i) << endl;
	}
}