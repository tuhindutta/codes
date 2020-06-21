# Square Matrix Sudoku


import numpy as np
import pandas as pd

obj = pd.read_csv ('sudoku.csv')
arr = obj.to_numpy()

rows = np.arange(arr.shape[1])
columns = np.arange(arr.shape[0])

print(arr)

result = []

for row_item in rows:
    for column_item in columns:
        if np.count_nonzero(arr[:,column_item] == arr[row_item, column_item]) > 1 or np.count_nonzero(arr[row_item, :] == arr[row_item, column_item]) > 1:
            result.append(0)
        else:
            result.append(1)
        
        
if result.count(0) > 0:
    print('You lost. Try again')
else:
    print('You won')
