cd rocm_smi_lib-master
sudo mkdir -p build
cd build
sudo cmake ../
sudo make
sudo make install
sudo rm rocmsmi.zip
make doc
cd latex
make
