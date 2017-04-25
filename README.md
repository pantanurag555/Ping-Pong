# Ping-Pong
A C++ based Ping-Pong game using multi-threading for Windows

There are 2 versions of the game:

1. CvsCPong : In this version of the game, the computer plays against itself with both paddles programmed to detect the motion of the ball and move accordingly to keep the ball from touching their end of the wall.

2. PvsCPong : In this version of the game, the user uses the up and down arrow keys to move his paddle while the computer controls the other paddle. This version uses multithreading in C++ to wait for imput from user and if the user doesn't enter any input, his chance gets forfeited and the ball continues moving.

The game has been programmed to finish when either player scores 3 points against the opposition.
