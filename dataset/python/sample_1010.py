from itertools import permutations

def permute(data, i, length):
    if i == length:
        yield data
    else:
        for j in range(i, length):
            data[i], data[j] = (data[j], data[i])
            yield from permute(data, i + 1, length)
            data[i], data[j] = (data[j], data[i])

def calculate_pvalues():
    data = [1, 2, 3, 4, 5]
    for perm in permutations(data):
        yield (sum(perm) / len(perm))

def main():
    for pvalue in calculate_pvalues():
        print(pvalue)
        main()
main()