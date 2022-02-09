#include <ros/ros.h>
#include <ros/console.h>
#include <nav_msgs/Path.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <tf/transform_broadcaster.h>
#include <tf/tf.h>
#include <cstdlib>
#include <visualization_msgs/Marker.h>
#include "std_msgs/String.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <ros/platform.h>
#include <ros/time.h>
#include <stdio.h>
#include <iomanip>

std::vector<float> data_line_x;
std::vector<float> data_line_y;
std::vector<float> data_line_cog;

void csvreadx(){
    std::ifstream inputFile("/home/xu/catkin_ws/src/using_markers/src/X736745.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 1;j <383;j++){ 
            getline(readstr,number,','); 
            data_line_x.push_back(atof(number.c_str())); 
            }
    }
}

void csvready(){
    std::ifstream inputFile("/home/xu/catkin_ws/src/using_markers/src/Y736745.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 1;j <383;j++){ 
            getline(readstr,number,','); 
            data_line_y.push_back(atof(number.c_str())); 
            }
    }
}

void csvreadcog(){
    std::ifstream inputFile("/home/xu/catkin_ws/src/using_markers/src/COG736745.csv"); //path
    std::string line;
    while (getline(inputFile,line)){
        std::string number;
        std::istringstream readstr(line); //string2stream  //devided with'，'
        for(int j = 1;j <383;j++){ 
            getline(readstr,number,','); 
            data_line_cog.push_back(atof(number.c_str())); 
            }
    }
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "showpath");

    ros::NodeHandle ph;
    ros::Publisher path_pub = ph.advertise<nav_msgs::Path>("trajectory", 1, true);
    ros::Publisher point_pub = ph.advertise<geometry_msgs::PointStamped>("point", 1, true);

    ros::Time current_time, last_time;
    current_time = ros::Time::now();
    last_time = ros::Time::now();

    nav_msgs::Path path;

    //nav_msgs::Path path;
    path.header.stamp = current_time;
    path.header.frame_id = "my_frame";
    int dt = 25;

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

  csvreadx();
  csvready();
  csvreadcog();
    
    ros::Rate loop_rate(5);
    while (ros::ok())
    {

        current_time = ros::Time::now();
       
        x = 1000*(data_line_x[dt]-6.72);
        y = 1000*(data_line_y[dt]-51.18);
        z += 0.000;
       float th =0 ;

        geometry_msgs::PoseStamped this_pose_stamped;
        geometry_msgs::PointStamped this_point_stamped;

        this_pose_stamped.pose.position.x = x;
        this_pose_stamped.pose.position.y = y;
        this_pose_stamped.pose.position.z = z;

        this_point_stamped.header.stamp = current_time;
        this_point_stamped.header.frame_id = "my_frame";
        this_point_stamped.point.x = x;
        this_point_stamped.point.y = y;
        this_point_stamped.point.z = z;
        ROS_INFO("current_Latitude: %f", data_line_y[dt]);
        ROS_INFO("current_Longitude: %f", data_line_x[dt]);
        ROS_INFO("current_COG: %f", data_line_cog[dt]);
        geometry_msgs::Quaternion goal_quat = tf::createQuaternionMsgFromYaw(th);
        this_pose_stamped.pose.orientation.x = goal_quat.x;
        this_pose_stamped.pose.orientation.y = goal_quat.y;
        this_pose_stamped.pose.orientation.z = goal_quat.z;
        this_pose_stamped.pose.orientation.w = goal_quat.w;

        this_pose_stamped.header.stamp = current_time;
        this_pose_stamped.header.frame_id = "my_frame";
        path.poses.push_back(this_pose_stamped);

        path_pub.publish(path);
        point_pub.publish(this_point_stamped);

        dt=dt+1;
        ros::spinOnce(); // check for incoming messages

        last_time = current_time;
        loop_rate.sleep();
        if(dt>=382){
            break;
        }
    }

    return 0;
}
