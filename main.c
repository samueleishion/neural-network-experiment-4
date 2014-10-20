#include <stdio.h> 
#include <inttypes.h> 
#include "bio.h" 
#include "map.h" 

#define CAST(t,e) ((t)(e)) 
#define TYPED_MALLOC(t) CAST(t*,malloc(sizeof(t))) 

int main(int argc, char **argv) {
	printf("MAIN\n"); 
	return 0; 
}