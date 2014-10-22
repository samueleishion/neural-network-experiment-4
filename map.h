// http://stackoverflow.com/questions/4384359/quick-way-to-implement-dictionary-in-c
#include <stdlib.h> 
#include <string.h> 

#define HASHSIZE 101

static struct map_entry *hashtab[HASHSIZE]; 

typedef struct map_entry map_entry;  
struct map_entry { 
	struct map_entry *next; 
	char *name; 
	int defn; 
}; 

unsigned hash(char *s) {
	unsigned hashval; 
	for(hashval=0; *s!='\0'; s++) 
		hashval = *s+31*hashval; 
	return hashval%HASHSIZE; 
}

struct map_entry *lookup(char *s) {
	struct map_entry *np; 
	for(np=hashtab[hash(s)]; np!=NULL; np=np->next) 
		if(strcmp(s,np->name)==0) 
			return np; 
	return NULL; 
}

struct map_entry *push(char *name, int defn) {
	struct map_entry *np; 
	unsigned hashval; 
	if((np=lookup(name))==NULL) {
		np=(struct map_entry *) malloc(sizeof(*np)); 
		if(np==NULL||(np->name=name)==NULL) 
			return NULL; 
		hashval = hash(name); 
		np->next = hashtab[hashval]; 
		hashtab[hashval] = np; 
	} else free((void *) &np->defn); 

	if((np->defn=defn)==NULL) 
		return NULL; 

	return np; 
}