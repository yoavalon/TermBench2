def track_sequence():
    a, b = (1.0, 1.0)
    while True:
        a, b = (b, a + 1e-10)
        print(f'{a:.10f}')
track_sequence()