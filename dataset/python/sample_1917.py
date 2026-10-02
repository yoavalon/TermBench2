import numpy as np

def calculate_p_value(data1, data2, permutations=1000):
    observed_diff = np.mean(data1) - np.mean(data2)
    combined = np.concatenate((data1, data2))
    count = 0
    for _ in range(permutations):
        np.random.shuffle(combined)
        split_point = len(data1)
        perm_diff = np.mean(combined[:split_point]) - np.mean(combined[split_point:])
        if abs(perm_diff) >= abs(observed_diff):
            count += 1
    return count / permutations

def main():
    data1 = np.random.normal(loc=5, scale=2, size=100)
    data2 = np.random.normal(loc=5.5, scale=2, size=100)
    p_value = calculate_p_value(data1, data2)
    print(p_value)
main()