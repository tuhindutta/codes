#Temperature conversion

import math
tempunit=input('Enter temperature unit type, (C)elcius / (F)arenheit/ (K)elvin:')
temp=float(input('Enter temperature: '))

if tempunit.lower() == 'c':
    conv = float((9*(temp/5))+32)
    conv2 = float(temp + 273.15)
    print(f'Temperature in Farenheit: {conv}°F')
    print(f'Temperature in Kelvin: {conv2}°K')

elif tempunit.lower() == 'f':
    conv = float(((temp-32)*5)/9)
    conv2 = float(conv + 273.15)
    print(f'Temperature in Celcius: {conv}°C')
    print(f'Temperature in Kelvin: {conv2}°K')

elif tempunit.lower() == 'k':
    conv = float(temp - 273.15)
    conv2 = float((9*(conv/5))+32)
    print(f'Temperature in Celcius: {conv}°C')
    print(f'Temperature in Farenheit: {conv2}°F')

else:
    print('Invalid Input')
