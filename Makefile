neunet: bio.h 
	gcc -Wall main.c bio.h -o main 
	@./main 

clean: 
	rm -f main *.o *~ 