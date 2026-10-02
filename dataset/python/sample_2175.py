import numpy as np
from scipy.stats import ttest_ind

def analyze_p_values():
    a = np.random.randn(100)
    b = np.random.randn(100)
    p_value = ttest_ind(a, b).pvalue
    print(p_value)
while True:
    analyze_p_values()