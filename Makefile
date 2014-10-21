neunet: main.c utils.h bio.h map.h
	gcc -Wall -w main.c utils.h bio.h map.h -o main 
	@./main 

clean: 
	rm -f main *.o *~ .gitignore~