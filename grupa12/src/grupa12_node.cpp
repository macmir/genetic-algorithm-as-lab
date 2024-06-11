// Copyright 2024 111
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "grupa12/grupa12_node.hpp"
#include <vector>

namespace grupa12
{
auto custom_qos = rclcpp::QoS(rclcpp::KeepLast(1), rmw_qos_profile_sensor_data);
Grupa12Node::Grupa12Node(const rclcpp::NodeOptions & options)
:  Node("grupa12", options)
{
  grupa12_ = std::make_unique<grupa12::Grupa12>();
  // param_name_ = this->declare_parameter("param_name", 456);
  // grupa12_->foo(param_name_);
  cloud_sub_ = this->create_subscription<sensor_msgs::msg::LaserScan>(
    "/sensing/lidar/scan", custom_qos, std::bind(
      &Grupa12Node::cloudCallback, this,
      std::placeholders::_1));
  lidar_means_pub_ = this->create_publisher<std_msgs::msg::Float32MultiArray>("/filtered_lidar", custom_qos);


}

void Grupa12Node::cloudCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg) const
{
 
  std::vector<float>lidar_means;
  float sum=0;
  int div=9; // count of lasers -1
  // int probes=5; //cout of probes to be get from the laser from the left and right
  int cnt=0; //1081
  // bool calculated=false;
  for (auto&el: msg->ranges)
  {
    
    cnt+=1;
    sum=sum+el;
    if(cnt==int(1080/div))
    {
      lidar_means.emplace_back(sum/120);
      sum=0;
      cnt=0;
      
    }
  }
  


  // for (auto&el: msg->ranges)
  // {
  //    cnt+=1;
  //    if(cnt>int(1080/div)-probes && cnt<=int(1080/div)+probes)
  //    {
  //       sum=sum+el;
  //       calculated=true;
  //    }
  //    else
  //    {
  //       if(calculated==true)
  //       {

  //         lidar_means.emplace_back(sum/(2*probes));
  //         calculated=false;
  //         cnt=0;
  //         sum=0;

  //       }
  //    }

  // }

  std_msgs::msg::Float32MultiArray lidar_means_msg;
  lidar_means_msg.data = lidar_means; // Assuming lidar_means is a std::vector<float>

    // Publish the message
  // std::cout<<"START"<<std::endl;
  // for(auto &el: lidar_means)
  // {
  //   std::cout<<el<<std::endl;
  // }
  // std::cout<<"STOP"<<std::endl;
  lidar_means_pub_->publish(lidar_means_msg);
  lidar_means.clear();
  
}

}  // namespace grupa12

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(grupa12::Grupa12Node)

