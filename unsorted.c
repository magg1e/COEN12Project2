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

//O(n)
static int search(SET *sp, char *elt){
	assert(sp != NULL && elt != NULL);
	int i = 0;
	for(i = 0; i < ((sp->count)); i++){  //searches through array
		if(strcmp((sp->elts[i]), elt) == 0){  
			return i;   //if word is found, index is returned
		}
	}
	return (-1);
}

//O(n)
void addElement(SET *sp, char *elt){
   	assert(sp != NULL && elt != NULL);
   	if(sp->count == sp->length){ 
	     //cant add word if at max capacity
   	}   
   	if(search(sp, elt) != -1){
	     //if word exists in array, cant be added
   	}
	else{
   		sp->elts[sp->count] = strdup(elt);
		//allocates memory, copies string and returns pointer
		
		(sp->count)++;
	}
}

//O(n)
void removeElement(SET *sp, char *elt){
	assert(sp != NULL && elt != NULL);
	if(search(sp, elt) == -1){
	    //if word not in array, can't be removed
	}
	else{
		int x = search(sp, elt);
		free(sp->elts[x]);  //deallocate memory for word
		(sp->elts[x]) = (sp->elts[(sp->count) - 1]); //last word moved to x
		(sp->count)--;
	}
}

//O(n)
char *findElement(SET *sp, char *elt){
   	assert(sp != NULL && elt != NULL);
	if(search(sp, elt) == -1){  //if word not in array, return NULL
		return NULL;
	}
	else{
		int x = search(sp, elt);  //else return matching element
		return (sp->elts[x]);
	}
}

//O(n)
char **getElements(SET *sp){
	assert(sp != NULL);
	char **copy;
   	memcpy(copy, sp->elts, sp->count);  //copies elements of elts to copy
	return copy;
}












