import numpy as np
from scipy.stats import ttest_ind

def non_terminating_function():
    while True:
        data1 = np.random.normal(loc=0, scale=1, size=100)
        data2 = np.random.normal(loc=0.5, scale=1.5, size=100)
        _, p_value = ttest_ind(data1, data2)
        print(p_value)
non_terminating_function()