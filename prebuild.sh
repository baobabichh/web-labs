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

git clone https://github.com/abseil/abseil-cpp.git
cd abseil-cpp

mkdir build
cd build
cmake ..
make
sudo make install

sudo apt-get update -y
sudo apt-get upgrade -y

cd ..
cd ..

export MY_INSTALL_DIR=$HOME/.local
mkdir -p $MY_INSTALL_DIR
export PATH="$MY_INSTALL_DIR/bin:$PATH"

rm -rf grpc/* grpc/.*
rmdir grpc
git clone --recurse-submodules -b v1.66.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc
cd grpc
mkdir -p cmake/build
pushd cmake/build
cmake -DgRPC_INSTALL=ON \
      -DgRPC_BUILD_TESTS=OFF \
      -DCMAKE_INSTALL_PREFIX=$MY_INSTALL_DIR \
      ../..
make -j 4
make install
popd

cd ..
echo "Now in $(pwd)"

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

ifconfig


cd ..
cd ..

export MY_INSTALL_DIR=$HOME/.local
mkdir -p $MY_INSTALL_DIR
export PATH="$MY_INSTALL_DIR/bin:$PATH"

sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt install -y cmake

sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt install -y build-essential autoconf libtool pkg-config

sudo apt-get update -y
sudo apt-get upgrade -y

cd ..
cd ..



git clone --recurse-submodules -b v1.66.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc

cd grpc
mkdir -p cmake/build
pushd cmake/build
cmake -DgRPC_INSTALL=ON \
      -DgRPC_BUILD_TESTS=OFF \
      -DCMAKE_INSTALL_PREFIX=$MY_INSTALL_DIR \
      ../..
make -j 4
make install
popd


cd examples/cpp/helloworld

mkdir -p cmake/build
pushd cmake/build
cmake -DCMAKE_PREFIX_PATH=$MY_INSTALL_DIR ../..
make -j 4


cd ~/web/web-labs
./build_protos.sh