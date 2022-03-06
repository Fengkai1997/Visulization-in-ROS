# Visulization-in-ROS of many ships in many areas

1. Get data from ENC dataset(map of river) and AIS data(ship movement data)
2. Convert ENC data to separate shapefile to get the shape, location and some other infomation(Python GDAL and Shapefile)
   Store it in csv with Pandas
3. Visulize with shapefile data which is stored in csv in RViz in ROS(C++，build ROS node）then get the static Map
4. Process AIS data（over 1000000 rows per day），Filter out valid data, categorize and organize it（Pandas) and know how to use dynamic variable names.
5. Dynamic visulization,the ship can move, write code , with considering the kinematic model of ships, can show the location and pose of ship.
6. Modify the code for synchronaiztion requirements, means the time in visulization is proportional to the time in real world and the speed of all ships is proportional to the    real ship. Know how calculate time inverval
7. Solving the concurrency problem because of large number of nodes
8. Write a template code and Design auto code generator to build all ROSnode code automatically from AIS-data(include cmakelist and roslaunch file),sucessfully, automatocally create 3000 rosnode cpp file and cmakelist.txt and roslaunch file
9. Try to learn the strukture of ROS master and how it plan and schedule tasks


Example in Neuss harbour:
![finalresults_screenshot](https://user-images.githubusercontent.com/85012724/153255565-29bd8b0e-e0a8-4c1a-a6c3-2c75583c583f.png)
many ships with time sequence
![2022-02-23 21-15-09 的屏幕截图](https://user-images.githubusercontent.com/85012724/155400821-2341ee1b-87d9-4bfd-8b1d-2a77bb652cb1.png)


