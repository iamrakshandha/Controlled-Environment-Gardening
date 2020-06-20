# Controlled-Environment-Gardening
SOFTWARES AND PLATFORMS USED

1.	IDE - Arduino (Version: 1.8.9, OS: Windows Installer for Windows XP and up)
2.	IDE – PyCharm (Version: 2019.3.1 Professional Edition, Build: #PY-193.5662.61, OS: Windows)
3.	Amazon Web Services (Storage as a Service, QuickSight)
4.	Blynk Library (Version: 0.6.1) and Blynk Android Mobile Application (Version: 2.27.12)


INSTALLATION AND CONFIGURATION

1.	INSTALLING ARDUINO ON WINDOWS
•	Go to Arduino’s Official Website and download the Arduino IDE - https://www.arduino.cc/en/main/software
•	Click on ‘Windows Installer for Windows XP and up’.
•	Click on ‘Just Download’.

2.	INSTALLING PyCharm ON WINDOWS
•	Go to PyCharm’s Official Website and download the PyCharm IDE -  https://www.jetbrains.com/pycharm/download/#section=windows
•	Click on ‘Windows’ option and download the Professional Edition of PyCharm.

IMPLEMENTATION

1.	RUNNING THE CODE IN ARDUINO IDE

•	Install and open Arduino IDE.
•	Click on ‘File’-> ‘Open’ to open the Arduino sketches from the location in computer where Arduino sketches have been saved. 
•	Click on ‘Verify’ for compiling the code and ‘Upload’ to upload the compiled code to the Arduino board.
•	Check Serial Monitor for output.

2.	RUNNING THE CODE IN PYCHARM 

•	Install and open PyCharm.
•	Install boto3 package inside PyCharm by clicking File -> Settings -> Project: photo -> Project Interpreter -> + -> search for boto3 -> Install package. Boto3 package in PyCharm is used to upload photo.csv to AWS S3 bucket created.
•	Click on ‘File’-> ‘Open’ to open the PyCharm folder ‘photo’ containing three python scripts and one csv file (photo.csv) is generated when script.py is run. Script.py is run to covert Arduino serial monitor data to csv file, cal.py is run to calculate light energy used and upload.py is run to upload photo.csv to S3 bucket.
•	Right-click on python scripts and click ‘Run script’ to run the scripts.

3.	AWS 

•	Sign up or Log in to AWS Console - https://aws.amazon.com/console/
•	Use ‘Find Services search box’ to search for AWS services.
•	Direct to Simple Storage Service (S3) Service, click on ‘create bucket’ and create a new bucket named ‘projectlightintensity’. 
•	Click on the ‘bucket -> Permissions tab’ to enable public access. Make the S3 bucket publicly accessible.
•	When upload.py is run in PyCharm, photo.csv is uploaded to projectlightintensity bucket as lightintensity object. 
•	Direct to QuickSight service, click on ‘New analysis’ -> ‘New data set’.
•	Create a data set using S3 as a data source. Provide a data source name (could be any name) and upload the manifest (json) file containing the Object URL to connect to S3 object.
•	Light intensity field, LED state field and time filed are considered to plot the graph in AWS QuickSight.

4.	BLYNK

•	Download the blynk library from GitHub and unzip them (libraries folder and tools folder) - https://github.com/blynkkk/blynk-library/releases/tag/v0.6.1
•	Install the Blynk android application from Play Store
•	Log in using Facebook or create an account.
•	Create new project.
•	When a new project is created, an authentication token is sent to your specified email.
•	Configure the android application exactly as your hardware connection setup.
•	Include the authentication token in the program and run it (Blynk.ino) in the Arduino IDE.
•	Open command prompt and direct to scripts folder in the libraries folder - C:\Users\Rakshandha Kannappan\Documents\Arduino\libraries\Blynk\scripts
•	Run blynk-ser.bat and select COM5
•	Hardware components, Arduino code and android app will now be connected for monitoring and controlling sensors.
