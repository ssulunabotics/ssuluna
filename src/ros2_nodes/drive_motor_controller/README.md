# Drive Motor Controller
Listens to velocity commands published by teleop twist joy on the network.  
Converts to direction and speed i.e.  
"f150" for forward at 150

When you first plug the arduino into the pi, run:

```bash
sudo chmod 666 /dev/ttyACM0
```
to let the Pi access the USB port

To run the package:

```
ros2 run drive_motor_controller drive_motor_controller
```

When updating ros module code:

```bash
colcon build --packages-select drive_motor_controller
source install/setup.bash
```

To view the topic it publishes to:

```bash
ros2 topic echo /drive_motor_controller
```