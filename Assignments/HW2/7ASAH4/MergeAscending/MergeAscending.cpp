/*
Student 1, Edgar Zapata
Student 2, Asaiah Logan
    Make sure the files are in each respected folder.
      for example:
        folder 1: Ascendingcode & Ascending.txt
        folder 2: etc
        folder 3: etc
      run each on Visual studio
      Or run on terminal
      c++ or g++ each file  and ./a.out for the output of each program
*/
#include <chrono>
#include <cmath>
#include <fstream>
#include <iomanip> //fix, setw
#include <iostream>
#include <stdlib.h> //srand, rand
#include <time.h>  
#include <vector>

using namespace std;

// rMergeSort; returns: void; params: vector<int>&, long left, long right;
void rMergeSort(vector<int>& newVect, long left, long right);
// Merge; returns: void; params: vector<int>&, long left, long m, long right;
void Merge(vector<int>& newVect, long left, long m, long right);

int main() {
	ifstream infile;  // initalizing print
	ofstream outfile; // functions
	int nums;

	// array of quantity of integers to randomly generate
	// also, loop control variable
	int a[100000];

	vector<int> vec1; // dynamically allocate and fill vector with values
	infile.open("AscendingOrder.txt");
	for (int i = 0; i < 100000; i++) {
		infile >> nums;
		vec1.push_back(nums);
	}

	// time the recursive Merge Sort with copy of array
	auto start = chrono::steady_clock::now();
	rMergeSort(vec1, 0, vec1.size() - 1); // calling recursive
											  // merge sort
	auto end = chrono::steady_clock::now();

	cout << "Merge sort in Ascending order time " << endl;

	cout << "in sec:" << endl;
	cout << chrono::duration_cast<chrono::seconds>(end - start).count()
		<< " sec" << endl;
	cout << endl;

	cout << "in usec:" << endl;
	cout << chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
	cout << endl;

	cout << "in nanosecondes: " << endl;
	cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;
	cout << endl;

  return 0;
}



/*
 * Return: void
 * Parameter: vector<int>& vec, long left, long right
 * Purpose: perform recursive merge sort on a vector
 */
void rMergeSort(vector<int>& newVect, long left, long right) {
	// if 0 or 1 elements in subarray, stop
	if (left >= right)
		return;
	// More than 2 elements in subarray, sort
	else { // compute middle
		long m = left + (right - left) / 2;

		// sort 1st subarray and sort 2nd subarray
		rMergeSort(newVect, left, m);
		rMergeSort(newVect, m + 1, right);

		// merge two sorted subarrays
		Merge(newVect, left, m, right);
	}
}

/*
 * Return: void
 * Parameter: vector<int>& newVect, long left, long m, long right
 * Purpose: Merge two sorted halves of an array
 */
void Merge(vector<int>& newVect, long left, long m, long right) {
	// determine sizes of two sorted parts
	long n1 = m - left + 1;
	long n2 = right - m;

	// Dynamically allocate temp arrays for both subarrays
	int* L = new int[n1];
	int* R = new int[n2];

	// Copy data to temp arrays L[] and R[]
	for (long i = 0; i < n1; i++)
		L[i] = newVect[left + i];
	for (long j = 0; j < n2; j++)
		R[j] = newVect[m + 1 + j];

	// Merge the temp arrays backk into arr[l..r]

	long i = 0;	// Initial index of first subarray
	long j = 0;	// Initial index of second subarray
	long k = left; // Initial index of merged subarray

	// while elements in both subarrays, merge
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			newVect[k] = L[i];
			i++;
		}
		else {
			newVect[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy remaining elements of L[], if there are any
	while (i < n1) {
		newVect[k] = L[i];
		i++;
		k++;
	}

	// Copy remaining elements of R[], if there are any
	while (j < n2) {
		newVect[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}