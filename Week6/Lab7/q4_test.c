#include <stdio.h>

int main(void) {
    int s1_, s2_, s3_, s4_;
    char s1[10], s2[10], s3[10], s4[10];

    printf("Please enter first string: ");
    scanf("%s", s1);

    printf("Please enter second string: ");
    scanf("%s", s2);

    printf("Please enter third string: ");
    scanf("%s", s3);

    printf("Please enter fourth string: ");
    scanf("%s", s4);

    sscanf(s1, "%d", &s1_);
    sscanf(s2, "%d", &s2_);
    sscanf(s3, "%d", &s3_);
    sscanf(s4, "%d", &s4_);

    int sum = s1_ + s2_ + s3_ + s4_;
    printf("Sum: %d\n", sum);

    return 0;
}
