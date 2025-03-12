#include <stdio.h>

#define MAX_SIZE 40

int move_one_element(int from, int to, int arr[], int size);

void addunsorted(int n, int arr[], int size)
{
  if (size < MAX_SIZE)
  {
    arr[size] = n;
  }
}

int removeunsorted(int number, int arr[], int size)
{
  int removed_count = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (number == arr[i])
    {
      move_one_element(i, size - 1, arr, size);
      i--;
      size--;
      removed_count++;
    }
  }
  return removed_count;
}

int findunsorted(int number, int arr[], int size)
{
  for (size_t i = 0; i < size; i++)
  {
    if (number == arr[i])
      return i;
  }
  return -1;
}

void addsorted(int n, int arr[], int size)
{
  int l_i = 0;
  int r_i = size;
  while (l_i != r_i)
  {
    int m = (l_i + r_i) / 2;
    if (arr[m] >= n)
    {
      r_i = m;
    }
    else
    {
      l_i = m + 1;
    }
  }
  move_one_element(size + 1, l_i, arr, MAX_SIZE);
  arr[l_i] = n;
}

int removesorted(int n, int arr[], int size)
{
  int removedcount = 0;
  int l_i = 0;
  int r_i = size;
  while (l_i != r_i)
  {
    int m = (l_i + r_i) / 2;
    if (arr[m] >= n)
    {
      r_i = m;
    }
    else
    {
      l_i = m + 1;
    }
  }
  while (arr[l_i] == n)
  {
    move_one_element(l_i, size - 1, arr, MAX_SIZE);
    size--;
    removedcount++;
  }
  r_i = l_i;
  while (arr[r_i] == n)
  {
    move_one_element(r_i, size - 1, arr, MAX_SIZE);
    size--;
    r_i--;
    removedcount++;
  }

  return removedcount;
}

findsorted(int n, int arr[], int size)
{
  int l_i = 0;
  int r_i = size;
  while (l_i != r_i)
  {
    int m = (l_i + r_i) / 2;
    if (arr[m] >= n)
    {
      r_i = m;
    }
    else
    {
      l_i = m + 1;
    }
  }
  if (arr[l_i] == n)
  {
    return l_i;
  }
  return -1;
}

void print_arr(int arr[], int size)
{
  for (size_t i = 0; i < size; i++)
  {
    printf("%d, ", arr[i]);
  }
}

int main()
{
  int unsorted[MAX_SIZE];
  int unsorted_size = 0;

  for (size_t i = 0; i < 20; i++)
  {
    addunsorted(i, unsorted, unsorted_size++);
  }

  for (size_t i = 0; i < 10; i++)
  {
    unsorted_size -= removeunsorted(i * 2, unsorted, unsorted_size);
  }

  print_arr(unsorted, unsorted_size);
  printf("find 7 %d\n", findunsorted(7, unsorted, unsorted_size));

  int sorted[MAX_SIZE];
  int sorted_size = 0;

  for (size_t i = 1; i < 10; i++)
  {
    addsorted(i * 2, sorted, sorted_size++);
    printf("sorted:");
    print_arr(sorted, sorted_size);
    printf("\n");
  }
  addsorted(7, sorted, sorted_size++);
  addsorted(7, sorted, sorted_size++);
  addsorted(7, sorted, sorted_size++);
  addsorted(9, sorted, sorted_size++);
  addsorted(0, sorted, sorted_size++);
  addsorted(0, sorted, sorted_size++);
  addsorted(0, sorted, sorted_size++);
  addsorted(0, sorted, sorted_size++);
  addsorted(0, sorted, sorted_size++);
  addsorted(43, sorted, sorted_size++);
  addsorted(44, sorted, sorted_size++);
  print_arr(sorted, sorted_size);
  
  printf("find 7 %d\n", findsorted(7, sorted, sorted_size));
  printf("\n");
  for (size_t i = 0; i < 10; i++)
  {
    sorted_size -= removesorted(i * 2, sorted, sorted_size);
  }
  
  print_arr(sorted, sorted_size);
  printf("find 7 %d\n", findsorted(7, sorted, sorted_size));
  printf("\n");
  sorted_size -= removesorted(7, sorted, sorted_size);
  print_arr(sorted, sorted_size);
  printf("\n");
  sorted_size -= removesorted(12, sorted, sorted_size);
  print_arr(sorted, sorted_size);
  printf("\n");

  printf("find 7 %d", findsorted(7, sorted, sorted_size));
}

int move_one_element(int from, int to, int arr[], int size)
{
  if (from >= size || from < 0 || to >= size || to < 0)
  {
    return -1;
  }
  else if (to == from || size <= 1)
  {
    return 0;
  }

  int tmp = arr[from];
  for (size_t i = from; (to > from) ? i < to : i > to;)
  {
    arr[i] = arr[i + ((to > from) ? 1 : -1)];
    // printf("%d -> %d\n", i + ((to > from) ? 1 : -1), i);
    // print_arr(arr, size);

    if (to > from)
    {
      i++;
    }
    else
    {
      i--;
    }
  }
  arr[to] = tmp;

  if (to > from)
  {
    return to - from;
  }
  else
  {
    return from - to;
  }
}