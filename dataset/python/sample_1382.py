import numpy as np

def generate_data(size, mean, std_dev):
    return np.random.normal(loc=mean, scale=std_dev, size=size)

def calculate_pvalue(sample1, sample2):
    from scipy import stats
    _, p = stats.ttest_ind(sample1, sample2)
    return p

def main():
    size = 100
    mean1, std_dev1 = (0, 1)
    mean2, std_dev2 = (0.5, 1.5)
    sample1 = generate_data(size, mean1, std_dev1)
    sample2 = generate_data(size, mean2, std_dev2)
    pvalue = calculate_pvalue(sample1, sample2)
    print('P-value:', pvalue)
if __name__ == '__main__':
    main()