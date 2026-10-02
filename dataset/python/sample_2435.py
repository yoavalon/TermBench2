def f(x):
    a, b, c = (0, 1, 1)
    for _ in range(x):
        a, b, c = (b, c, a + b + c)
    return a
if __name__ == '__main__':
    f(10)