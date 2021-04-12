# Calculate area subtended on axis by geometric figures


import math
import sympy as sp
from scipy.integrate import quad

conic = input('(S)traight line / (C)ircle / (P)arabola : ')

if conic.lower() == 's':
    slope = float(input('Enter slope: '))
    c = float(input('Starting point distance compensation from x-axis: '))
    axis = input('Enter if you want to find area subjected to (x) or (y) axis? ')
    if axis.lower() == 'x':
        llimit = float(input('Enter lower limit: '))
        ulimit = float(input('Enter upper limit: '))
        def f(x):
            return ((slope*x) + c)
        area = quad(f,llimit, ulimit)
        print(area[0])
    elif axis.lower() == 'y':
        llimit = float(input('Enter lower limit: '))
        ulimit = float(input('Enter upper limit: '))
        def f(y):
            return ((y-c) / slope)
        area = quad(f,llimit, ulimit)
        print(area[0])
    else:
        print("Invalid Input!!!!")


elif conic.lower() == 'c':
    h = float(input('Distance of centre from y-axis: '))
    k = float(input('Distance of centre from x-axis: '))
    r = float(input('Enter radius: '))
    axis = input('Enter if you want to find area subjected to (x) or (y) axis? ')
    if axis.lower() == 'x':
        llimit = float(input('Enter lower limit: '))
        ulimit = float(input('Enter upper limit: '))
        def f(x):
            return (math.sqrt(r**2 - (x-h)**2) + k)
        area = quad(f,llimit, ulimit)
        print(area[0])
    elif axis.lower() == 'y':
        llimit = float(input('Enter lower limit: '))
        ulimit = float(input('Enter upper limit: '))
        def f(y):
            return (math.sqrt(r**2 - (y-k)**2) + h)
        area = quad(f,llimit, ulimit)
        print(area[0])
    else:
        print("Invalid Input!!!!")


elif conic.lower() == 'p':
    a = float(input('Enter a: '))
    h = float(input('Enter vertex x co-ordinate: '))
    k = float(input('Enter vertex y co-ordinate: '))
    axis = input('Enter if you want to find area subjected to (x) or (y) axis? ')
    if axis.lower() == 'x':
        llimit = float(input('Enter lower limit: '))
        ulimit = float(input('Enter upper limit: '))
        def f(x):
            return math.sqrt(4*a*(x-h) + k)
        area = quad(f,llimit, ulimit)
        print(area[0])
    elif axis.lower() == 'y':
        llimit = float(input('Enter lower limit: '))
        ulimit = float(input('Enter upper limit: '))
        def f(y):
            return math.sqrt((((y-k)**2)/(4*a)) + h)
        area = quad(f,llimit, ulimit)
        print(area[0])
    else:
        print("Invalid Input!!!!")
        
else:
    print('Invalid Input')


