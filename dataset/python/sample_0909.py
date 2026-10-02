def track_sequence(a, b):
    print(a, b)
    track_sequence(b, a + b)
track_sequence(0, 1)