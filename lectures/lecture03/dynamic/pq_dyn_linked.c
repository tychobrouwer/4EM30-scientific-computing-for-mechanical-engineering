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

#include "pq_dyn_linked.h"
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

   ( PQ*     pq )
{
  return pq->count == 0;
}


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void put

  ( PQ*    pq   , 
    ITEM   item )
{
  int newID; // doel: pq.obj [ new ] is vrij
  
  if ( pq->free == -1 ) 
  { 
    newID = pq->count;
  } 
  else 
  {
    newID = pq->free;
    pq->free = pq->item[ pq->free ].next;
  }

  pq->item [ newID ] = item;
  
  if ( pq->first == -1 || item.prio < pq->item[ pq->first ].prio ) 
  {
    pq->item[ newID ].next = pq->first;
    pq->first = newID;
  } 
  else 
  { 
    int i;
    for ( i = pq->first; pq->item[i].next != -1 && 
            pq->item[ pq->item[i].next ].prio <= item.prio; i = pq->item[i].next ); // empty loop body! 

    pq->item[ newID ].next = pq->item[ i ].next;
    pq->item[ i ].next = newID;
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
  pq->first = pq->item[pq->first].next;
  pq->item[oldFirst].next = oldFree;

  pq->count = pq->count - 1;

  return item;
}

  

