#include<FenwickTree.h>

FenwickTree::FenwickTree() {
	this->numArray = NULL;
	this->length = 0;
}

FenwickTree::FenwickTree(int length) {
	this->numArray = new int[length + 1];
	this->length = length+1;
	for (int i = 0; i < this->length; ++i) {
		this->numArray[i] = 0;
	}
}

FenwickTree::~FenwickTree() {
	delete this->numArray;
	this->length = 0;
}

void FenwickTree::initArray(int length) {
	if (this->numArray == NULL) {
		this->numArray = new int[length + 1];
		this->length = length+1;
	}
	for (int i = 0; i < this->length; ++i) {
		this->numArray[i] = 0;
	}
}

void FenwickTree::set(vector<int> inputArray) {
	int index = 1;
	for (int num : inputArray) {
		update(index, num);
		index++;
	}
}

void FenwickTree::update(int index, int value) {
	int toAdd = value;
	while (index < length) {
		this->numArray[index] += toAdd;
		index = getNextIndex(index);
	}
}

int FenwickTree::prefixSum(int index) {
	int sum = 0;
	while (index != 0) {
		sum += this->numArray[index];
		index = getParent(index);
	}
	return sum;
}

int FenwickTree::getLength() {
	return this->length;
}

int FenwickTree::rangeSum(int start, int end) {
	return prefixSum(end) - prefixSum(start);
}

/* Rule of parent : Remove last bit which equals to 1.
   1.Get 2 complement from current index.
   2.And current index with 2 complement number.
   3.Subtract current index with value above.
*/
int FenwickTree::getParent(int index) {
	int twoComp = ~index + 1;
	twoComp &= index;
	index -= twoComp;
	return index;
}

/* Rule of next index :
   1.Get 2 complement from current index.
   2.And current index with 2 complement number.
   3.Add current index with value above.
*/
int FenwickTree::getNextIndex(int index) {
	int twoComp = ~index + 1;
	twoComp &= index;
	index += twoComp;
	return index;
}

void FenwickTree::printAll() {
	for (int i = 1; i < this->length; ++i) {
		cout << this->numArray[i] << "  ";
	}
	cout << endl;
}