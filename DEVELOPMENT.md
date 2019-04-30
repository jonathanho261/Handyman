# Development
### Stage 1: Setting up OpenCV Library

(April 8, 2019)
1. Installed OpenCV through Homebrew
2. Cloned OpenCV repositories off of GitHub
3. Tried to follow step by step instructions from YouTube vidoes from years ago
4. Could not access library, so read online instructions
5. cmake command not working through command line so cmake application was downloaded and utilized to create the make files
6. OpenCV was built through the source
7. Tried to build simple webcam, errors regarding the includes and files
8. Once errors were fixed, program crashed because of Info.plist file was not present. Error message:
"This app has crashed because it attempted to access privacy-sensitive data without a usage description.  The app's Info.plist must contain an NSCameraUsageDescription key with a string value explaining to the user how the app uses this data."
9. Created my own info.plist and added it to the identity of project, but the plist file will not allow me to add it to the target membership
10. Decided to work on it another day after 9 hours of attempting to set up OpenCV


(April 10, 2019)
1. Went to Office hours for 2 hours to try to fix Info.plist errors.
2. Built from source again and tried to implenment OpenCv through the command line
3. Nothing I tried worked. Another 5 hours down the drain.

(April 18, 2019)
1. Tried new approach, used ofxcv along with OpenCv. Added to addons, added the header search files, library search files, and linker flags.
2. Thought OpenCv Info.plist would work (in which it did)!
3. Copied code from github to have something working. 
4. Worked through linker errors.
5. Got webcam to show up -> getting progress. Now we can actually start coding. (will add code from test project to this project in next commit)

(April 19, 2019)
1. Experimented with background learning and contour finding.
2. Added functionality where user can click a key to learn the background. Then, when there is movement, a panel will show the difference between the learned background and the user's movement.
3. Started playing around with detecting HSV colors. Hardcoded certain HSV values for a green glove and used the mouse to detect if the glove was found or not.
** Main take-aways from today: figured out background learning and detecting user's movements. Learned about HSV.

(April 20, 2019)
1. Enhanced HSV detection. Have a broader range of values to detect the HSV values for the green glove.

(April 21, 2019)
1. Figured out how to only get a range of HSV colors with a scrollbar. 
2. Now can isolate the glove as the foreground and eliminate the face of the user and the background.
**Next goal: intertwine the detecting movement (with the learned background) and the isolation of the glove to detect only the movements of the glove.


(April 22, 2019)
1. Reorganized code so that it is in better coding practices.
2. Attempted to merge isolated foreground with contour drawing.

(April 23, 2019)
1. Successfully draws coutours based on isolated glove through the HSV color isolation
2. Added centriod drawing to hand
3. Started playing with reading if the hand is going left/right/up/down. Still very buggy, will continue to work on it later.

(April 24, 2019) 
1. Added finding average of all contours for centroid and velocity -> thus making hand reading significantly more accurate and reliable

(April 25, 2019)
1. Added game file and dino file
2. Game file now just addes the ground into the background
3. Dino file now animates the dinosaur by moving it's leg up and down
**Next goal, get dino game to animate with cactus. Final step is to link dino game with hand movement

(April 26, 2019) 
1. Added update and draw to the ground so that the ground will animate and move to the left of the screen

(April 28, 2019)
1. Added animation to make the dinosuar jump (have not yet connected it to OpenCV but it works fine)
2. Removed a lot of magic numbers for testing within the code
3. Also added animation to make the dinosaur duck.
**Photoshop was used to crop and edit the images of the dinosaur so that I can alternate between the two images for the animation to happen

(April 29, 2019)
1. Completed all of the cactus animation (so that random cacti show up and code takes care of removing the cacti from memory when the cactus is moves off the screen)
2. Added collision mechanism between the cacti and the dinosaur -> game will now end if the two share a few critical points. A little buggy but I think it will do for the final project.
3. Changed all my passing by value to unique_ptrs so that it is much more efficient.
4. Added start button, restart functionality, and a score menu.


Final notes: Did not add arerial obstacles because of time contraints. Collision mechanisms still a bit buggy. Lots of magic numbers inside the code (because have not found a good way to contour the edges of the transparent images so that collisions are really accurate -> all my collisions are trial and error points). Overall, the project met what I wanted to do except for the few bugs listed above. I would like to extend this project further in the future.
