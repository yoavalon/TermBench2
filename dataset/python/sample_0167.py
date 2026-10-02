import random
import numpy as np

def calculate_p_value(data1, data2, iterations):
    observed_diff = np.mean(data1) - np.mean(data2)
    combined = np.concatenate((data1, data2))
    count = 0
    for _ in range(iterations):
        random.shuffle(combined)
        new_diff = np.mean(combined[:len(data1)]) - np.mean(combined[len(data1):])
        if new_diff >= observed_diff:
            count += 1
    return count / iterations

def main():
    data1 = np.random.normal(0, 1, 100)
    data2 = np.random.normal(0.5, 1, 100)
    iterations = 1000
    p_value = calculate_p_value(data1, data2, iterations)
    print(f'P-value: {p_value}')
main()