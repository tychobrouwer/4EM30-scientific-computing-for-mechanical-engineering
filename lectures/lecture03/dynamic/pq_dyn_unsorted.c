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

#include "pq_dyn_unsorted.h"
#include <stdio.h>
#include <limits.h>


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void clear

  ( PQ*    pq )
  
{
  pq->count = 0; 
}
//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

bool isEmpty

  ( PQ*      pq )
  
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

  ( PQ*     pq , 
    ITEM    item )
{
  pq->items[pq->count] = item;
  pq->count++;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

ITEM getPrio

  ( PQ*     pq )
  
{
  ITEM prioItem;

  int  minID   = INT_MAX;
  int  minPrio = INT_MAX;   

  int  i;

  for ( i = 0 ; i < pq->count ; i++ ) 
  {
    if ( pq->items[i].prio < minPrio ) 
    {
      minID = i;
      minPrio = pq->items[i].prio;
    }
  }

  prioItem = pq->items [ minID ];
  
  if ( minID < (pq->count-1) )
  {
    pq->items [ minID ] = pq->items [ pq->count - 1 ]; 
  }

  pq->count = pq->count - 1;

  return prioItem;
}
