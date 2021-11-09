#include "SearchNSort.h"
#include <chrono>
#include <cstdlib>
#include <iostream>

int compare(const int &x, const int &y) { return (x - y); }

void fill(int *pA, int n) {
  for (int i = 0; i < n; i++) {
    pA[i] = rand();
  }
}

bool isSorted(int *pArr, unsigned n) {
  for (unsigned i = 0u; i < n - 1u; i++) {
    if (pArr[i] > pArr[i + 1]) {
      return false;
    }
  }
  return true;
}

void shuffle(int *pArr, unsigned n) {
  for (unsigned i = 0u; i < n; i++) {
    std::swap(pArr[i], pArr[rand() % n]);
  }
}

int main(int argc, char **ppszArgs) {
  using namespace std;

  srand(time(NULL));

  int powerCap = atoi(ppszArgs[1]);

  cout << "p\tn\tbs\tis\tss\tms\tqs" << endl;

  int n = 256;

  for (int power = 8; power <= powerCap; power++) {
    int *pArr = new int[n];

    fill(pArr, n);

    cout << power << "\t" << n << "\t";

    // bubblesort test
    long double dur = 0;
    for (int i = 0; i < 10; i++) {
      shuffle(pArr, n);
      // do the sort
      auto begin = chrono::high_resolution_clock::now();
      SearchNSort<int>::bubbleSort(pArr, n, compare);
      auto end = chrono::high_resolution_clock::now();
      if (!isSorted(pArr, n)) {
        cerr << "\n***** UNSORTED AFTER BUBBLESORT!" << endl;
        return EXIT_FAILURE;
      }
      dur +=
          chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    }
    dur /= 10;
    cout << dur << "\t";

    // insertion sort test
    dur = 0;
    for (int i = 0; i < 10; i++) {
      shuffle(pArr, n);
      // do the sort
      auto begin = chrono::high_resolution_clock::now();
      SearchNSort<int>::insertionSort(pArr, n, compare);
      auto end = chrono::high_resolution_clock::now();
      if (!isSorted(pArr, n)) {
        cerr << "\n***** UNSORTED AFTER INSERTIONSORT!" << endl;
        return EXIT_FAILURE;
      }
      dur +=
          chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    }
    dur /= 10;
    cout << dur << "\t";

    // selection sort test
    dur = 0;
    for (int i = 0; i < 10; i++) {
      shuffle(pArr, n);
      // do the sort
      auto begin = chrono::high_resolution_clock::now();
      SearchNSort<int>::selectionSort(pArr, n, compare);
      auto end = chrono::high_resolution_clock::now();
      if (!isSorted(pArr, n)) {
        cerr << "\n***** UNSORTED AFTER SELECTIONSORT!" << endl;
        return EXIT_FAILURE;
      }
      dur +=
          chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    }
    dur /= 10;
    cout << dur << "\t";

    // merge sort test
    dur = 0;
    for (int i = 0; i < 10; i++) {
      shuffle(pArr, n);
      // do the sort
      auto begin = chrono::high_resolution_clock::now();
      SearchNSort<int>::mergeSort(pArr, n, compare);
      auto end = chrono::high_resolution_clock::now();
      if (!isSorted(pArr, n)) {
        cerr << "\n***** UNSORTED AFTER MERGESORT!" << endl;
        return EXIT_FAILURE;
      }
      dur +=
          chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    }
    dur /= 10;
    cout << dur << "\t";

    // quick sort test
    dur = 0;
    for (int i = 0; i < 10; i++) {
      shuffle(pArr, n);
      // do the sort
      auto begin = chrono::high_resolution_clock::now();
      SearchNSort<int>::quickSort(pArr, n, compare);
      auto end = chrono::high_resolution_clock::now();
      if (!isSorted(pArr, n)) {
        cerr << "\n***** UNSORTED AFTER QUICKSORT!" << endl;
        return EXIT_FAILURE;
      }
      dur +=
          chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    }
    dur /= 10;
    cout << dur << "\t";

    cout << endl;
    delete[] pArr;

    n *= 2;
  }

  return EXIT_SUCCESS;
}
