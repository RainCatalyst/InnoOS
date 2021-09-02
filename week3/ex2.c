#include <stdio.h>

void bubble_sort(int numbers[], int size)
{
  for (int it = 0; it < size; it++){
    for (int i = 1; i < size; i++){
      if (numbers[i-1] < numbers[i]){
        int temp = numbers[i-1];
        numbers[i-1] = numbers[i];
        numbers[i] = temp;
      }
    }
  }
}

void main()
{
  int numbers[5] = {4, 3, 1, 2, 5};
  bubble_sort(numbers, 5);
  for (int i = 0; i < 5; i++){
    printf("%d ", numbers[i]);
  }
}
