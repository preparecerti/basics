/*
최소(최대) 히프 - 배열 구현
최소값을 root로 가지는 트리 구조

삽입 : O(logn)
삭제 : O(logn)
*최소(최대)값 탐색 : O(1)

*/

inline void swap(int &a, int &b) {
	static int tmp = a;
	a = b;
	b = tmp;
}

struct MinHeap {
#define HEAP_SIZE 100
	int data[HEAP_SIZE]; // data[0]은 알고리즘의 일관성을 위해 사용하지 않는다.
	int top = 0;

	void push(int d);
	int pop();
	bool contains(int d);
};

// 트리의 마지막 노드에 값을 저장한다.
// 마지막 노드부터 root node까지 아래를 반복한다. (상향식)
// 부모 노드와 값을 비교하며 더 작으면 교체한다.
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

// 마지막 원소를 root node로 옮긴다.
// root node부터 시작하여 아래를 반복한다. (하향식)
// 자식 노드들 중에 작은 것을 골라 부모노드로 교체한다. 
// - 더이상 자식이 없거나 교체할 필요가 없으면 종료한다.
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