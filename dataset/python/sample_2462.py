def f(x):
    if x < 0:
        return
    f(x - 1)
    print(x)
f(5)