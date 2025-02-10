//------------------------------------------------------------------------------
//  
// Monthly savings calculator (runtime 10 years)
//
// (c) 2020-2024 Joris Remmers, TU/e
//
//------------------------------------------------------------------------------

#include <stdio.h>
#define MAXRUNTIME 120
#define MONTHSPERYEAR 12

int main(void)
{
  float monthlyDeposit = 0.0;
  float totalAmount = 0.0;
  float rate = 0.0;

  int   iMonth = 0;
  
  printf ( "Enter the monthly deposit: " );
  scanf  ("%f",&monthlyDeposit);
  
  printf ( "Enter the annual interest rate(in %%) : " );
  scanf  ("%f",&rate);
  
  rate = 0.01*rate/MONTHSPERYEAR;

  for( iMonth = 1; iMonth <= MAXRUNTIME ; iMonth++ )
  {
    totalAmount += monthlyDeposit;
    totalAmount *= (1.0 + rate );
    
    printf("After %4d months, the amount is %8.2f euros\n",iMonth,totalAmount);
  }

  return 0;
}
