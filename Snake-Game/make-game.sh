#!/bin/bash


pushd ..
    #make clean
    make
    pushd ./Bin/linux-x86_64/Debug/Snake-Game
        ./Snake-Game
    popd
popd