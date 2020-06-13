#Find the intersection points of any given curves.

import numpy as np  
import matplotlib.pyplot as plt  

def my_formula():
    return np.sin(np.arange(0, 10, 0.01) * 2) * 1000

def my_formula2():
    return np.sin(np.arange(10, 20, 0.01) * 2) * 1000

def my_formula3():
    return np.arange(0, 1000) + 15

def graph(formula):  
    x = np.arange(0, 1000, 1)  
    y = formula()
    plt.plot(x, y)  

 
def idx(curve1,curve2):
    main = np.argwhere(np.diff(np.sign(curve1() - curve2()))).flatten()
    plt.plot(curve1()[main], curve2()[main], 'ro')
    
    
graph(my_formula)
graph(my_formula2)
graph(my_formula3)
idx(my_formula,my_formula2)
idx(my_formula,my_formula3)
idx(my_formula2,my_formula3)


plt.show()
