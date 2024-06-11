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

#ifndef GRUPA12__GRUPA12_NODE_HPP_
#define GRUPA12__GRUPA12_NODE_HPP_

#include <memory>
#include <rclcpp/rclcpp.hpp>

#include "grupa12/grupa12.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"

#include <vector>
#include <cmath>


namespace grupa12
{
using Grupa12Ptr = std::unique_ptr<grupa12::Grupa12>;

class GRUPA12_PUBLIC Grupa12Node : public rclcpp::Node
{
public:
  explicit Grupa12Node(const rclcpp::NodeOptions & options);

private:
  Grupa12Ptr grupa12_{nullptr};
  void cloudCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg) const;
  rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr cloud_sub_;
  rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr lidar_means_pub_;
  int64_t param_name_{123};
};
}  // namespace grupa12

#endif  // GRUPA12__GRUPA12_NODE_HPP_