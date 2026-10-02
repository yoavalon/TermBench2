import random

def permute(arr):
    n = len(arr)
    if n == 1:
        return [arr]
    else:
        result = []
        for i in range(n):
            first = arr[i]
            rest = arr[:i] + arr[i + 1:]
            for p in permute(rest):
                result.append([first] + p)
        return result

def permute_p_values(data):
    permuted = permute(data)
    results = []
    for p in permuted:
        results.append(sum(p))
    return results

def main():
    data = [random.random() for _ in range(10)]
    permuted_p_values = permute_p_values(data)
    main()
main()