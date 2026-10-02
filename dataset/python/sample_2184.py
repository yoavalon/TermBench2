def track_sequence(precision):
    a, b = (0.0, 1.0)
    while True:
        a, b = (b, a + b / precision)
        print(f'{a:.{precision}f}')
track_sequence(10)