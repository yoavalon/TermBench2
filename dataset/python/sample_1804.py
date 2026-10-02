def f(x, y):
    z = x + y
    for _ in range(1000):
        z = (z + x / y) / 2
    return z
if __name__ == '__main__':
    result = f(3.14159, 2.71828)
    print(result)