/*
Author:		Billy Gene Ridgeway
Purpose:	Learn the concept of doubly linked lists in C.
Date:		August 3rd., 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem {
	struct listitem *next;		// Pointer to the next item.
	struct listitem *prev;		// Pointer to the previous item.
	int data;					// Some integer data.
} LISTITEM;						// Name of shortcut to listitem struct.

// NOTE: This example just illustrates how doubly linked lists work.

int main() {
	LISTITEM *temp, head;

	// NOTE: For convenience here, I'll use a LISTITEM to store the list forward and backward pointers
	// since the LISTITEM's data is only 4 bytes, this doesn't matter, but for a large data part, 
	// it would be inefficient.
	// First indicate that the list has nothing in it 
	// ... this is done by setting both list pointers to point to themselves

	head.next = (LISTITEM*)&head;					// Both next and prev pointers are initalized to poing
	head.prev = (LISTITEM*)&head;					// back to address of the head structure.
	head.data = -1;									// -1 is here for clarity  - it isn't actually used.

													// Now populate the list.
	for (int i = 0; i < 3; i++) {
		temp = malloc(sizeof(LISTITEM));			// Allocate some memory for the new list item.
		temp->data = i;								// Set the list item's data to the loop count so that we can see where it is in the list.
		temp->next = head.next;						// Set temp->next to point to head.next. This sets the Front pointer.
		head.next = temp;							// Set head.next to point to the newly created struct in temp.
		temp->prev = &head;							// Set temp->prev to point to the address of head. This sets the Back pointer.
		temp->next->prev = temp;					// Use next pointer to get to the prev pointer and assign it the address
													// of the current struct held in temp to be used in the next iteration of the loop.
													// Now both next and prev point to head.
	}

	printf("\n *** Now going forward through the list. ***\n\n");
	// Now let's see what we have going forward.
	temp = head.next;								// Initialize our temporary variable to the head of the list.
	while (temp != &head) {							// Keep going until we've reach the end.
		printf("forward list item: current is %p; next is %p; prev is %p; data is %d\n", temp, temp->next, temp->prev, temp->data);
		temp = temp->next;							// Move to the next item in the list	.				
	}

	printf("\n *** Now going backwards through the list. ***\n\n");
	// Now going backwards through the list.
	temp = head.prev;								// Initialize our temporary variable to the tail of the list.
	while (temp != &head) {							// Keep going until we've reach the end.
		printf("backward list item: current is %p; next is %p; prev is %p; data is %d\n", temp, temp->next, temp->prev, temp->data);
		temp = temp->prev;							// Move to the previous item in the list.					
	}

	return 0;
}