#include <stdio.h>

void
swap(int arr[], int p, int q)
{
  int tmp = arr[p];
  arr[p] = arr[q];
  arr[q] = tmp;
}
  
void
quick_sort(int arr[], int len)
{
  if (len <= 1)
    return;

  int base = arr[0];
  int p = 0, q = len - 1;

  while (p < q) {
    while (arr[q] >= base && q > p)
      q--;
    while (arr[p] <= base && p < q)
      p++;
    swap(arr, p, q);
  }

  swap(arr, 0, q);

  quick_sort(arr, q);
  quick_sort(&arr[q + 1], len - q -1);

}

int
main()
{
  int arr[] = {6, 4, 1, 7, 0, 5, 8, 9};
  int arr1[] = {5, 7, 4, 2, 8, 9, 0};

  quick_sort(arr, sizeof(arr) / sizeof(int));
  quick_sort(arr1, sizeof(arr1) / sizeof(int));
  for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    printf("%d\n", arr[i]);
  printf("\n");
  for (int i = 0; i < sizeof(arr1) / sizeof(int); i++)
    printf("%d\n", arr1[i]);
}
