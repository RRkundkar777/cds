# Script to build all DSA files concurrently with global_main

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