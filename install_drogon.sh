#!/bin/bash

sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y libmysqlclient-dev
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y libmariadb-dev-compat libmariadb-dev
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y libsqlite3-dev
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y libhiredis-dev
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y postgresql-server-dev-all
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y build-essential autoconf libtool pkg-config
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y git gcc g++ cmake
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y libjsoncpp-dev
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y uuid-dev
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y zlib1g-dev
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y openssl libssl-dev
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y protobuf-compiler-grpc
sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get install -y libprotobuf-dev protobuf-compiler
sudo apt-get update -y
sudo apt-get upgrade -y

rm -rf drogon/* drogon/.*
rmdir drogon
git clone https://github.com/drogonframework/drogon
cd drogon
git submodule update --init
mkdir build
cd build
cmake .. -DMYSQL=ON
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


cd ..
cd ..

sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt install -y cmake

sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt install -y build-essential autoconf libtool pkg-config

sudo apt-get update -y
sudo apt-get upgrade -y
