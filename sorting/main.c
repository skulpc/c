#include <stdio.h>

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void print_arr(int arr[], int size);
void print_str_arr(char *str, int arr[], int size);
void print_arr_with_wall(int wall, int arr[], int size);
void selection_sort(int arr[], int size);
void insert_sort(int arr[], int size);
int move_one_element(int from, int to, int arr[], int size);

int main()
{
  printf("\n");
  int arr[] = {7, 2, 4, 1, 5, 3, 6};
  // int arr[] = {2, 4, 1, 5, 7, 3, 6};

  // print_arr(arr, SIZE(arr));
  // move_one_element(SIZE(arr) - 1, 0, arr, SIZE(arr));
  // print_arr(arr, SIZE(arr));

  // selection_sort(arr, SIZE(arr));
  // print_str_arr("selection sort:\n", arr, SIZE(arr));

  insert_sort(arr, SIZE(arr));
  print_str_arr("insert sort:\n", arr, SIZE(arr));
}

void selection_sort(int arr[], int size)
{
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
    int tmp = arr[i];
    arr[i] = arr[min];
    arr[min] = tmp;
  }
}

void insert_sort(int arr[], int size)
{
  for (size_t i = 1; i < size; i++) //TODO: size - 1?
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
  for (size_t i = 0; i < size; i++)
  {
    printf("%d", arr[i]);
    if (i + 1 == wall)
    {
      printf("|");
    }
    else
    {
      printf(" ");
    }
  }
  printf("\n");
}