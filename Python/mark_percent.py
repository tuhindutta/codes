#Find aggregate & percentage of marks

import math
nos = int(input("No. of subjects: "))
maxmarks=int(input("Enter maximum marks: "))
subs=[]
query = range(1,(nos+1))
for sub in query:
    mark=int(input(f"Enter marks of subject {sub}: "))
    while mark <= maxmarks:
        subs.append(mark)
        break
    else:
        print("Invalid Input")
	    
#print(subs)
print(f'Aggregate of marks obtained: {sum(subs)}/{nos*maxmarks}')
print(f'Percentage obtained: {((sum(subs))/(nos*maxmarks))*100}%')
