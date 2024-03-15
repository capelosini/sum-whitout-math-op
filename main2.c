#include <stdio.h>
// not working yet
int sum(int x, int y){
  int result = 0;
  int carry = 0;
  int sum = 0;
  do{
    // int a = (x & (1 << i)) != 0; // != 0
    // int b = (y & (1 << i)) != 0; // != 0
    int a = x & 1;
    int b = y & 1;
    x >>= 1;
    y >>= 1;
    sum = a ^ b ^ carry;
    carry = (a & b) | (a & carry) | (b & carry);
    result <<= 1;
    result |= sum;
    printf("A: %d B: %d | Carry: %d Sum: %d\n", a, b, carry, sum);
  } while(x != 0 || y != 0);
  //printf("SUM: %d\nCARRY: %d\nRESULT: %d\n", sum, carry, result, result);
  return result;
}

int main(){
  printf("%d\n", sum(255, 255));

  return 0;
}
