#!/bin/bash

./Setup-Linux.sh

pushd ..

rm -rf ./Bin/linux-x86_64/Debug/Snake-Game/Assets

cp -R ./Snake-Game/Assets ./Bin/linux-x86_64/Debug/Snake-Game/Assets

make && {
    pushd ./Bin/linux-x86_64/Debug/Snake-Game
    ./Snake-Game
    popd
}
popd
