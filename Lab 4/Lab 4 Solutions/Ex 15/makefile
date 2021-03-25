FILENAME = main.c
HEADERS_SOURCES = $(wildcard source/*.c)
HEADER_OBJECTS = $(patsubst source/%.c, objects/%.o, $(HEADERS_SOURCES))
OUT = main
COMPILER = gcc

# Rule to compute the main program while requiring the objects files
$(OUT) : $(FILENAME) $(HEADER_OBJECTS)
	gcc $(FILENAME) $(HEADER_OBJECTS) -o $(OUT)

# Implicit rule to compute the object file
objects/%.o : source/%.c
	gcc -c $^ -o $@

run : $(OUT)
	./$(OUT)

debug : $(FILENAME) $(HEADER_OBJECTS)
	gcc -g $(FILENAME) $(HEADER_OBJECTS) -o $(OUT)
	gdb $(OUT)

clear :
	rm -f $(OUT) $(HEADER_OBJECTS)

###################### HELPER #####################
# out.o: src.c src.h
#   $@   # "out.o" (target)
#   $<   # "src.c" (first prerequisite)
#   $^   # "src.c src.h" (all prerequisites)

# %.o : %.c
# 	gcc -c $^ -o $@


# Putting @ before a command allows to avoid printing it to the shell
 # findind all headers files : HEADERS_SOURCES  = $(wildcard headers/*.c)
 # converting headers to objects : HEADER_OBJECTS  = $(patsubst %.c, %.o, HEADERS_SOURCES)
