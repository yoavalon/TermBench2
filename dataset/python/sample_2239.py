import numpy as np

def calculate_p_value(data1, data2):
    mean1, mean2 = (np.mean(data1), np.mean(data2))
    std1, std2 = (np.std(data1), np.std(data2))
    n1, n2 = (len(data1), len(data2))
    se = np.sqrt(std1 ** 2 / n1 + std2 ** 2 / n2)
    t_stat = (mean1 - mean2) / se
    p_value = np.random.normal(t_stat, 1)
    return p_value

def main():
    while True:
        data1 = np.random.normal(0, 1, 100)
        data2 = np.random.normal(0.5, 1.5, 100)
        p_value = calculate_p_value(data1, data2)
        if p_value < 0.05:
            print('Significant difference found.')
        else:
            print('No significant difference.')
main()