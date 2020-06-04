#Program to find the no. of repeatations of a particular digit in a given range


start = int(input("Range starting from: "))        #Mention the start of the subject range
end = int(input("Range upto: "))                   #Mention the start of the subject range
find = input("Enter the digit you want to find: ") #Mention the digit whose repeatation you ought to find

target = list(range(start, end+1))                 #Listing the range
#print(target)
req = []
for num in target:
    num = str(num)
    nums = list(num)                               #Listing a particular number in range to work on
    #print(nums)  
    length = list(range(0, (len(num))))
    #print(length)
    for op in length:
        if nums[op] == find:
            req.append(1)

#print(req)
print(len(req))
   
