# standard compile options for the c executable
COMP ?= gcc
WARN = -Wall

# deposit directories
SOURCES = ./sources
EXES = ./exes

# default super-target
all: 
	#testing vector
	$(COMP) $(WARN) $(SOURCES)/vectorTest.c -o $(EXES)/vectorTest
	
	#testing list
	$(COMP) $(WARN) $(SOURCES)/listTest.c -o $(EXES)/listTest
