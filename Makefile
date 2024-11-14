# Target to build the program
calc:
	mkdir -p build
	gcc -o build/calc src/calc.c -lm

# Clean target to remove build files
clean:
	rm -rf build
