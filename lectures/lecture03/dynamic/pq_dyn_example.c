/*******************************************************************************
*   Example program to test the performance of different
*   priority queue implementations with dynamic memory 
*   allocation.
*
* (c) 2019-2022, Joris Remmers (Mechanical Engineering, TUE)
*
* 02-2019  Version 1.
* 01-2022  Cleaning up code
*******************************************************************************/

#include <stdio.h>
#include <time.h>
//#include "pq_dyn_unsorted.h"
//#include "pq_dyn_sorted.h"
//#include "pq_dyn_sorted_bs.h"
//#include "pq_dyn_linked.h"
#include "pq_dyn_binaryheap.h"
#include <stdlib.h>

#define TOTALITEMS 100000

int main ( void ) 
{
  PQ  *pq = malloc(sizeof( PQ ) + TOTALITEMS*sizeof(ITEM));

  ITEM item;

  clear ( pq );

  clock_t t1,t2;
  
  double timeSpent;

  t1 = clock();

  int i;

  for ( i = 0 ; i < TOTALITEMS/2 ; i++ )
  {
    item.data = "Star Wars";
    item.prio = rand()%10000+1;
    put( pq , item );
  }

  t2 = clock();
  timeSpent = (double)(t2 - t1) / CLOCKS_PER_SEC;

  printf ( "Time spend: %e \n", timeSpent );
  t1 = clock();

  for ( i = 0 ; i < TOTALITEMS/2 ; i++ )
  {
    item = getPrio( pq );
  }

  t2 = clock();
  timeSpent = (double)(t2 - t1) / CLOCKS_PER_SEC;

  printf ( "Time spend: %e \n", timeSpent );
  t1 = clock();

  for ( i = 0 ; i < TOTALITEMS/2 ; i++ )
  {
    item.data = "Avengers";
    item.prio = rand()%20;
    put( pq , item );
  }

  t2 = clock();
  timeSpent = (double)(t2 - t1) / CLOCKS_PER_SEC;

  printf ( "Time spend: %e \n", timeSpent );
  t1 = clock();

  return 0;
}
