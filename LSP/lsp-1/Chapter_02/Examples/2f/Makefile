all: run clean

run: ex1 
	./ex1
	ls -l myfile.txt	
	./ex1

run2: ex1
	touch myfile.txt
	-./ex1
	ls -l myfile.txt

clean:
	rm -f ex? myfile.txt 
