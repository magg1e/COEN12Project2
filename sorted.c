/*
 * Maggie Dong
 * Project #2
 * October 5th, 2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include <assert.h>
#include <stdbool.h>
	 
struct set{
	int count;  //num of elements in set
	int length;  //max capacity of set
	char **elts;  //dynamic array to hold strings
};
 
//O(n)  
SET *createSet(int maxElts){
	SET *sp;
	sp = malloc(sizeof(SET));
	assert(sp != NULL);  //verifies that sp is not null
	sp->count = 0;
	sp->length = maxElts;
	sp->elts = malloc(sizeof(char*)*maxElts);  //allocates memory for elts
	assert(sp->elts != NULL);
	return sp;
}
 
//O(n)
void destroySet(SET *sp){
	assert(sp != NULL);
	int i = 0;
	for(i = 0; i < sp->count; i++){
	free(sp->elts[i]);  //deallocates the words in the array
	}
	free(sp->elts);  //deallocates array
	free(sp);  //deallocates set
}
				 
//O(1)
int numElements(SET *sp){
	return (sp->count);  //returns num of elements
}

//O(logn)
static int search(SET *sp, char *elt, bool *found){
	assert(sp != NULL && elt != NULL);
	int lo, hi, mid; lo = 0; hi = sp->count - 1;  //declare variables
	while(lo <= hi){
		mid = (lo + hi)/2;  //mid is in between lo and hi
		if((strcmp(elt, sp->elts[mid])) < 0){
			hi = mid - 1;  //if word is less, ignore upper half
		}
		else if((strcmp(elt, sp->elts[mid])) > 0){
			lo = mid + 1;  //if word is more, ignore lower half
		}
		else{
			*found = true;
			return mid;
		}
	}
	*found = false;
	return lo;
}

//O(n)
void addElement(SET *sp, char *elt){
	assert(sp != NULL && elt != NULL);
	if(sp->count == sp->length){
		//cant add word if at max capacity
    }
	bool x;
	int idx = search(sp, elt, &x);
	if(x  == true){
	   //if word exists in array, cant be added
	 }
	else{
		int i = 0;
		for(i = sp->count - 1; i >= idx; i--){
			sp->elts[i + 1] = sp->elts[i];  //shifts all words greater than elt up
		}
		sp->elts[idx] = strdup(elt);  //allocates memory, copies string, returns pointer
		sp->count++;  //count increases
	}
}

//O(n)
void removeElement(SET *sp, char *elt){
	assert(sp != NULL && elt != NULL);
	bool x;
	int idx = search(sp, elt, &x);
	if(x == false){
		//if word not in array, can't be removed
	}
	else{
		free(sp->elts[idx]); //deallocates memory for word
		int i = 0;
		for(i = idx; i < sp->count; i++){
			sp->elts[i] = sp->elts[i + 1];  //shifts all words down
		}
		sp->count--;  //count decreases 
	}
}

//O(logn)
char *findElement(SET *sp, char *elt){
	assert(sp != NULL && elt != NULL);
	bool x;
	int idx = search(sp, elt, &x);
	if(x == false){
		return NULL;  //if word not found, cant be returned
	}
	else{
		return (sp->elts[idx]);  //return element at index
	}
}

//O(n)
char **getElements(SET *sp){
    assert(sp != NULL);
	char **copy;
	memcpy(copy, sp->elts, sp->count);  //copies elements of elts to copy
	return copy;

}
