#!/bin/bash

sudo apt-get update
sudo apt install libmysqlclient-dev
sudo apt install libmariadb-dev-compat libmariadb-dev
sudo apt install libsqlite3-dev
sudo apt install libhiredis-dev
sudo apt install postgresql-server-dev-all
sudo apt install -y build-essential autoconf libtool pkg-config

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

sudo apt install git gcc g++ cmake
sudo apt install libjsoncpp-dev
sudo apt install uuid-dev
sudo apt install zlib1g-dev
sudo apt install openssl libssl-dev

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
sleep 1
echo "Running"
./our-chat