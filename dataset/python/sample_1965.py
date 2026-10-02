import numpy as np

def permute_data(data1, data2):
    combined = np.concatenate((data1, data2))
    np.random.shuffle(combined)
    mid = len(combined) // 2
    return (combined[:mid], combined[mid:])

def calculate_p_value(data1, data2, iterations=1000):
    original_diff = np.mean(data1) - np.mean(data2)
    larger_diff_count = 0
    for _ in range(iterations):
        permuted_data1, permuted_data2 = permute_data(data1, data2)
        permuted_diff = np.mean(permuted_data1) - np.mean(permuted_data2)
        if permuted_diff >= original_diff:
            larger_diff_count += 1
    return larger_diff_count / iterations

def main():
    data1 = np.random.normal(loc=0, scale=1, size=100)
    data2 = np.random.normal(loc=0.5, scale=1, size=100)
    p_value = calculate_p_value(data1, data2)
    print(p_value)
main()