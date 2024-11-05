import serial
import time

# Connect to Arduino
ser = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)  # Wait for the connection to initialize

while True:
    if ser.in_waiting > 0:
        data = ser.readline().decode().strip()
        print("Received from Arduino:", data)

