cmake_minimum_required(VERSION 3.14)
project(grupa12)

find_package(autoware_cmake REQUIRED)
autoware_package()

ament_auto_add_library(${PROJECT_NAME} SHARED
  include/grupa12/grupa12.hpp
  include/grupa12/visibility_control.hpp
  src/grupa12.cpp
)

ament_auto_add_library(${PROJECT_NAME}_node SHARED
  include/grupa12/grupa12_node.hpp
  src/grupa12_node.cpp
)

rclcpp_components_register_node(${PROJECT_NAME}_node
  PLUGIN "grupa12::Grupa12Node"
  EXECUTABLE ${PROJECT_NAME}_node_exe
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  ament_add_ros_isolated_gtest(test_grupa12
    test/test_grupa12.cpp
  )
  ament_target_dependencies(test_grupa12 ${TEST_SOURCES})
  target_link_libraries(test_grupa12 ${PROJECT_NAME})
endif()

ament_auto_package(INSTALL_TO_SHARE
  launch
  config
)
