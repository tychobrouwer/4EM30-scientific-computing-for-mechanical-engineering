#include "mylib.h"

int check_reset(int amount) {
  Coin coins[10];
  int n;

  n = init(coins);
  split(amount, coins);
  reset(coins, n);

  int i = 0;
  for (i = 0; i < n; i++)
  {
    if (coins[i].count != 0) {
      printf("Reset not resetting coins correctly\n");
      
      return 0;
    }
  }
  printf("Reset working correctly\n");
  
  return 1;
}

int check_valid(int amount, int expected) {
  int valid_check = valid(amount);

  if (valid_check && !expected || !valid_check && expected) {
    printf("Valid not working correctly\n");

    return 0;
  }

  printf("Valid working correctly\n");
  
  return 1;
}

int main(void)
{
  int check_r = check_reset(375);
  int check_v = check_valid(375, 1);
  int check_v_2 = check_valid(373, 0);

  return 0;
}

