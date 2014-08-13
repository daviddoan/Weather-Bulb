from pyowm import OWM
import serial
import time

ser = serial.Serial(3) #replace with COMPORT -1
ser.baudrate = 9600
ser.close()
ser.open()

API_key = '2417d98e524df449d7930e013b398e5d'
owm = OWM(API_key)
obs = owm.weather_at('Boston,US')
w = obs.get_weather()
temp = w.get_temperature()['temp'] # pulls temperature in kelvin
temp = (9/5)*(temp - 273) + 32 #converts to fahrenheit
wind = w.get_wind()['speed']


while True:
	if temp > 90:
		if wind > 10:
			ser.write(str(5).encode()) 
		else:
			ser.write(str(1).encode())
	elif temp < 90 and temp > 75:
		if wind > 10:
			ser.write(str(5).encode())
		else:
			ser.write(str(2).encode())
	elif temp <= 75 and temp > 60:
		if wind > 10:
			ser.write(str(6).encode())
		else:
			ser.write(str(4).encode())
	elif temp <= 60:
		if wind > 10:
			ser.write(str(6).encode())
		else:
			ser.write(str(3).encode())	
	time.sleep(600)	

