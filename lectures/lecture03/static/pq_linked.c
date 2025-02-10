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

#include "pq_linked.h"
#include <stdio.h>


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void clear

  ( PQ*    pq )
  
{
  pq->count = 0;
  pq->first = -1;
  pq->free  = -1;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

bool isEmpty

  ( PQ*    pq )
{
  return pq->count == 0;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void put

  ( PQ*     pq   , 
    ITEM    item )
{
  int newID;
  
  if ( pq->free == -1 ) 
  { 
    newID = pq->count;
  } 
  else 
  {
    newID = pq->free;
    pq->free = pq->next [ pq->free ];
  }

  pq->item [ newID ] = item;

  if ( pq->first == -1 || item.prio < pq->item[ pq->first ].prio ) 
  {
    pq->next [ newID ] = pq->first;
    pq->first = newID;
  } 
  else 
  { 
    int i;
    for ( i = pq->first; pq->next[i] != -1 && 
            pq->item[ pq->next[i] ].prio <= item.prio; i = pq->next[i] ); 

    pq->next [ newID ] = pq->next [ i ];
    pq->next [ i ] = newID;
  }
  pq->count = pq->count + 1;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

ITEM getPrio

  ( PQ*    pq )
{
  ITEM item;

  item = pq->item [ pq->first ];

  int oldFree = pq->free;
  int oldFirst = pq->first;

  pq->free  = pq->first;
  pq->first = pq->next[pq->first];
  pq->next[oldFirst] = oldFree;

  pq->count = pq->count - 1;

  return item;
}
