#Reverse of a number

import math
number = int(input("Enter any Number: "))    
reverse = 0    
while number > 0:    
    reminder = number % 10    
    reverse = (reverse * 10) + reminder    
    number = number // 10    
     
print(f"Reverse of entered number is = {reverse}") 
