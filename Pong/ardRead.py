import serial
#set up player positions
posLimit = 255
def readPositions():
        # ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
        # ser.flush()
        # line = ser.readline().decode('utf-8').rstrip()
        # line.split(":")
        # if line[0] == "p1":
        #     p1Pos = line[1]
        # if line[0] == "p2":
        #     p2Pos = line[1]
        # positions = [p1Pos,p2Pos]
        return(10,10)