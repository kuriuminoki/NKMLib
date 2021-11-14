#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class GraphTable {
public:
	//�ӂ��Ȃ�
	const int NO_EDGE = 0;
private:
	//�m�[�h�̐�
	int V;

	//�ӂ̃e�[�u��
	vector<vector<int> > table;

	//�ŒZ�����̎n�_
	int start;

	//�e�m�[�h�ւ̍ŒZ����
	vector<int> min;

private:
	//�Z�O�����e�[�V�����t�H���g���̃G���[��
	void seg_error(int to, int from);
public:
	//�m�[�h�̐����w�肵�ăO���t���쐬
	GraphTable(int V);

	//�n�_�ƏI�_���w�肵�ĕӂ�ݒ肷�� �R�X�g��0�ȊO�Ō��߂��
	void set_edge(int to, int from, int cost = 1);

	//�ӂ�����Ȃ炻�̃R�X�g�A�Ȃ��Ȃ�0��Ԃ�
	int get_edge(int to, int from);

	//�S�Ă̕ӂ̃R�X�g�𖳌��ɐݒ肷��
	void set_inf();

	//�n�_���w�肵�ĒP��n�_�ŒZ������������
	void calc_shortest(int s = 0);

	//�m�[�h���w�肵�Ďn�_����̍ŒZ�������擾�ł��� ���calc_shortest()���Ă�
	int get_shortest(int v);

	//���ݎn�_�ƂȂ��Ă���m�[�h��Ԃ�
	int get_start();
};

void GraphTable::seg_error(int to, int from) {
	cout << "Segmentation Fault" << endl;
	cout << "�m�[�h" << to << "����" << from << "�ւ̕ӂ��Q�Ƃ��悤�Ƃ��܂����B" << endl;
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