gz-sim-ss14
===========

Gazebo Version
===========
I've installed ros-hydro-desktop-full, so i'm using Gazebo 1.9.5.

Homework 1
===========
To use my world and my models, you've to compile my code. Therefore you've to do the following steps:

1. cd Homework1/
2. mkdir build && cd build
3. cmake ../
4. make
5. gazebo -s ./libhomework1.so ../worlds/homework1.world (or gzserver -s ./libhomework1.so ../worlds/homework1.world and gzclient in different terminals)
