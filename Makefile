neunet: main.c utils.h bio.h map.h arraylist.h 
	gcc -Wall -w main.c utils.h bio.h map.h arraylist.h -o main 
	@./main 

clean: 
	rm -f main *.o *~ .gitignore~