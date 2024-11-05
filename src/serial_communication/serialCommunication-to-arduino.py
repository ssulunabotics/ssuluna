#Made by: Spencer Odom
#For EE lunar robot project. The goal was to be able to SSH into the raspberry pi and runt this python script to activate LEDS on the arduino.
#The goal was accomplished and this is fundamental to our test robot. we now can use this to run our motors and test them wirelessly when SSH'd into the pi

import serial
import time

# Specify the serial port and the baud rate
arduino_port = "/dev/ttyACM0"  # Change this to the port you found earlier (e.g., ttyUSB0)
baud_rate = 9600  # Match this with the baud rate set in your Arduino sketch

# Initialize the serial connection
ser = serial.Serial(arduino_port, baud_rate, timeout=1)

# Give the Arduino some time to reset after establishing the connection
time.sleep(2)

# Function to send data to Arduino
def send_signal_to_arduino(data):
    print(f"Sending: {data}")
    ser.write(data.encode())  # Send the data as bytes
    time.sleep(1)  # Wait for the data to be processed

try:
    while True:
        command = input("Enter up, down, left, right to signal LEDs (Enter q to quit: ")
        if command == 'q':
            break
        send_signal_to_arduino(command)

except KeyboardInterrupt:
    print("Program interrupted")

finally:
    ser.close()  # Always close the serial connection when done
