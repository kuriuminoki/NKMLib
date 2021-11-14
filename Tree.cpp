#include<iostream>
#include<vector>

using namespace std;

class Tree {
private:
	//�m�[�h�̐�
	int V;

	//�e�q�֌W�̐�
	int E;

	//���̃m�[�h
	int root;

	//�m�[�h�̃L�[�l
	vector<int> key;

	//�m�[�h�̎q
	vector<vector<int> > leaf;

	//�m�[�h�̐e
	vector<vector<int> > par;
private:
	void seg_error(int to, int from);
public:
	//�m�[�h�̐����w�肵�Ė؂���� �L�[�l���w��ł���
	Tree(int V, int K = 0);

	//����ݒ肷��
	void set_root(int v);

	//�����擾����
	int get_root();

	//�L�[�l��ݒ肷��
	void set_key(int v, int k);

	//�L�[�l���擾����
	int get_key(int v);

	//�e�q�֌W��ǉ�����
	void add_edge(int p, int c);

	//�m�[�h�����q�̐����擾����
	unsigned int sum_leaf(int v);

	//�m�[�h�����e�̐����擾����
	unsigned int sum_par(int v);

	//�m�[�h�̐e���擾���� ��������ꍇ���Ԗڂ����w�肷��
	int get_par(int v, int n = 0);
};


void Tree::seg_error(int to, int from) {
	cout << "Segmentation Fault" << endl;
	cout << "�e�m�[�h" << to << "����" << from << "�ւ̕ӂ��Q�Ƃ��悤�Ƃ��܂����B" << endl;
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
		cout << "�m�[�h" << v << "��" << n << "�Ԗڂ̐e�͑��݂��܂���B" << endl;
	}
	return par[v][n];
}