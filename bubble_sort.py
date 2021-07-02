arr = [5, 7, 4, 2, 8, 9, 0]

for i in range(len(arr), 1, -1):
    for j in range(1, i):
        if arr[j - 1] > arr[j]:
            tmp = arr[j - 1]
            arr[j - 1] = arr[j]
            arr[j] = tmp


print arr
