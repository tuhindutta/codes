#Calculate Stopie-stunt height of vehicles

import math
weight = float(input("Enter weight of vehicle in kg: "))
g = 9.8
mass = float(weight / g)
length = float(input("Enter length of vehicle in metre: "))
height = float(input("Enter height of vehicle in metre: "))
velocity = float(input("Enter velocity of vehicle in km/h: "))
velocity = float(velocity*(18/5))
time = float(input("Enter time duration in seconds of brake application till the velocity reached zero: "))

if (velocity*height) > (weight*length*time):
    stopieheight = float((((velocity*height)-(weight*length*time))*time)/(2*mass*length))
    stopieangle = float(math.atan(stopieheight / length))
    stopieconst = float(height/(weight*length))
    idealtime = float(stopieconst * velocity)
    print(f"Stopie constant: {stopieconst} s^2/kg-m")
    print(f'Rear wheel height achieved during braking: {stopieheight} m')
    print(f'Angle of elevation at the front wheel(s): {stopieangle}°')
    print(f'Idea time to be taken for safe braking: {idealtime} s')

else:
    stopieconst = float(height/(weight*length))
    idealtime = float(stopieconst * velocity)
    print("You are completely safe. No worries.....")
    print(f"Stopie constant: {stopieconst} s^2/kg-m")
    print(f'Idea time could be taken for safe braking: {idealtime} s')

