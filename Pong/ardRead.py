import serial
#set up player positions
posLimit = 255
def readPositions():
        positions = [0,0]
        ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
        ser.flush()
        line = ser.readline().decode('utf-8').rstrip()
        line.split(":", " ")
        if line[0] == "p1":
             positions[0] = line[1]
        if line[2] == "p2":
             positions[1] = line[3]
        return(positions)