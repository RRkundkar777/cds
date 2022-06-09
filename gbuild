# Script to build all DSA files concurrently with global_main
#! /bin/bash

# Data Structure Registry
declare -a DSA_REG

# Create a temporary folder
mk_tmp()
{
    if [ -d "./tmp" ]; 
    then
        :
    else
        mkdir tmp
    fi
}

# register "to be compiled" dsa folders
register_dsa_dirs()
{
    echo "Registering DSAs....."
    DSA_REG[0]="./array"
}

# compile code files from a single dsa folder
compile_dir()
{
    DSA_DIRNAME=$1
    for file in $DSA_DIRNAME/*.cpp
    do
        filename=`echo "$file" | awk -F'/' '{print $3}'`
        g++ -c $file -o ./tmp/$filename.o
        echo "Compiling $file"
    done
}

# Compile code files from all registered dsa folders
compile()
{
    echo "Compilation in Progress...."
    for location in ${DSA_REG[@]}
    do
        compile_dir $location
    done
}

# Compile global_main file
build_main()
{
    echo "Building Main Object....."
    g++ -c global_main.cpp -o ./tmp/global_main.cpp.o
}

# Remove the "main.cpp.o" type files
remove_local_main()
{
    rm ./tmp/main.cpp.*
}

# build the final app
build_app()
{
    echo "Building Application 'ubd'"
    g++ ./tmp/*.o -o ubd
}

# run the final app
boot_app()
{
    echo -e "Testing all Data Integrity....\n"
    ./ubd
}

# remove the .o files
remove_dumps()
{
    echo "Removing all dumps......"
    rm -r ./tmp
}

# remove the app
remove_app()
{
    echo "Removing executable...."
    rm ubd
}

# Driver Code
main()
{
    ARGS=$1
        # If script is not sourced --> do this
        if [[ "${BASH_SOURCE[0]}" == "${0}" ]]
        then
            if [[ $ARGS == "-r" ]]
            then
                # remove the tmp folder
                remove_dumps
                remove_app
            else
                # create tmp folder 
                mk_tmp

                # register DSAs and compile all 
                register_dsa_dirs
                compile

                # compile global main, remove local main 
                build_main
                remove_local_main

                # build and run the final app 
                build_app
                boot_app
            fi
        fi
}

# Execute!
main $1