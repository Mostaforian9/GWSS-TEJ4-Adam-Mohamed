import ardRead
import positions
import pyglet
import time
from pyglet.window import key
from pyglet import *


#making fullscreen window and get size
win = window.Window(fullscreen=True)
winWidth = win.get_size()[0]
winHeight = win.get_size()[1]

#setting up players and keyboard
gameElements = pyglet.graphics.Batch()
title = pyglet.graphics.Batch()
score = pyglet.graphics.Batch()
keyboard = key.KeyStateHandler()
win.push_handlers(keyboard)

playerWidth = 20
playerHeight = 100
ballHeight = 20
ballWidth = 20
position = positions.posCalc(winHeight,winWidth,ballHeight,ballWidth,playerHeight,playerWidth)

#creating the graphics for paddles and ball
p1 = shapes.Rectangle(0, ardRead.readPositions()[0], playerWidth, playerHeight, color=(255,255,255), batch=gameElements)
p2 = shapes.Rectangle(winWidth-playerWidth, ardRead.readPositions()[1], playerWidth, playerHeight, color=(255,255,255), batch=gameElements)
p1Points = 0
p2Points = 0
ball = shapes.Rectangle(100,500, ballWidth, ballHeight, color=(255,255,255), batch=gameElements)

#creating graphics for the score

p1Score= pyglet.text.Label(str(0),
                          font_name='Dropy',
                          font_size=100,
                          x=winWidth/3 -50, y=winHeight-150 ,
                          bold = True,
                          batch=score)

p2Score = pyglet.text.Label(str(0),
                          font_name='Dropy',
                          font_size=100,
                          x=winWidth*2/3, y=winHeight-150 ,
                          bold = True,
                          batch=score)
fieldLine = shapes.Rectangle(winWidth/2,0 , 2, 300000, color=(255,255,255), batch=score)

def update(dt):

    #playerPositions = ardRead.readPositions()    
    if keyboard[key.W]: #reads keyboard input to move players
        p1.y = position.movePlayer(p1.y,True)
    if keyboard[key.S]:
        p1.y = position.movePlayer(p1.y,False)    
    if keyboard[key.UP]:
        p2.y = position.movePlayer(p2.y,True)
    if keyboard[key.DOWN]:
        p2.y = position.movePlayer(p2.y,False)   

    ball.position = position.moveBall(ball.x,ball.y,p1.y,p2.y) #moves the ball

    if position.p1Score(ball.x): #checks if a player scored
        p1Score.text = str(position.p1Points)
        ball.position=(winWidth/2,winHeight/2)
    if position.p2Score(ball.x):
        p2Score.text = str(position.p2Points)
        ball.position=(winWidth/2,winHeight/2)
    win.clear()
    gameElements.draw()
    score.draw()

if __name__ == '__main__':
    pyglet.clock.schedule_interval(update, 1 / 120)
    app.run()



    #creating graphics for the start screen
# pong = pyglet.text.Label('PONG',
#                           font_name='Dropy',
#                           font_size=100,
#                           x=winWidth/2, y=winHeight/2 ,
#                           bold = True,
#                           batch=title)

# pressStart = pyglet.text.Label('PRESS START',
#                           font_name='Dropy',
#                           font_size=100,
#                           x=winWidth/4, y=winHeight/4 ,
#                           bold = True,
#                           batch=title)
# p4 = shapes.Rectangle(winWidth/2, winHeight/2, 1000000, 5, color=(255,255,255), batch=gameElements)
# p3 = shapes.Rectangle(winWidth/2, winHeight/2, 5, 1000000, color=(255,255,255), batch=gameElements)