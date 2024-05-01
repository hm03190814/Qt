rm -rf build && \
mkdir build && \
cd build && \
cmake .. && \
make -j12 && \
clear && \
./test_qt