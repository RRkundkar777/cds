# Script to build all DSA files concurrently with global_main
#! /bin/bash

# Data Structure Registry
declare -a DSA_REG

# Importing useful functions
import()
{
    array_dir="./array/test.sh"
    source $array_dir
}

# register "to be compiled" dsa folders
register()
{
    DSA_REG[0]="./aa-sample-dsa"
    DSA_REG[1]="./array"
}

# compile code files from a single dsa folder
ind_compile()
{
    DSA_DIRNAME=$1
    for file in $DSA_DIRNAME/*.cpp
    do
        filename=`echo "$file" | awk -F'/' '{print $3}'`
        g++ -c $file -o ./tmp/$filename.o
    done
}

# Compile code files from all registered dsa folders
compile_all()
{
    for location in ${DSA_REG[@]}
    do
        ind_compile $location
    done
}

# Compile global_main file
compile_main()
{
    g++ -c global_main.cpp -o ./tmp/global_main.cpp.o
}

# Remove the "main.cpp.o" type files
remove_local_main()
{
    rm ./tmp/main.cpp.*
}

# build the final app
gbuild()
{
    g++ ./tmp/*.o -o ubd
}

# run the final app
gboot()
{
    ./ubd
}

# remove the .o files
remove_all_dumps()
{
    rm -r ./tmp
}

# remove the app
remove_ubd()
{
    rm ubd
}

# Driver Code
main()
{
        # If script is not sourced --> do this
        if [[ "${BASH_SOURCE[0]}" == "${0}" ]]
        then
            # create tmp folder 
            import
            tmp

            # register DSAs and compile all 
            register
            compile_all

            # compile global main, remove local main 
            compile_main
            remove_local_main

            # build and run the final app 
            gbuild
            gboot

            # remove the tmp folder
            remove_all_dumps
        fi
}

# Execute!
main