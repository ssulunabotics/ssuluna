# ssuluna
Jordan Nakamoto

Outer Shell Designed for developer navigation I hope...
SRC Scoped by Core Rover Functions
~  dig, drive, dump, perception
LOW LEVEL
~  each functional group has hardware files (/ino), python interface, and ros messages
LOW-MID LEVEL
~  control_auto and control_manual have programs for controlling the rover
MID LEVEL
~  each functional group and control group ros messages are handled by ros nodes and published via topic to the state machine
HIGH LEVEL
~  the state machine changes the robot's behavior based on incoming data from nodes, accepting conditions to transition states

```
/ssuluna                              # Project root directory
│
├── /boot                              # Launch files and scripts to initialize various parts of the software stack
│   └── launch.sh                      # Main launch script to bring up all rover systems
│
├── /config                            # Configuration files for the rover's subsystems (ROS)
│   └── params.yaml                    # Global configuration parameters for the rover
│
├── /documentation/jordan              # Documentation for the project, just jot stuff down and we'll compile it with GPT later as needed
│   └── ...                            
│
├── /libraries                         # External libraries or custom dependencies, will probably .gitignore these and record as install scripts
│
├── /misc                              # Miscellaneous files (tools, helper scripts, or extra resources)
│
├── /simulation                        # Gazebo and RViz simulation files for testing in a simulated environment
│   ├── rover_model.urdf               # The rover's URDF model for Gazebo simulation
│   └── gazebo.launch.py               # Launch file for running Gazebo simulations
│
├── /src                               # Core source code directory (handles all subsystem logic)
│   ├── /control_auto                  # Autonomous control logic and ROS2 nodes
│   │   └── navigation_node.py         # ROS2 node responsible for autonomous navigation
│   │   └── ...      
│   │
│   ├── /control_manual                # Manual control logic and ROS2 nodes
│   │   └── joystick_controller.py     # ROS2 node for manual control using a joystick or controller
│   │
│   ├── /digging                       # Digging subsystem logic and sensors
│   │   ├── dig_controller.py          # ROS2 node for controlling the digging mechanism
│   │   └── /ino                       # Arduino code for controlling the digging system hardware
│
│   ├── /driving                       # Driving subsystem logic and sensors
│   │   ├── motor_control.py           # ROS2 node for controlling the motors (wheel movement)
│   │   ├── wheel_encoders.py          # ROS2 node for reading wheel encoder data
│   │   └── /ino                       # Arduino code for controlling the motors and reading encoders
│
│   ├── /dumping                       # Dumping subsystem logic and sensors
│   │   ├── dump_controller.py         # ROS2 node for controlling the dumping mechanism
│   │   └── /ino                       # Arduino code for controlling the dumping system hardware
│
│   ├── /perception                    # Perception systems (camera, LiDAR, and other sensor logic)
│   │   ├── /cameras                   # Camera sensor handling and GPIO interaction
│   │   │   ├── CameraData.msg         # ROS message for camera data (e.g., AprilTag detection), not sure what else the camera will do yet
│   │   │   ├── LidarData.msg          # ROS message for LiDAR sensor data
│   │   │   ├── camera.py              # ROS2 node for handling camera data processing
│   │   │   ├── lidar.py               # ROS2 node for handling LiDAR data processing
│   │   │   └── /ino                   # Arduino code for camera and LiDAR hardware interface
│   │
│   ├── /load                          # Load sensors used in the digging and dumping subsystems
│   │   ├── LoadSensor.msg             # ROS message for load sensor data
│   │   ├── dig_load_sensor.py         # ROS2 node for managing load sensor data during digging
│   │   ├── dump_load_sensor.py        # ROS2 node for managing load sensor data during dumping
│   │   └── /ino                       # Arduino code for reading load sensor data
│   │
│   ├── /orientation                   # Orientation sensors (IMU is a gyrometer, accelerometer) for monitoring the rover's orientation
│   │   ├── imu_reader.py              # ROS2 node for handling IMU sensor data
│   │   └── /ino                       # Arduino code for IMU hardware
│
├── /recovery                          # Handles recovery routines when the rover gets stuck or needs assistance
│   └── stuck_recovery.py              # ROS2 node for initiating recovery actions
│
├── /ros2_nodes                        # Collection of all ROS2 nodes that handle various subsystems and tasks
│   └── ...                            # THESE WILL PUBLISH DATA AND STATE TO THE STATE MACHINE
│
├── /state_machine                     # MANAGES OVERALL high-level behavior of the rover (via state transitions, transition CONDITIONS)
│   ├── StateUpdate.msg                # ROS message for state machine updates (state transitions)
│   ├── rover_state_machine.py         # The core state machine logic
│   ├── /behaviors                     # behaviors or actions (not sure what to call it) the state machine can trigger (e.g., navigate, dig, transport)
│   └── /goals                         # High-level mission goals (e.g., explore, excavation, transport)
│
├── README.md                          # Project overview and setup instructions
├── launch.sh                          # BIG BUTTON, Top-level launch script for starting the rover's systems
├── Log.txt                            # Log file for tracking system events or debugging output
```