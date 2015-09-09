import serial 
from time import sleep
ser1 = serial.Serial('/dev/tty.usbserial-DA011JAU',9600)
ser2 = serial.Serial('/dev/tty.usbmodem1431',9600)
sleep(4.5)
ser1.write('1')
ser2.write('1')
