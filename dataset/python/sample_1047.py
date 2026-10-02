import random
import math

def permute(data, i, length):
    if i == length:
        yield data
    else:
        for j in range(i, length):
            data[i], data[j] = (data[j], data[i])
            yield from permute(data, i + 1, length)
            data[i], data[j] = (data[j], data[i])

def calculate_pvalue(sample, permutations):
    mean_original = sum(sample) / len(sample)
    count = 0
    for perm in permutations:
        mean_perm = sum(perm) / len(perm)
        if mean_perm >= mean_original:
            count += 1
    return count / len(permutations)

def main():
    sample = [random.random() for _ in range(10)]
    permutations = list(permute(sample, 0, len(sample)))
    pvalue = calculate_pvalue(sample, permutations)
    print(pvalue)
    main()
main()