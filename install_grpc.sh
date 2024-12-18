sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get install -y cmake

sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get install -y build-essential autoconf libtool pkg-config

sudo apt-get update -y
sudo apt-get upgrade -y

sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get install -y libc-ares-dev



git clone --recurse-submodules -b v1.66.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc

cd grpc
mkdir -p cmake/build
cd cmake/build
cmake -DgRPC_INSTALL=ON \
      -DgRPC_BUILD_TESTS=OFF \
      -DgRPC_CARES_PROVIDER=package \
      ../..
make -j 4
make install
cd ..
cd ..

cd examples/cpp/helloworld

mkdir -p cmake/build
cd cmake/build
cmake ../..
make -j 4