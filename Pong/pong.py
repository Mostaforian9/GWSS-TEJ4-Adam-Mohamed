import ardRead
import positions
import pyglet
import time
from pyglet import *


#making fullscreen window and get size
win = window.Window(fullscreen=True)
winWidth = win.get_size()[0]
winHeight = win.get_size()[1]

#setting up players
batch = pyglet.graphics.Batch()

playerWidth = 20
playerHeight = 100
ballHeight = 20
ballWidth = 20
ballPos = positions.posCalc(winHeight,winWidth,ballHeight,ballWidth,playerHeight,playerWidth)

#creating the graphics for paddles and ball
p1 = shapes.Rectangle(0, ardRead.readPositions()[0], playerWidth, playerHeight, color=(255,255,255), batch=batch)
p2 = shapes.Rectangle(winWidth-playerWidth, ardRead.readPositions()[1], playerWidth, playerHeight, color=(255,255,255), batch=batch)
ball = shapes.Rectangle(100,500, ballWidth, ballHeight, color=(255,255,255), batch=batch)


def update(dt):
    playerPositions = ardRead.readPositions()
    p1.y = playerPositions[0] + 550
    p2.y = playerPositions[1]
    ball.position = ballPos.moveBall(ball.x,ball.y,p1.y,p2.y)
    win.clear()
    batch.draw()    
if __name__ == '__main__':
    pyglet.clock.schedule_interval(update, 1 / 120.0)
    app.run()