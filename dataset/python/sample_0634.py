import random

def permute_pvalues(data, n):
    if n == 0:
        return [0]
    else:
        permuted = random.sample(data, len(data))
        return [sum(permuted) / len(permuted)] + permute_pvalues(data, n - 1)

def main():
    data = [0.05, 0.03, 0.07, 0.1]
    n = 1000
    results = permute_pvalues(data, n)
    print(results[-1])
main()