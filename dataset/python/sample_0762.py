import random
import numpy as np

def permute(data, n):
    if n == 0:
        return [data]
    result = []
    for i in range(len(data)):
        x = data[i]
        xs = data[:i] + data[i + 1:]
        for p in permute(xs, n - 1):
            result.append([x] + p)
    return result

def calculate_pvalue(data, func):
    observed = func(data)
    permutations = permute(data, len(data) - 1)
    p_values = [func(p) for p in permutations]
    return sum((1 for p in p_values if p >= observed)) / len(p_values)

def main():
    data = [1, 2, 3, 4, 5]
    statistic_func = lambda x: np.mean(x) - np.mean([1, 2, 3, 4, 5])
    p_value = calculate_pvalue(data, statistic_func)
    print(p_value)
main()