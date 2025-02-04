#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void print_arr(int arr[], int size);
void print_str_arr(char *str, int arr[], int size);
void print_arr_with_wall(int wall, int arr[], int size);
void print_arr_with_char(int wall, char c, int arr[], int size);
void shuffle(int arr[], int size);

void selection_sort(int arr[], int size);
void insert_sort(int arr[], int size);
void bubble_sort(int arr[], int size);
void shaker_sort(int arr[], int size);
void binary_insertion_sort(int arr[], int size);

int move_one_element(int from, int to, int arr[], int size);

int main()
{
  printf("\n");
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  // int arr[] = {2, 4, 1, 5, 7, 3, 6};

  // print_arr(arr, SIZE(arr));
  // move_one_element(SIZE(arr) - 1, 0, arr, SIZE(arr));
  // print_arr(arr, SIZE(arr));

  shuffle(arr, SIZE(arr));

  printf("selection sort:\n");
  selection_sort(arr, SIZE(arr));
  print_arr(arr, SIZE(arr));

  shuffle(arr, SIZE(arr));

  printf("insert sort:\n");
  insert_sort(arr, SIZE(arr));
  print_arr(arr, SIZE(arr));

  shuffle(arr, SIZE(arr));

  printf("bubble sort:\n");
  bubble_sort(arr, SIZE(arr));
  print_arr(arr, SIZE(arr));

  shuffle(arr, SIZE(arr));

  printf("shaker sort:\n");
  shaker_sort(arr, SIZE(arr));
  print_arr(arr, SIZE(arr));

  shuffle(arr, SIZE(arr));

  printf("binary insertion sort:\n");
  binary_insertion_sort(arr, SIZE(arr));
  print_arr(arr, SIZE(arr));
}

void shuffle(int arr[], int size)
{
  srand(time(NULL));
  for (size_t i = 0; i < size; i++)
  {
    int r = rand() % size;
    // move_one_element(i, r, arr, size);
    arr[i] = r + 1;
  }
}

void selection_sort(int arr[], int size)
{
  print_arr(arr, size);
  for (size_t i = 0; i < size - 1; i++)
  {
    int min = i;
    for (size_t u = i + 1; u < size; u++)
    {
      if (arr[u] < arr[min])
      {
        min = u;
      }
    }
    if (min != i)
    {
      move_one_element(min, i, arr, size);
    }
    print_arr_with_wall(i + 1, arr, size);
  }
}

void insert_sort(int arr[], int size)
{
  for (size_t i = 1; i < size; i++) // TODO: size - 1?
  {
    print_arr_with_wall(i, arr, size);
    // int selected = arr[i];
    for (size_t u = 0; u < i; u++)
    {
      if (arr[i] < arr[u])
      {
        move_one_element(i, u, arr, size);
        break;
      }
    }
  }
}

void bubble_sort(int arr[], int size)
{
  for (size_t i = 0; i < size - 1; i++)
  {
    print_arr_with_wall(size - i, arr, size);

    int switched = -1;
    for (size_t u = 1; u < size - i; u++)
    {
      if (arr[u - 1] > arr[u])
      {
        int tmp = arr[u - 1];
        arr[u - 1] = arr[u];
        arr[u] = tmp;

        switched = u;
      }
    }
    if (switched == -1)
    {
      break;
    }
    else
    {
      i = size - (switched + 1);
    }
  }
}

// (double sided bubble sort)
void shaker_sort(int arr[], int size)
{
  int high_zone = size;
  int low_zone = -1;

  while (1)
  {
    print_arr_with_char(high_zone, '(', arr, size);

    int switched = low_zone;
    for (size_t u = low_zone + 2; u < high_zone; u++)
    {
      if (arr[u - 1] > arr[u])
      {
        int tmp = arr[u - 1];
        arr[u - 1] = arr[u];
        arr[u] = tmp;

        switched = u;
      }
    }
    if (switched == low_zone)
    {
      break;
    }
    else
    {
      high_zone = switched;
    }

    print_arr_with_char(low_zone, ')', arr, size);

    switched = high_zone;
    for (size_t u = high_zone - 1; u > low_zone + 1; u--)
    {
      if (arr[u - 1] > arr[u])
      {
        int tmp = arr[u - 1];
        arr[u - 1] = arr[u];
        arr[u] = tmp;

        switched = u;
      }
    }
    if (switched == high_zone)
    {
      break;
    }
    else
    {
      low_zone = switched - 1;
    }
  }
}

void binary_insertion_sort(int arr[], int size)
{
  for (size_t i = 1; i < size; i++) // TODO: size - 1?
  {
    printf("\n");
    print_arr_with_wall(i, arr, size);
    // int selected = arr[i];
    int p = i;
    int l = 0;
    while (p != l)
    {
      int mid = (l + p) / 2;
      printf("%d mid\n", mid);
      if (arr[i] < arr[mid])
      {
        p = mid;
      }
      else
      {
        l = mid + 1;
      }
      print_arr_with_char(l, 'L', arr, size);
      print_arr_with_char(p, 'P', arr, size);
    }
    move_one_element(i, l, arr, size);
  }
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

void print_arr(int arr[], int size)
{
  for (size_t i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void print_str_arr(char *str, int arr[], int size)
{
  printf("%s", str);
  for (size_t i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void print_arr_with_wall(int wall, int arr[], int size)
{
  print_arr_with_char(wall, '|', arr, size);
}

void print_arr_with_char(int wall, char c, int arr[], int size)
{
  if (wall == 0) {
    printf("%c", c);
  }
  else {
    printf(" ");
  }
  for (size_t i = 0; i < size; i++)
  {
    printf("%d", arr[i]);
    if (i + 1 == wall)
    {
      printf("%c", c);
    }
    else
    {
      printf(" ");
    }
  }
  printf("\n");
}