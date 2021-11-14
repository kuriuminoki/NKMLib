#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class GraphTable {
public:
	//辺がない
	const int NO_EDGE = 0;
private:
	//ノードの数
	int V;

	//辺のテーブル
	vector<vector<int> > table;

	//最短距離の始点
	int start;

	//各ノードへの最短距離
	vector<int> min;

private:
	//セグメンテーションフォルト時のエラー文
	void seg_error(int to, int from);
public:
	//ノードの数を指定してグラフを作成
	GraphTable(int V);

	//始点と終点を指定して辺を設定する コストも0以外で決めれる
	void set_edge(int to, int from, int cost = 1);

	//辺があるならそのコスト、ないなら0を返す
	int get_edge(int to, int from);

	//全ての辺のコストを無限に設定する
	void set_inf();

	//始点を指定して単一始点最短距離問題を解く
	void calc_shortest(int s = 0);

	//ノードを指定して始点からの最短距離を取得できる 先にcalc_shortest()を呼べ
	int get_shortest(int v);

	//現在始点となっているノードを返す
	int get_start();
};

void GraphTable::seg_error(int to, int from) {
	cout << "Segmentation Fault" << endl;
	cout << "ノード" << to << "から" << from << "への辺を参照しようとしました。" << endl;
}

GraphTable::GraphTable(int V) {
	table = vector<vector<int> >(V, vector<int> (V, NO_EDGE));
	min = vector<int>(V, INT_MAX);
}

void GraphTable::set_edge(int to, int from, int cost) {
	if (to < 0 || to >= V) { seg_error(to, from); return; }
	if (from < 0 || from >= V) { seg_error(to, from); return; }
	table[to][from] = cost;
}

int GraphTable::get_edge(int to, int from) {
	if (to < 0 || to >= V) { seg_error(to, from); return 0; }
	if (from < 0 || from >= V) { seg_error(to, from); return 0; }
	return table[to][from];
}

void GraphTable::set_inf() {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			table[i][j] = INT_MAX;
		}
	}
}

void GraphTable::calc_shortest(int s) {
	if (s < 0 || s >= V) { seg_error(s, s); return; }
	start = s;
	min[s] = 0;
	while (true) {
		bool update = true;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (table[i][j] == NO_EDGE) { continue; }
				if (min[i] != INT_MAX && min[j] > min[i] + table[i][j]) {
					min[j] = min[i] + table[i][j];
					update = true;
				}
			}
		}
		if (!update) { break; }
	}
}

int GraphTable::get_shortest(int v) {
	return min[v];
}

int GraphTable::get_start() {
	return start;
}