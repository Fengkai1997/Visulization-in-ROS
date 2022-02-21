#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <ros/platform.h>
#include <ros/time.h>
#include <stdio.h>
#include <iomanip>


//Xu dynamic Pose and Postition version 5

const int q=134;//number of points
const float pi = 3.1415926;
//global variables
std::vector<float> data_line_x;
std::vector<float> data_line_y;
std::vector<float> data_line_cog;
std::vector<float> data_line_update;
std::vector<std::string> data_line_time;

//csvread functions
void csvreadx(){
    std::ifstream inputFile("/home/xu/catkin_ws/src/areas736_745/Boat/Boat2912155/Boat00_2912155_long.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 0;j <q+1;j++){ 
            getline(readstr,number,','); 
            data_line_x.push_back(atof(number.c_str())); 
            }
    }
}

void csvready(){
    std::ifstream inputFile("/home/xu/catkin_ws/src/areas736_745/Boat/Boat2912155/Boat00_2912155_lati.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 0;j <q+1;j++){ 
            getline(readstr,number,','); 
            data_line_y.push_back(atof(number.c_str())); 
            }
    }
}

void csvreadcog(){
    std::ifstream inputFile("/home/xu/catkin_ws/src/areas736_745/Boat/Boat2912155/Boat00_2912155_COG.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 0;j <q+1;j++){ 
            getline(readstr,number,','); 
            data_line_cog.push_back(atof(number.c_str())); 
            }
    }
}


void csvreadupdate(){
    std::ifstream inputFile("/home/xu/catkin_ws/src/areas736_745/Boat/Boat2912155/Boat00_2912155_timeinterval.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 0;j <q+1;j++){ 
            getline(readstr,number,','); 
            data_line_update.push_back(atof(number.c_str())); 
            }
    }
}

void csvreadtime(){
    std::ifstream inputFile("/home/xu/catkin_ws/src/areas736_745/Boat/Boat2912155/Boat00_2912155_time.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 0;j <q+1;j++){ 
            getline(readstr,number,','); 
            data_line_time.push_back(number.c_str()); 
            }
    }
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "Boat00_2912155");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);
  ros::Publisher markerPub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);
  


  visualization_msgs::Marker marker;
  marker.header.frame_id= "/my_frame";
  marker.header.stamp = ros::Time::now();
  marker.ns =  "Boat00_2912155";
  marker.action = visualization_msgs::Marker::ADD;
  marker.pose.orientation.w = 1.0;
  marker.id =0;
  marker.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
  marker.scale.z = 1;
  marker.color.b =0;
  marker.color.g = 250;
  marker.color.r =250;
  marker.color.a = 1;

  ros::Rate r(10);

  float f = 0.0;
  //variable for location vector
  int j =0;

  csvreadx();
  csvready();
  csvreadcog();
  csvreadupdate();
  csvreadtime();

  while (ros::ok())
  {

    visualization_msgs::Marker points, line_strip, line_list;
    points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id = "/my_frame";
    points.header.stamp = line_strip.header.stamp = line_list.header.stamp = ros::Time::now();
    points.ns = line_strip.ns = line_list.ns = "Boat00_2912155";
    points.action = line_strip.action = line_list.action = visualization_msgs::Marker::ADD;
    points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w = 1.0;



    points.id = 0;
    line_strip.id = 1;
    line_list.id = 2;



    points.type = visualization_msgs::Marker::POINTS;
    line_strip.type = visualization_msgs::Marker::LINE_STRIP;
   line_list.type = visualization_msgs::Marker::LINE_LIST;



    // POINTS markers use x and y scale for width/height respectively
    points.scale.x = 0.1;
    points.scale.y = 0.1;

    // LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
  line_strip.scale.x = 0.3;
   line_list.scale.x = 0.3;



    // Points are red
    points.color.r = 1.0f;
    points.color.a = 1.0;

    // Line strip is blue
    line_strip.color.g = 1.0;
    line_strip.color.a = 1.0;

    //Line list is green
    line_list.color.g = 1.0;
    line_list.color.a =1.0;
    
      //key synchron code!
   ros::Duration(data_line_update[j]/12).sleep();





    //pose for each location points with kinematic model
    for (uint32_t i = 0; i < 6; ++i)
    { //X
      float arry6[]={ 1000*(data_line_x[j]-6.72)+3*sin(data_line_cog[j]*pi/180)/4,
                                 1000*(data_line_x[j]-6.72)+2.2361*sin((data_line_cog[j]-26.565)*pi/180)/4,
                                 1000*(data_line_x[j]-6.72)-cos( data_line_cog[j]*pi/180 )/4,
                                  1000*(data_line_x[j]-6.72)+cos( data_line_cog[j]*pi/180 )/4,
                                 1000*(data_line_x[j]-6.72)+2.2361*sin((data_line_cog[j]+26.565)*pi/180)/4,
                                  1000*(data_line_x[j]-6.72)+3*sin( data_line_cog[j]*pi/180)/4}; 
      


      //Y
      float arry7[]={1000*(data_line_y[j]-51.18)+3*cos( data_line_cog[j]*pi/180 )/4,
                                1000*(data_line_y[j]-51.18)+2.2361*cos((data_line_cog[j]-26.565)*pi/180)/4,
                                1000*(data_line_y[j]-51.18)+sin( data_line_cog[j]*pi/180 )/4,
                                1000*(data_line_y[j]-51.18)-sin(data_line_cog[j]*pi/180 )/4,
                               1000*(data_line_y[j]-51.18)+2.2361*cos((data_line_cog[j]+26.565)*pi/180)/4,
                               1000*(data_line_y[j]-51.18)+3*cos( data_line_cog[j]*pi/180 )/4};
     // float x = arry1[i];
      //float y = arry2[i];

    geometry_msgs::Point p;
     p.x = 1*(arry6[i]);
     p.y = 1*(arry7[i]);
      
      double z  = 0.0;
      p.z = z;

      points.points.push_back(p);
      line_strip.points.push_back(p);

      // The line list needs two points for each line
      line_list.points.push_back(p);
      p.z += 0.0;
      line_list.points.push_back(p);
    marker_pub.publish(points);
    marker_pub.publish(line_strip);
    marker_pub.publish(line_list);
    

    //ROS info out put
    ROS_INFO_STREAM("Ship_id:  " <<"Boat00_2912155");
    ROS_INFO_STREAM("current_Time:  " <<data_line_time[j]);
    ROS_INFO("current_Latitude: %f", data_line_y[j]);
    ROS_INFO("current_Longitude: %f", data_line_x[j]);
    ROS_INFO("current_COG: %f\n", data_line_cog[j]);



 

    }



    geometry_msgs::Pose pose;
    pose.position.x =  1000*(data_line_x[j]-6.72)-1;
    pose.position.y =  1000*(data_line_y[j]-51.18);
    pose.position.z =0;
    marker.text="Boat2912155";
    marker.pose=pose;
    markerPub.publish(marker);


    r.sleep();
   
   
   
   // read the next postion point

    j=j+1;
    if(j>=q){
      break;
    }
    f += 0.04;
  }
}
