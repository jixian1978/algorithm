#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

typedef struct pair pair_t;

struct pair {
  const char* prefix;
  const char* words;
  pair_t* next;
};

#define min(a, b) ((a) < (b) ? (a) : (b))

int
compare(const char* a, const char* b)
{
  int a_len = strlen(a);
  int b_len = strlen(b);

  for (int i = 0; i < min(a_len, b_len); i++) {
    if (a[i] > b[i])
      return 1;
    else if (a[i] < b[i])
      return -1;
  }

  if (a_len > b_len)
    return 1;
  else if (a_len < b_len)
    return -1;
  else
    return 0;
}

#define swap(a, b, type) do {\
  type tmp; \
  tmp = a; \
  a = b; \
  b = tmp; \
} while(0);

void
heapify(const char* words[], int len, int i)
{
  int max = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < len && compare(words[l], words[max]) > 0)
    max = l;
  if (r < len && compare(words[r], words[max]) > 0)
    max = r;
  if (max != i) {
    swap(words[i], words[max], const char*);
    heapify(words, len, max);
  }
}

void
heap_sort(const char* words[], int len)
{
  for (int i = len / 2 - 1; i >= 0; i--) {
    heapify(words, len, i);
  }

  for (int i = len - 1; i > 0; i--) {
    swap(words[0], words[i], const char*);
    heapify(words, i, 0);
  }
}

int
is_prefix(const char* a, const char* b)
{
  int a_len = strlen(a);
  int b_len = strlen(b);
  for (int i = 0; i < min(a_len, b_len); i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }

  return 1;
}

pair_t*
get_prefix_words(const char* words[], int len)
{
  heap_sort(words, len);

  pair_t* tail = NULL;
  pair_t* head = NULL;

  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (is_prefix(words[i], words[j])) {
        pair_t* cur = malloc(sizeof(pair_t));
        cur->prefix = words[i];
        cur->words = words[j];
        cur->next = NULL;
        if (head == NULL) {
          head = tail = cur;
        } else {
          tail->next = cur;
          tail = cur;
        }
      } else {
        break;
      }
    }
  }

  return head;
}
  
int
main()
{
  const char* words[] = {"app", "apple", "cat", "car", "apples", "dogs", "cars"};

  pair_t* head = get_prefix_words(words, sizeof(words) / sizeof(const char*));

  while (head) {
    printf("%s, %s\n", head->prefix, head->words);
    head = head->next;
  }
}
