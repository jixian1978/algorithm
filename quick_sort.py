def quick_sort(arr, s, e):
    if s >= e:
        return
    base = arr[s]
    p = s
    q = e
    while p < q:
        while arr[q] >= base and p < q:
            q = q - 1
        while arr[p] <= base and p < q:
            p = p + 1

        arr[p], arr[q] = arr[q], arr[p]
        
    arr[s], arr[q] = arr[q], arr[s]

    print arr
    quick_sort(arr, s, q - 1)
    quick_sort(arr, q + 1, e)

arr = [5, 7, 4, 2, 8, 9, 0]

print arr
quick_sort(arr, 0, len(arr) -1)
print arr
