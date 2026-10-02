def f(x, y):
    return x + f(x, y) if x < y else 0
f(1, 2)