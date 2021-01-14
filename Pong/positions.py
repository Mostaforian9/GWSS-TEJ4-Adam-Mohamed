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
        self.p1Points = 0
        self.p2Points = 0
    def p1Score(self,ballx):
        if (ballx+self.ballWidth > self.winWidth): #checks left and right boundary, and checks if p1 has scored
            self.ballMovingUp = bool(random.randint(0,1))
            self.ballMovingLeft = False
            self.p1Points += 1
            return(True)
        return(False)

    def p2Score(self,ballx):  #checks left and right boundary, and checks if p2 has scored      
        if (ballx < 0):
            self.ballMovingUp = bool(random.randint(0,1))
            self.ballMovingLeft = True
            self.p2Points += 1
            return(True)
        return(False)

    def ballInBounds(self,ballx,bally,p1Pos,p2Pos): #checks if the ball is on the screen 
        if (bally+self.ballHeight > self.winHeight): #check for top and bottom boundary
            self.ballMovingUp = False
        elif (bally < 0):
            self.ballMovingUp = True


    def ballOnPaddle(self,ballx,bally,p1Pos,p2Pos): #checks if the ball has collided with a paddle
        if (ballx <= self.playerWidth and ballx > 0): 
            if (bally+self.ballHeight > p1Pos and bally < p1Pos+self.playerHeight ):
                self.ballMovingLeft = False

        elif (ballx+self.ballWidth >= self.winWidth-self.playerWidth and ballx+self.ballWidth < self.winWidth):
            if (bally < p2Pos+self.playerHeight and bally+self.ballHeight > p2Pos ):
                self.ballMovingLeft = True


    def moveBall(self,ballx,bally,p1Pos,p2Pos): #checks if the ball is colliding with a player, or a boundry, then moves it accordingly
        self.ballInBounds(ballx,bally,p1Pos,p2Pos)
        self.ballOnPaddle(ballx,bally,p1Pos,p2Pos)
        if self.ballMovingLeft:
            ballx = ballx - 2
        else:
            ballx = ballx + 2

        if self.ballMovingUp:
            bally = bally + 2
        else:
            bally = bally - 2
        return((ballx,bally))

    def movePlayer (self,y,up): #checks if the player can move up or down and returns the y position if possible 
        if up: 
            if y+self.playerHeight < self.winHeight:
                return(y+5)
        if not up:
            if y > 0:
                return(y-5)
        return y
