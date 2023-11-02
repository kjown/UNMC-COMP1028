#include <stdio.h>

void add(int a[2][2]);
void subtract(int a[2][2]);
void multiply(int a[2][2]);
void divide(int a[2][2]);
int gcd(int x,int y);

int main(){
    int array[2][2];

    printf("Enter the numerator and denominator of fraction 1: ");
    scanf("%d %d", &array[0][0], &array[0][1]);
    printf("Enter the numerator and denominator of fraction 2: ");
    scanf("%d %d",&array[1][0], &array[1][1]);

    add(array);
    subtract(array);
    multiply(array);
    divide(array);

    return 0;
}

int gcd(int x, int y){
    if(y == 0){
        return x;
    }else{
        return gcd(y,x%y);
    }
}

void add(int a[2][2]){
    int num_x,num_y,total_num, total_deno;

    if(a[0][1]==a[1][1]){
        total_num = a[0][0] + a[1][0];
        total_deno = a[0][1];
    }else{
        num_x = a[0][0] * a[1][1];
        num_y = a[1][0] * a[0][1];
        total_num = num_x + num_y;
        total_deno = a[0][1]*a[1][1];
    }

    int common_divisor = gcd(total_num,total_deno);
    total_num = total_num/common_divisor;
    total_deno = total_deno/common_divisor;

    printf("%d/%d + %d/%d = %d/%d\n", a[0][0], a[0][1], a[1][0], a[1][1], total_num, total_deno);
}

void subtract(int a[2][2]){
    int num_x,num_y,total_num, total_deno;

    if(a[0][1]==a[1][1]){
        total_num = a[0][0] - a[1][0];
        total_deno = a[0][1];
    }else{
        num_x = a[0][0] * a[1][1];
        num_y = a[1][0] * a[0][1];
        total_num = num_x - num_y;
        total_deno = a[0][1]*a[1][1];
    }

    int common_divisor = gcd(total_num,total_deno);
    total_num = total_num/common_divisor;
    total_deno = total_deno/common_divisor;

    printf("%d/%d - %d/%d = %d/%d\n", a[0][0], a[0][1], a[1][0], a[1][1], total_num, total_deno);
}

void multiply(int a[2][2]){
    int total_num, total_deno;
    total_num = a[0][0]*a[1][0];
    total_deno = a[0][1]*a[1][1];

    int common_divisor = gcd(total_num,total_deno);
    total_num = total_num/common_divisor;
    total_deno = total_deno/common_divisor;

    printf("%d/%d * %d/%d = %d/%d\n", a[0][0], a[0][1], a[1][0], a[1][1], total_num, total_deno);
}

void divide(int a[2][2]){
    int total_num, total_deno;
    total_num = a[0][0]*a[1][1];
    total_deno = a[0][1]*a[1][0];

    int common_divisor = gcd(total_num,total_deno);
    total_num = total_num/common_divisor;
    total_deno = total_deno/common_divisor;

    printf("%d/%d / %d/%d = %d/%d\n", a[0][0], a[0][1], a[1][0], a[1][1], total_num, total_deno);
}