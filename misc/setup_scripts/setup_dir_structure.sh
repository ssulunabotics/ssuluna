#!/bin/bash
# SETUP DIR STRUCTURE.py
# Initializes Project Structure
# Jordan

# Base directory
mkdir -p rover_project/{src,simulation,config,tests,documentation,scripts}

# Source directories with feature-specific messages and services
mkdir -p rover_project/src/{driving,digging,dumping,sensors/{vision,load},state_machine,recovery,manual_control,autonomous_control,ros2_nodes}

# Driving feature files with messages and services
touch rover_project/src/driving/{motor_control.py,motor_control.ino,wheel_encoders.py,WheelEncoders.msg,ControlMotors.srv,hardware_config.yaml}

# Digging feature files with services and messages
touch rover_project/src/digging/{dig_controller.py,dig_controller.ino,StartDigging.srv,DiggingStatus.msg,hardware_config.yaml}

# Dumping feature files with messages
touch rover_project/src/dumping/{dump_controller.py,dump_controller.ino,DumpingStatus.msg,hardware_config.yaml}

# Sensors (vision and load) files and configurations
mkdir -p rover_project/src/sensors/vision
touch rover_project/src/sensors/vision/{camera.py,lidar.py,VisionData.msg,hardware_config.yaml}
mkdir -p rover_project/src/sensors/load
touch rover_project/src/sensors/load/{dig_load_sensor.py,dump_load_sensor.py,LoadSensor.msg,load_sensor.ino,hardware_config.yaml}

# IMU sensor file
touch rover_project/src/sensors/{imu_reader.py,hardware_config.yaml}

# State machine with custom message for state updates
touch rover_project/src/state_machine/{rover_state_machine.py,StateUpdate.msg}

# Recovery feature
touch rover_project/src/recovery/stuck_recovery.py

# Manual control files
touch rover_project/src/manual_control/{joystick_controller.py,hardware_config.yaml}

# Autonomous control with custom action definition
touch rover_project/src/autonomous_control/{navigation_node.py,PathPlanning.action,sensor_integration.py,hardware_config.yaml}

# ROS2 nodes (common across features)
touch rover_project/src/ros2_nodes/{driving_node.py,digging_node.py,dumping_node.py,vision_node.py,lidar_node.py,state_machine_node.py,recovery_node.py,manual_control_node.py,autonomous_control_node.py}

# Simulation directories and files
mkdir -p rover_project/simulation/{gazebo,rviz}
touch rover_project/simulation/gazebo/{rover_model.urdf,world.world,gazebo.launch.py,config.yaml}
touch rover_project/simulation/rviz/{rviz_config.rviz,rviz.launch.py}

# Config files
touch rover_project/config/{params.yaml,mode_config.yaml}

# Test directories
mkdir -p rover_project/tests/{driving,digging,dumping,vision,lidar,load_sensors,imu,state_machine,manual_control,autonomous_control,integration}

# Documentation and Scripts directories
mkdir -p rover_project/{documentation,scripts}

# README and documentation files
touch rover_project/README.md
touch rover_project/documentation/{overview.md,setup_guide.md,architecture.md}

echo "Directory structure created successfully!"