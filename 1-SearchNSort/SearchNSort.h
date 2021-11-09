#include <utility>

/**
 * Templated class with functions for searching and sorting.
 */

template <class T> class SearchNSort {
public:
  /**
   * Perform a binary search on an array.
   *
   * \param pArr Pointer to the first element of the array to search.
   * The array must be sorted in ascending order.
   * \param n Number of elements in the array
   * \param key Key value to search for
   * \param compare Pointer to function used to compare two elements;
   * must return negative if x < y, zero if x == y, or positive if
   * x > y.
   * \return Index of the first occurence of key in pArr, or -1 if key
   * isn't found in the array.
   */
  static int binarySearch(const T *pArr, unsigned n, const T &key,
                          int (*compare)(const T &x, const T &y));

  /**
   * Sort an array using an optimized bubble sort algorithm.
   *
   * \param pArr Pointer to the first element of the array to sort.
   * \param n Size of the array.
   * \param compare Pointer to function used to compare two elements;
   * must return negative if x < y, zero if x == y, or positive if
   * x > y.
   */
  static void bubbleSort(T *pArr, unsigned n,
                         int (*compare)(const T &x, const T &y));

  /**
  * Sort an array using a insertion sort algorithm.
  *
  * \param pArr Pointer to the first element of the array to sort.
  * \param n Size of the array.
  * \param compare Pointer to function used to compare two elements;
  * must return negative if x < y, zero if x == y, or positive if
  * x > y.
  */
  static void insertionSort(T *pArr, unsigned n,
                            int (*compare)(const T &x, const T &y));

  /**
   * Perform a linear search on an array.
   *
   * \param pArr Pointer to the first element of the array to search.
   * \param n Number of elements in the array
   * \param key Key value to search for
   * \param compare Pointer to function used to compare two elements;
   * must return negative if x < y, zero if x == y, or positive if
   * x > y.
   * \return Index of the first occurence of key in pArr, or -1 if key
   * isn't found in the array.
   */
  static int linearSearch(const T *pArr, unsigned n, const T &key,
                          int (*compare)(const T &x, const T &y));

  /**
   * Sort an array using a merge sort algorithm.
   *
   * \param pArr Pointer to the first element of the array to sort.
   * \param n Size of the array.
   * \param compare Pointer to function used to compare two elements;
   * must return negative if x < y, zero if x == y, or positive if
   * x > y.
   */
  static void mergeSort(T *pArr, unsigned n,
                        int (*compare)(const T &x, const T &y));

  /**
   * Sort an array using a quicksort algorithm.
   *
   * \param pArr Pointer to the first element of the array to sort.
   * \param n Size of the array.
   * \param compare Pointer to function used to compare two elements;
   * must return negative if x < y, zero if x == y, or positive if
   * x > y.
   */
  static void quickSort(T *pArr, unsigned n,
                        int (*compare)(const T &x, const T &y)) {

    quickSort(pArr, 0, n - 1, compare);
  }

  /**
   * Sort an array using a selection sort algorithm.
   *
   * \param pArr Pointer to the first element of the array to sort.
   * \param n Size of the array.
   * \param compare Pointer to function used to compare two elements;
   * must return negative if x < y, zero if x == y, or positive if
   * x > y.
   */
  static void selectionSort(T *pArr, unsigned n,
                            int (*compare)(const T &x, const T &y));

private:
  /**
   * Merge two sorted portions of an array into another.
   *
   * \param pA Array containing two sorted portions.
   * \param pB Scratch array destination.
   * \param left Sorted portions are pA[left, mid - 1] and
   * pA[mid, right - 1].
   * \param right
   * \param mid
   * \param compare Pointer to function used to compare two elements;
   * must return negative if x < y, zero if x == y, or positive if
   * x > y.
   */
  static void merge(T *pA, T *pB, int left, int right, int mid,
                    int (*compare)(const T &x, const T &y));

  /**
   * Recursive helper function for mergeSort().
   *
   * \param pA Pointer to first element of the array to sort.
   * \param pB Pointer to first element of scratch array.
   * \param left Index of leftmost element in the section to be
   * sorted.
   * \param right One past index of rightmost element in the section
   * to be sorted.
   * \param compare Pointer to function used to compare two elements;
   * must return negative if x < y, zero if x == y, or positive if
   * x > y.
   */
  static void mergeSort(T *pA, T *pB, int left, int right,
                        int (*compare)(const T &x, const T &y));

  /**
   * Partitioning helper function for quickSort().
   *
   * \param pArr Pointer to first element of the array to sort.
   * \param lo Index of leftmost element in range being sorted.
   * \param hi Index of rightmost element in range being sorted.
   * \param compare Pointer to function used to compare two elements;
   * must return negative if x < y, zero if x == y, or positive if
   * x > y.
   * \return index in [lo, hi] such that everything to the left is
   * less than or equal to everything to the right.
   */
  static int partition(T *pArr, int lo, int hi,
                       int (*compare)(const T &x, const T &y));

  /**
   * Recursive helper function for quickSort().
   *
   * \param pArr Pointer to first element of the array to sort.
   * \param lo Index of leftmost element in range being sorted.
   * \param hi Index of rightmost element in range being sorted.
   * \param compare Pointer to function used to compare two elements;
   * must return negative if x < y, zero if x == y, or positive if
   * x > y.
   */
  static void quickSort(T *pArr, int lo, int hi,
                        int (*compare)(const T &x, const T &y));
};

/*
 * Implementation of iterative binarySearch() function.
 */
template <class T>
int SearchNSort<T>::binarySearch(const T *pArr, unsigned n, const T &key,
                                 int (*comp)(const T &x, const T &y)) {

  int i = 0, j = n - 1, mid, res;
  while (i <= j) {
    mid = (i + j) / 2;
    res = comp(pArr[mid], key);
    if (res == 0) {
      return mid;
    } else if (res > 0) {
      j = mid - 1;
    } else {
      i = mid + 1;
    }
  }

  return -1;
}

/*
 * Implementation of bubbleSort() function.
 */
template <class T>
void SearchNSort<T>::bubbleSort(T *pArr, unsigned n,
                                int (*comp)(const T &x, const T &y)) {

  do {
    unsigned newN = 0u;
    for (unsigned i = 1u; i < n; i++) {
      if (comp(pArr[i - 1], pArr[i]) > 0) {
        std::swap(pArr[i - 1], pArr[i]);
        newN = i;
      }
    }
    n = newN;
  } while (n != 0u);
}

/*
 * Implementation of insertionSort() function.
 */
template <class T>
void SearchNSort<T>::insertionSort(T *pArr, unsigned n,
                                   int (*comp)(const T &x, const T &y)) {

  for (unsigned i = 1u; i < n; i++) {
    unsigned j = i;
    while (j > 0u && comp(pArr[j - 1], pArr[j]) > 0) {
      std::swap(pArr[j], pArr[j - 1]);
      j--;
    }
  }
}

/*
 * Implementation of linearSearch() function.
 */
template <class T>
int SearchNSort<T>::linearSearch(const T *pArr, unsigned n, const T &key,
                                 int (*comp)(const T &x, const T &y)) {

  for (unsigned i = 0u; i < n; i++) {
    if (comp(pArr[i], key) == 0) {
      return i;
    }
  }

  // not found? Return -1 flag value
  return -1;
}

/*
 * Implementation of private merge() function.
 */
template <class T>
void SearchNSort<T>::merge(T *pA, T *pB, int left, int right, int mid,
                           int (*comp)(const T &x, const T &y)) {

  int i = left, j = mid;

  for (int k = left; k < right; k++) {
    if (i < mid && (j >= right || comp(pA[i], pA[j]) <= 0)) {
      pB[k] = pA[i++];
    } else {
      pB[k] = pA[j++];
    }
  }
}

/*
 * Implementation of public mergeSort() function.
 */
template <class T>
void SearchNSort<T>::mergeSort(T *pArr, unsigned n,
                               int (*comp)(const T &x, const T &y)) {
  // create temporary array
  T *pB = new T[n];

  // do the sorting
  mergeSort(pArr, pB, 0, n, comp);

  // free temporary array
  delete[] pB;
}

/*
 * Implementation of private mergeSort() helper function.
 */
template <class T>
void SearchNSort<T>::mergeSort(T *pA, T *pB, int left, int right,
                               int (*comp)(const T &x, const T &y)) {

  // array of size one or less is already sorted!
  if ((right - left) < 2) {
    return;
  }

  // otherwise, split, sort, and merge
  int mid = (left + right) / 2;
  mergeSort(pA, pB, left, mid, comp);
  mergeSort(pA, pB, mid, right, comp);
  merge(pA, pB, left, right, mid, comp);

  // copy from scratch back to original array
  for (int i = left; i < right; i++) {
    pA[i] = pB[i];
  }
}

/*
 * Implementation of partition() helper function.
 */
template <class T>
int SearchNSort<T>::partition(T *pArr, int lo, int hi,
                              int (*compare)(const T &x, const T &y)) {

  // arbitrarily choose first value in range as pivot value
  const T &pivot = pArr[lo];

  // indices to slide right and left
  int i = lo - 1;
  int j = hi + 1;

  while (true) {
    // slide i right until we find value >= pivot
    while (compare(pArr[++i], pivot) < 0)
      ; // empty loop body

    // slide j left until we find value <= pivot
    while (compare(pArr[--j], pivot) > 0)
      ; // empty loop body

    // if the indices have crossed, j is the pivot index
    if (i >= j) {
      return j;
    }

    // if not, swap the out of place elements and continue
    // sliding i and j
    std::swap(pArr[i], pArr[j]);
  }
}

/*
 * Implementation of recursive quickSort() helper function.
 */
template <class T>
void SearchNSort<T>::quickSort(T *pArr, int lo, int hi,
                               int (*compare)(const T &x, const T &y)) {

  // portion of size 0 or 1 is already sorted!
  if (lo < hi) {

    // array portion of array so pArr[lo, p - 1] is <= pArr[p],
    // and pArr[p + 1, hi) is >= pArr[p]
    int p = partition(pArr, lo, hi, compare);

    // recursively sort left and right halves
    quickSort(pArr, lo, p, compare);
    quickSort(pArr, p + 1, hi, compare);
  }
}

/*
 * Implementation of selectionSort() function.
 */
template <class T>
void SearchNSort<T>::selectionSort(T *pArr, unsigned n,
                                   int (*comp)(const T &x, const T &y)) {
  unsigned i, j, minIndex;

  for (i = 0u; i < n - 1u; i++) {

    minIndex = i;
    for (j = i + 1u; j < n; j++) {
      if (comp(pArr[j], pArr[minIndex]) < 0) {
        minIndex = j;
      }
    }

    if (minIndex != i) {
      std::swap(pArr[i], pArr[minIndex]);
    }
  }
}
