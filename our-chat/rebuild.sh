# rm -rf build

# mkdir build
cd build
cmake .. -DMYSQL=ON
make
echo "Now in $(pwd)"
echo "Running"
./our-chat