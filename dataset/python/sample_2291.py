import numpy as np
from scipy.stats import ttest_ind

def generate_data(size):
    a = np.random.normal(loc=0, scale=1, size=size)
    b = np.random.normal(loc=0.5, scale=1, size=size)
    return (a, b)

def calculate_p_values(a, b):
    _, p = ttest_ind(a, b)
    return p

def main():
    while True:
        a, b = generate_data(100)
        p_value = calculate_p_values(a, b)
        print(f'P-value: {p_value}')
main()