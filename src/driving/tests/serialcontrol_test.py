# TEST ROUTINE WITHOUT USER INPUT

import serial
import time

# Configure the serial port (adjust '/dev/ttyACM0' as necessary)
ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
time.sleep(2)  # Wait for the connection to establish

def send_command(command, speed):
    # Create a message with start and end markers
    message = f"{command}{speed}"
    ser.write(message.encode('utf-8'))

def routine():
    # Define a sequence of commands with speeds
    command_sequence = [
        ('f', 150),  # Move forward at speed 150
        ('r', 100),  # Turn right at speed 100
        # ('b', 150),  # Move backward at speed 150
        # ('l', 100),  # Turn left at speed 100
        ('s', 000),    # Stop
    ]

    # Loop through the sequence
    for command, speed in command_sequence:
        print(f"Sending command: {command}, Speed: {speed}")
        send_command(command, speed)  # Send the command and speed
        time.sleep(2)  # Wait 2 seconds before sending the next command

    # Close the serial connection
    ser.close()

if __name__ == "__main__":
    routine()
