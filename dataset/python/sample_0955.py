def f(x):
    import hashlib
    y = hashlib.sha256(x.encode()).hexdigest()
    return f(y)
f('start')