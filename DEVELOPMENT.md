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

