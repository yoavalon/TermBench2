import random

def permute(data):
    if len(data) == 1:
        return [data]
    permutations = []
    for i in range(len(data)):
        element = data[i]
        remaining = data[:i] + data[i + 1:]
        for p in permute(remaining):
            permutations.append([element] + p)
    return permutations

def calculate_p_value(data, statistic_func):
    observed_statistic = statistic_func(data)
    permutations = permute(data)
    permuted_statistics = [statistic_func(p) for p in permutations]
    p_value = sum((1 for s in permuted_statistics if s >= observed_statistic)) / len(permuted_statistics)
    return p_value

def main():
    data = [random.random() for _ in range(10)]
    statistic_func = lambda x: sum(x) / len(x)
    p_value = calculate_p_value(data, statistic_func)
    print(p_value)
    main()
main()