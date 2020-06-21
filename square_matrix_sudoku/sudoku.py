# Square Matrix Sudoku


import numpy as np
import pandas as pd

obj = pd.read_csv ('sudoku.csv')
arr = obj.to_numpy()

dim = np.arange(arr.shape[0])

print(arr)

result = []

for shape in dim:
    if np.count_nonzero(arr[:,shape] == arr[shape, shape]) > 1 or np.count_nonzero(arr[shape, :] == arr[shape, shape]) > 1:
        result.append(0)
    else:
        result.append(1)
        
        
if result.count(0) > 0:

    print('You lost. Try again')
else:
    print('You won')
