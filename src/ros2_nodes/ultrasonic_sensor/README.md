When you first plug the arduino into the pi, run:

```bash
sudo chmod 666 /dev/ttyACM0
```

When updating ros module code:

```bash
colcon build --packages-select ultrasonic_sensor
source install/setup.bash
ros2 run ultrasonic_sensor arduino_publisher
```

To view the topic it publishes to:

```bash
ros2 topic echo /ultrasonic_data
```