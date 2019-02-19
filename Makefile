# patterned on Makefile by Jerod Weinman for CSC 161, Spring 2015

# This program and all MyroC software is licensed under the Creative Commons
#  Attribution-Noncommercial-Share Alike 4.0 International License.
#  Details may be found at http://creativecommons.org/licenses/by-nc-sa/4.0/

# Type "make foo". 
# We rely on the implicit  rules foo.c -> foo.o for compiling and
# foo.o --> foo for linking

# Use the gcc compiler
CC = gcc

# Set preprocessor flags
#CPPFLAGS=

# Set appropriate compiling flags
CFLAGS=-Wall -Wno-deprecated-declarations -std=gnu99 -pthread -lMyroC -leSpeakPackage

# Set dynamic library path
#DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:/usr/local/lib

# Set linker flags to include the relevant libraries
LDFLAGS= -lMyroC -leSpeakPackage -framework OpenGL -framework GLUT 

#----------------------------------------------------------------------------
# cleanup rules: To invoke this command, type "make clean".
# Use this target to clean up your directory, deleting (without warning) 
#   object files, old emacs source versions, and core dumps.

clean: 
	rm -f *.o *~ core*

