#include <stdio.h>

#define swap(a, b) do { \
  (a) = (a) ^ (b); \
  (b) = (b) ^ (a); \
  (a) = (a) ^ (b); \
} while(0);
  
void
heapify(int arr[], int arr_len, int i)
{
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int max = i;

  if (l < arr_len && arr[l] > arr[max])
    max = l;

  if (r < arr_len && arr[r] > arr[max])
    max = r;

  if (i != max) {
    swap(arr[i], arr[max]);
    heapify(arr, arr_len, max);
  }
  
}


void
heap_sort(int arr[], int arr_len)
{
  for (int i = arr_len / 2 - 1; i >= 0; i--) {
    heapify(arr, arr_len, i);
  }

  for (int i = arr_len - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int
main()
{
  int arr[] = {6, 4, 1, 7, 0, 5, 8, 9};

  heap_sort(arr, sizeof(arr) / sizeof(int));
  for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    printf("%d\n", arr[i]);
}
