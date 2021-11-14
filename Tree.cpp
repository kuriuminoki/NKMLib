#include<iostream>
#include<vector>

using namespace std;

class Tree {
private:
	//ノードの数
	int V;

	//親子関係の数
	int E;

	//根のノード
	int root;

	//ノードのキー値
	vector<int> key;

	//ノードの子
	vector<vector<int> > leaf;

	//ノードの親
	vector<vector<int> > par;
private:
	void seg_error(int to, int from);
public:
	//ノードの数を指定して木を作る キー値も指定できる
	Tree(int V, int K = 0);

	//根を設定する
	void set_root(int v);

	//根を取得する
	int get_root();

	//キー値を設定する
	void set_key(int v, int k);

	//キー値を取得する
	int get_key(int v);

	//親子関係を追加する
	void add_edge(int p, int c);

	//ノードが持つ子の数を取得する
	unsigned int sum_leaf(int v);

	//ノードが持つ親の数を取得する
	unsigned int sum_par(int v);

	//ノードの親を取得する 複数ある場合何番目かを指定する
	int get_par(int v, int n = 0);
};


void Tree::seg_error(int to, int from) {
	cout << "Segmentation Fault" << endl;
	cout << "親ノード" << to << "から" << from << "への辺を参照しようとしました。" << endl;
}

Tree::Tree(int V, int K) {
	key = vector<int>(V, K);
}

void Tree::set_root(int v) {
	root = v;
}

int Tree::get_root() {
	return root;
}

void Tree::set_key(int v, int k) {
	key[v] = k;
}

int Tree::get_key(int v) {
	return key[v];
}

void Tree::add_edge(int p, int c) {
	if (p < 0 || p >= V || c < 0 || c >= V) {
		seg_error(p, c);
		return;
	}
	leaf[p].push_back(c);
	par[c].push_back(p);
}

unsigned int Tree::sum_leaf(int v) {
	return leaf[v].size();
}

unsigned int Tree::sum_par(int v) {
	return par[v].size();
}

int Tree::get_par(int v, int n) {
	if (n < 0 || n >= (int)sum_par(n)) {
		cout << "Segmentation Fault" << endl;
		cout << "ノード" << v << "に" << n << "番目の親は存在しません。" << endl;
	}
	return par[v][n];
}