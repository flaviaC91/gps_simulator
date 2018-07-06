#pragma once

// ROS
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include "gps_simulator/gps_simulator.h"

namespace gps_simulator {

class GpsSimulatorNode
{
 public:
  /*!
   * Constructor.
   * @param nodeHandle the ROS node handle.
   */
  GpsSimulatorNode(ros::NodeHandle& nh, ros::NodeHandle& nh_private);

  /*!
   * Destructor.
   */
  virtual ~GpsSimulatorNode();

 private:
  /*!
   * ROS topic callback method.
   * @param message the received message.
   */
  void odometryCallback(const nav_msgs::Odometry& odometry_msgs);

  //! ROS node handle.
  ros::NodeHandle& nh_;
  ros::NodeHandle& nh_private_;

  //! ROS topic subscriber.
  ros::Subscriber odom_sub_;

  // GPS simulator
  GpsSimulator gps_simulator_;
};

}
