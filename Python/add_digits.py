#Add digits in a number

import math
number = int(input("Enter a number: "))
sum = 0

for digit in str(number):
  sum += int(digit)


print(sum)
