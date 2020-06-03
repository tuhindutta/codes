#Temperature conversion

import math
tempunit=input('Enter temperature unit type, (C)elcius / (F)arenheit:')
temp=float(input('Enter temperature: '))

if tempunit.lower() == 'c':
    conv = float((9*(temp/5))+32)
    print(f'Temperature in Farenheit: {conv}°F')
    
elif tempunit.lower() == 'f':
    conv = float(((temp-32)*5)/9)
    print(f'Temperature in Celcius: {conv}°C')
else:
    print('Invalid Input')
