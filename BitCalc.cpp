#include<iostream>

using namespace std;

///////ビット演算関連////////////////////////

/* 指定した長さ分ビットを表示し、改行する */
void BitPrintLen(int x, int len) {
	if (len <= 0 || len > 32) return;

	for (int i = len - 1; i >= 0; i--) {
		cout << (1 & (x >> i)) << flush;
	}
	cout << endl;
}

/* n 桁目が1 ならtrue を返す (n > 0)*/
bool BitOneFlag(int x, int n) {
	return 1 & (x >> (n - 1));
}

/* 1 が何個あるかを返す*/
int BitCount(int x) {
	if (x == 0) { return 0; }
	return BitCount(x >> 1) + (x & 1);
}

///////////////////////////////////////////////////