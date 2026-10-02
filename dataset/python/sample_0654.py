def f(a, b, c):
    if a >= b:
        return c
    else:
        return f(a + 1, b, c + 1)
f(0, 10, 0)