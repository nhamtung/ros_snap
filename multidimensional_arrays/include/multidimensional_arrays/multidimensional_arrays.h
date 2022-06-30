#ifndef MULTIDIMENSIONAL_ARRAYS_H
#define MULTIDIMENSIONAL_ARRAYS_H
#pragma once
#pragma comment(lib, "urlmon.lib")

#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <boost/thread.hpp>
#include "geometry_msgs/PoseStamped.h"

using namespace std;

namespace MultidimentionalArrays_ns
{
    class ExecuteAction{
        private:
            ros::Subscriber current_pose_sub;
            geometry_msgs::PoseStamped current_pose;

            void currentPoseCallback(const geometry_msgs::PoseStamped::ConstPtr& msg);
        public:
            ExecuteAction(ros::NodeHandle n);
            ~ExecuteAction();

            double buffer[8][500];
            int buffer_height = 0;
    };
}

#endif