# Final Project
## Introduction
Handyman is an exectuable game that reads the movements of the user's hand (isloated by a glove) to command the movements of the character.

## External Libraries
1. OpenCV:
+ used to capture the user's movement, isolate the color of the glove, contour the movements of the hand, and to caculate the relative velocity of the centroid of the isolated hand.
2. OpenFrameWorks:
+ used to build the GUI of the app, create the window, and to setup, update, and draw the exectuable.

## How to play
1. First, to isolate the hand, a glove of a different color must be placed on the hand so that program will not confuse other parts of your body as your hand.
2. Use the gui slider to find the right HSV values so that only a white hand is shown in the black image on the right. Try to eliminate as much noise in the background as possible.
3. Once the hand has been successfully isolated, the contours of the hand should be drawn on the panel depiciting the webcam and a red dot should be drawn representing the centroid. Make sure the centroid is drawn at the center of the hand or else there may be errors in reading the hand movements. Hold the hand in a fist to ensure proper reading.
4. Now that the hand has been properly registered, click the start button to start the game. A rectangle showing the game should appear. To control the dinosaur, move your hand up to jump, shake left and right to duck. Avoid the cactus or else the game is over.
5. To restart the game, just click the start button again.
