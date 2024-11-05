import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import serial
import time

class ArduinoPublisher(Node):
    def __init__(self):
        super().__init__('arduino_publisher')
        # Set up the publisher
        self.publisher_ = self.create_publisher(String, 'ultrasonic_data', 10)
        # Set up the serial connection
        self.ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
        time.sleep(2)  # Wait for the connection to stabilize

        # Create a timer to call the read_and_publish function every second
        self.timer = self.create_timer(0.1, self.read_and_publish)

    def read_and_publish(self):
        if self.ser.in_waiting > 0:
            data = self.ser.readline().decode('utf-8').strip()
            self.get_logger().info(f'Received: {data}')
            # Publish the data
            msg = String()
            msg.data = data
            self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    arduino_publisher = ArduinoPublisher()
    rclpy.spin(arduino_publisher)
    arduino_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
