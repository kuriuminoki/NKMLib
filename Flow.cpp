#include<iostream>
#include<vector>
#include<queue>

using namespace std;


const int INF = 1000000;

struct edge { int to, cap, rev; };

vector<edge> G[100];
int level[100];
int iter[100];

void add_edge(int from, int to, int cap) {
	edge a = { to, cap, G[to].size() };
	G[from].push_back(a);
	edge b = { from, 0, G[from].size() - 1 };
	G[to].push_back(b);
}


void bfs(int s) {
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		for (int i = 0; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if (e.cap > 0 && level[e.to] < 0) {
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f) {
	if (v == t) { return f; }
	for (int &i = iter[v]; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (e.cap > 0 && level[v] < level[e.to]) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

class Matching {
private:
	int N, K;
	vector<vector<bool> > graph;
public:
	Matching(int n, int k);
	~Matching();
public:
	void add_pair(int index1, int index2);
	int max_matching();
};

Matching::Matching(int n, int k) {
	N = n; K = k;
	for (int i = 0; i < N; i++) {
		graph.push_back(vector<bool>(K, false));
	}
}

Matching::~Matching() {
	
}

void Matching::add_pair(int index1, int index2) {
	graph[index1][index2] = true;
}

int Matching::max_matching() {
	int s = N + K, t = s + 1;
	for (int i = 0; i < N; i++) {
		add_edge(s, i, 1);
	}
	for (int i = 0; i < K; i++) {
		add_edge(N + i, t, 1);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			if (graph[i][j]) {
				add_edge(i, N + j, 1);
			}
		}
	}
	int flow = 0;
	for (;;) {
		bfs(s);
		if (level[t] < 0) { return flow; }
		memset(iter, 0, sizeof(iter));
		int f;
		while ((f = dfs(s, t, INF)) > 0) {
			flow += f;
		}
	}
}