import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/pi4ubuntumate/ssuluna/src/ros2_nodes/ultrasonic_sensor/install/ultrasonic_sensor'
