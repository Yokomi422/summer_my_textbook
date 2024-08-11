TARGET = main

all: compile 
	echo "--------executed----------" &&  ./$(TARGET) && rm -rf $(TARGET).out a.out main main.dSYM && echo "--------end----------\n"

compile:
	gcc -o $(TARGET) $(TARGET).c

