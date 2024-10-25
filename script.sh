#!/bin/bash

sudo apt install git gcc g++ cmake
sudo apt install libjsoncpp-dev
sudo apt install uuid-dev
sudo apt install zlib1g-dev
sudo apt install openssl libssl-dev



git clone https://github.com/drogonframework/drogon
cd drogon
git submodule update --init
mkdir build
cd build
cmake ..
make && sudo make install

cd ..
cd ..

echo "Now in $(pwd)"
cd our-chat
echo "Now in $(pwd)"
cd build
echo "Now in $(pwd)"
cmake ..
make
echo "Now in $(pwd)"

sleep 1
echo "Running"
./our-chat