import math
men = float(input('Enter men population % : '))
menlit = float(input('Enter men literacy out of total population % : '))
lit = float(input('Total literacy % : '))

female = float(100-men)
femalelit = float(lit - menlit)

intramalelit = float(menlit/men)
intrafemalelit = float(femalelit/female)

print(f'Intra male literacy rate: {intramalelit}%')
print(f'Intra female literacy rate: {intrafemalelit}%')
print(f'Women population: {female}%')
print(f'Women literacy out of total population: {femalelit}')
