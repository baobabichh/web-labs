
git clone https://github.com/graphql/libgraphqlparser.git

wget https://www.python.org/ftp/python/2.7.9/Python-2.7.9.tgz
sudo tar xzf Python-2.7.9.tgz
cd Python-2.7.9
sudo ./configure --enable-optimizations
sudo make altinstall

cd ..

rm -rf Python-2.7.9.tgz

cd libgraphqlparser
cmake -DPYTHON_EXECUTABLE:FILEPATH=../Python-2.7.9/python . 
make