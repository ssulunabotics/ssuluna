import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import serial
import time

class SerialMotorController(Node):
    def __init__(self):
        super().__init__('drive_motor_controller')
        
        # Create a subscriber to the '/cmd_vel' topic
        self.subscription = self.create_subscription(
            Twist,
            '/cmd_vel',
            self.twist_callback,
            10)  # QoS profile depth 10
        self.subscription  # prevent unused variable warning

        # Configure the serial port (adjust '/dev/ttyUSB0' as necessary)
        self.ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
        time.sleep(2)  # Wait for the serial connection to establish
        
        self.get_logger().info("Drive motors node initialized.")

    def twist_callback(self, msg):
        # Convert Twist message to motor commands
        command, speed = self.convert_twist_to_command(msg)
        
        # Send the command over serial
        self.send_command(command, speed)
        self.get_logger().info(f"Sent command: {command}{speed}")

    def convert_twist_to_command(self, twist_msg):
        linear = twist_msg.linear.x
        angular = twist_msg.angular.z
        
        # Define a threshold for each motion to decide direction
        speed = int(abs(linear) * 255) if linear != 0 else int(abs(angular) * 255)

        # Determine command based on linear and angular velocities
        if linear > 0:
            command = 'f'  # Fodrive_motor_controllerrward
        elif linear < 0:
            command = 'b'  # Backward
        elif angular > 0:
            command = 'l'  # Turn left
        elif angular < 0:
            command = 'r'  # Turn right
        else:
            command = 's'  # Stop

        # Clamp speed between 0 and 255
        speed = min(max(speed, 0), 255)
        return command, speed

    def send_command(self, command, speed):
        # Create a message with a newline delimiter
        message = f"{command}{speed}\n"
        self.ser.write(message.encodrive_motor_controlde('utf-8'))

def main(args=None):
    rclpy.init(args=args)
    motor_controller = SerialMotorController()

    try:
        rclpy.spin(motor_controller)  # Keep the node active
    except KeyboardInterrupt:
        pass
    finally:
        motor_controller.ser.close()  # Close the serial connection
        motor_controller.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
