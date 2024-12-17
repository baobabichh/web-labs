sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get install -y cmake

sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get install -y build-essential autoconf libtool pkg-config

sudo apt-get update -y
sudo apt-get upgrade -y


git clone --recurse-submodules -b v1.66.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc

cd grpc
mkdir -p cmake/build
cd cmake/build
cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. \
      -DgRPC_INSTALL=ON                \
      -DCMAKE_BUILD_TYPE=Release       \
      -DgRPC_ABSL_PROVIDER=package     \
      -DgRPC_CARES_PROVIDER=package    \
      -DgRPC_PROTOBUF_PROVIDER=package \
      -DgRPC_RE2_PROVIDER=package      \
      -DgRPC_SSL_PROVIDER=package      \
      -DgRPC_ZLIB_PROVIDER=package     \
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