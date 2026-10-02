def func(a, b):
    while True:
        c = a + b
        a = b
        b = c
func(1.0, 2.0)