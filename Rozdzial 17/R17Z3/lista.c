/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* interface functions */
/* set the list to empty */
void InitializeList(List * plist)
{
    plist->pozycje = 0;
}

/* returns true if list is empty */
bool ListIsEmpty(const List * plist)
{
    if (plist->pozycje == 0)
        return true;
    else
        return false;
}

/* returns true if list is full */
bool ListIsFull(const List * plist)
{
    if (plist->pozycje == MAXROZM)
        return true;
    else
        return false;
}

/* returns number of nodes */
unsigned int ListItemCount(const List * plist)
{
    return plist->pozycje;
}

/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation) */
bool AddItem(Item item, List * plist)
{
  
    if (plist->pozycje == MAXROZM)
        return false; /* quit function on failure */
    plist->wpisy[plist->pozycje] = item;
    plist->pozycje++;

    return true;
}

/* visit each node and execute function pointed to by pfun */
void Traverse (const List * plist, void (* pfun)(Item item) )
{
    int i = 0;

    while (i != plist->pozycje)
    {
        (*pfun)(plist->wpisy[i++]); /* apply function to item */
    }
}

/* free memory allocated by malloc() */
/* set list pointer to NULL */
void EmptyTheList(List * plist)
{
    plist->pozycje = 0;
}
