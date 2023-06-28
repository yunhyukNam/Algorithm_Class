#include <stdio.h>

int main(void) {
  int a;
  scanf("%d", &a);

  for (int i = 0; i <= (a-1); i++) {
    if (a % i == 0) {
      printf("%d로 나뉘어지므로 prime이 아닙니다.", i);
    } 
    else {
        printf("%d는 prime", a);
    }
  }

  return 0;
}