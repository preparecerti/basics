/*
�ּ�(�ִ�) ���� - �迭 ����
�ּҰ��� root�� ������ Ʈ�� ����

���� : O(logn)
���� : O(logn)
*�ּ�(�ִ�)�� Ž�� : O(1)

*/

inline void swap(int &a, int &b) {
	static int tmp = a;
	a = b;
	b = tmp;
}

struct MinHeap {
#define HEAP_SIZE 100
	int data[HEAP_SIZE]; // data[0]�� �˰����� �ϰ����� ���� ������� �ʴ´�.
	int top = 0;

	void push(int d);
	int pop();
	bool contains(int d);
};

// Ʈ���� ������ ��忡 ���� �����Ѵ�.
// ������ ������ root node���� �Ʒ��� �ݺ��Ѵ�. (�����)
// �θ� ���� ���� ���ϸ� �� ������ ��ü�Ѵ�.
void MinHeap::push(int d) {
	data[++top] = d;
	if (top == 1) return;

	for (int i = top; i != 1; i /= 2) {
		int& parent = data[i / 2];
		if (d < parent) {
			swap(parent, data[i]);
		}
		else break;
	}
}

// ������ ���Ҹ� root node�� �ű��.
// root node���� �����Ͽ� �Ʒ��� �ݺ��Ѵ�. (�����)
// �ڽ� ���� �߿� ���� ���� ��� �θ���� ��ü�Ѵ�. 
// - ���̻� �ڽ��� ���ų� ��ü�� �ʿ䰡 ������ �����Ѵ�.
int MinHeap::pop() {
	int ret = data[1];
	swap(data[1], data[top--]);

	for (int i = 1; i < top;) {
		if (i * 2 > top) break;
		
		int iChild;
		{
			int iLeft = i * 2;
			int iRight = iLeft + 1;
			if (iRight > top) {
				iChild = iLeft;
			}
			else {
				iChild = data[iLeft] < data[iRight] ? iLeft : iRight;
			}
		}

		if (data[iChild] < data[i]) {
			swap(data[iChild], data[i]);
			i = iChild;
		}
		else break;
	}

	return ret;
}

bool MinHeap::contains(int d) {
	// TODO
}