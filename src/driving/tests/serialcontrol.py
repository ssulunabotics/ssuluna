import curses
import serial
import time

# Configure the serial port (adjust '/dev/ttyUSB0' as necessary)
ser = serial.Serial('/dev/ttyACM0', 115200, timeout=100)
time.sleep(2)  # Wait for the connection to establish

def send_command(command, speed):
    # Create a message with start and end markers
    message = f"{command}{speed}\n"
    ser.write(message.encode('utf-8'))
    
def main(stdscr):
    # Set up curses
    curses.curs_set(0)  # Hide cursor
    stdscr.clear()
    stdscr.addstr("Enter command (f: forward, b: backward, l: left, r: right, s: stop, x: exit) and speed (0-255):\n")
    max_y, max_x = stdscr.getmaxyx()

    # Create a new window for scrolling commands
    win = curses.newwin(max_y - 2, max_x, 1, 0)
    win.scrollok(True)  # Enable scrolling in the window

    while True:
        win.addstr("Command: ")
        command = win.getch()  # Get a single character

        if command == ord('x'):  # Exit command
            break

        win.addstr(" Speed: ")
        speed_input = ""
        while True:
            char = win.getch()
            if char in (curses.KEY_ENTER, 10, 13):  # Enter key
                break
            elif char == curses.KEY_BACKSPACE or char == 127:  # Handle backspace
                if speed_input:  # Only remove if there's input
                    speed_input = speed_input[:-1]
                    win.delch(win.getyx()[0], win.getyx()[1] - 1)  # Delete character from screen
            else:
                speed_input += chr(char)
                win.addch(char)  # Display the character
        
        try:
            speed = int(speed_input)
            if speed < 0 or speed > 255:
                win.addstr("\nInvalid speed. Please enter an integer between 0 and 255.\n")
                continue
        except ValueError:
            win.addstr("\nInvalid speed. Please enter a valid integer.\n")
            continue

        # Map user input to command character
        if command == ord('f'):
            send_command('f', speed)  # Forward
        elif command == ord('b'):
            send_command('b', speed)  # Backward
        elif command == ord('l'):
            send_command('l', speed)  # Left
        elif command == ord('r'):
            send_command('r', speed)  # Right
        elif command == ord('s'):
            send_command('s', 0)       # Stop (speed is irrelevant)
        else:
            win.addstr("\nUnknown command. Use f, b, l, r, s, or x.\n")

        # Add a newline for readability and scroll if necessary
        win.addstr("\n")
        win.refresh()

    ser.close()  # Close the serial connection

if __name__ == "__main__":
    curses.wrapper(main)
