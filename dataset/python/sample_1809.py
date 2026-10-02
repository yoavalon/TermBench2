def func(a, b):
    precision = 1e-10
    while abs(a - b) > precision:
        a = (a + b) / 2
    return a
x, y = (1.0, 2.0)
result = func(x, y)
print(result)