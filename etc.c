#include <stdio.h>

int main(void) {
  int a;
  scanf("%d", &a);

  for (int i = 0; i <= (a-1); i++) {
    if (a % i == 0) {
      printf("%d�� ���������Ƿ� prime�� �ƴմϴ�.", i);
    } 
    else {
        printf("%d�� prime", a);
    }
  }

  return 0;
}