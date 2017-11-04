# CMake generated Testfile for 
# Source directory: /home/localguest/Documents/Neuro_3
# Build directory: /home/localguest/Documents/Neuro_3/build-dir3
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(networktest "networktest")
add_test(neuronetest "neuronetest")
subdirs(gtest)
