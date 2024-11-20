# Drive Motor Controller
Listens to velocity commands published by teleop twist joy on the network.  
Converts to direction and speed i.e.  
"f150" for forward at 150

When you first plug the arduino into the pi, run:

```bash
sudo chmod 666 /dev/ttyACM0
```
to let the Pi access the USB port

You may need to source

```bash
source /install/setup.bash
```

To run the package:

```
ros2 run drive_motor_controller drive_motor_controller
```

Now the node is running on the pi or the rover

Set this as a linux env variable or append this to the .bashrc file on both computers

```bash
ROS_DOMAIN = 0 
```

Then fire up teleop_twist_joy on another computer on the network and the...
drive_motor_controller will interpret the messages over cmd_vel

```bash
ros2 launch teleop_twist_joy teleop-launch.py joy_config:='xbox'
```

```
ros2 topic echo joy
```

cmd_vel breaks down into forward and angular velocities


When updating ros module code:

```bash
colcon build --packages-select drive_motor_controller
source install/setup.bash
```

To view the topic it publishes to:

```bash
ros2 topic echo /drive_motor_controller
```