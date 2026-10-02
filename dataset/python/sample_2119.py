def track_sequence():
    a, b = (0.0, 1.0)
    while True:
        c = a + b
        a, b = (b, c)
        print(c)
track_sequence()