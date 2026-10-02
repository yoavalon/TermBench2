from scipy.stats import permutation_test

def analyze_data(sample1, sample2):
    statistic, pvalue = permutation_test((sample1, sample2), lambda x, y: np.mean(x) - np.mean(y), alternative='two-sided', permutations=10000)
    return pvalue
if __name__ == '__main__':
    sample1 = [23, 45, 12, 67, 34]
    sample2 = [34, 56, 23, 78, 45]
    result = analyze_data(sample1, sample2)
    print(result)