#Distance in different units

import math

dist = int(input("Enter distance in km: "))

print(f'Distance in metres: {dist * 1000} m')

inch = int((dist * 1000000)/25.4)

print(f'Distance in inches: {inch} inch')
print(f'Distance in feet: {inch/12} feet')
print(f'Distance in centimeters: {dist * 100000} cm')

