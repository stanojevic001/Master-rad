cd rocm_smi_lib-master
sudo mkdir -p build
cd build
sudo cmake ../
sudo make
sudo make install
sudo cp /opt/rocm/lib/librocm_smi64.so ../../
sudo cp -r /opt/rocm/rocm_smi/ ../../
cd ../../
