def heapify(arr, arr_len, i):
    max = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < arr_len and arr[l] > arr[max]:
        max = l
    if r < arr_len and arr[r] > arr[max]:
        max = r
    if max != i:
        arr[i], arr[max] = arr[max], arr[i]
        heapify(arr, arr_len, max)

def heap_sort(arr, arr_len):
    for i in range(arr_len / 2 -1, -1, -1):
        heapify(arr, arr_len, i)
    for i in range(arr_len - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)
        print arr

arr = [5, 7, 4, 2, 8, 9, 0]

heap_sort(arr, len(arr))
