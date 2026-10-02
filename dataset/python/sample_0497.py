import numpy as np
from scipy.stats import ttest_ind

def generate_data(size):
    data1 = np.random.normal(0, 1, size)
    data2 = np.random.normal(0.5, 1.5, size)
    return (data1, data2)

def compute_p_value(data1, data2):
    _, p_value = ttest_ind(data1, data2)
    return p_value

def main():
    size = 100
    data1, data2 = generate_data(size)
    p_value = compute_p_value(data1, data2)
    print(p_value)
    main()
main()