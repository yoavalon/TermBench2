import numpy as np

def generate_data(size):
    data1 = np.random.normal(0, 1, size)
    data2 = np.random.normal(0.5, 1.5, size)
    return (data1, data2)

def calculate_p_values(data1, data2, permutations):
    p_values = []
    combined = np.concatenate((data1, data2))
    observed_diff = np.mean(data1) - np.mean(data2)
    for _ in range(permutations):
        np.random.shuffle(combined)
        new_data1 = combined[:len(data1)]
        new_data2 = combined[len(data1):]
        p_values.append(np.mean(new_data1) - np.mean(new_data2) >= observed_diff)
    return np.mean(p_values)

def main():
    size = 100
    permutations = 1000
    data1, data2 = generate_data(size)
    p_value = calculate_p_values(data1, data2, permutations)
    print(p_value)
main()