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

#include "pq_dyn_sorted.h"
#include <stdio.h>


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void clear

  ( PQ*   pq )
{
  pq->count = 0;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

bool isEmpty

  ( PQ*     pq )
  
{
  if ( pq->count == 0 )
  {
    return true;
  }
  else
  {
    return false;
  }
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void put

  ( PQ*      pq   , 
    ITEM     item )
{
  int i=0;

  for ( i = 0 ; i < pq->count ; i++ )
  {
    if ( item.prio > pq->items[i].prio )
    {
      break;
    }
  }
  
  int iInsert = i;

  for ( i = pq->count ; i > iInsert ; i-- )
  {
    pq->items[i] = pq->items[i-1];
  }
   
  pq->items[iInsert] = item;

  pq->count++;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

ITEM getPrio

  ( PQ*     pq )
  
{
  pq->count = pq->count - 1;

  return pq->items[ pq->count ];
}
