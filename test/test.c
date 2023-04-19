#include <stdio.h>
int main(void){
    char* name1 = "KM University";
    char name2[] = "KM University";

    printf("%s\n", name1);
    printf("%s\n", name2);

    name2[0] = 'A';
    printf("%s\n", name2);

    name1[0] = 'A';
    printf("%s\n", name1);

    name1[0] = 'A';
    printf("%s\n", name1);

    return 0;
}