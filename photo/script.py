import serial
import time
import datetime
import csv

serial = serial.Serial('COM5', 9600)

print("connected to: " + serial.portstr)
filename = "photo" + ".csv"
print(filename)

with open(filename, 'w', newline='') as csvFile:
	while True:
		try:
			sensorValue = str(serial.readline().decode('utf-8'))
			sensorValue = sensorValue.rstrip()
			atTime = time.strftime('%H:%M:%S')
			print(atTime + "->" + sensorValue)
			column = sensorValue.split(":")
			print(column)
			writer = csv.writer(csvFile, delimiter=",")
			writer = csv.writer(csvFile, delimiter=",")
			writer.writerow([atTime, column[0], column[1],column[2]])
		except:
			csvFile.close()
			print("Keyboard Interrupt")
			break
serial.close()


#reading data from serial port
#serial port is USB port
#converted to serial port virtually
# converts from one encoding scheme to another
# strftime method returns a string representing date and time using date, time or datetime object
# csv.write returns writer object responsible for converting the data into delimited strings
# writerow function writes a row of data
#open(filename, mode) -> file object
#a Open the file in append mode i.e add new data to the end of the file.
