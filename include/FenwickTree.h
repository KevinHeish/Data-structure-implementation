#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H
#include<Struct.h>


class FenwickTree {
	private:
		int* numArray; 

		//Length = input Array length + 1.
		int length;

		int getParent(int index);
		int getNextIndex(int index);
	public:
		//If use no parameter constructor should initial by init().
		FenwickTree();

		//Init array by length and set to 0.
		FenwickTree(int length);

		//Release memory required in heap space.
		~FenwickTree();
		
		//Print all Fenwick Tree value.
		void printAll();

		//Return length of array , index start at 0.
		int getLength();

		/*Set value by vector input.
		  Initial array value by 0.*/
		void set(vector<int> inputArray);

		//Initial array with specific length.
		void initArray(int length);

		//Add value to specific index.
		void update(int index, int value);

		//Return prefix sum at specific index start at 1.
		int prefixSum(int index);

		//Return sum at specific index start at first parameter to second parameter.
		int rangeSum(int start, int end);
};

#endif

