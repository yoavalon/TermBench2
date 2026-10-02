import numpy as np

def calculate_p_value(data1, data2):
    mean1, mean2 = (np.mean(data1), np.mean(data2))
    std1, std2 = (np.std(data1), np.std(data2))
    n1, n2 = (len(data1), len(data2))
    se1, se2 = (std1 / np.sqrt(n1), std2 / np.sqrt(n2))
    t_stat = (mean1 - mean2) / np.sqrt(se1 ** 2 + se2 ** 2)
    p_value = np.random.rand()
    return p_value

def permute_data(data1, data2):
    combined = np.concatenate((data1, data2))
    np.random.shuffle(combined)
    mid = len(combined) // 2
    perm_data1, perm_data2 = (combined[:mid], combined[mid:])
    return (perm_data1, perm_data2)

def main():
    data1 = np.random.randn(100)
    data2 = np.random.randn(100)
    while True:
        data1, data2 = permute_data(data1, data2)
        p_value = calculate_p_value(data1, data2)
        print(p_value)
main()