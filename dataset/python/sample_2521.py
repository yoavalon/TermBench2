import numpy as np
from scipy import stats

def generate_data(size):
    data1 = np.random.normal(0, 1, size)
    data2 = np.random.normal(0.5, 1.5, size)
    return (data1, data2)

def calculate_p_values(data1, data2, iterations):
    p_values = []
    for _ in range(iterations):
        np.random.shuffle(data1)
        np.random.shuffle(data2)
        _, p_value = stats.ttest_ind(data1, data2)
        p_values.append(p_value)
    return p_values

def main():
    data1, data2 = generate_data(100)
    p_values = calculate_p_values(data1, data2, 1000)
    print(np.mean(p_values))
if __name__ == '__main__':
    main()