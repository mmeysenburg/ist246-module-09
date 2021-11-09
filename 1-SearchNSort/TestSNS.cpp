#include "SearchNSort.h"
#include <cstdlib>
#include <iostream>
#include <utility>

int compare(const int &x, const int &y) { return (x - y); }

void print(const int *pArr, unsigned n) {
  using namespace std;
  cout << "[";
  for (unsigned i = 0u; i < n - 1; i++) {
    cout << pArr[i] << ", ";
  }
  cout << pArr[n - 1] << "]" << endl;
}

void shuffle(int *pArr, unsigned n) {
  for (unsigned i = 0u; i < n; i++) {
    std::swap(pArr[i], pArr[rand() % n]);
  }
}

int main() {
  using namespace std;

  srand(68333);

  int *pArr = new int[200];

  for (int i = 0; i < 200; i++) {
    pArr[i] = rand() % 200;
  }

  print(pArr, 200);

  cout << SearchNSort<int>::linearSearch(pArr, 200, 59, compare) << endl;
  cout << SearchNSort<int>::linearSearch(pArr, 200, 159, compare) << endl;
  cout << SearchNSort<int>::linearSearch(pArr, 200, 300, compare) << endl;
  cout << SearchNSort<int>::linearSearch(pArr, 200, 118, compare) << endl;

  SearchNSort<int>::bubbleSort(pArr, 200, compare);

  print(pArr, 200);

  shuffle(pArr, 200);
  print(pArr, 200);

  SearchNSort<int>::selectionSort(pArr, 200, compare);
  print(pArr, 200);

  shuffle(pArr, 200);
  SearchNSort<int>::insertionSort(pArr, 200, compare);
  print(pArr, 200);

  cout << SearchNSort<int>::binarySearch(pArr, 200, 1, compare) << endl;
  cout << SearchNSort<int>::binarySearch(pArr, 200, 199, compare) << endl;
  cout << SearchNSort<int>::binarySearch(pArr, 200, 112, compare) << endl;
  cout << SearchNSort<int>::binarySearch(pArr, 200, 89, compare) << endl;
  cout << SearchNSort<int>::binarySearch(pArr, 200, -1, compare) << endl;
  cout << SearchNSort<int>::binarySearch(pArr, 200, 200, compare) << endl;

  shuffle(pArr, 200);
  SearchNSort<int>::mergeSort(pArr, 200, compare);
  print(pArr, 200);

  shuffle(pArr, 200);
  SearchNSort<int>::quickSort(pArr, 200, compare);
  print(pArr, 200);

  delete[] pArr;

  return EXIT_SUCCESS;
}
