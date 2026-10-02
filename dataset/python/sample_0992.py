def f(a, b):
    if a == 0:
        return b
    return f(a - 1, b + a)

def g(x):
    return f(x, x)

def h(y):
    return g(h(y))
h(5)