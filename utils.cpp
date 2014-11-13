#include <iostream> 

long random() {
	static unsigned int nSeed = time(NULL); 
	nSeed = (8253729 * nSeed +2396403); 
	return (long) nSeed % 32763; 
}