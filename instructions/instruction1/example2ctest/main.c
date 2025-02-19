/****************************************************************************
 *                                                                          *
 * File    : main.c  part of: example2ctest                                 *
 *                                                                          *
 * Purpose : Simple program that calculates the coins in which a certain    *
 *           amount can be broken down.                                     *
 *                                                                          *
 * History : Date      Reason                                               *
 *           23/01/10  Created by Joris Remmers                             *
 *                     (in combination wit example2c)                       *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>
#include "../example2c/mylib.h"

int main(void)
{
  Coin coins[10];
  int amount;
  int n;

  n = init(coins);

  // test 1

  printf("Test 1: splitting 100 cent\n");

  amount = 100;

  split(amount, coins);

  if (coins[0].count == 0 &&
      coins[1].count == 1 &&
      coins[2].count == 0 &&
      coins[3].count == 0 &&
      coins[4].count == 0 &&
      coins[5].count == 0)
  {
    report(amount, coins, n);

    printf("Test 1 passed\n");
  }
  else
  {
    report(amount, coins, n);

    printf("Test 1 failed\n");
  }

  reset(coins, n);

  // test 2

  printf("\nTest 2: splitting 780 cent\n\n");

  amount = 780;

  split(amount, coins);

  if (coins[0].count == 3 &&
      coins[1].count == 1 &&
      coins[2].count == 1 &&
      coins[3].count == 1 &&
      coins[4].count == 1 &&
      coins[5].count == 0)
  {
    report(amount, coins, n);

    printf("Test 2 passed\n");
  }
  else
  {
    report(amount, coins, n);

    printf("Test 2 failed\n");
  }

  reset(coins, n);

  // test 3

  printf("\nTest 3: resetting coin counters\n\n");

  coins[0].count = 3;
  coins[1].count = 1;
  coins[2].count = 1;
  coins[3].count = 1;
  coins[4].count = 1;
  coins[5].count = 4;

  reset(coins, n);

  if (coins[0].count == 0 &&
      coins[1].count == 0 &&
      coins[2].count == 0 &&
      coins[3].count == 0 &&
      coins[4].count == 0 &&
      coins[5].count == 0)
  {
    report(amount, coins, n);

    printf("Test 3 passed\n");
  }
  else
  {
    report(amount, coins, n);

    printf("Test 3 failed\n");
  }

  // Test 4

  printf("\nTest 4.1: check valid amount\n\n");

  amount = 100;

  if (check(amount) == 1)
  {
    printf("Test 4.1 passed\n");
  }
  else
  {
    printf("Test 4.1 failed\n");
  }

  printf("\nTest 4.2: check invalid amount % 5\n\n");

  amount = 6;

  if (check(amount) == 0)
  {
    printf("Test 4.2 passed\n");
  }
  else
  {
    printf("Test 4.2 failed\n");
  }

  printf("\nTest 4.3: check invalid amount > 1000\n\n");

  amount = 1001;

  if (check(amount) == 0)
  {
    printf("Test 4.3 passed\n");
  }
  else
  {
    printf("Test 4.3 failed\n");
  }

  printf("\nTest 4.4: check invalid amount < 0\n\n");

  amount = -1;

  if (check(amount) == 0)
  {
    printf("Test 4.4 passed\n");
  }
  else
  {
    printf("Test 4.4 failed\n");
  }

  return 0;
}
