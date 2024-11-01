git clone -b v1.34.0 https://github.com/grpc/grpc
cd grpc
git submodule update --init

# Компилируем и устанавливаем
mkdir -p cmake/build
cd cmake/build
cmake ../.. -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=/usr/local
make -j4
make install