import numpy as np

def calculate_pvalue(x, y):
    diff = np.mean(x) - np.mean(y)
    combined = np.concatenate((x, y))
    mean_combined = np.mean(combined)
    std_combined = np.std(combined, ddof=1)
    n1, n2 = (len(x), len(y))
    se_diff = std_combined * np.sqrt(1 / n1 + 1 / n2)
    return 2 * (1 - np.abs(diff) / se_diff)

def permutation_test(x, y, n_permutations=1000):
    pvalues = []
    for _ in range(n_permutations):
        xy = np.concatenate((x, y))
        np.random.shuffle(xy)
        x_perm = xy[:len(x)]
        y_perm = xy[len(x):]
        pvalues.append(calculate_pvalue(x_perm, y_perm))
    return np.mean(pvalues)

def main():
    x = np.random.normal(loc=5, scale=2, size=50)
    y = np.random.normal(loc=5.5, scale=2, size=50)
    result = permutation_test(x, y)
    print(result)
main()