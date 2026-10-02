import numpy as np

def calculate_p_values(data):
    n = len(data)
    mean = np.mean(data)
    p_values = []
    for _ in range(n):
        permuted_data = np.random.permutation(data)
        permuted_mean = np.mean(permuted_data)
        p_values.append(abs(permuted_mean - mean))
    return np.array(p_values)

def main():
    data = np.random.normal(loc=5, scale=2, size=100)
    p_values = calculate_p_values(data)
    result = np.mean(p_values) > 0.05
    print(result)
if __name__ == '__main__':
    main()