import random



class posCalc:
    def __init__(self,winH,winW,ballH,ballW,playerH,playerW):
        self.ballHeight = ballH
        self.ballWidth = ballW
        self.playerHeight = playerH
        self.playerWidth = playerW
        self.winHeight = winH 
        self.winWidth = winW
        self.ballMovingUp = True
        self.ballMovingLeft = False


    def ballInBounds(self,x,y,p1Pos,p2Pos): #checks if the ball is on the screen 
        if (y+self.ballHeight > self.winHeight): #check for top and bottom boundary
            self.ballMovingUp = False
        elif (y < 0):
            self.ballMovingUp = True
        if (x+self.ballWidth > self.winWidth): #sends a score message if someone scores
            self.ballMovingUp = bool(random.randint(0,1))
            self.ballMovingLeft = False
            return("p1Score")       
        elif (x < 0):
            self.ballMovingUp = bool(random.randint(0,1))
            self.ballMovingLeft = True
            return("p2Score")
        if (x < self.playerWidth):
            if (y < p1Pos+self.playerHeight and y+self.ballHeight > p1Pos ):
                self.ballMovingLeft = False

        elif (x+self.ballWidth > self.winWidth-self.playerWidth):
            if (y < p2Pos+self.playerHeight and y+self.ballHeight > p2Pos ):
                self.ballMovingLeft = True


    def moveBall(self,ballx,bally,p1Pos,p2Pos): #checks if the ball is colliding with a player, or a boundry, then moves it accordingly
        self.ballInBounds(ballx,bally,p1Pos,p2Pos)
        if self.ballMovingLeft:
            ballx = ballx + 2
        else:
            ballx = ballx - 2

        if self.ballMovingUp:
            bally = bally + 2
        else:
            bally = bally - 2
        return((ballx,bally))
