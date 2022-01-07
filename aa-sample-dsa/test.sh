# Script to build code files of array data structure
#! /bin/bash

# Make the tmp folder
tmp()
{
    if [ -d "./tmp" ]; 
    then
        :
    else
        mkdir tmp
    fi
}

# Compile the code files into tmp
compile()
{
    for file in ./*.cpp
    do
        g++ -c $file -o ./tmp/$file.o
    done
}

# Build the app
build()
{
    g++ $(ls ./tmp/*.o) -o app
}

# Run it
run()
{
    ./app
}

# Remove object files
removeDumps()
{
    rm -r ./tmp
}

# Remove the app
removeApp()
{
    rm app
}

# Driver Code
main()
{
    # If bash script is not being sourced --> execute this
    if [[ "${BASH_SOURCE[0]}" == "${0}" ]]
    then 
        tmp
        compile
        build
        removeDumps
    fi
}

# Execute !
main