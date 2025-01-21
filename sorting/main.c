#include <stdio.h>

#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void print_arr(int arr[], int size);
void print_str_arr(char *str, int arr[], int size);
void print_arr_with_wall(int wall, int arr[], int size);
void selection_sort(int arr[], int size);
void insert_sort(int arr[], int size);
void move_part_up_by_one(int start, int count, int arr[]);

int main()
{
    int arr[] = {5, 3, 3, 7, 9, 4, 5, 6, 1, 2, 8, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

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
    for (size_t i = 1; i < size; i++)
    {
        print_arr_with_wall(i, arr, size);
        // int selected = arr[i];
        for (size_t u = 0; u < i; u++)
        {
            if (arr[i] < arr[u])
            {
                int tmp = arr[i];
                move_part_up_by_one(u, i-u, arr);
                arr[u] = tmp;
                break;
            }
        }
    }
}

void move_part_up_by_one(int start, int count, int arr[]) {
    for (size_t i = start; i < start+count; i++)
    {
        arr[i] = arr[i];
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
        if (i+1 == wall){
            printf("|");
        }
        else {
            printf(" ");
        }
    }
    printf("\n");
}