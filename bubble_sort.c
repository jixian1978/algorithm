#include <stdio.h>

void
bubble_sort(int arr[], int arr_len)
{
  for (int i = arr_len; i >= 2; i--)
    for (int j = 1; j < i; j++)
      if (arr[j - 1] > arr[j]) {
        int tmp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = tmp;
      }
}

int
main()
{
  int arr[] = {6, 4, 1, 7, 0, 5, 8, 9};

  bubble_sort(arr, sizeof(arr) / sizeof(int));
  for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    printf("%d\n", arr[i]);
}
