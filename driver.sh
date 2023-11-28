#!/bin/bash

# Compile the source files
g++ -c encrypt/encryptModule.cpp -o encryptModule.o
g++ -c decrypt/decryptModule.cpp -o decryptModule.o
g++ -c main/mainModule.cpp -o mainModule.o

# Link the object files to create the executable
g++ encryptModule.o decryptModule.o mainModule.o -o MyEncryptionPackage

# Run the executable
./MyEncryptionPackage
