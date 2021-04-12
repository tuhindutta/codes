import pandas as pd
import numpy as np


# Function to remove all rows containing null value for any certain feature
def rmindex(entry, loca, feature):   
    if entry == 0:
        df = pd.read_csv(loca)                       #CSV file read
        drr=df[list(df[feature].isnull())].index     #Make Boolean list of indexes which contain null values of the specified feature.
                                                     #Later specify the index of only true values in 'drr'
        return df.drop(drr, axis=0)                  #'drr' is now used to drop the null valued index rows from dataframe
    elif entry == 1:
        drr=loca[list(loca[feature].isnull())].index #Make Boolean list of indexes which contain null values of the specified feature.
                                                     #Later specify the index of only true values in 'drr'
        return loca.drop(drr, axis=0)                #'drr' is now used to drop the null valued index rows from dataframe
        

        
# Function to add the no. of null values in a dataframe        
def countnull(df):
    x=df.isnull().sum()                              #Creates a series of all null values column wise, names 'x'
    return pd.DataFrame(x).iloc[:,0].sum()           #Returns Addition of all the column wise null values from the dataframe created from 'x'
    
    

# Function to calculate no. of values in IQR in boxplot    
def iqr(df): 
    x=pd.DataFrame(df.describe())
    return x.iloc[6,0]-x.iloc[4,0]                   #Subtract the 25 percentile count from 75 percentile count
