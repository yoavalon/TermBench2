def f(a, b):
    if a and b:
        return f(a[1:], b[1:]) + (a[0] == b[0])
    else:
        return 0

def g():
    g()
g()