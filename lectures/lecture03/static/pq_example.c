/*******************************************************************************
*   Example program to test the performance of different
*   priority queue implementations with static memory 
*   allocation.
*
* (c) 2019-2022, Joris Remmers (Mechanical Engineering, TUE)
*
* 02-2019  Version 1.
* 01-2022  Cleaning up code
*******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Uncomment one of the five methods.

//#include "pq_unsorted.h"
//#include "pq_sorted.h"
//#include "pq_sorted_bs.h"
//#include "pq_linked.h"
#include "pq_binaryheap.h"

int main ( void ) 
{
  PQ   pq;
  ITEM item;

  clear ( &pq );

  clock_t t1,t2;
  
  double timeSpent;

  t1 = clock();

  int i;

  for ( i = 0 ; i < 1000 ; i++ )
  {
    item.data = "Star Wars";
    item.prio = rand()%1000+2;
    put( &pq , item );
  }

  /* here, do your time-consuming job */

  t2 = clock();
  timeSpent = (double)(t2 - t1) / CLOCKS_PER_SEC;

  printf ( "Time spend: %e \n", timeSpent );
  t1 = clock();

  for ( i = 0 ; i < 500 ; i++ )
  {
    item = getPrio( &pq );
  }

  t2 = clock();
  timeSpent = (double)(t2 - t1) / CLOCKS_PER_SEC;

  printf ( "Time spend: %e \n", timeSpent );
  t1 = clock();

  for ( i = 0 ; i < 500 ; i++ )
  {
    item.data = "Avengers";
    item.prio = rand()%20;
    put( &pq , item );
  }

  t2 = clock();
  timeSpent = (double)(t2 - t1) / CLOCKS_PER_SEC;

  printf ( "Time spend: %e \n", timeSpent );
  t1 = clock();

  return 0;
}
