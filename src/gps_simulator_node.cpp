#include "gps_simulator/gps_simulator_node.h"
#include <ros/console.h>

namespace gps_simulator {

GpsSimulatorNode::GpsSimulatorNode(ros::NodeHandle& nh, ros::NodeHandle& nh_private)
    : nh_(nh), nh_private_(nh_private) {
  ROS_INFO("Creating object of type GpsSimulatorNode.");
  odom_sub_ = nh_.subscribe("/firefly1/ground_truth/odometry", 1,
                                      &GpsSimulatorNode::odometryCallback, this);
  ROS_INFO("Successfully launched node.");
}

GpsSimulatorNode::~GpsSimulatorNode(){}


void GpsSimulatorNode::odometryCallback(const nav_msgs::Odometry& odometry_msgs) {
  ROS_INFO("Odometry received!");
}

} // gps_simulator

int main(int argc, char** argv) {
  ros::init(argc, argv, "gps_simulator_node");
  ros::NodeHandle nh("");
  ros::NodeHandle nh_private("~");

  gps_simulator::GpsSimulatorNode gpsSimulatorNode(nh, nh_private);

  ros::spin();
  return 0;
}
