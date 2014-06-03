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
5. type ```gzserver -s ./libhomework1.so ../worlds/homework1.world``` in one terminal and execute
6. start ```gzclient``` in a different terminal
7. (or just ```gazebo -s ./libhomework1.so ../worlds/homework1.world``` for server and client together)

now you should see a moving box and sphere

Homework 2
===========
To use my world and my models, you've to compile my code. Therefore you've to do the following steps:

1. cd Homework2/
2. mkdir build && cd build
3. cmake ../
4. make
5. export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:~/PATH/TO/REPO/gz_sim-ss14/Homework2/build
5. type ```gzserver ../worlds/homework2.world``` in one terminal and execute
6. start ```gzclient``` in a different terminal
7. (or just ```gazebo ../worlds/homework2.world``` for server and client together)

now you should see two falling spheres. Then a joint is created and both spheres should be move. After some seconds the joint will be removed and only one sphere should move.
