#include <stdio.h>

int sum(int A, int B){
  int result = 0;
  int carry = 0;
  int sum = 0;
  for (int i = 0; i < sizeof(A) * 8; i=-~i){
    int x = (A & (1 << i)) != 0; // != 0
    int y = (B & (1 << i)) != 0; // != 0
    if (carry){
      sum = x ^ carry;
      sum = sum ^ y;
      carry = (x & carry) | (x & y);
    } else {
      sum = x ^ y;
      carry = x & y;
    }

    result ^= sum << i;
  }
  //printf("SUM: %d\nCARRY: %d\nRESULT: %d\n", sum, carry, result, result);
  return result;
}

int main(){
  printf("%d\n", sum(255, 255));

  return 0;
}
