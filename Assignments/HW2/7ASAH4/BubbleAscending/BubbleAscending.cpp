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

#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;

// lines
//  38 -  55 
// Bubble sort taken from  https://www.geeksforgeeks.org/bubble-sort
//

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// Driver code
int main()
{
  // setting the size to 100,000
  // to setup the array  
  ifstream file;
  file.open("AscendingOrder.txt");

  int arr[100000];

  if (file.is_open())
  {
    for (int i = 0; i < 100000; i++)
    {
      file >> arr[i];
    }
      file.close();
  }
    else {
    cout << "Can't find the file" << endl;
  }

  // getting the size of array 
  int n = sizeof(arr) / sizeof(arr[0]);


  // Timing bubble sort algorithm 
  // in nanosecs, microsecs, secs
  auto start = chrono::steady_clock::now();
  bubbleSort(arr, n);
  auto end = chrono::steady_clock::now();

  cout << "Bubble sort in Ascending order time " << endl;

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