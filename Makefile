neunet: main.c bio.h map.h
	gcc -Wall -w main.c bio.h map.h -o main 
	@./main 

clean: 
	rm -f main *.o *~ 