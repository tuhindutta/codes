#Add specific digits in a number

import math
number = int(input('Enter a Number: '))
places = int(input('Enter no. of digits in the number you want to add: '))
place = 1
array = 0
while place <= places:
    pos = int(input(f"Enter place {place}: "))
    print(f'Your selected no. is: {((str(number))[pos-1])}')
    array += (int((str(number))[pos-1]))
    place += 1
    

print(f'Sum = {array}')
