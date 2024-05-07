import random
import sys
import pygame
from pygame.locals import *

# acceleration_x, acceleration_y = ball
pygame.init()

# display info
width, height = 800, 600

# double buffering enabled to improve display performance
screen = pygame.display.set_mode((width, height), DOUBLEBUF)
pygame.display.set_caption("Balls")
font = pygame.font.Font(None, 14)
# constants
MAX_VEL, MIN_VEL = 500, 100
BALL_RAD = 20
FRAME_CAP = 60
MAX_COLOR = 255
BUTTON_POS = (700, 0)
BUTTON_SIZE = (100, 75)

class Ball:
    def __init__(self):
        # centers ball
        self.x = width // 2
        self.y = height // 2

        # random velocity
        velocity_x = random.choice([-1, 1]) * random.randint(MIN_VEL, MAX_VEL)
        velocity_y = random.choice([-1, 1]) * random.randint(MIN_VEL, MAX_VEL)
        # force = impule = change in momentum = mass * (velocity2 - velocity1) - > (mass * (velocity2 - velocity1))/ mass = acceleration
        self.dx = velocity_x
        self.dy = velocity_y

        # random color
        self.color = (random.randint(0, MAX_COLOR), random.randint(0, MAX_COLOR), random.randint(0, MAX_COLOR))

    def update_position(self):
        # uses runge-kutta 4th order for more accurate position estimation

        # you can think of this like a midpoint reimann sum where you find a value between
        # each point and the smaller the distance the more accurate the integral becomes

        # time increment -> change in time -> time differential -> dt
        # (the smaller dt is the more accurate, but takes longer and is harder on the computer to compute)
        delta_time = 0.01
        
        # first order
        k1x, k1y = self.dx * delta_time, self.dy * delta_time # finds an initial approximation for the position

        # second order
        k2x, k2y = (self.dx + k1x / 2) * delta_time, (self.dy + k1y / 2) * delta_time 
        # think of the equation like delta_time / 2. In that case this finds a more accurate position approximation by multiplying by a smaller dt
        
        # third order
        k3x, k3y = (self.dx + k2x / 2) * delta_time, (self.dy + k2y / 2) * delta_time 
        # similar to the second order, but uses the more accurate k2x and k2y

        # fourth order
        k4x, k4y = (self.dx + k3x) * delta_time, (self.dy + k3y) * delta_time 
        # similar to k1x with the larger dt, but with improved accuracy by using k3x and k3y
        
        # takes the weighted avg. the 2* indicates which were the most accurate and allows them to have the most impact on the avg
        self.x += (k1x + 2 * k2x + 2 * k3x + 2 * k4x) / 6
        self.y += (k1y + 2 * k2y + 2 * k3y + 2 * k4y) / 6

        self.check_boundaries()

    def check_boundaries(self):
        # check if the ball is outside the screen boundaries
        if self.x < 0:
            self.x = 0
            self.dx = abs(self.dx)

        elif self.x > width:
            self.x = width
            self.dx = -abs(self.dx)

        if self.y < 0:
            self.y = 0
            self.dy = abs(self.dy)

        elif self.y > height:
            self.y = height
            self.dy = -abs(self.dy)
    
    # indicates this operates on the Ball class and not on the instances of each ball
    @classmethod 
    def make_ball(cls, ball_list):
        # makes a new ball
        new_ball = cls()

        # keeps track of how many balls there are
        ball_list.append(new_ball)

class Button:
    def __init__(self):
        self.screen = screen
        self.color = (MAX_COLOR, 0, 0)
        self.position = BUTTON_POS
        self.size = BUTTON_SIZE
        self.mouse_x = None
        self.mouse_y = None
    
    def mouse_pos(self):
        self.mouse_x, self.mouse_y = pygame.mouse.get_pos()

    def draw_button(self):
        pygame.draw.rect(self.screen, self.color, (*self.position, *self.size))
        text = font.render(f"Cursor's at ({self.mouse_x}, {self.mouse_y})", True, (0, 0, 0))
        self.screen.blit(text, self.position)

    def check_click(self, balls):
        if (self.position[0] <= self.mouse_x <= self.position[0] + self.size[0] and self.position[1] <= self.mouse_y <= self.position[1] + self.size[1]):
            Ball.make_ball(balls)

balls = []
button = Button()

# game loop
clock = pygame.time.Clock()
while True:
    for event in pygame.event.get():
        # checks if you press the button
        if event.type == pygame.MOUSEBUTTONDOWN:
            button.check_click(balls)

        elif event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    # clear the screen
    screen.fill((MAX_COLOR, MAX_COLOR, MAX_COLOR))

    # make balls move
    for ball in balls:
        ball.update_position()


    # draw all balls on the screen
    for ball in balls:
        pygame.draw.circle(screen, ball.color, (int(ball.x), int(ball.y)), BALL_RAD)

    # draw button
    button.mouse_pos() 
    button.draw_button()

    # update display
    pygame.display.flip()

    # frame cap
    clock.tick(FRAME_CAP)
