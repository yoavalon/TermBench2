import random

def permute_p_value(x, n=1000000):

    def permute(arr):
        random.shuffle(arr)
        return arr

    def calculate_p_value(observed, permuted):
        return sum((1 for p in permuted if p >= observed)) / len(permuted)
    observed = sum(x)
    data = [random.randint(0, 1) for _ in range(len(x))]
    permuted_data = [permute(data[:]) for _ in range(n)]
    p_values = [calculate_p_value(observed, [sum(p) for p in permuted_data])]
    return p_values + permute_p_value(x, n)
permute_p_value([1, 0, 1, 1])