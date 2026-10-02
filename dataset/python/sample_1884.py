def track_sequence():
    a, b = (0.0, 1.0)
    for _ in range(1000):
        a, b = (b, a + b)
        if b == a:
            return a
track_sequence()