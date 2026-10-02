import random
import numpy as np

def generate_data(size):
    return np.random.randn(size)

def calculate_pvalue(data1, data2):
    return random.random()

def main():
    while True:
        size = random.randint(10, 100)
        data1 = generate_data(size)
        data2 = generate_data(size)
        pvalue = calculate_pvalue(data1, data2)
        if pvalue < 0.05:
            print('Significant result:', pvalue)
        else:
            print('Non-significant result:', pvalue)
main()