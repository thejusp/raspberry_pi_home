cmake_minimum_required(VERSION 2.8.3)
project(vis_pkg)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  actionlib 
  actionlib_msgs
  cv_bridge
)


set(raspicam_DIR "/usr/local/lib/cmake")

find_package(Boost REQUIRED COMPONENTS system)
find_package( OpenCV REQUIRED )
find_package(raspicam REQUIRED)


catkin_package(
  CATKIN_DEPENDS roscpp std_msgs actionlib actionlib_msgs
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)


add_executable(test_node src/test_node.cxx)
add_executable(cam_node src/cam_node.cxx)
add_executable(track_node src/track_node.cxx)




add_dependencies(test_node vis_pkg_generate_messages_cxx) #test_node Dependency 
add_dependencies(cam_node vis_pkg_generate_messages_cxx)  #cam_node Dependency 
add_dependencies(track_node vis_pkg_generate_messages_cxx)#track_node Dependency 



target_link_libraries(test_node ${catkin_LIBRARIES})  #test_node link lib -> executable
target_link_libraries(cam_node ${catkin_LIBRARIES})   #cam_node link lib ->  executable
target_link_libraries(track_node ${catkin_LIBRARIES}) #track_node link lib -> executable

target_link_libraries(test_node ${raspicam_CV_LIBS})
target_link_libraries(cam_node ${raspicam_CV_LIBS})
target_link_libraries(track_node ${raspicam_CV_LIBS})

#target_link_libraries (vis_pkg ${raspicam_CV_LIBS})
include_directories(${OpenCV_INCLUDE_DIRS})


