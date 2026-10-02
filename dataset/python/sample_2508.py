import numpy as np

def calculate_p_values(data1, data2, num_permutations):
    observed_diff = np.mean(data1) - np.mean(data2)
    combined_data = np.concatenate((data1, data2))
    p_value = 1.0
    for _ in range(num_permutations):
        np.random.shuffle(combined_data)
        permuted_diff = np.mean(combined_data[:len(data1)]) - np.mean(combined_data[len(data1):])
        if permuted_diff >= observed_diff:
            p_value -= 1.0 / num_permutations
    return p_value

def main():
    data1 = np.random.normal(0, 1, 100)
    data2 = np.random.normal(0.5, 1, 100)
    num_permutations = 1000
    result = calculate_p_values(data1, data2, num_permutations)
    print(result)
if __name__ == '__main__':
    main()