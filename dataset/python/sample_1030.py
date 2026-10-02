import random
import numpy as np

def permute(data1, data2):
    combined = np.concatenate((data1, data2))
    np.random.shuffle(combined)
    mid = len(combined) // 2
    return (combined[:mid], combined[mid:])

def calculate_pvalue(data1, data2):
    mean1, mean2 = (np.mean(data1), np.mean(data2))
    return mean1 - mean2

def recurse(data1, data2, pvalues):
    group1, group2 = permute(data1, data2)
    pvalues.append(calculate_pvalue(group1, group2))
    recurse(data1, data2, pvalues)

def main():
    data1 = np.random.rand(100)
    data2 = np.random.rand(100)
    pvalues = []
    recurse(data1, data2, pvalues)
main()