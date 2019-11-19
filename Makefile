multi: multithread_search.c
	gcc multithread_search.c -o multi -lpthread 
test:  
	./multi
clean:
	rm -f ./multi
