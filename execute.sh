#!/bin/sh

fileName=$1
extension="${fileName##*.}"
fileNameWithoutExt="${fileName%.*}"

if [ "$extension" = "cpp" ]; then
	echo -e "\nCompiling $fileName file...\n--------------------\n"
	g++ $fileName -o $fileNameWithoutExt && ./$fileNameWithoutExt && rm $fileNameWithoutExt
elif [ "$extension" = "c" ]; then
	echo -e "\nCompiling $fileName file...\n--------------------\n"
	gcc $fileName -o $fileNameWithoutExt && ./$fileNameWithoutExt && rm $fileNameWithoutExt
else
	echo "Error: The file is not a C or C++ file."
fi
