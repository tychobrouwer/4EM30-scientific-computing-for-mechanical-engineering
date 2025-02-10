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

  int i;

  clear ( pq );

  item.data = "Star Wars"; 
  item.prio = 10;
  put( pq , item );

  item.data = "Luke Skywalker";
  item.prio = 42;
  put( pq , item );

  item.data = "Obi-Wan Kenobi";
  item.prio = 7;
  put( pq , item );

  item.data = "Darth Vader";
  item.prio = 99;
  put( pq , item );

  item.data = "Princess Leia";
  item.prio = 15;
  put( pq , item );

  for ( i = 0 ; i < 2 ; i++ )
  {
    item = getPrio( pq );
    printf("Get prio %3d : %s\n",item.prio,item.data);
  }

  item.data = "Han Solo";
  item.prio = 31;
  put( pq , item );

  for ( i = 0 ; i < 4 ; i++ )
  {
    item = getPrio( pq );
    printf("Get prio %3d : %s\n",item.prio,item.data);
  }

  return 0;
}
