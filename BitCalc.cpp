#include<iostream>

using namespace std;

///////�r�b�g���Z�֘A////////////////////////

/* �w�肵���������r�b�g��\�����A���s���� */
void BitPrintLen(int x, int len) {
	if (len <= 0 || len > 32) return;

	for (int i = len - 1; i >= 0; i--) {
		cout << (1 & (x >> i)) << flush;
	}
	cout << endl;
}

/* n ���ڂ�1 �Ȃ�true ��Ԃ� (n > 0)*/
bool BitOneFlag(int x, int n) {
	return 1 & (x >> (n - 1));
}

/* 1 �������邩��Ԃ�*/
int BitCount(int x) {
	if (x == 0) { return 0; }
	return BitCount(x >> 1) + (x & 1);
}

///////////////////////////////////////////////////