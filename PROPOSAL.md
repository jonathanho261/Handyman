# Final Project Proposal
## Outside library: OpenCV
link: https://opencv.org/ 
+ OpenCV is an open source computer vision software library based in C++, Java, and Python. I plan to utilize OpenCV to interpret hand movements from the user.

## OpenFrameWorks Libraries:  App and Graphics
link: https://openframeworks.cc/documentation/
+ I plan to use the App library to create the main viewing window for my application and it will be used to monitor the state of the application
+ I plan to use the Graphics library to display different aspects of my application.

## Project Overview:
+ Will use OpenFrameWorks to develop main GUI which will consist of a main game window, with a small screen that displays the user through a webcam
+ User will control the game through the their hand movements (either by tapping/swiping/moving hand)
  * In order to control the game, the user must first initialize their hand through the webcam
  * User will hold up hand to match a computer-drawn hand displayed over the webcam image
  * Once the hand has been initialized, the computer-drawn hand will be removed
+ Game play will be very simple.
  * Most likely just an infinite obstacle traversal game that speeds up as the user progresses further into the game
  * Will be in 2D (Like the Google dinosaur game)
  * Goal is to go as far as possible
+ Additional feature if time allows
  * Storing high scores through a database online rather than writing to a file
  * Adding mini games or different difficultly levels
