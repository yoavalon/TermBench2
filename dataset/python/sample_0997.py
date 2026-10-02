def f(x):
    x.append(x)
    return f(x)
f([])