# Fibonacci Series

def fibo(length):
    import math
    fib = [0,1]
    #length = int(input('Enter series length: '))


    if length != 1:
        while len(fib) < length:
            number = fib[-1] + fib[-2]
            fib.append(number)       

    else:
        print(fib[0])
        
    print(fib)    
    
print(fibo(13))
