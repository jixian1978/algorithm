def heapify(words, size, i):
    m = i;
    l = 2 * i + 1
    r = 2 * i + 2
    if l < size and words[l] > words[m]:
        m = l
    if r < size and words[r] > words[m]:
        m = r
    if m != i:
        words[i], words[m] = words[m], words[i]
        heapify(words, size, m)


def heap_sort(words):
    for i in range(len(words) / 2 - 1, -1, -1):
        heapify(words, len(words), i)
    for i in range(len(words) - 1, 0, -1):
        words[0], words[i] = words[i], words[0]
        heapify(words, i, 0)

def get_prefix_words(words):
    heap_sort(words)
    res = []
    for i in range(len(words)):
        for j in range(i + 1, len(words)):
            if words[j].startswith(words[i]):
                res.append((words[i], words[j]))
            else:
                break
    return res


words = ["app", "apple", "cat", "car", "apples", "dogs", "cars"]

prefix_words = get_prefix_words(words)

for pair in prefix_words:
    print pair
