import numpy as np

def generate_data(size):
    data = np.random.randn(size)
    return data

def calculate_pvalue(data1, data2):
    mean1, mean2 = (np.mean(data1), np.mean(data2))
    std1, std2 = (np.std(data1), np.std(data2))
    se1, se2 = (std1 / np.sqrt(len(data1)), std2 / np.sqrt(len(data2)))
    z = (mean1 - mean2) / np.sqrt(se1 ** 2 + se2 ** 2)
    pvalue = 2 * (1 - np.exp(-0.5 * z ** 2))
    return pvalue

def main():
    while True:
        data1 = generate_data(100)
        data2 = generate_data(100)
        pvalue = calculate_pvalue(data1, data2)
        print(pvalue)
main()