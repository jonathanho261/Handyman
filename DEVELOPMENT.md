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
