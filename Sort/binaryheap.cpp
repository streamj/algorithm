#include <iostream>
using namespace std;

template <class Item>
class MaxPQ{
public:
	MaxPQ(int maxN) : N(0) { pq = new Item[maxN + 1]; }
	bool isEmpty() const { return N == 0; }
	void insert(Item item){
		pq[++N] = item;
		swin(N);
	}
	int size() const { return N; }
	Item getMax(){
		Item max = pq[1];
		exch(1, N--);
		sink(1);
		return max;
	}

private:
	void exch(int i, int j);
	void swin(int k);
	void sink(int k);
	Item* pq;
	int N;
};

template <class Item>
void MaxPQ<Item>::exch(int i, int j)
{
	Item t = pq[i];
	pq[i] = pq[j];
	pq[j] = t;
}

template <class Item>
void MaxPQ<Item>::swin(int k)
{
	while (k > 1 && pq[k / 2] < pq[k]){
		exch(k / 2, k); // parent is k/2;
		k = k / 2;
	}
}

template <class Item>
void MaxPQ<Item>::sink(int k)
{
	while (2 * k <= N) {
		int j = 2 * k;
		if (j < N && pq[j] < pq[j + 1]){ j++; }
		if (!(pq[j] < pq[k])) { break; }

		exch(k, j);
		k = j;
	}
}

int main()
{
	MaxPQ<int> p(100);
	if (p.isEmpty()){
		cout << "empty" << endl;
	}
	p.insert(10);
	p.insert(101);
	p.insert(999);

	if (!p.isEmpty()){
		cout << p.size() << endl;
	}

	p.insert(100);
	p.insert(88);

	cout << p.size() << endl;
	cout << p.getMax() << endl;
	cout << p.size() << endl;

	return 0;
}
