(CC)= gcc


arith : arith.o libstatic.a 
	$(CC) -o arith arith.o -L. -lstatic

arith.o : arith.c 
	$(CC) -c -o arith.o arith.c 

clean : 
	rm -rf *.o arith 