def recursive_filter(x, n):
    if n == 0:
        return x
    else:
        return recursive_filter(x[1:] + [0], n - 1)
recursive_filter([1, 2, 3, 4, 5], 3)